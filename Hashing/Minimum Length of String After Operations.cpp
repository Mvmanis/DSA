    // Leetcode Link               : https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
    // Video                       : https://www.youtube.com/watch?v=VZ9Qiy75rZU



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force )

//T.C : O(N^2)  
//S.C : O(N) space used 

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>markedArray(n , 1);

        int length = n;

        for(int i = 1;i<n-1;i++){
            char ch = s[i];
            if(markedArray[i] == 0) continue;
            // check in the left..
            int foundInLeft = false;
            int foundInLeftIndex = -1;
            for(int j = 0;j<i;j++){
                if(s[j] == ch && markedArray[j] == 1){
                    foundInLeft = true;
                    foundInLeftIndex = j;
                    break;
                }
            }

            // check in the right..
            int foundInRight = false;
            int foundInRightIndex = -1;
            for(int j = i+1;j<n;j++){
                if(s[j] == ch && markedArray[j] == 1){
                    foundInRight = true;
                    foundInRightIndex = j;
                    break;
                }
            }

            if(foundInLeft && foundInRight){
                markedArray[foundInRightIndex] = 0;
                markedArray[foundInLeftIndex] = 0;
                length -= 2;
            }
        }

        return length;
        
    }
};


/********************************************************************************************************************************/


// Approach - 2  (better)- two pass solution

//T.C : O(N) + O(N)  
//S.C : O(26) + O(26) space used 

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>hash(26, 0);

        for(int i = 0;i<n;i++){
            hash[s[i]-'a']++;
        }

        vector<int>seenChars(26, 0);

        for(int i = 0;i<n;i++){
            int index = s[i]-'a';
            
            int left = seenChars[index];
            seenChars[index]++;
            int right = hash[index] - seenChars[index];
            if(left>0 && right>0){
                seenChars[index] -= 2;
                hash[index] -= 2;
            }
        }

        int count = 0;
        for(int i = 0;i<26;i++){
            count += hash[i];
        }

        return count;
    }
};


/********************************************************************************************************************************/


// Approach - 3  (optimal) - one pass solution

//T.C : O(N)
//S.C : O(26) space used

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int deleted = 0;

        vector<int>freq(26, 0);

        for(int i = 0;i<n; i++){
            freq[s[i]-'a']++;

            if(freq[s[i]-'a'] == 3){
                deleted += 2;
                freq[s[i]-'a'] -= 2;
            }
        }

        return n - deleted;
    }
};