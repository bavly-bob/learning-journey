// Find the missing letter in the passed letter array
// https://www.codewars.com/kata/5839edaa6754d6fec10000a2
// You will be given an array of consecutive (increasing) letters as input.
// There will be exactly one letter missing. Write a function to find
// the missing letter and return it.

#include <iostream>
#include <vector>

char findMissingLetter(const std::vector<char>& chars)
{
  // TODO: Find the missing char in the consecutive letter sequence and return it.
  for(int i= 1; i < chars.size();i++)
    if(chars[i] - chars[0] != i) return chars[i-1] + 1;
  return ' ';
}