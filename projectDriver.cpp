#include "dictionary.h"

int main()
{
  Dictionary webster;
  std::string str = "HELLO";
  //webster.spellCheck(str);
  std::cout << char(120) << std::endl;
  webster.insert("HELLO WORLD");
  webster.insert("PLease");
  webster.insert("YAY");
  webster.print();


}
