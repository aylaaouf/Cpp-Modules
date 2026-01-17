#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Replace {
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        std::string content;
    public:
        Replace(const std::string &filename, const std::string &s1, const std::string &s2);
        ~Replace();
        bool ReplaceProcess();
};

#endif