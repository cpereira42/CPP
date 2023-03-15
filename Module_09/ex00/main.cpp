#include "BitcoinExchange.hpp"

int main(int argc, char*argv[]) {
    if(argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        Btc btc("data.csv");
        btc.loadData(',');
        btc.checkInput(argv[1]);
        btc.process('|');
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
return 0;
}