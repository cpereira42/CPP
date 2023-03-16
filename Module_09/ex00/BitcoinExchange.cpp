#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { return ;}
BitcoinExchange::BitcoinExchange(std::string nameFile) : _nameFile(nameFile) {return ;}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) { 
    *this = obj;
    return ;
}
BitcoinExchange::~BitcoinExchange(void) {return ;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
    {
        this->_data = obj._data;
        this->_mymap = obj._mymap;
        this->_nameFile = obj._nameFile;
        this->_myfile = obj._myfile;
    }
    return (*this);
}


void BitcoinExchange::checkInput(std::string nameFile){
    std::ifstream myfile (nameFile);
    if (myfile.is_open())
        _myfile = std::string((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
    else
        throw BitcoinExchange::InvalidFile();;
    myfile.close();
}

void BitcoinExchange::loadData(char splitter){
    
    std::ifstream myfile (_nameFile); 
    std::string key;
    std::string value;
    if (myfile.is_open())
    {
        getline(myfile, key);
        while (! myfile.eof() )
        {
            getline(myfile, key, splitter);
            getline(myfile, value);
            this->_data.insert(std::pair<std::string,double>(key,std::stod(value)));
        }
    }
    myfile.close();
}

bool BitcoinExchange::checkValidDate(std::string dataStr){

    int year ;
    int month ;
    int day ;

    sscanf(dataStr.c_str(), "%d-%d-%d", &year, &month, &day);
    if (day > 31 || day < 0 || month > 12 || month < 0 || year > 2022  || year < 2009 )
    {
        std::cout << "Error: bad input => " << dataStr << std::endl;;
        return false;
    }
    return true;
}

std::string BitcoinExchange::reduceDate(std::string dataStr){
    int year ;
    int month ;
    int day ;

    sscanf(dataStr.c_str(), "%d-%d-%d", &year, &month, &day);

    day--;
    if (day <= 0){
        day =31;
        month --;
    }
    if (month <= 0){
        month = 12;
        year --;
    }
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << "-"
       << std::setw(2) << month << "-" << std::setw(2) << day;
    return ss.str();
}

bool BitcoinExchange::checkExist(std::string date){
    std::map<std::string,double>::iterator it = this->_data.begin();
    it = this->_data.find(date);
    if (it == this->_data.end()){
        return false;
    }
    return true;
}

void BitcoinExchange::process(char splitter){
    std::string key;
    std::string value;
    std::string line;
    std::string date;
    double price;
    size_t pos = 0;

    std::istringstream iss(_myfile);
    getline(iss, key);
    while (! iss.eof() )
    {
        getline(iss, line);
        if ((pos = line.find(splitter)) != std::string::npos){
            std::vector<std::string> substrings;
            std::string substring = line.substr(0, pos);
            substrings.push_back(substring);
            line.erase(0, pos + 1);
            substrings.push_back(line);
            key = substrings[0];
            value = substrings[1];
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
        date = key;
        if (!checkValidDate(date))
            continue;

        if (!is_numeric(value)) {
            std::cout << "Error: input contains non-numeric characters." << std::endl;
            continue;
        }
                           
        if (std::stod(value) < 0){
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (std::stod(value) >  1000){
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
            
        while (!checkExist(date))
            date = reduceDate(date);

        price = this->_data.find(date)->second * std::stod(value) ;
        std::cout <<  key << " => " << value << " = " << price << '\n';
    }
}

bool BitcoinExchange::is_numeric(const std::string& s) {
    bool decimal_point_found = false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (i == 0 && s[i] == '-')
            continue;
        if (c == '.') {
            if (decimal_point_found) {
                return false; // mais de um ponto decimal encontrado
            } else {
                decimal_point_found = true;
            }
        } else if (!std::isdigit(c)) {
            return false; // caractere não numérico encontrado
        }
    }
    return true;
}