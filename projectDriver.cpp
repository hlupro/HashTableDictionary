#include "dictionary.h"

int main()
{
  Dictionary webster;
  std::string str = "HELLO";
  //webster.spellCheck(str);
  webster.readFile();
  //webster.print();
  webster.numOfBucket();
  if(webster.search("1st"))
  {
    std::cout << "Found" << std::endl;
  }

}
