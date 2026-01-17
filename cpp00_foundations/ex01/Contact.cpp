#include "Contact.hpp"

void Contact::setFirstName(const std::string &value)
{
    FirstName = value;
}

std::string Contact::getFirstName() const
{
    return (FirstName);
}

void Contact::setLastName(const std::string &value)
{
    LastName = value;
}

std::string Contact::getLastName() const
{
    return (LastName);
}

void Contact::setNickName(const std::string &value)
{
    NickName = value;
}

std::string Contact::getNickName() const
{
    return (NickName);
}

void Contact::setPhoneNumber(const std::string &value)
{
    PhoneNumber = value;
}

std::string Contact::getPhoneNumber() const
{
    return (PhoneNumber);
}

void Contact::setDarkestSecret(const std::string &value)
{
    DarkestSecret = value;
}

std::string Contact::getDarkestSecret() const
{
    return (DarkestSecret);
}
