    // Leetcode Link               : https://leetcode.com/problems/counting-words-with-a-given-prefix/description//


/**************************************************************** C++ ****************************************************************/


//Approach-1 (Brute Force)
//T.C : O(n^k) , k= length of longest string in words here I am considering substr() method time.
//S.C : O(1) // if we don not consider substr() method space

class Solution {
public:

    bool isWordPrefix(string word, string pref){
        if(pref.size()>word.size()) return false;
        int n = pref.size();
        if(word.substr(0 , n) == pref) return true;
        return false;
    }


    int prefixCount(vector<string>& words, string pref) {
        int countOfPrefix = 0;
        for(string word : words){
            if(isWordPrefix(word, pref)) countOfPrefix++;
        }
        return countOfPrefix;
    }
};

/********************************************************************************************************************************/


//Approach-2 (Using Trie)

// will write the Trie code after learning it.