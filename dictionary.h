#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include "doublyLinkedList.h"
#include <fstream>
#include "hash.h"


class Dictionary
{
  private:
    int size;
    int largest;
    int smallest;
    int averageNode;
    double time;
    LinkedList** arr;

  public:
    Dictionary();
    void insert(std::string str);
    void readFile();
    bool search(std::string str);
    int hash(std::string str);
    void spellCheck(std::string str);
    void numOfBucket();
    void print();
    ~Dictionary();

};

#endif
