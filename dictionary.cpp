#include "dictionary.h"

Dictionary :: Dictionary()
{
  size = 10000;
  arr = new LinkedList*[size];

  for(int i = 0; i < size; i++)
  {
    arr[i] = new LinkedList;
  }
}

void Dictionary :: insert(std::string str)
{
  int num = strHash(str);
  arr[num]->insert(str);
}

void Dictionary :: print()
{
  arr[0]->printList();
}

void Dictionary :: readFile()
{
  int num = 0;
  std::string str;
  std::ifstream inFile;
  inFile.open("english.txt");

  if(inFile)
  {

    while(getline(inFile, str))
    {
      insert(str);
      num++;
    }
    inFile.close();
  }
  else
  {
    std::cout << "Unable to open file." << std::endl;
  }
  std::cout << num << std::endl;
}

bool Dictionary :: search(std::string str)
{
  return arr[strHash(str)]->searchList(str);
}

void Dictionary :: spellCheck(std::string str)
{
  LinkedList suggest;
  std::string dummy = str;

  for(int i = 0; i < str.length() -1; i++) //generates every letter combination possible
  {
    for(int j = i+1; j <str.length();j++)
    {
      dummy = str;
      char temp = dummy[i];
      dummy[i] = dummy[j];
      dummy[j] = temp;
      if(dummy.compare(str) != 0)
      {
      //  std::cout << dummy << std::endl;
      }
    }
  }

  for(int i = 0; i < str.length() + 1; i++)
  {

    for(int j = 97; j < 123; j++) //Adds a lowercase letter
    {
      // char c = char(j);
      dummy = str;
      dummy.insert(i,1,char(j));
    //  std::cout << dummy << std::endl;
    }
    for(int j = 65; j < 91; j++) //Adds a capital letter
    {
      // char c = char(j);
      dummy = str;
      dummy.insert(i,1,char(j));
    //  std::cout << dummy << std::endl;
    }
  }

  for(int i = 0; i < str.length(); i++) //replacement and delete edit
  {
    dummy = str;
    dummy.erase(i,1);
    std::cout << dummy << std::endl;
    for(int j = 97; j < 123; j++) //Replaces char at pos i with char(j) "lowercase"
    {
      dummy = str;
      dummy.replace(i,1,1,char(j));
      std::cout << dummy << std::endl;
    }
    for(int j = 65; j < 91; j++) //Replaces char at pos i with char(j) "uppercase"
    {
      dummy = str;
      dummy.replace(i,1,1,char(j));
      std::cout << dummy << std::endl;
    }
  }
}

void Dictionary :: numOfBucket()
{
  int num = 0;
  for(int i = 0; i < size; i++)
  {
    if(arr[i]->isEmpty() != true)
    {
      num++;
    }
  }
  std::cout << num << std::endl;
}

Dictionary :: ~Dictionary()
{
  for(int i = 0; i < size; i++)
  {
    delete arr[i];
  }
  delete [] arr;
}
