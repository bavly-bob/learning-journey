// https://leetcode.com/problems/merge-strings-alternately/
// You are given two strings word1 and word2. Merge the strings by putting alternating characters from each string, starting with word1. If a string runs out of characters, append the remaining characters of the other string.


class Solution {
public:
    string addRest(int n, string s)
    {
        string s1="";
        for(int i = n; i < s.size(); i++)
        {
            s1 += s[i];
        }
        return s1;
    }
    string mergeAlternately(string word1, string word2) 
    {
        bool turn = true; 
        int size = word1.size() + word2.size();
        string result = "";
        for(int i = 0; i < size;)
        {
            if(word1[i] == '\0') { result += addRest(i,word2); return result;}
            if(word2[i] == '\0') { result += addRest(i,word1); return result;}
            
            if(turn && word1[i] != '\0')
            {   
                result += word1[i];
                turn = false;
            }
            else if(word2[i] != '\0')
            {
                result += word2[i];
                turn = true;
                i++;
            }
        } 
        return result;  
    }
};

// other solution
string mergeAlternately(string word1, string word2) {
    string result = "";
    int i = 0;
    while (i < word1.length() || i < word2.length()) {
        if (i < word1.length()) {
            result += word1[i];
        }
        if (i < word2.length()) {
            result += word2[i];
        }
        i++;
    }
    return result;
}

