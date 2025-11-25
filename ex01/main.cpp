#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
  PhoneBook phonebook;
  std::string command;

  while ((true))
  {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";

    if (!std::getline(std::cin, command))
      break;

    if (command == "ADD")
      phonebook.addContact();

    else if (command == "SEARCH")
      phonebook.searchContacts();

    else if (command == "EXIT")
    {
      std::cout << "Bye!" << std::endl;
      break;
    }
    else
      std::cout << "Invalid command. Try again." << std::endl;
  }
  return 0;
}
