    // Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03



/**************************************************************** C++ ****************************************************************/


// Approach - 1 Brute Force using two for loop......

//T.C : O(N*N)
//S.C : O(1)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i<n-1;i++){
            //leftsum..
            int leftSum = 0;
            for(int j = 0;j<=i;j++){
                leftSum += nums[j];
            }

            // rightSum 
            int rightSum = 0;
            for(int j = i+1;j<n;j++){
                rightSum += nums[j];
            }

            if(leftSum >= rightSum) count++;
        }
        return count;

    }
};


/********************************************************************************************************************************/


//Approach-2 Optimised (Using cumulative Sum/Prefix Sum)
//T.C : O(N)
//S.C : O(1)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        long long sum = 0;
        for(auto x : nums) sum += x;
        long long leftSum = 0;

        for(int i = 0;i<n-1;i++){
            leftSum += nums[i];
            long long rightSum = sum - leftSum;

            if(leftSum >= rightSum) count++;
        }

        return count;
    }
};
