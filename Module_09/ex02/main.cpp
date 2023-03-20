#include "PmergeMe.hpp"

int main(int argc, char*argv[]) {
    if(argc < 2){
        std::cout << "Error" << std::endl;
        return 1;
    }

    
    try
    {
        PmergeMe pMergeMe;
        pMergeMe.loadData(argc, argv);
        pMergeMe.Sort();
        pMergeMe.printInfo(argc, argv);
        std::cout << pMergeMe << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

return 0;
}