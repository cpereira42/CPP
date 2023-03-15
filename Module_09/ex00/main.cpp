/*#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <fstream>      // std::ifstream
#include <map>
#include <stdlib.h>
#include <sstream>*/
#include "BitcoinExchange.hpp"

/*
std::map<std::string,double> loadData(std::string nameFile, char splitter){

    std::map<std::string,double> mymap;
    std::ifstream myfile (nameFile); 
    std::string key;
    std::string value;

    if (myfile.is_open())
    {
        getline(myfile, key);
        while (! myfile.eof() )
        {
            getline(myfile, key, splitter);
            getline(myfile, value);
            mymap.insert (std::pair<std::string,double>(key,std::stod(value)));
        }
    }
    myfile.close();
    return mymap;
}*/

/*
bool checkValidDate(std::string dataStr){

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
}*/

/*
std::string reduceDate(std::string dataStr){
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
}*/

/*
bool checkExist(std::map<std::string,double> data, std::string date){
    std::map<std::string,double>::iterator it = data.begin();
    it = data.find(date);
    if (it == data.end()){
        return false;
    }
    return true;
}*/


/*void checkInput(std::string nameFile, char splitter, std::map<std::string,double> data){
    std::ifstream myfile (nameFile);
    std::string key;
    std::string value;
    std::string line;
    std::string date;
    double price;
    size_t pos = 0;

    if (myfile.is_open())
    {
        getline(myfile, key);
        while (! myfile.eof() )
        {
            getline(myfile, line);
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
            date = key;
            if (!checkValidDate(date))
                continue;

            if (std::stod(value) < 0){
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (std::stod(value) >  INT_MAX){
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
                
            while (!checkExist(data, date))
                date = reduceDate(date);

            price = data.find(date)->second * std::stod(value) ;
            std::cout <<  key << " => " << value << " = " << price << '\n';
        }
    }
    else {
        std::cout << "Error: could not open file." << std::endl;
    }
    myfile.close();
}*/

int main(int argc, char*argv[]) {
    if(argc != 2){
        std::cout << "Error: could not open file." << argv[1] << std::endl;
        return 1;
    }

    try
    {
        Btc btc("data.csv");
        btc.loadData(',');
        btc.checkInput(argv[1]);
        btc.process('|');
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    


    // fazer a checagem se a entrada não for numérica
    //btc linha 108

    //std::map<std::string,double> data;
    //btc.loadData("data.csv", ',');

    
    //data = loadData("data.csv", ',');
    //checkInput(argv[1], '|', data);
return 0;
}