#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook()
:_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
  int index = _count % 8;

  std::cout << "Adding a new contact at slot " << index << std::endl;
  _contacts[index].input();

  if (_contacts[index].valid())
    _count++;
}

static bool isNumber(const std::string &str)
{
  if (str.empty())
    return false;
  for (std::size_t i = 0; i < str.size(); i++)
  {
    if (!std::isdigit(str[i]))
      return false;
  }
  return true;
}


void PhoneBook::searchContacts() const
{
  if (_count == 0)
  {
    std::cout << "PhoneBook is empty. Add a contact first." << std::endl;
    return ;
  }

  int max;
  if (_count < 8)
    max = _count;
  else
    max = 8;

  for (int i = 0; i < max; i++)
  {
    if (_contacts[i].valid())
      _contacts[i].printRow(i);
  }

  std::cout << "Enter the index of the contact you want to see: ";

  std::string line;
  if (!std::getline(std::cin, line))
    return ;

  if (!isNumber(line))
  {
    std::cout << "Invalid index (not a number)." << std::endl;
    return ;
  }

  int index = std::atoi(line.c_str());
  if (index < 0 || index >= max || !_contacts[index].valid())
  {
    std::cout << "Invalid index." << std::endl;
    return ;
  }

  _contacts[index].printDetails();
}

