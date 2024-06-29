#ifndef __PRINT_HPP__
# define __PRINT_HPP__

#define DEFAULT "\033[0;m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PRINT(color, text) std::cout << color << text << std::endl
#define COLOR(color, text) color << text
#define ENDL std::cout << std::endl

#define HEADER_LENGTH 76

#include <iostream>
#include <iomanip>

void header(const char* str, const char *color = DEFAULT) {
	std::string title(str);
	std::size_t length = HEADER_LENGTH;
	std::size_t computed_length = (HEADER_LENGTH - title.length() - 2) / 2;
	std::cout << color << std::setfill('#');
	std::cout << std::setw(length) << std::setfill('#') << "" << std::endl;
	std::cout << std::setw(computed_length) << std::setfill('#') << "";
	std::cout << " " << title << " ";
	std::cout << std::setw(computed_length + (title.length() % 2 ? 1 : 0)) << std::setfill('#') << "" << std::endl;
	std::cout << std::setw(length) << std::setfill('#') << "" << DEFAULT << std::endl;
}
#endif