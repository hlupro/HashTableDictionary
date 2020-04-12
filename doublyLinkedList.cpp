#include "doublyLinkedList.h"
#include <iostream>

LinkedList :: LinkedList()
{
  head = NULL;
  end = NULL;
  size = 0;
}

void LinkedList :: insert(std::string str)
{
  Node* newNode = new Node;
	newNode->prev = NULL;
	newNode->key = str;

	if (head != NULL)
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		newNode->next = NULL;
		head = newNode;
		end = newNode;
	}
  size++;
}

int LinkedList :: getListSize()
{
  return size;
}

void LinkedList :: printList()
{
  Node* cursor = head;
  while(cursor != NULL)
  {
    std::cout << cursor->key << std::endl;
    cursor = cursor->next;
  }
}

LinkedList :: ~LinkedList()
{
  while(head != end)
  {
    Node* del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
  delete head;
}
