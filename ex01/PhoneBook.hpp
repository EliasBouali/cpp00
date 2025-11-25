#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;

private:
    Contact _contacts[8];
    int     _count;
};

#endif
