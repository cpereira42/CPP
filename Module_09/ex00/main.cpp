#include "BitcoinExchange.hpp"

int main(int argc, char*argv[]) {
    if(argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange BitcoinExchange("data.csv");
        BitcoinExchange.loadData(',');
        BitcoinExchange.checkInput(argv[1]);
        BitcoinExchange.process('|');
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
return 0;
}