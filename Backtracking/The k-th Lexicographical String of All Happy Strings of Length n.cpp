/*     Scroll below to see JAVA code also    */
/*
    Video                       : https://www.youtube.com/watch?v=sQ1gHiDtcXg
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

    // I was not able to come up with anything - so focus on such problems 
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
    public:
        void solve(int n, string &curr, vector<string> &result) {
            if (curr.length() == n) {
                result.push_back(curr);
                return;
            }
            
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (!curr.empty() && curr.back() == ch)
                    continue;
                
                // Do
                curr.push_back(ch);
    
                // Explore
                solve(n, curr, result);
    
                // Undo
                curr.pop_back();
            }
        }
    
        string getHappyString(int n, int k) {
            string curr = "";
            vector<string> result;
            solve(n, curr, result);
    
            if (result.size() < k) 
                return "";
            
            return result[k - 1];
        }
    };
    
    
    
    //Approach-2 (Khandani Backtracking remplate - Without storing all possible strings)
    //T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
    //S.C : O(n) by recursion system stack
    class Solution {
    public:
        void solve(int n, string &curr, int &count, int k, string &result) {
            if (curr.length() == n) {
                count++;
                if (count == k) {
                    result = curr;  // Store only the k-th string
                }
                return;
            }
            
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (!curr.empty() && curr.back() == ch)
                    continue;
                
                // Do
                curr.push_back(ch);
    
                // Explore
                solve(n, curr, count, k, result);
    
                // If result is found, exit early
                if (!result.empty()) return;
    
                // Undo
                curr.pop_back();
            }
        }
    
        string getHappyString(int n, int k) {
            string curr = "";
            string result = "";
            int count = 0;
            
            solve(n, curr, count, k, result);
    
            return result;
        }
    };