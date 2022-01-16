
struct PhoneNumber
{
  unsigned short countryCode;
  unsigned short cityCode;
  unsigned int number;
  int extensionNumber = -1;
  void printPhoneNumber() const;
  bool operator<(const PhoneNumber &phoneNumber);
  bool operator==(const PhoneNumber &phoneNumber);
};
