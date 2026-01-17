#include <iostream>

void To_Upper(char &c)
{
    c -= 32;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                To_Upper(av[i][j]);
            std::cout << av[i][j];
        }
    }
    std::cout << "\n";
}
