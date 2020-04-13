//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//doublyLinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>


class LinkedList
{
public:

  struct Node{
    std::string key;
    Node* next;
    Node* prev;
  };

	Node* head; //head of the list
	Node* end; //end of the list
  int size;

	LinkedList(); //default constructor
	void insert(std::string str); //insert string into the list
	int getListSize(); //get list size function
	bool searchList(std::string str); //Searches list
  bool isEmpty(); //Determines if the list is empty
  void spellCheck(std::string str, LinkedList* output); //Creates everyPossible permutation on a string
  void printList(); //search for a specific student function
  ~LinkedList();
};

#endif
