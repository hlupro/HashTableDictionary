#include "dictionary.h"

Dictionary :: Dictionary()
{
  arr = new LinkedList*[size];

  for(int i = 0; i < size; i++)
  {
    arr[i] = new LinkedList;
  }
}
