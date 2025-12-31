// Backspace in String
// https://www.codewars.com/kata/5727bb0fe81185ae62000ae3
// Given a string S, where '#' represents a backspace character, return the final string after all backspaces have been processed.
// Example: "abc#d##c" -> "ac"

#include <string>
#include <stack>
#include <algorithm>
std::string cleanString(const std::string &s) 
{
    std::string str = "";
    std::stack<char> clean;
    for(char c : s)
    {
      if( c != '#') clean.push(c);
      else if(!clean.empty()) clean.pop();
    }
    
    int sizee = clean.size();
    for(int i =0 ; i < sizee;i++)
    {
      str += clean.top();
      clean.pop();
    }
    std::reverse(str.begin(), str.end());
    return str;
}