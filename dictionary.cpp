//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//dictionary.cpp
#include "dictionary.h"

Dictionary :: Dictionary()
{
  size = 10000;
  largest = 0;
  smallest = 0;
  averageNode = 0;
  arr = new LinkedList*[size];

  for(int i = 0; i < size; i++)
  {
    arr[i] = new LinkedList;
  }
}

void Dictionary :: findAll() //Finds all the statistical data about the dictionary
{
  largest = arr[1]->size;
  smallest = arr[1]->size;
  for(int i  = 1; i < size; i++)
  {
    if(arr[i]->size > largest)
    {
      largest = arr[i]->size;
    }
    if(arr[i]->size < smallest)
    {
      smallest = arr[i]->size;
    }
  }
  averageNode = (double)words / (double)size;
  std::cout << "----------------------------------------------\n";
  std::cout << "Loading DataBase\n";
  std::cout << "----------------------------------------------\n";
  std::cout << "Total words = " << words << std::endl;
  std::cout << "Biggest Bucket size = " << largest << std::endl;
  std::cout << "Smallest bucket size = " << smallest << std::endl;
  std::cout << "Total number of buckets = " << size << std::endl;
  std:: cout << "Number of Buckets Used = " << numOfBucket() << std::endl;
  std::cout << "Average number of nodes in each bucket = " << averageNode << std::endl;
}

void Dictionary :: insert(std::string str) //inserts a word into the dictionary
{
  int num = strHash(str); //hash of the string which determines what bucket
  arr[num]->insert(str); //string is inserted
}

void Dictionary :: print() //prints the List
{
  arr[0]->printList();
}

void Dictionary :: readFile() //Reads in strings from a file and inserts them into dictionary
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
  words = num;
}

bool Dictionary :: search(std::string str) //searches for a word in the dictionary
{
  return arr[strHash(str)]->searchList(str);
}


void Dictionary :: extractString(std::string str, LinkedList* mispelled) //Extracts words from a string
{
  int len = 1;
  int end = str.length();
  std::string strSub;
  int j;

  for(int i = 0; i < str.length(); i+=len) //For loop that extracts words from a string. i is the start pos
  {
    len = 1; //using the str.substr function I need the length of the substring which is len
    j = i;  //j iterates through the string until it hits a space or punctuation
    while(j < str.length()-1 && str.at(j) != ' ' && str.at(j) != '.' && str.at(j) != '!' && str.at(j) != '?') //Until j is equal to a space or punctuation keep incrementing
    {
      j++;
      len++;
    }
    if(str.at(j) == '.' || str.at(j) == '!' || str.at(j) == '?') //If j is a punctuation char, take the substring at i and len-1 so the char is not added
    {
      strSub = str.substr(i,len-1);
      len++;   //increment length so the next loop starts at the next non space char.
      if(search(strSub) != true)
      {
        mispelled->insert(strSub);
      }
    }
    else
    {
      if(str.at(j) == str.at(end-1))
      {
          strSub = str.substr(i,len);
          if(search(strSub) != true)
          {
            mispelled->insert(strSub);
          }
      }
      else
      {
        strSub = str.substr(i,len-1); //If j is a space, take the substring at i,len
        if(search(strSub) != true)
        {
          mispelled->insert(strSub);
        }
      }
    }
  }
}

int Dictionary :: numOfBucket() //Returns number of buckets in use
{

  int num = 0;
  for(int i = 0; i < size; i++)
  {
    if(arr[i]->isEmpty() != true)
    {
      num++;
    }
  }

  return num;
}

Dictionary :: ~Dictionary()
{
  for(int i = 0; i < size; i++)
  {
    delete arr[i];
  }
  delete [] arr;
}
