#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <sys/time.h>
#include <iomanip> //setprecision

class PmergeMe {
    public:
        PmergeMe (void);
        ~PmergeMe (void);
        PmergeMe(const PmergeMe& obj);

        PmergeMe&    operator=(const PmergeMe& obj);

        void bubbleSortVector(void);
        void bubbleSort(void);
        bool isInteger(const std::string number);
        void loadData(int argc, char*argv[]);
        void printInfo(int argc, char*argv[]);
        double getTime(void);
        double deltaTime(long long time);


    private :
       std::vector<int> _myVector;
       std::list<int>   _myList;
       double           _timer1;
       double           _timer2;

    
    class NotIsANumber : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Error: not is a number.");
            }
    };

};

std::ostream&    operator<<(std::ostream& o, const PmergeMe& i);
#endif