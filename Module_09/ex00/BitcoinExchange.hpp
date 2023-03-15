#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <sstream>

class Btc {
    public:
        Btc (void);
        Btc (std::string fileName);
        Btc (const Btc &obj);
        ~Btc (void);

        Btc& operator=(const Btc& obj);

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


#endif