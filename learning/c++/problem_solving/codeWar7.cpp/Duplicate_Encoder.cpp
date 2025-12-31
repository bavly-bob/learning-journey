/* duplicate_encode
    https://www.codewars.com/kata/54b42f9314d9229fd6000d9c
    instructions:
    The goal of this exercise is to convert a string to a new string where each character in
    the new string is "(" if that character appears only once in the original string, or ")"
    if that character appears more than once in the original string. Ignore capitalization when
    determining if a character is a duplicate. (this program assume that the input is inside the acsii table)*/

#include <string>
#include <cctype>
#include <vector>

std::string duplicate_encoder(const std::string& word)
{
  std::vector<int>arr(256, 0);
  std::string result= "";

  for(int i = 0; i < word.size(); i++)
  {
    arr[tolower(word[i])] ++;
  }
  
  for(int i = 0; i < word.size(); i++)
  {
    result +=  arr[tolower(word[i])] > 1 ? ')' : '(';  
  }
  return result;
}