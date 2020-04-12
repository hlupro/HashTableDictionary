#include "dictionary.h"

int main()
{
  //Dictionary webster;
  LinkedList list;
  list.insert("TEST");
  list.insert("HI");
  list.insert("FEVER");
  std::cout << list.getListSize() << std::endl;
  list.printList();
  return 0;
}
