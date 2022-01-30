
#pragma once

#include "SPhoneNumber.h"
#include "SPerson.h"
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <optional>


class PhoneBook
{
 private:
  std::vector<std::pair<Person, PhoneNumber>> *m_phoneBook;
 public:
  PhoneBook(std::ifstream&);
  PhoneBook();
  ~PhoneBook();
  void sortByName();
  void sortByPhone();
  void changePhoneNumber(const Person&, const PhoneNumber&);
  // this func will be return vector of PhoneNumber objects (one or several) or nullopt
  std::optional<std::vector<PhoneNumber>> getPhoneNumber(const std::string&);
  std::vector<std::pair<Person, PhoneNumber>>& getValue() const;
};

std::ostream& operator<< (std::ostream&, const PhoneBook&);
