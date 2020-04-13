//Hunter Lupro
//Project2
//Dr. Anderson
//April 12, 2020
//hash.cpp
#include "hash.h"
size_t hash(size_t x)
{
  //will be used for 2^32
  size_t w = 32;
  //value below w but not too small
  size_t p = 13;
  //ten-digit prime
  size_t a = 5754853343;
  //
  size_t ax = a*x;
  //variable in order to avoid mismatch data types
  size_t one = 1;

  //another way to do ax mod 2^w using bitwise operators AKA binary mask
  size_t axModW = ax & ((one<<w) - one);
  //another way to divide by 2^(w-p) essentially cutting off the bits
  size_t hash = axModW >> (w-p);
  return hash;
}

//Similar to the first hash function but this one takes position into account
//by multiplying each char by i+1 before adding it to the sum.
size_t strHash(std::string str)
{
  size_t sum = 0;
  int size = str.length();
  for (int i = 0; i < size; i++)
  {
    sum += (str[i] * (i+1));
  }
  return hash(sum);
}
