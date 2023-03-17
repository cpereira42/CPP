#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstring>

class RPN {
    public:
        RPN (void);
        RPN (const RPN &obj);
        ~RPN (void);

        RPN& operator=(const RPN& obj);

        void calc(void);
        void loadData(std::string input);
        int  getTotal(void) const;


    private:
        std::stack<int> _numbers;
        std::stack<char> _signal;
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
    class CantBeCalculate : public std::exception
    {
        public:
            virtual const char *what() const throw(){
                return ("Can't be calculated");
            }
    };
};

std::ostream&    operator<<(std::ostream& o, const RPN& i);

#endif