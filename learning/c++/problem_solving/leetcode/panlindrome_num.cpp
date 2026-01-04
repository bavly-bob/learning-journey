class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false; // negatives or trailing zero

        int rev = 0;
        while (x > rev) { 
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        // For odd digits (int that has odd number of digits), ignore the middle digit
        return x == rev || x == rev / 10;
    }
};