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
    std::chrono::time_point<std::chrono::high_resolution_clock> inicio = std::chrono::high_resolution_clock::now();
    int n = _myVector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (_myVector[j] > _myVector[j + 1]) {
                std::swap(_myVector[j], _myVector[j + 1]);
            }
        }
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duracao = fim - inicio;
    _timer1 = duracao.count();
}

void PmergeMe::bubbleSort(void) {
    std::chrono::time_point<std::chrono::high_resolution_clock> inicio = std::chrono::high_resolution_clock::now();
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
    std::chrono::time_point<std::chrono::high_resolution_clock> fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duracao = fim - inicio;
    _timer2 = duracao.count();
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

void PmergeMe::printInfo(int argc, char*argv[]){
    std::cout << "Before : " ;
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl << "After  : ";
    for (std::vector<int>::iterator it = _myVector.begin(); it != _myVector.end(); it++) {
       std::cout << *it << " ";
    }
    std::cout << std::endl << "Time to process a range of " << _myVector.size() << " elements with std::vector : " << _timer1 << " us" << std::endl;
    std::cout << "Time to process a range of " << _myList.size() <<" elements with std::list   : " << _timer2 << " us" << std::endl;

}

