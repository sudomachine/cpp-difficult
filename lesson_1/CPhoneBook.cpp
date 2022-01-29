
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
  PhoneBook::m_phoneBook = new std::vector<std::tuple<Person, PhoneNumber>>;

  // read file
  
  std::string sName, fName, tName, countryC, cityC, number, exNumber;

  while (file)
    {
      // read a row from file
      file >> sName >> fName >> tName >> countryC >> cityC >> number >> exNumber;
      if (exNumber == "-") exNumber = "-1";
      if (tName == "-") tName = "";

      // add Person and PhoneNumber objects to phone book
      PhoneBook::m_phoneBook->push_back(std::tuple<Person, PhoneNumber> {Person(sName, fName, tName), PhoneNumber(std::stoi(countryC), std::stoi(cityC), std::stoi(number), std::stoi(exNumber))});

      // data FAIL !!!!!!!!!
      // read last row two times from file 
      // std::cout << *this << std::endl;
    }
}

// FILE content
 /*
Sudakov;Andrey;Alekseevich;7;981;7947513;-
Achmetov;Vladimir;-;7;921;3278318;-
Kovalev;Denis;Olegovich;7;981;2449040;6003
Zemelis;Olga;Vyacheslavovna;7;906;2565709;-
Zhavko;Stepan;-;7;921;2547859;-
*/

PhoneBook::~PhoneBook()
{
  // destr
  delete PhoneBook::m_phoneBook;
}

void PhoneBook::sortByName()
{
  // returns true if first name(t1) less than second name(t2)
  auto cmpNames = [](std::tuple<Person, PhoneNumber> t1, std::tuple<Person, PhoneNumber> t2)
		  {
		    return std::get<0>(t1) < std::get<0>(t2);
		  };
  // sort vector by name
  std::sort(PhoneBook::m_phoneBook->begin(), PhoneBook::m_phoneBook->end(), cmpNames);
}

void PhoneBook::sortByPhone()
{
  // returns true if first number(t1) less than second number(t2)
  auto cmpNumbers = [](std::tuple<Person, PhoneNumber> t1, std::tuple<Person, PhoneNumber> t2)
		    {
		      return std::get<1>(t1) < std::get<1>(t2);
		    };
  // sort vector by phone
  std::sort(PhoneBook::m_phoneBook->begin(), PhoneBook::m_phoneBook->end(), cmpNumbers);
}

std::optional<std::vector<PhoneNumber>> PhoneBook::getPhoneNumber(const std::string secondName)
{
  // if not found
  std::vector<PhoneNumber> phoneNumbersList;

  for (const auto& record: *PhoneBook::m_phoneBook)
    {
      // found the same second name
      if (secondName == std::get<0>(record).secondName)
	{
	  // if found 1 record
	  phoneNumbersList.push_back(std::get<1>(record));
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
      if (std::get<0>(record) == person)
	{
	  // phoneNumber from phone book = new number
	  std::get<1>(record) = newPhoneNumber;
	  break;
	  }
      // 2.2 do not anything
    }
}

std::vector<std::tuple<Person, PhoneNumber>>& PhoneBook::getValue() const
{
  return *PhoneBook::m_phoneBook;
  // don't understand why use dereferencing a pointer
  // if must return the link to vector
  // because m_phoneBook is a pointer (CPhoneBook.h L15)
}

std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook)
{
  for (const auto& contact: phoneBook.getValue())
    {
      out << std::get<0>(contact) << ", " << std::get<1>(contact) << std::endl;
    }
  return out;
}
