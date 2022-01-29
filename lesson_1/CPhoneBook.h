
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
  std::vector<std::tuple<Person, PhoneNumber>> *m_phoneBook;
 public:
  PhoneBook(std::ifstream &file);
  PhoneBook();
  ~PhoneBook();
  void sortByName();
  void sortByPhone();
  void changePhoneNumber(const Person&, const PhoneNumber&);
  // this func will be return vector of PhoneNumber objects (one or several) or empty
  std::optional<std::vector<PhoneNumber>> getPhoneNumber(std::string secondName);
  std::vector<std::tuple<Person, PhoneNumber>>& getValue() const;
};

std::ostream& operator<< (std::ostream& out, const PhoneBook& phoneBook);
