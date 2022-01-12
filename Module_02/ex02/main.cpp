#include <iostream>
# include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;


	Fixed c(10);
	Fixed d(2.25f);
	std::cout << std::endl << "c: " << c << " d: " << d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;

	

    return 0;
}