#include "BitcoinExchange.hpp"

bool extractData(std::map<std::string, double>& data, std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database." << std::endl;
        return (false);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string rateS = line.substr(pos + 1);
        double rateD = std::atof(rateS.c_str());
        data[date] = rateD;
    }
    return (true);
}

void processDataInput(std::map<std::string, double>& data, std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find("|");
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string rateS = line.substr(pos + 1); 
    }
}