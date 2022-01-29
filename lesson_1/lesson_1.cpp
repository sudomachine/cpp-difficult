
#include "SPerson.h"
#include "SPhoneNumber.h"
#include "CPhoneBook.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>

int main()
{
  
  // test
  Person p("Sudakov", "Andrey");
  std::cout << Person("Jhon", "Sinna") << std::endl;
  
  Person p2("Sudakov", "Andrey", "Alekseevich");

  std::cout << "What name is bigger?" << std::endl;
  std::cout << p << " OR " << p2 << std::endl;

  std::cout << "p < p2: " << ((p < p2) ? "TRUE" : "FALSE") << std::endl;
  std::cout << "p == p2: " << ((p == p2) ? "TRUE" : "FALSE") << std::endl;
  
  
  // TEST
  PhoneNumber number(7, 981, 7947513, 0);
  PhoneNumber number2(7, 981, 7947513, 1);

  std::cout << number << " and " << number2 << std::endl;

  std::cout << (number < number2) << std::endl;
  std::cout << (number == number2) << std::endl;
  
  
  // test
  std::ifstream file("fileForRead");

  if (!file)
    {
      std::cout << "File is not open!" << std::endl;
      return 0;
    }

  PhoneBook pb(file);
  
  std::cout << "PHONE BOOK\n" << pb << std::endl;

  pb.sortByName();
  std::cout << "SORTED by NAME\n" << pb << std::endl;

  pb.sortByPhone();
  std::cout << "SORTED by PHONE\n" << pb << std::endl;
  
  pb.changePhoneNumber(Person("Sudakov", "Andrey", "Olegovich"),
		       PhoneNumber(7, 981, 7947513));
  std::cout << "RESULT:" << std::endl << pb << std::endl;

  std::cout << "\nTEST getPhoneNumber" << std::endl;
  auto vNumbers = pb.getPhoneNumber("Zemelis");
  if (vNumbers)
    {
      for (const auto& number: *vNumbers)
	{
	  std::cout << number << std::endl;
	}
    }
  
  /*
  std::ifstream file("fileForRead");
  PhoneBook book(file);
  std::cout << book << std::endl;

  std::cout << "------SortByPhone------" << std::endl;
  book.sortByPhone();
  std::cout << book << std::endl;

  std::cout << "------SortByName------" << std::endl;
  book.sortByName();
  std::cout << book << std::endl;

  std::cout << "------GetPhoneNumber------" << std::endl;
  auto printPhoneNumber = [&book](const std::string& secondName)
			  {
			    std::cout << secondName << "\t";
			    auto answer = book.getPhoneNumber(secondName);
			    if (get<0>(answer).empty())
			      {
				std::cout << get<1>(answer);
			      }
			    else
			      {
				std::cout << get<0>(answer);
			      }
			    std::cout << std::endl;
			  };

  printPhoneNumber("Sudakov");
  printPhoneNumber("Achmetov");
  printPhoneNumber("Ivanov");

  std::cout << "------changePhoneNumber------" << std::endl;
  book.changePhoneNumber(Person("Zemelis", "Olga", "Vyacheslavovna"),
			 PhoneNumber(7, 123, 15344458));
  book.changePhoneNumber(Person("Kovalev", "Denis", "Olegovich"),
			 PhoneNumber(16, 465, 9155448, 13));
  std::cout << book << std::endl;
  */
}
