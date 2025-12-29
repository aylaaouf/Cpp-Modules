#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST 1: Instantiation ---" << std::endl;
    DiamondTrap d1("Monster");

    std::cout << "\n--- TEST 2: WhoAmI ---" << std::endl;
    d1.whoAmI();

    std::cout << "\n--- TEST 3: Attack ---" << std::endl;
    d1.attack("Target_Dummy");
    
    std::cout << "\n--- TEST 5: Copy Constructor ---" << std::endl;
    DiamondTrap d2(d1);
    d2.whoAmI();

    std::cout << "\n--- TEST 6: Destruction Chain ---" << std::endl;
    return (0);
}