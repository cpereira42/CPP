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
        std::cout << "in construtor" << std::endl;
        PmergeMe pMergeMe2(argc, argv);
        std::cout << pMergeMe2 << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    



    /*
    std::list<int> list;
    std::vector<int> vector;

    std::cout << "mostra argumentos." << argv[1] << std::endl;
    vector = loadDataToVector(argc, argv);
    list = loadDataToList(argc, argv);

    long dif;
    clock_t start = clock();
    bubbleSortVector(vector);
    clock_t end = clock();
    dif = static_cast<long>((end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000000));
    // Imprimir o tempo decorrido
    std::cout << "Time to process a range of: timSort " << vector.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << dif << " us" << std::endl;
    


    start = clock();
    bubbleSort(list);
    end = clock();
    dif = static_cast<long>((end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000000));
    // Imprimir o tempo decorrido
    std::cout << "Time to process a range of: buble " << vector.size() << " elements with std::list : " << std::fixed << std::setprecision(5) << dif << " us" << std::endl;
    
    
    */

return 0;
}