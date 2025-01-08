    // Leetcode Link               : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/


/**************************************************************** C++ ****************************************************************/


//Approach-1 (Brute Force)
//T.C : O(n^2*k) , k= length of longest string in words here I am considering substr() method time.
//S.C : O(1) // if we don not consider substr() method space

class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        if(n1 > n2) return false;

        // is not prefix
        if(str2.substr(0 , n1) != str1) return false;

        // is not suffix;
        if(str2.substr(n2-n1) != str1) return false;
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                bool ans = isPrefixAndSuffix(words[i], words[j]);
                if(ans){
                    count++;
                }
            }
        }

        return count;
    }
};

/********************************************************************************************************************************/


//Approach-2 (Using Trie)

// will write the Trie code after learning it.