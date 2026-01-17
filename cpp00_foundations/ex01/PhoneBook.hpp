#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
private:
    Contact contacts[8];
    int index;
    int count;

    std::string truncate(const std::string &value) const;

public:
    PhoneBook();
    void addContact();
    void search() const;
};

#endif