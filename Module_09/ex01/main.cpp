#include "RPN.hpp"

int main(int argc, char*argv[]) {
    if(argc != 2){
        std::cout << "Error: On args" << std::endl;
		std::cout << "Ex ./RPN \"1 2 + 3 +\"" << std::endl;
        return 1;
    }
    
    try
    {
        std::string input = argv[1];
        RPN rpn;
        rpn.loadData(input);
        std::cout << rpn << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
return 0;
}