    // Leetcode Link               : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
    // Video                       : https://www.youtube.com/watch?v=G8YjG1MEoYg

    // Note:- I solved all approach by own



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force )

//T.C : O(limit * queries)  
//S.C : O(limit) space used 

class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int>nums(limit+1, 0);
            vector<int>result;
            for(int i = 0;i<queries.size();i++){
                int x = queries[i][0];
                int y = queries[i][1];
    
                nums[x] = y;
                unordered_set<int>s;
                for(int i = 0;i<limit+1;i++){
                    if(nums[i] != 0) s.insert(nums[i]);
                }
    
                result.push_back(s.size());
    
            } 
    
            return result;
        }
    };
    
    
    /********************************************************************************************************************************/
    
    
    // Approach - 2  (Optimal) - using two hashmaps
    
    //T.C : O(N)  
    //S.C : O(N)

    class Solution {
        public:
            vector<int> queryResults(int limit, vector<vector<int>>& queries) {        
                unordered_map<int, int>levelMap;
                unordered_map<int, int>countMap;
                vector<int>result;
                for(int i = 0;i<queries.size();i++){
                    int x = queries[i][0];
                    int y = queries[i][1];
                    
                    if(levelMap.find(x) != levelMap.end()){
                        countMap[levelMap[x]]--;
                        if(countMap[levelMap[x]]==0){
                            countMap.erase(levelMap[x]);
                        }
                        levelMap[x] = y;
                        countMap[levelMap[x]]++;
                    }
                    else{
                        levelMap[x] = y;
                        countMap[levelMap[x]]++;
                    }
                   
                    result.push_back(countMap.size());
                } 
        
                return result;
            }
        };
