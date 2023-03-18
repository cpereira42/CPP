#include "RPN.hpp"

RPN::RPN(void) { return ;}
RPN::RPN(const RPN& obj) { 
    *this = obj;
    return ;
}
RPN::~RPN(void) {return ;}

RPN& RPN::operator=(const RPN& obj)
{
    if (this != &obj)
    {
        this->_total = obj._total;
        this->_numbers = obj._numbers;
    }
    return (*this);
}

bool RPN::isSignal(char signal){
    if(signal == '+' || signal== '-' || signal == '*' || signal == '/')
        return true;
    return false;
}

void RPN::calc(char signal){

    int sum;

    if (isSignal(signal))
    {
        if (_numbers.size() > 1)
        {
            sum = _numbers.top();
            _numbers.pop();
            if (signal == '+')
                sum = _numbers.top() + sum;
            if (signal == '-')
                sum = _numbers.top() - sum;
            if (signal == '*')
                sum = _numbers.top() * sum;
            if (signal == '/'){
                if (_numbers.top() == 0 || sum == 0)
                    throw RPN::DivisionByZero();
                sum = _numbers.top() / sum;
            }
            _numbers.pop();
            _numbers.push(sum);
        } 
        else 
            throw RPN::InvalidInput();
    }
}

void RPN::loadData(std::string input) {

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    for (size_t i = 0 ; i <= input.length() -1 ; i++){
        if(input[i] >= '0' && input[i] <= '9')
            _numbers.push(input[i] - 48);
        else if(isSignal(input[i]))
            calc(input[i]);
        else
            throw RPN::InvalidInput();
    }
    if (_numbers.size() > 1)
        throw RPN::InvalidInput();
    _total = _numbers.top();

}
int RPN::getTotal(void) const{ return _total;}

std::ostream&    operator<<(std::ostream& o, const RPN& i)
{
    o << i.getTotal();
    return o;
}