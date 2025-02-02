    // Leetcode Link               : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force )

//T.C : O(N^2)  
//S.C : O(N) space used 

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int>sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());
        for(int i = 0;i<n;i++){
            int firstEle = sortedArray[0];
            for(int j = 1;j<n;j++){
                sortedArray[j-1] = sortedArray[j];
            }
            sortedArray[n-1] = firstEle;
            if(sortedArray == nums) return true;
        }
        return false;
    }
};


/********************************************************************************************************************************/


// Approach - 2  (Optimal) > By observation and finding smallerCounts.

//T.C : O(N)  
//S.C : O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        int smallerCount = 0;
        int n = nums.size();

        for(int i = 1;i<n;i++){
            if(nums[i]<nums[i-1]) smallerCount++;
        }

        if(nums[0]<nums[n-1]) smallerCount++;
        return smallerCount<=1;
    }
};
