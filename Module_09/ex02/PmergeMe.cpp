#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { return ;}
PmergeMe::PmergeMe(int argc, char **argv) { 
    loadData(argc, argv);
    Sort();
    printInfo(argc, argv);
    return ;}

PmergeMe::~PmergeMe(void) {return ;}
PmergeMe::PmergeMe(const PmergeMe& obj) { 
    *this = obj;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != &obj)
    {
        this->_myVector = obj._myVector;
        this->_myDeque = obj._myDeque;
        this->_timerVector = obj._timerVector;
        this->_timerDeque = obj._timerDeque;
    }
    return (*this);
}

void PmergeMe::Sort(void){
    double start;
    start = getTime();
    merge_insert_sort(_myVector);
    _timerVector = deltaTime(start);

    start = getTime();
    merge_insert_sort(_myDeque);
    _timerDeque = deltaTime(start);
}



bool PmergeMe::isInteger(const std::string number){
    try {
        atoi(number.c_str());
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

void PmergeMe::loadData(int argc, char*argv[]){
    std::set<int> checker;
    int number;
    _size = argc;


    for (int i = 1; i < argc; i++)
        if (isInteger(argv[i])){
            number = atoi(argv[i]);
            _myVector.push_back(number);
            _myDeque.push_back(number);
            if (checker.find(number) != checker.end())
                throw Duplicated();
            checker.insert(number);
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
}

template<typename T>
void PmergeMe::merge_insert_sort(T& container) {
    if (container.size() <= 1) {
        return;
    }
    int mid = container.size() / 2;
    T left(container.begin(), container.begin() + mid);
    T right(container.begin() + mid, container.end());
    merge_insert_sort(left);
    merge_insert_sort(right);
    typename T::iterator i = left.begin();
    typename T::iterator j = right.begin();
    typename T::iterator k = container.begin();
    while (i != left.end() && j != right.end()) {
        if (*i < *j) {
            *k = *i;
            ++i;
        } else {
            *k = *j;
            ++j;
        }
        ++k;
    }
    while (i != left.end()) {
        *k = *i;
        ++i;
        ++k;
    }
    while (j != right.end()) {
        *k = *j;
        ++j;
        ++k;
    }
}

double PmergeMe::getVectorTimer() const {
    return _timerVector;
}

double PmergeMe::getDequeTimer() const{
    return _timerDeque;
}

int PmergeMe::getSize() const {
    return _size;
}


std::ostream&    operator<<(std::ostream& o, const PmergeMe& i)
{
    o << std::endl <<  "Time to process a range of " <<  i.getSize() << " elements with std::vector : "  << std::fixed << std::setprecision(5) << i.getVectorTimer() << " us" << std::endl;
    std::cout << "Time to process a range of " << i.getSize() <<" elements with std::deque   : "  << std::fixed << std::setprecision(5) << i.getDequeTimer() << " us";
    return o;
}


