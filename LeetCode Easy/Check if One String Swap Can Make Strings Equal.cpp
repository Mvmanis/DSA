    // Leetcode Link               : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force )

//T.C : O(N^2)  
//S.C : O(1) space used 

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                swap(s1[i], s1[j]);
                if(s1 == s2) return true;
                swap(s1[i], s1[j]);
            }
        }
        return false;
    }
};


/********************************************************************************************************************************/


// Approach - 2  (better) > using hashing 

//T.C : O(N)  
//S.C : O(26)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int nonMatchingCharCounts = 0;
        int i = 0;
        vector<int>chars(26, 0);
        for(char ch : s1){
            chars[ch - 'a']++;
        }

        for(char ch : s2){
            chars[ch - 'a']--;
        }

        for(int i = 0;i<26;i++){
            if(chars[i] != 0) return false;
        }

        while(i<n){
            if(s1[i] != s2[i]){
                nonMatchingCharCounts++;
            }
            i++;
        }
        return nonMatchingCharCounts == 0 || nonMatchingCharCounts == 2;
    }
};



/********************************************************************************************************************************/


// Approach - 3  (optimal) > using some analysis

//T.C : O(N)  
//S.C : O(1)

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diffs = 0;
        int firstDiff = 0;
        int secondDiff = 0;
        int n = s1.size();
        if (s1 == s2) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffs++;
                if (diffs > 2)
                    return false;
                else if (diffs == 1) {
                    firstDiff = i;
                } else {
                    secondDiff = i;
                }
            }
        }

        return s1[firstDiff] == s2[secondDiff] &&
               s2[firstDiff] == s1[secondDiff];
    }
};