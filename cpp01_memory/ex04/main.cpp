#include "Replace.hpp"

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>\n"; 
        return (1);
    }
    if (!av[2][0]) {
        std::cerr << "Error: s1 cannot be empty\n";
        return (1);
    }    
    Replace r(av[1], av[2], av[3]);
    if (!r.ReplaceProcess()) { return (1); }
    return (0);
}