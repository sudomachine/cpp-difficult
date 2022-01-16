
struct Person
{
  const char* firstName = nullptr;
  const char* secondName = nullptr;
  const char* thirdName = nullptr;
  void printPersonData() const;
  bool operator<(const Person &person);
  bool operator==(const Person &person);
};

bool compareNames(const char* name1, const char* name2);
