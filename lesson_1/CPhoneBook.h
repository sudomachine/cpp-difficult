
#include "SPhoneNumber.h"
#include "SPerson.h"
#include <tuple>


class PhoneBook
{
 private:
  std::tuple<Person, PhoneNumber> *phoneBook;
 public:
  PhoneBook();
  ~PhoneBook();
  void printPhoneBook() const;
  void sortByName();
  void sortByPhone();
  std::tuple<const char*, PhoneNumber> getPhoneNumber(const char* secondName) const;
  void changePhoneNumber(const Person& person, const PhoneNumber& newNumber);
};
