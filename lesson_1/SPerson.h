
#pragma once
#include <iostream>
#include <string>
#include <optional>

struct Person
{
  std::string secondName;
  std::string firstName;
  std::optional<std::string> thirdName;

  Person(std::string secondName,
	 std::string firstName,
	 std::optional<std::string> thirdName = std::nullopt);
  bool operator<(const Person& person) const;
  bool operator==(const Person& person) const;
  friend std::ostream& operator<<(std::ostream& out, const Person& person);
};

bool compareNames(std::string name1, std::string name2);


