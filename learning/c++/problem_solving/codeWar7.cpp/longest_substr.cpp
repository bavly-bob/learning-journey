// Longest Substring Between Two Equal Characters

#include <string>
using namespace std;
int counter(string s, char a)
{
    size_t first = s.find(a);
    size_t last = s.rfind(a);
    if( first == string::npos || last == string::npos) return 0;
    return ( last - first + 1);
}

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int max_index, max_value=-1;
        for(int i =0 ;i < 26;i++)
        {
            int x = counter(s, (char) ('a'+i) );
            if(max_value < x) 
            {
                max_value = x;
                max_index = i;
            }
        }
        if (max_index == -1) return "";
        return s.substr( s.find((char) ('a'+max_index)) , max_value);
    }
};