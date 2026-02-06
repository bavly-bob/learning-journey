/*
    https://leetcode.com/problems/longest-common-prefix/submissions/1910154435/
    
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
*/
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty()) return "";

        string result = "";
        int n = strs.size();

        for (int i = 0; i < strs[0].size(); i++) 
        {
            char ch = strs[0][i];

            for (int j = 1; j < n; j++)
                if (i >= strs[j].size() || strs[j][i] != ch)
                    return result;
            
            result += ch;
        }
        return result;
    }
};