#include "SPerson.h"
#include <iostream>
#include <tuple>

bool compareNames(std::string name1, std::string name2)
{
  if (name1 == name2)
    return true;
  else
    return false;
}

Person::Person(std::string secondName,
	       std::string firstName,
	       std::optional<std::string> thirdName)
{
  this->secondName = secondName;
  this->firstName = firstName;
  this->thirdName = thirdName;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
  out << person.secondName << " " << person.firstName;
  if (person.thirdName.has_value())
    {
      out << " " << person.thirdName.value();
    }
  return out;
}

bool Person::operator<(const Person& person) const
{
  return std::tie(this->secondName, this->firstName, this->thirdName) <
    std::tie(person.secondName, person.firstName, person.thirdName);
}

bool Person::operator==(const Person& person) const
{
  return std::tie(this->secondName, this->firstName, this->thirdName) ==
    std::tie(person.secondName, person.firstName, person.thirdName);
}
