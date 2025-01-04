    // Leetcode Link               : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/



/**************************************************************** C++ ****************************************************************/


// Approach - 1 

//T.C : O(N*26)
//S.C : O(26)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_set<char>letters;
        int ans = 0;

        for(auto ch : s){
            letters.insert(ch);
        }


        for(auto ch : letters){
            int leftIndex = -1;
            int rightIndex = -1;

            for(int i = 0;i<n;i++){
                if(s[i] == ch){
                    if(leftIndex == -1){
                        leftIndex = i;
                    }
                    rightIndex = i;
                }
            }

            unordered_set<char>st;
            for(int i = leftIndex + 1;i<= rightIndex-1;i++){
                st.insert(s[i]);
            }

            ans += st.size();
        }

        return ans;

    }
};


/********************************************************************************************************************************/


//Approach-2 (Storing first and last indices before hand)
//T.C : O(N*26)
//S.C : O(26)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        vector<pair<int, int>>indices(26 , {-1, -1});

        for(int i = 0;i<n;i++){
            int indexOfChar = s[i] - 'a';
            if(indices[indexOfChar].first == -1){
                indices[indexOfChar].first = i;
            }
            indices[indexOfChar].second = i;
        }

        for(int i = 0;i<26;i++){
            int leftIndex = indices[i].first;

            int rightIndex = indices[i].second;
            if(leftIndex == -1) continue; 

            unordered_set<char>st;
            for(int i = leftIndex + 1;i<= rightIndex-1;i++){
                st.insert(s[i]);
            }

            ans += st.size();
        }

        return ans;

    }
};