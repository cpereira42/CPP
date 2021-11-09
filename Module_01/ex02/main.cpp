
#include <iostream>
#include <string> // To use string
#include <iomanip>

int	main (void)
{
    std::string phrase;
    std::string *phrasePTR;
    std::string &phraseREF = phrase;

    phrase = "HI THIS IS BRAIN";
    phrasePTR = &phrase;

	std::cout << "Adress string "	<< &phrase << std::endl;
    std::cout << "Adress stringPTR "	<< phrasePTR << std::endl;
    std::cout << "Adress stringREF "	<< &phraseREF << std::endl;
    std::cout << "String by stringPTR "	<< *phrasePTR << std::endl;
    std::cout << "String by stringREF "	<< phraseREF << std::endl;
    return (0);
}