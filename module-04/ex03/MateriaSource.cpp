#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete (inventory[i]);
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete (inventory[i]);
                inventory[i] = NULL;
            }
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return (*this);
}


void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m->clone();
            delete m;
            return ;
        }
    }
    delete (m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] && inventory[i]->getType() == type)
            return (inventory[i]->clone());
    }
    return (NULL);
}