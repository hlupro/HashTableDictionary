#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include "doublyLinkedList.h"


class Dictionary
{
  private:
    int size = 10000;
    int largest;
    int smallest;
    int used;
    int averageNode;
    double time;
    LinkedList** arr;

  public:
    Dictionary();
    void insert(std::string);
    bool search(std::string);
    int hash(std::string);
    void spellCheck(std::string);

};

#endif
