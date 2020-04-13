//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//dictionary.h
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
    int size; //Number of buckets
    int largest; //Number of nodes the largest bucket has
    int smallest; //Number of nodes the smallest bucket has
    int words; //Total words inserted into dictionary
    int used; //Number of buckets used
    double averageNode; //Average Number of nodes in buckets
    LinkedList** arr; //Array of LinkedLists

  public:
    Dictionary();
    void insert(std::string str);
    void readFile();
    bool search(std::string str);
    int hash(std::string str);
    int numOfBucket();
    void extractString(std::string str, LinkedList* input);
    void findAll();
    void print();
    ~Dictionary();

};

#endif
