/*     Scroll below to see JAVA code also    */
/*
    Video                       : https://www.youtube.com/watch?v=quUIQ2pw5EU
    Leetcode Link               : https://leetcode.com/problems/count-number-of-bad-pairs
*/

// I was not able to come up with any thing for optimal approach
// this is a pattern fo hashing on equation -> here we move number and index on one side generally help -> watch video


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
    
            long long result = 0;
    
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    if(j-i != nums[j] - nums[i]) {
                        result++;
                    }
                }
            }
    
            return result;
        }
    };
    
    //Approach-2 (Using hashmap) - optimal
    //T.C : O(n)
    //S.C : O(n)
    class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
    
            long long result = 0;
            for(int i = 0; i < n; i++) {
                nums[i] = nums[i]-i;
            }
    
            unordered_map<int, int> mp;
            mp[nums[0]] = 1;
    
            for(int j = 1; j < n; j++) {
                int countOfNumsj = mp[nums[j]];
    
                int totalNumsBeforej = j;
    
                int badPairs = totalNumsBeforej - countOfNumsj;
    
                result += badPairs;
    
                mp[nums[j]]++;
            }
    
            return result;
        }
    };
    
    
    //Approach-3 (Using hashmap)- optimal
    //T.C : O(n)
    //S.C : O(n)
    class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            int n = nums.size();
    
            long long result = 0;
            unordered_map<int, int> mp;
    
            for(int i = 0; i < n; i++) {
                int diff = nums[i] - i;
    
                int totalPairsTillIndex = i;
                int goodPairs           = mp[diff];
    
                result += (totalPairsTillIndex - goodPairs);
    
                mp[diff]++; 
            }
    
            return result;
        }
    };
    