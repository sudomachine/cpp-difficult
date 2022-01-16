
#include "CPhoneBook.h"

void PhoneBook::printPhoneBook() const
{
  // print
}

void PhoneBook::sortByName()
{
  //sort
}

void PhoneBook::sortByPhone()
{
  //sort
}

std::tuple<const char*, PhoneNumber> PhoneBook::getPhoneNumber(const char* secondName) const
{
  return std::tie(secondName, PhoneNumber{9,999,9999999});
}

void PhoneBook::changePhoneNumber(const Person& person, const PhoneNumber& newNumber)
{
  //change
}
