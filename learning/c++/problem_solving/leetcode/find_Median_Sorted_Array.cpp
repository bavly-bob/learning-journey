// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();
        
        // merging the two sorted array into one
        vector<int> merged(n + m);
        int k=0, j=0;
        for(int i = 0; i < n + m ; i++)
        {             
            if(k==n)
            {
                for(int l = j; l < m; l++)
                {
                    merged[i] = nums2[l];
                    i++;
                }
                break;
            }
            if(j==m)
            {
                for(int l = k; l < n; l++)
                {
                    merged[i] = nums1[l];
                    i++;
                }
                break;
            }
            if(nums1[k] < nums2[j])
            {
                merged[i] = nums1[k];
                k++;
            }
            else
            {
                merged[i] = nums2[j];
                j++;
            }

        }   
        
        // finding the median
        if ((n + m) % 2 == 0)
            return (merged[(n + m) / 2 - 1] + merged[(n + m) / 2]) / 2.0;
        else
            return merged[(n + m) / 2];
    }
};

// Time complexity: O(n + m)
// Space complexity: O(n + m)

// another optimized solution

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Ensure nums1 is the smaller array to optimize binary search
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0;
        int high = n;
        int totalLength = n + m;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (totalLength + 1) / 2 - partitionX;
            
            // Get the four boundary elements
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == n) ? INT_MAX : nums1[partitionX];
            
            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == m) ? INT_MAX : nums2[partitionY];
            
            // Check if we found the correct partition
            if (maxX <= minY && maxY <= minX) {
                // Correct partition found, calculate median
                if (totalLength % 2 == 0) {
                    // Even number of elements
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    // Odd number of elements
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                // We are too far right in nums1, move left
                high = partitionX - 1;
            } else {
                // We are too far left in nums1, move right
                low = partitionX + 1;
            }
        }
        
        // Should not reach here if inputs are valid sorted arrays
        throw invalid_argument("Input arrays are not sorted or invalid");
    }
};

// Time complexity: O(log(min(n, m)))
// Space complexity: O(1)