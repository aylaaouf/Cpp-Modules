#include "Replace.hpp"

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2) {
    this->filename = filename;
    this->s1 = s1;
    this->s2 = s2;
}

Replace::~Replace() {};

bool Replace::ReplaceProcess() {
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for reading.\n";
        return (false);
    }
    std::stringstream buffer;
    buffer << input.rdbuf();
    this->content = buffer.str();
    input.close();

    std::string outpout;
    size_t pos = 0;
    while (true) {
        size_t found = content.find(s1, pos);
        if (found == std::string::npos) {
            outpout += content.substr(pos);
            break ;
        }
        outpout += content.substr(pos, found - pos);
        outpout += s2;
        pos = found + s1.length();
    }
    std::ofstream outp((filename + ".replace").c_str());
    if (!outp.is_open()) {
        std::cerr << "Error: Could not open file '"
            << filename << ".replace' for writing.\n";
        return (false);
    }
    outp << outpout;
    outp.close();
    return (true);
}
