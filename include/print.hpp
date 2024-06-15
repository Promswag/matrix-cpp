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