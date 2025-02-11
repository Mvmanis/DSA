/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=v6_q_fu1ev0
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/remove-all-occurrences-of-a-substring
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            //s.length() = m
            //part.length() = n;
            //O(m*n)
            while(true) {
                int idx = s.find(part);
    
                if(idx == string::npos) {
                    break;
                }
    
                s.erase(idx, part.length());
            }
    
            return s;
        }
    };
    
    
    //Approach-2 (Using Stack)
    //T.C : O(m*n)
    //S.C : O(m)
    class Solution {
        public:
        
            bool check( stack<char>&st, string& part){
                stack<char>temp = st;
                int n = part.size();
                for(int i = n-1;i>=0;i--){
                    if(temp.top() != part[i]) return false;
                    temp.pop();
                }
                return true;
            }
        
            string removeOccurrences(string s, string part) {
                stack<char>st;
                int n = s.size();
        
                for(int i = 0;i<n;i++){
                    st.push(s[i]);
                    if(st.size()>=part.size() && check(st, part)){
                        for(int j = 0;j<part.size();j++){
                            st.pop();
                        }
                    }
                }
        
                string ans = "";
                while(!st.empty()){
                    ans = st.top() + ans;
                    st.pop();
                }
                return ans;
            }
        };
    
    
    //Approach-3 (Using string as a stack)
    //T.C : O(m*n)
    //S.C : O(1), not considering result as extra space
    class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string result = "";
            int n = part.length();
    
            for(char &ch : s) {
                result.push_back(ch);
    
                if(result.length() >= n && result.substr(result.length() - n) == part) {
                    result.erase(result.length() - n);
                }
            }
    
            return result;
        }
    };