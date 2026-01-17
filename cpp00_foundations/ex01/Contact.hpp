#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;

    public:
        void setFirstName(const std::string &value);
        std::string getFirstName() const;

        void setLastName(const std::string &value);
        std::string getLastName() const;

        void setNickName(const std::string &value);
        std::string getNickName() const;

        void setPhoneNumber(const std::string &value);
        std::string getPhoneNumber() const;

        void setDarkestSecret(const std::string &value);
        std::string getDarkestSecret() const;
};

#endif