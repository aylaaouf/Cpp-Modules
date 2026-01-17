#include "PhoneBook.hpp"

int main() {
    PhoneBook pb;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) {
            std::cout << "No input. Exiting.\n";
            break;
        }
        if (cmd == "ADD") {
            pb.addContact();
        } else if (cmd == "SEARCH") {
            pb.search();
        } else if (cmd == "EXIT") {
            std::cout << "Goodbye :)\n";
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
    return (0);
}