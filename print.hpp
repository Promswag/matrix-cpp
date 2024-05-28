#define BLACK std::string("30")
#define RED std::string("31")
#define GREEN std::string("32")
#define YELLOW std::string("33")
#define BLUE std::string("34")
#define MAGENTA std::string("35")
#define CYAN std::string("36")
#define WHITE std::string("37")
#define PRINT(color, text) std::cout << "\033[" + color + "m" << text << "\033[0;m" << std::endl
#define COLOR(color, text) "\033[" + color + "m" << text << "\033[0;m"
#define ENDL std::cout << std::endl