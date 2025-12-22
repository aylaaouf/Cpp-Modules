#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(0, 10);

    Point P_inside(3, 2);
    Point P_edge(5, 0);
    Point P_outside(10, 10);

    std::cout << "P_inside: " << (bsp(A, B, C, P_inside) ? "inside" : "outside") << std::endl;
    std::cout << "P_edge:   " << (bsp(A, B, C, P_edge) ? "inside" : "outside") << std::endl;
    std::cout << "P_outside:" << (bsp(A, B, C, P_outside) ? "inside" : "outside") << std::endl;

    return 0;
}