
#pragma once

#include "SPhoneNumber.h"
#include "SPerson.h"
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>


class PhoneBook
{
 private:
  std::vector<std::tuple<Person, PhoneNumber>> *m_phoneBook;
 public:
  PhoneBook(std::ifstream &file);
  PhoneBook();
  ~PhoneBook();
  void sortByName();
  void sortByPhone();
  void changePhoneNumber(const Person&, const PhoneNumber&);
  std::tuple<std::string, PhoneNumber> getPhoneNumber(std::string secondName);
  std::vector<std::tuple<Person, PhoneNumber>>& getValue() const;
};

std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook);
