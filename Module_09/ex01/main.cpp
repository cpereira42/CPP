#include "RPN.hpp"

int main(int argc, char*argv[]) {
    if(argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {
        std::string input = argv[1];
        RPN rpn;
        rpn.loadData(input);
        rpn.calc();
        std::cout << rpn << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
return 0;
}