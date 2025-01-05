    // Leetcode Link               : https://leetcode.com/problems/shifting-letters/description/



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force)

//T.C : O(N*N)
//S.C : O(1)

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // brute force....
        int n = shifts.size();
        int j = 0;
        int shiftIndex = 0;
        while(shiftIndex<n){
            int increment = shifts[shiftIndex];
            for(int i = 0;i<=j;i++){
                int val = s[i] - 'a';
                val += increment;
                val = val%26;
                s[i] = 'a' + val;
            }
            j++;
            shiftIndex++;
        }
        return s;
    }
};


/********************************************************************************************************************************/


//Approach-2 (Optimised) - pre calculating total shifts..
//T.C : O(N)
//S.C : O(1)

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        long long totalShift = 0;
        for(auto x : shifts) totalShift += x;

        for(int index = 0;index<s.size();index++){
            s[index] = 'a' + (s[index] - 'a' + totalShift) % 26;
            totalShift -= shifts[index]; 
        }

        return s;
    }
};