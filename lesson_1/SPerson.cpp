#include "SPerson.h"
#include <iostream>
#include <tuple>

bool compareNames(const char* name1, const char* name2)
{
  // for comparison of third names
  // both are nullptr
  if (!name1 && !name2)
    return true;
  // one of them is nullptr
  else if (!name1 || !name2)
    return false;
  
  bool comparisonResult = true;
  unsigned i = 0; // index for cycle
  while (name1[i] != '\0' || name2[i] != '\0')
    {
      if (name1[i] != name2[i])
	{
	  comparisonResult = false;
	  break;
	}
      ++i;
    }
  // name1 and name2 have different sizes
  if (name1[i] != name2[i])
    comparisonResult = false;
  return comparisonResult;
}

Person::Person(const char* secondName,
	       const char* firstName,
	       const char* thirdName)
{
  this->secondName = secondName;
  this->firstName = firstName;
  this->thirdName = thirdName;
}

std::ostream& operator<< (std::ostream& out, const Person& person)
{
  out << person.secondName << " " << person.firstName;
  if (person.thirdName)
    out << " " << person.thirdName;
  return out;
}

bool Person::operator< (const Person &person)
{
  /*
  // using tie comparison compiler compare char[] pointers ! wrong comparison
  return std::tie(this->firstName, this->secondName, this->thirdName) <
    std::tie(person.firstName, person.secondName, person.thirdName);
  */
  
  // SECOND NAMES COMPARISON
  unsigned i = 0; // index for cycle
  while (this->secondName[i] != '\0' || person.secondName[i] != '\0')
    {
      if (this->secondName[i] < person.secondName[i])
	return true;
      else if (this->secondName[i] > person.secondName[i])
	return false;
      ++i;
    }
  // if this name bigger than person name OR on the contrary
  if (this->secondName[i] == '\0' && person.secondName[i] != '\0')
    return true; // this name smaller than person name
  else if (this->secondName[i] != '\0' && person.secondName[i] == '\0')
    return false; // this name bigger than person name

  // FIRST NAMES COMPARISON
  i = 0;
  while (this->firstName[i] != '\0' || person.firstName[i] != '\0')
    {
      if (this->firstName[i] < person.firstName[i])
	return true;
      else if (this->firstName[i] > person.firstName[i])
	return false;
      ++i;
    }
  // if this name bigger than person name OR on the contrary
  if (this->firstName[i] == '\0' && person.firstName[i] != '\0')
    return true; // this name smaller than person name
  else if (this->firstName[i] != '\0' && person.firstName[i] == '\0')
    return false; // this name bigger than person name
 
  // THIRD NAMES COMPARISON
  i = 0;
  // if one of third names there is not
  if (!this->thirdName && person.thirdName)
    return true;
  else if (!this->thirdName || !person.thirdName)
    return false;
  // if both third names there are
  while (this->thirdName[i] != '\0' || person.thirdName[i] != '\0')
    {
      if (this->thirdName[i] < person.thirdName[i])
	return true;
      else if (this->thirdName[i] > person.thirdName[i])
	return false;
      ++i;
    }
  // if this name bigger than person name OR on the contrary
  if (this->thirdName[i] == '\0' && person.thirdName[i] != '\0')
    return true; // this name smaller than person name
  else if (this->thirdName[i] != '\0' && person.thirdName[i] == '\0')
    return false; // this name bigger than person name
  
  return false;
}

bool Person::operator==(const Person &person)
{
  /*
  // using tie comparison compiler compare char[] pointers ! wrong comparison
  return std::tie(this->firstName, this->secondName, this->thirdName) ==
    std::tie(person.firstName, person.secondName, person.thirdName);
  */

  // SECOND NAMES COMPARISON
  if (!compareNames(this->secondName, person.secondName))
    return false;
 
  // FIRST NAMES COMPARISON
  else if (!compareNames(this->firstName, person.firstName))
    return false;
  
  // THIRD NAMES COMPARISON
  else if (!compareNames(this->thirdName, person.thirdName))
    return false;
  else
    return true;
}
