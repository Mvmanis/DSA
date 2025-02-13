    // Leetcode Link               : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/



/**************************************************************** C++ ****************************************************************/


//Approach (Using Heap)
//T.C : Onlogn)
//S.C : O(n)

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long, vector<long>, greater<long>>pq;
            for(int i = 0;i<nums.size();i++){
                pq.push(nums[i]);
            }
            int operations = 0;
    
            while(!pq.empty() && pq.size()>=2){
                long long firstEle = pq.top();
                if(firstEle>=k) break;
                pq.pop();
                long long secondEle = pq.top();
                pq.pop();
                long long newValue = min(firstEle, secondEle)*2 + max(firstEle, secondEle);
                pq.push(newValue);
                operations++;
            }
    
            return operations;
        }
    };