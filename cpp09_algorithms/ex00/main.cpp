#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::map<std::string, double> data;
    if (!extractData(data, "data.csv"))
        return (1);
    processDataInput(data, av[1]);
}