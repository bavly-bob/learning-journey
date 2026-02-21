/*
https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2026-02-19

Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:
If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

Example 1:
Input: version1 = "1.01", version2 = "1.0"
Output: 0
Explanation: Version 1.01 and 1.0 are equal to 1.
*/


//first solution came to my mind
class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        vector<int> v1, v2;
        string part;

        stringstream ss1(version1);
        while (getline(ss1, part, '.'))
            v1.push_back(stoi(part));

        stringstream ss2(version2);
        while (getline(ss2, part, '.'))
            v2.push_back(stoi(part));

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; i++) {
            int a = (i < v1.size()) ? v1[i] : 0;
            int b = (i < v2.size()) ? v2[i] : 0;

            if (a > b) return 1;
            if (a < b) return -1;
        }
        return 0;
    }
};

// second solution came to my mind

// treating the version as an integer, as the constraint is All the given revisions in version1 and version2 can be stored in a 32-bit integer.
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;

        while (i < v1.size() || j < v2.size()) {
            int num1 = 0, num2 = 0;

            while (i < v1.size() && v1[i] != '.')
                num1 = num1 * 10 + (v1[i++] - '0');

            while (j < v2.size() && v2[j] != '.')
                num2 = num2 * 10 + (v2[j++] - '0');

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;

            i++; j++; // skip dots
        }
        return 0;
    }
};