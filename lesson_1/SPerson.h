
#pragma once
#include <iostream>

struct Person
{
  const char* firstName = nullptr;
  const char* secondName = nullptr;
  const char* thirdName = nullptr;
  bool operator<(const Person &person);
  bool operator==(const Person &person);
  friend std::ostream& operator<<(std::ostream& out, const Person& person);
};

bool compareNames(const char* name1, const char* name2);


