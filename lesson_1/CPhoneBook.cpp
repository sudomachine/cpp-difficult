
#include "CPhoneBook.h"
#include <string>
#include <algorithm>

PhoneBook::PhoneBook(std::ifstream &file)
{
  if (!file)
    {
      std::cout << "File is not open!" << std::endl;
      throw;
    }
  
  // constr
  PhoneBook::m_phoneBook = new std::vector<std::pair<Person, PhoneNumber>>;

  // read file
  
  std::string sName, fName, tName, countryC, cityC, number, exNumber;
  std::optional<int> oExNumber;
  std::optional<std::string> oTName;

  while (file)
    {
      // read a row from file
      file >> sName >> fName >> tName >> countryC >> cityC >> number >> exNumber;
      if (exNumber == "-")
	{
	  oExNumber = std::nullopt;
	}
      else
	{
	  oExNumber = std::stoi(exNumber);
	}
      if (tName == "-")
	{
	  oTName = std::nullopt;
	}
      else
	{
	  oTName = tName;
	}
      // add Person and PhoneNumber objects to phone book
      PhoneBook::m_phoneBook->push_back(std::pair<Person, PhoneNumber> {
	  Person(sName, fName, oTName),
	    PhoneNumber(std::stoi(countryC),
			std::stoi(cityC),
			std::stoi(number),
			oExNumber)});

      // data FAIL !!!!!!!!!
      // read last row two times from file 
    }
}

// FILE content
 /*
Sudakov Andrey Alekseevich 7 981 7947513 1
Achmetov Vladimir - 7 921 3278318 -
Kovalev Denis Olegovich 7 981 2449040 6003
Zemelis Olga Vyacheslavovna 7 906 2565709 -
Sudakov Oleg Alekseevich 7 981 1947513 1
Sudakov Andrey Olegovich 8 981 7947513 1
Zhavko Stepan - 7 921 2547859 -
*/

PhoneBook::~PhoneBook()
{
  // destr
  delete PhoneBook::m_phoneBook;
}

void PhoneBook::sortByName()
{
  auto cmpNames = [](std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2)
		  {
		    return p1.first < p2.first;
		  };
  // sort vector by name
  std::sort(PhoneBook::m_phoneBook->begin(), PhoneBook::m_phoneBook->end(), cmpNames);
}

void PhoneBook::sortByPhone()
{
  auto cmpNumbers = [](std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2)
		    {
		      return p1.second < p2.second;
		    };
  // sort vector by phone
  std::sort(PhoneBook::m_phoneBook->begin(), PhoneBook::m_phoneBook->end(), cmpNumbers);
}

std::optional<std::vector<PhoneNumber>> PhoneBook::getPhoneNumber(const std::string& secondName)
{
  // if not found
  std::vector<PhoneNumber> phoneNumbersList;

  for (const auto& record: *PhoneBook::m_phoneBook)
    {
      // found the same second name
      if (secondName == record.first.secondName)
	{
	  // if found 1 record
	  phoneNumbersList.push_back(record.second);
	}
    }

  if (phoneNumbersList.size() > 0)
    {
      // if found one or more
      return phoneNumbersList;
    }
  else
    {
      // if not found
      return std::nullopt;
    }
}

void PhoneBook::changePhoneNumber(const Person& person, const PhoneNumber& newPhoneNumber)
{
  // 1 find this person
  for (auto& record: *PhoneBook::m_phoneBook)
    {
      // take Person obj from phone book and compare with this name
      // 2.1 change number if there
      if (record.first == person)
	{
	  // phoneNumber from phone book = new number
	  record.second = newPhoneNumber;
	  break;
	  }
      // 2.2 do not anything
    }
}

std::vector<std::pair<Person, PhoneNumber>>& PhoneBook::getValue() const
{
  return *PhoneBook::m_phoneBook;
}

std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook)
{
  for (const auto& record: phoneBook.getValue())
    {
      out << record.first << ", " << record.second << std::endl;
    }
  return out;
}
