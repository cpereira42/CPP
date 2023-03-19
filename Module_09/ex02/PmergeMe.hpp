#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream> // to print
#include <stdlib.h> // to convert atoi
#include <sys/time.h> // calculate time
#include <iomanip> //setprecision
#include <set> //to verify duplicates


class PmergeMe {
    public:
        PmergeMe (void);
        PmergeMe (int argc, char **argv);
        ~PmergeMe (void);
        PmergeMe(const PmergeMe& obj);

        PmergeMe&    operator=(const PmergeMe& obj);

        bool isInteger(const std::string number);
        void loadData(int argc, char*argv[]);
        void Sort(void);
        void printInfo(int argc, char*argv[]);
        double getTime(void);
        double deltaTime(long long time);
        template <typename T>
        void merge_insert_sort(T& container);
        double getVectorTimer() const;
        double getDequeTimer() const;
        int getSize() const;

    private :
       std::vector<int> _myVector;
       std::deque<int>  _myDeque;
       double           _timerVector;
       double           _timerDeque;
       int              _size;

    
    class NotIsANumber : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Error: not is a number.");
            }
    };

    class Duplicated : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Number duplicated");
            }
    };

};

std::ostream&    operator<<(std::ostream& o, const PmergeMe& i);
#endif