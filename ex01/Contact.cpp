#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static std::string limitToTenCharacters(const std::string &str)
{
  if (str.length() > 10)
    return str.substr(0, 9) + ".";
  return str;
}

static void readNonEmptyLine(const std::string &prompt, std::string &field)
{
  while (true)
  {
    std::cout << prompt;
    if (!std::getline(std::cin, field))
      return ;
    if (!field.empty())
      return ;
    std::cout << "Field cannot be empty. Please try again." << std::endl;
  }
}

Contact::Contact()
: _firstName(), _lastName(), _nickname(), _phoneNumber(), _darkestSecrect()
{
}

Contact::~Contact()
{
}

void Contact::input()
{
  readNonEmptyLine("First name: ", _firstName);
  readNonEmptyLine("Last name: ", _lastName);
  readNonEmptyLine("Nickname: ", _nickname);
  readNonEmptyLine("Phone number: ", _phoneNumber);
  readNonEmptyLine("Darkest secret: ", _darkestSecrect);
}

void Contact::printRow(int index) const
{
  std::cout << std::setw(10) << index << "|"
            << std::setw(10) << limitToTenCharacters(_firstName) << "|"
            << std::setw(10) << limitToTenCharacters(_lastName) << "|"
            << std::setw(10) << limitToTenCharacters(_nickname) << std::endl;
}

void Contact::printDetails() const
{
  std::cout << "First name: " << _firstName << std::endl;
  std::cout << "Last name: " << _lastName << std::endl;
  std::cout << "Nickname: " << _nickname << std::endl;
  std::cout << "Phone number: " << _phoneNumber << std::endl;
  std::cout << "Darkest secret: " << _darkestSecrect << std::endl;
}

bool Contact::valid() const
{
  if (_firstName.empty())
    return false;
  else
    return true;
}
