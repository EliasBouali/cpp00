#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();
    ~Contact();

    void input();
    void printRow(int index) const;
    void printDetails() const;
    bool valid() const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecrect;
};

#endif
