//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//projectDriver.cpp
#include "dictionary.h"
#include <chrono>
int main()
{
  std::cout << "======================Project 2===================" << std::endl;
  Dictionary webster;
  auto start = std::chrono::system_clock::now();
  webster.readFile(); //Inserting all words into the dictionary
  auto end = std::chrono::system_clock::now();
  webster.findAll();
  std::chrono::duration<double> elasped_seconds = end-start;
  std::cout << "Total time taken = "  << elasped_seconds.count() << std::endl;



  std::cout << "Type Something!\n" << std::endl;
  std::string str;
  std::getline (std::cin, str);
  LinkedList* input = new LinkedList;
  webster.extractString(str,input); //Extracts all possible words from string


  int mispells = input->size; //Total number of mispelled words
  int suggestions = 0; //

  LinkedList::Node* ptr;
  ptr = input->end;
  start = std::chrono::system_clock::now();
  while(ptr != NULL)
  {
    LinkedList* firstPerm = new LinkedList;
    input->spellCheck(ptr->key, firstPerm); //Sets firstPerm to be all possible permutations of a string
    LinkedList::Node* cursor = firstPerm->head;
    LinkedList* oneEdit = new LinkedList;

    while(cursor != NULL) //Loops thorugh
    {
      if(webster.search(cursor->key) == true) //Searches if any permutations are inside the dictionary
      {
        oneEdit->insert(cursor->key); //if dound they are added to a new list called OneEdit
      }
      cursor = cursor->next;
    }

    cursor = oneEdit->head;
    if(oneEdit->head != NULL) //If any edits were possible call the loop on OneEdit to find second edit distance
    {
      suggestions =+ oneEdit->size;
      std::cout << "\n" << ptr->key << " is mispelled! Below are words within one edit distance" << std::endl;
      std::cout << "--------------------------------------------------------------\n" <<std::endl;
      std::cout << "Suggestions for " << ptr->key << ": ";
      oneEdit->printList();
      std::cout << "\nBelow are words within two edit distance" << std::endl;
      std::cout << "-------------------------------------------" <<std::endl;
      cursor = oneEdit->head;
      while(cursor != NULL)
      {
        LinkedList* secondPerm = new LinkedList;
        oneEdit->spellCheck(cursor->key, secondPerm);

        LinkedList* twoEdit = new LinkedList;
        LinkedList::Node* secondPtr = secondPerm->head; //Set to second Perm
        while(secondPtr != NULL)
        {
          if (oneEdit->searchList(secondPtr->key) != true) //Checks for dupes
          {
            if(webster.search(secondPtr->key) == true) //If not dupe searches dictionary
            {
              twoEdit->insert(secondPtr->key); //If found in Dictionary added to final List
            }
          }
          secondPtr = secondPtr->next;
        }
        if(twoEdit->head != NULL)
        {
          std::cout << "\nSuggestions for " << cursor->key << ": ";
          twoEdit->printList();
          suggestions += twoEdit->size;
        }
        else
        {
          std::cout << "There are no suggestions for " << cursor->key << std::endl;
        }
        cursor=cursor->next;
        delete secondPerm;
        delete twoEdit;
      }

    }
    else
    {
      std::cout << "There are no suggestions for " << ptr->key << std::endl;
    }
    ptr = ptr->prev;
    delete firstPerm;
    delete oneEdit;
  }
  end = std::chrono::system_clock::now();
  elasped_seconds = end-start;
  std::cout << "\n--------------------------------------\n" << "Summary\n";
  std::cout << "---------------------------------------" << std::endl;
  std::cout << "Number of mispelled words = " << mispells << std::endl;
  std::cout << "Number of suggestions " << suggestions << std::endl;
  if (suggestions != 0)
  {
    std::cout << "Time required to find suggestions  = "  << elasped_seconds.count() << std::endl;
  }

  delete input;
}
