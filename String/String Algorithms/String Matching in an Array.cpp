    // Leetcode Link               : https://leetcode.com/problems/string-matching-in-an-array/description/



/**************************************************************** C++ ****************************************************************/


//Approach-1 (Brute Force)
//T.C : O(m*n^2) , m = length of longest string in words, n = size of words // here I am not considering substr() method time.
//S.C : O(1) // if we don not consider ans array...

class Solution {
public:

    bool searchWordFound(string& searchWord, string& word){
        if(searchWord.size()>word.size()) return false;
        int j = 0;
        int n = searchWord.size();

        while(j < word.size()){
            if(word[j] == searchWord[0]){
                string substring = word.substr(j , n);
                if(substring == searchWord) return true;
            }
            j++;
        }

        return false;
    }


    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n = words.size();

        for(int i = 0;i<n;i++){
            string searchWord = words[i];
            for(int j = 0;j<n;j++){
                if(i != j){
                    if(searchWordFound(searchWord, words[j])){
                        ans.push_back(searchWord);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};


/********************************************************************************************************************************/


//Approach-2 (Using KMP)
//T.C : O(m*n^2), m = length of longest string in words, n = size of words
//S.C : O(m)

// will write the KMP code after learning it.