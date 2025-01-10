    // Leetcode Link               : https://leetcode.com/problems/word-subsets/description/
    // Video                       : https://www.youtube.com/watch?v=EjXPzWYbviw



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force)

//T.C : O(N*M*(l1 + l2)) // where l1 = avg length of string in words1 and l2 = avg length of string in words2
//S.C : O(m) + O(k) map used // where m = total number of valid universal strings.

class Solution {
public:
    bool isSubset(string s, string t){
        unordered_map<char, int>m;
        for(auto x : t){
            m[x]++;
        }

        for(auto x : s){
            if(m.find(x) != m.end()){
                m[x]--;
            }
            if(m[x]==0){
                m.erase(x);
            }
        }

        return m.size() == 0 ? true : false;
    }



    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;

        int n = words1.size();
        for(int i = 0;i<n;i++){
            string a = words1[i];
            bool isUniversal = true;
            for(int j = 0;j<words2.size();j++){
                if(!isSubset(a, words2[j])){
                    isUniversal = false;
                    break;
                }
            }

            if(isUniversal) ans.push_back(a);

        }

        return ans;
    }
};


/********************************************************************************************************************************/


//Approach-2 (Optimised) - by doing bit mofification in code and using hashing and understanding the problem before.
//T.C : O(N*l1 + m*l2)
//S.C : O(m)

class Solution {
public:

    bool isUniversal(vector<int>&freq, vector<int>&m){
        for(int i = 0;i<26;i++){
            if(freq[i]<m[i]) return false;
        }

        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>m(26 , 0);
        vector<string>ans;

        for(string word : words2){
            vector<int>temp(26 , 0);

            for(auto x : word){
                temp[x - 'a']++;
                m[x-'a'] = max(m[x-'a'], temp[x-'a']);
            }
        }

        for(auto word : words1){
            vector<int>freq(26 , 0);
            for(auto ch : word){
                freq[ch - 'a']++;
            }
            if(isUniversal(freq, m)){
                ans.push_back(word);
            }
        }

        return ans;
    }
};