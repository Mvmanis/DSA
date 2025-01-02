    // Leetcode Link               : https://leetcode.com/problems/count-vowel-strings-in-ranges



/**************************************************************** C++ ****************************************************************/


// Approach - 1 Brute Force 

//T.C : O(N*Q)
//S.C : O(Q)

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>ans;
        set<char>s = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int count = 0;
            for(int j = left;j<=right;j++){
                int start = words[j][0];
                int end = words[j][words[j].size()-1];
                if(s.find(start) != s.end() && s.find(end) != s.end()) count++;
            }
            ans.push_back(count);
        }

        return ans;
    }
};


/********************************************************************************************************************************/


//Approach-2 Optimised (Using cummulativeSum array/Prefix Sum Array)
//T.C : O(N+Q)
//S.C : O(N)


class Solution {
public:

    bool isVowel(char& ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    bool isVowelString(string& s){
        if(isVowel(s[0]) && isVowel(s[s.size()-1])) return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>ans;
        vector<int>prefix(n);
        int val = 0;
        for(int i = 0;i<n;i++){
            if(isVowelString(words[i])) val++;
            prefix[i] = val;
        }

        for(int i = 0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int count = 0;
            if(left == 0){
                count = prefix[right];
            }
            else{
                count = prefix[right] - prefix[left-1];  // why this because if sum from 0-5 we know then for sum 2-5 we need to substart sum from 0 - 1 (which is left -1)
            }
            
            ans.push_back(count);
        }

        return ans;
    }
};



