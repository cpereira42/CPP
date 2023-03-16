#include "PmergeMe.hpp"
#include <vector>
#include <map>
#include <ctime>

#include <chrono>


/*void bubbleSortVector(std::vector<int>& myVector) {
    int n = myVector.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (myVector[j] > myVector[j + 1]) {
                std::swap(myVector[j], myVector[j + 1]);
            }
        }
    }
}*/

/*
void bubbleSort(std::list<int>& myList) {
    int n = myList.size();
    std::list<int>::iterator it_i = myList.begin();
    std::list<int>::iterator it_j = std::next(it_i);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*it_j < *it_i) {
                std::swap(*it_i, *it_j);
            }
            it_i++;
            it_j++;
        }
        it_i = myList.begin();
        it_j = std::next(it_i);
    }
}*/
/*
bool isInteger(const std::string number){
    try {
        std::stoi(number);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}


std::vector<int> loadDataToVector(int argc, char*argv[]){

    std::vector<int> vector;

    for (int i = 1; i < argc; i++)
        if (isInteger(argv[i]))
            vector.push_back(atoi(argv[i]));
        else
            std::cout << "Error" << std::endl;
    return vector;
}*/

/*
std::list<int> loadDataToList(int argc, char*argv[]){

    std::list<int> list;

    for (int i = 1; i < argc; i++)
        if (isInteger(argv[i]))
            list.push_back(atoi(argv[i]));
        else
            std::cout << "Error" << std::endl;
    return list;
}*/

void sortList(std::list<int> list){

    long dif;

    clock_t start = clock();
    list.sort();
    clock_t end = clock();
    dif = static_cast<long>((end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000000));
    // Imprimir o tempo decorrido
    std::cout << "Time to process a range of: " << list.size() << " elements with std::list : " << dif << " us" << std::endl;
}

/*
double sortVector(std::vector<int> vector){
    std::chrono::time_point<std::chrono::high_resolution_clock> inicio = std::chrono::high_resolution_clock::now();
    std::sort(vector.begin(), vector.end());
    
    std::chrono::time_point<std::chrono::high_resolution_clock> fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duracao = fim - inicio;
    return duracao.count();
}*/



int main(int argc, char*argv[]) {
    if(argc < 2){
        std::cout << "Error" << std::endl;
        return 1;
    }

    //std::vector<int> vector = loadDataToVector(argc, argv);

    //double tempo = sortVector(vector);
    //std::cout << "Tempo de execucao da funcao: " << tempo << " microsegundos." << std::endl;


    PmergeMe pMergeMe;
    try
    {
        pMergeMe.loadData(argc, argv);
        pMergeMe.bubbleSortVector();
        pMergeMe.bubbleSort();
        pMergeMe.printInfo(argc, argv);
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