// https://www.codewars.com/kata/52fba66badcd10859f00097e/train/cpp
// Disemvowel Trolls the mission is to write a function that takes a string
// and returns a new string with all vowels removed.

# include <string>

bool check_vowel(char s)
{
  s = tolower(s);
  if(s == 'a' || s == 'o'||s=='e'||s=='i' || s == 'u') return true;
  return false;
}

std::string disemvowel(const std::string& str) 
{
    std::string s ="";
    for(int i =0; i < str.size(); i++)
    {
      if(!check_vowel(str[i]))  // only add if not a vowel
            s += str[i];
    }
  return s;
}