#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstring>
#include <algorithm> 

class RPN {
    public:
        RPN (void);
        RPN (const RPN &obj);
        ~RPN (void);

        RPN& operator=(const RPN& obj);

        void loadData(std::string input);
        void calc(char signal);
        bool isSignal(char signal);
        int  getTotal(void) const;


    private:
        std::stack<int> _numbers;
        int              _total;
    
    class InvalidInput : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Error");
            }
    };
    class DivisionByZero : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Can't be divided by 0");
            }
    };
};

std::ostream&    operator<<(std::ostream& o, const RPN& i);

#endif