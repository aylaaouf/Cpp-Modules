#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>

bool extractData(std::map<std::string, double>& data,
    std::string filename);
void processDataInput(std::map<std::string, double>& data,
    std::string filename);

#endif