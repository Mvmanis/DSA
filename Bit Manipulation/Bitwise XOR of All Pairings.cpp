    // Leetcode Link               : https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/
    // Video                       : https://www.youtube.com/watch?v=19-Q_Krxj1w&t=505s

    //  Think a bit and it will be solved.
/**************************************************************** C++ ****************************************************************/


//Approach-1 (Brute Force two loops)
//T.C : O(N^2)
//S.C : O(N*M)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;

        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                int xorValue = nums1[i] ^ nums2[j];
                nums3.push_back(xorValue);
            }
        }
        int ans = 0;
        for(int i = 0;i<nums3.size();i++){
            ans ^= nums3[i];

        }

        return ans;
    }
};

/********************************************************************************************************************************/


// Solve Approach - 2 => Just think of xor property when we have even times a number then xor will be zero
// Using frequency count and Xor Property
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, long> mp;

        for(int &num : nums1) {
            mp[num] += n;
        }


        for(int &num : nums2) {
            mp[num] += m;
        }

        int result = 0;
        for(auto &it : mp) {
            int num = it.first;
            int freq = it.second;

            if(freq%2 != 0) { //ODD
                result ^= num;
            }
        }

        return result;
    }
};

/********************************************************************************************************************************/


//Approach-3 (Using Xor property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int XOR = 0;

        if(m % 2 != 0) { //m is of odd length
            for(int &num : nums2) {
                XOR ^= num;
            }
        }

        if(n % 2 != 0) { //n is of odd length
            for(int &num : nums1) {
                XOR ^= num;
            }
        }

        return XOR;
    }
};