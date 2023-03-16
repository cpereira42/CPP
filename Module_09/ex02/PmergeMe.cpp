#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { return ;}
PmergeMe::~PmergeMe(void) {return ;}
PmergeMe::PmergeMe(const PmergeMe& obj) { 
    *this = obj;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != &obj)
    {
        this->_myList = obj._myList;
        this->_myList = obj._myList;
        this->_timer1 = obj._timer1;
        this->_timer2 = obj._timer2;
    }
    return (*this);
}

void PmergeMe::bubbleSortVector(void) {
    
    double start = getTime();
    int n = _myVector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (_myVector[j] > _myVector[j + 1]) {
                std::swap(_myVector[j], _myVector[j + 1]);
            }
        }
    }

    _timer1 = deltaTime(start);
}

void PmergeMe::bubbleSort(void) {
    
    double start = getTime();
    int n = _myList.size();
    std::list<int>::iterator it_i = _myList.begin();
    std::list<int>::iterator it_j = std::next(it_i);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*it_j < *it_i) {
                std::swap(*it_i, *it_j);
            }
            it_i++;
            it_j++;
        }
        it_i = _myList.begin();
        it_j = std::next(it_i);
    }
    _timer2 = deltaTime(start);
}

bool PmergeMe::isInteger(const std::string number){
    try {
        std::stoi(number);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

void PmergeMe::loadData(int argc, char*argv[]){
    for (int i = 1; i < argc; i++)
        if (isInteger(argv[i])){
            _myVector.push_back(atoi(argv[i]));
            _myList.push_back(atoi(argv[i]));
        }
        else
            throw PmergeMe::NotIsANumber();
}

double    PmergeMe::getTime(void)
{
    struct timeval    time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

double    PmergeMe::deltaTime(long long time)
{
    if (time > 0)
        return (getTime() - time);
    return (0);
}


void PmergeMe::printInfo(int argc, char*argv[]){
    std::cout << "Before : " ;
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl << "After  : ";
    for (std::vector<int>::iterator it = _myVector.begin(); it != _myVector.end(); it++) {
       std::cout << *it << " ";
    }
    std::cout << std::endl << "Time to process a range of " <<  _myVector.size() << " elements with std::vector : "  << std::fixed << std::setprecision(5) << _timer1 << " us" << std::endl;
    std::cout << "Time to process a range of " << _myList.size() <<" elements with std::list   : "  << std::fixed << std::setprecision(5) << _timer2 << " us" << std::endl;

}

