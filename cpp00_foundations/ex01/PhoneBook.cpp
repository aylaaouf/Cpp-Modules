#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string &value) const {
    if (value.length() > 10)
        return (value.substr(0, 9) + ".");
    else
        return (value);
}

PhoneBook::PhoneBook() {
    index = 0;
    count = 0;
}

bool getField(const std::string &prompt, std::string &field){
    std::cout << prompt;
    if (!std::getline(std::cin, field)) {
        std::cout << "\nInput cancelled (EOF).\n";
        return (false);
    }
    if (field.empty()) {
        std::cout << "Field cannot be empty\n";
        return (getField(prompt, field));
    }
    return (true);
}

bool isValidPhoneNumber(const std::string &phone) {
    size_t start = 0;

    if (phone[0] == '+')
            start++;
    for (size_t i = start; i < phone.length(); i++) {
        if (!isdigit(phone[i]))
            return (false);
    }
    return (true);
}

void PhoneBook::addContact() {
    Contact temp;
    std::string input;
    if (!getField("Enter First Name: ", input)) return;
    temp.setFirstName(input);
    
    if (!getField("Enter Last Name: ", input)) return;
    temp.setLastName(input);
    
    if (!getField("Enter Nick Name: ", input)) return;
    temp.setNickName(input);
    
    while (true) {
        if (!getField("Enter Phone Number: ", input)) return;
        if (isValidPhoneNumber(input)) break;
        std::cout << "Invalid phone number! Only digits allowed.\n";
    }
    temp.setPhoneNumber(input);
    
    if (!getField("Enter Darkest Secret: ", input)) return;
    temp.setDarkestSecret(input);
    contacts[index % 8] = temp;
    index++;
    if (count < 8) { count++; }
}

void PhoneBook::search() const {
    std::string input;
    int index;

    if (count == 0) {
        std::cout << "PhoneBook empty\n";
        return;
    }
    std::cout << "Index | First Name | Last Name | Nickname\n";
    std::cout << "------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getNickName());
        std::cout << "\n";
    }
    std::cout << "------------------------------------------\n";
    std::cout << "enter index to view the contact: ";
    if (!std::getline(std::cin, input)) {
        std::cout << "\nError: No input\n";
        return;
    }
    index = atoi(input.c_str());
    if (index < 0 || index >= count) {
        std::cout << "Invalid index\n";
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickName() << "\n";
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}
