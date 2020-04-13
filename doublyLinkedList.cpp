//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//doublyLinkedList.cpp
#include "doublyLinkedList.h"
#include <iostream>

LinkedList :: LinkedList()
{
  head = NULL;
  end = NULL;
  size = 0;
}

void LinkedList :: insert(std::string str) //inserts string into the list
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

bool LinkedList :: searchList(std::string str) //Searches list returns true if found
{
  Node* cursor = head;
  while(cursor != NULL)
  {
    if(cursor->key.compare(str) == 0)
    {
      return true;
    }
    cursor = cursor->next;
  }
  return false;
}

bool LinkedList :: isEmpty() //if list is empty returns true if not returns false
{
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
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
    std::cout << "*" << cursor->key << "* ";
    cursor = cursor->next;
  }
  std::cout << "\n";
}

void LinkedList :: spellCheck(std::string str, LinkedList* output)
{

    std::string original = str;
    std::string dummy = original;
    int len = str.length();
    for(int i = 0; i < len -1; i++) //generates every letter combination possible
    {
      for(int j = i+1; j < len; j++)
      {
        dummy = original;
        char temp = dummy[i];
        dummy[i] = dummy[j];
        dummy[j] = temp;
        if(dummy.compare(original) != 0)
        {
          output->insert(dummy);
        }
      }
    }

    for(int i = 0; i < len + 1; i++)
    {

      for(int j = 97; j < 123; j++) //Adds a lowercase letter
      {
        // char c = char(j);
        dummy = original;
        dummy.insert(i,1,char(j));
        output->insert(dummy);
      }
      for(int j = 65; j < 91; j++) //Adds a capital letter
      {
        // char c = char(j);
        dummy = original;
        dummy.insert(i,1,char(j));
        output->insert(dummy);
      }
    }

    for(int i = 0; i < len; i++) //replacement and delete edit
    {
      dummy = original;
      dummy.erase(i,1);
      output->insert(dummy);
      for(int j = 97; j < 123; j++) //Replaces char at pos i with char(j) "lowercase"
      {
        dummy = original;
        dummy.replace(i,1,1,char(j));
        if(dummy.compare(original) != 0)
        {
          output->insert(dummy);
        }
      }
      for(int j = 65; j < 91; j++) //Replaces char at pos i with char(j) "uppercase"
      {
        dummy = original;
        dummy.replace(i,1,1,char(j));
        if(dummy.compare(original) != 0)
        {
          output->insert(dummy);
        }
      }
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
