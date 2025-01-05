    // Leetcode Link               : https://leetcode.com/problems/shifting-letters-ii/description/

    // In order to solve this problem you should know what is difference array technique 
    // Video - https://www.youtube.com/watch?v=ZHNVmtm08WY



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force) - using two loop

//T.C : O(Q*N)
//S.C : O(1)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int queries = shifts.size();
        for(int i = 0; i<queries; i++){
            int startIndex = shifts[i][0];
            int endIndex = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 1){ // move forward
                for(int i = startIndex; i<=endIndex; i++){
                    if(s[i] == 'z'){
                        s[i] = 'a';
                    }
                    else{
                        s[i]++;
                    }

                }
            }
            else{
                for(int i = startIndex; i<=endIndex; i++){
                    if(s[i] == 'a'){
                        s[i] = 'z';
                    }
                    else{
                        s[i]--;
                    }

                }
            }
        }
        return s;
    }
};


/********************************************************************************************************************************/


//Approach-2 (Optimised) - using difference array technique
//T.C : O(Q+N)
//S.C : O(N)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int queries = shifts.size();
        vector<int>updateArray(s.size(), 0);
        for(int i = 0; i<queries; i++){
            int startIndex = shifts[i][0];
            int endIndex = shifts[i][1];
            int direction = shifts[i][2];
            
            if(direction == 1){
                updateArray[startIndex] += 1;
                if(endIndex+1<s.size()){
                    updateArray[endIndex+1] -= 1;
                }
            }
            else{
                updateArray[startIndex] -= 1;
                if(endIndex+1<s.size()){
                    updateArray[endIndex+1] += 1;
                }
            }

        }
        
        for(int i = 1;i<s.size();i++){
            updateArray[i] += updateArray[i-1];
        }

        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            int val = updateArray[i]%26;  // handle edge case when updateArray[i] = -90 for example
            if(val < 0){ 
                val += 26;  // add +26 in case after modulo with 26 still in negative ex:- -90%26 = -12
            }
            s[i] = 'a' + (ch - 'a' + val)%26;
        }
        return s;
    }
};