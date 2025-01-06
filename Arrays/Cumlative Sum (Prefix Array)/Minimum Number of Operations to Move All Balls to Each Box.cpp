    // Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/



/**************************************************************** C++ ****************************************************************/


// Approach - 1 Brute Force using two for loop......

//T.C : O(N*N)
//S.C : O(N)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        // brute Force 
        int n = boxes.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int operationNeeded = 0;
            for(int j = 0;j<n;j++){
                if(boxes[j] == '1'){
                    operationNeeded += abs(i-j);
                }
            }
            ans.push_back(operationNeeded);
        }

        return ans;
        
    }
};


/********************************************************************************************************************************/


//Approach-2 Optimised (Using cumulative Sum/Prefix Sum)
//T.C : O(N)
//S.C : O(N) + O(N) + o(N) => for two prefix and suffix array
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n, 0);

        vector<int>leftCummValues(n , 0);
        int leftCummValue = 0;

        for(int i = 0;i<n;i++){
            leftCummValue += boxes[i] - '0';
            leftCummValues[i] = leftCummValue;
        }   

        int sum = 0;
        for(int i = 1;i<n;i++){
            sum += leftCummValues[i-1];
            ans[i] = sum;
        }

        vector<int>rightCummValues(n , 0);
        int rightCummValue = 0;

        for(int i = n-1;i>=0;i--){
            rightCummValue += boxes[i] - '0';
            rightCummValues[i] = rightCummValue;
        } 

        sum = 0;
        for(int i = n-2;i>=0;i--){
            sum += rightCummValues[i+1];
            ans[i] += sum;
        }  

        return ans;
        
    }
};


////////////////////// Or we can also write the top one without extra space
//T.C : O(N)
//S.C : O(N) // only for ans

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n, 0);

        int leftCummValue = 0;
        int leftSum = 0;

        for(int i = 0;i<n;i++){
            ans[i] += leftSum;
            leftCummValue += boxes[i] - '0';
            leftSum += leftCummValue;
        }   

        int rightCummValue = 0;
        int rightSum = 0;

        for(int i = n-1;i>=0;i--){
            ans[i] += rightSum;
            rightCummValue += boxes[i] - '0';
            rightSum  += rightCummValue;
        } 

        return ans;
        
    }
};