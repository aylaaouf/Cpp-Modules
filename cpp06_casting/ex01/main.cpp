#include "Serializer.hpp"

int main() 
{
    Data d;
    d.x = 19;
    d.str = "string";
    std::cout << d.str << std::endl;
    uintptr_t  raw = Serializer::serialize(&d);
    std::cout << raw << std::endl;
    Data *dp  = Serializer::deserialize(raw);
    std::cout << dp->str << std::endl;
}