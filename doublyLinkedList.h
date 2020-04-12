#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class LinkedList
{
  private:

  struct Node{
    std::string key;
    Node* next;
    Node* prev;
  };

	Node* head; //head of the list
	Node* end; //end of the list
  int size;

public:
	LinkedList(); //default constructor
	void insert(std::string str); //insert student function
	int getListSize(); //get list size function
	bool searchList(std::string str);
  bool isEmpty();
  void printList(); //search for a specific student function
  ~LinkedList();
};

#endif
