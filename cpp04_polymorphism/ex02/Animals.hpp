#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <string>
#include "Brain.hpp"

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal( const Animal& other );
        Animal& operator=( const Animal& other );
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const = 0;
};

class Dog : public Animal {
    private:
        Brain* brain;
    public:
        Dog();
        Dog( const Dog& other );
        Dog& operator=( const Dog& other );
        virtual ~Dog();
        void makeSound() const;
};

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat( const Cat& other );
        Cat& operator=( const Cat& other );
        virtual ~Cat();
        void makeSound() const;
};

#endif