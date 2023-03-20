#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

class BitcoinExchange {
    public:
        BitcoinExchange (void);
        BitcoinExchange (std::string fileName);
        BitcoinExchange (const BitcoinExchange &obj);
        ~BitcoinExchange (void);

        BitcoinExchange& operator=(const BitcoinExchange& obj);

        void loadData(char splitter);
        bool checkValidDate(std::string dataStr);
        std::string reduceDate(std::string dataStr);
        bool checkExist(std::string date);
        void process(char splitter);
        void checkInput(std::string nameFile);
        void copyMyFile(const std::ifstream& myFile);
        bool is_numeric(const std::string& s);

    private :
        std::map<std::string,double> _mymap;
        std::map<std::string,double> _data;
        std::string _nameFile;
        std::string _myfile;
    
    class InvalidFile : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Error: could not open file.");
            }
    };
};
    std::ostream&    operator<<(std::ostream& o, const BitcoinExchange& i);

#endif