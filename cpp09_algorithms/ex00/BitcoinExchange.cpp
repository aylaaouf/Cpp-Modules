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
    std::map<std::string, double>::iterator it;
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find("|");
        if (pos == std::string::npos)
        {
            std::string date = line.substr(0, pos);
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string rateS = line.substr(pos + 1);
        if (!date.empty() && date[date.length() - 1] == ' ')
            date.erase(date.length() - 1);
        if (rateS.find("-") != std::string::npos) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        double rateD = atof(rateS.c_str());
        if (rateD > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        it = data.lower_bound(date);
        if (it == data.end() || it->first != date)
            it--;
        double result = rateD * it->second;
        std::cout << date
                << " => "
                << rateD
                << " = "
                << result
                << std::endl;
    }
}