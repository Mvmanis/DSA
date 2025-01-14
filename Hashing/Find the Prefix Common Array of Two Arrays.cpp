    // Leetcode Link               : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
    // Video                       : https://www.youtube.com/watch?v=hVda-pNPiuA



/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force )

//T.C : O(N^2)  
//S.C : O(N) space used 

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>result;

        for(int i = 0;i<A.size();i++){
            set<int>s;
            for(int j = 0;j<=i;j++){
                s.insert(A[j]);
            }
            int count = 0;
            for(int j = 0;j<=i;j++){
                if(s.find(B[j]) != s.end()) count++;
            }

            result.push_back(count);
        }

        return result;
    }
};


/********************************************************************************************************************************/


// Approach - 2  (Optimal)

//T.C : O(N)  
//S.C : O(N)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>result(n , 0);
        vector<int>seenArray(51 , 0);
        if(A[0] == B[0]){
            seenArray[A[0]] = 1;
            result[0] = 1;
        }
        else{
            seenArray[A[0]] = 1;
            seenArray[B[0]] = 1;
        }

        

        for(int i = 1;i<A.size();i++){
            int a = A[i];
            int b = B[i];

            if(a == b){
               seenArray[a] = 1;
               result[i] = result[i-1] + 1; 
            }
            else{
                if(seenArray[a] == 1){
                    result[i] += 1;
                }
                else{
                    seenArray[a] = 1;
                }
                if(seenArray[b] == 1){
                    result[i] += 1;
                }
                else{
                    seenArray[b] = 1;
                }
                result[i] += result[i-1];
            }
            
        }

        return result;
    }
};