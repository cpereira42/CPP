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
        this->_signal = obj._signal;
        this->_numbers = obj._numbers;
    }
    return (*this);
}

void RPN::calc(void){
    
    if (_numbers.size() <= 0)
        throw RPN::CantBeCalculate();

    _total = _numbers.top();
    _numbers.pop();

    while (_numbers.size() >= 1) {
        if (_signal.top() == '+')
            _total += _numbers.top();
        if (_signal.top() == '-')
            _total -= _numbers.top();
        if (_signal.top() == '*')
            _total *= _numbers.top();
        if (_signal.top() == '/'){
            if(_numbers.top() == 0)
                throw RPN::DivisionByZero();
            _total /= _numbers.top();
        }
        _signal.pop();
        _numbers.pop();
    }
}

void RPN::loadData(std::string input) {
    char last = 'n';

    _numbers.empty();
    _signal.empty();

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    for (int i = input.size() - 1; i >= 0; i--){
        if(input[i] >= '0' && input[i] <= '9' && last == 's')
        {
            _numbers.push(input[i] - 48);
            if (i == 1)
                last = 's';
            else
                last = 'n';
        }
        else if((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && last == 'n')
        {
            _signal.push(input[i]);
            last = 's';
        }
        else
            throw RPN::InvalidInput();
    }
}
int RPN::getTotal(void) const{ return _total;}

std::ostream&    operator<<(std::ostream& o, const RPN& i)
{
    o << i.getTotal();
    return o;
}