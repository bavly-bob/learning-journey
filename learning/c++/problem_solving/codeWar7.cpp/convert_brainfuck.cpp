#include <iostream>

inline std::string to_brainfuck (const std::string& s_in) 
{
  std::string s ="";
  for(int i = 0 ; i < s_in.size();i++)
    {
      for(int j = 0; j < (int)s_in[i];j++) s += '+';
      s += ".[-]";
    }
  return s;
}