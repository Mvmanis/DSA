    // Leetcode Link               : https://leetcode.com/problems/minimize-xor/description/
    // Video                       : https://www.youtube.com/watch?v=9wrKWB1xDoY&t=8s

    //  This is a good problem where most of concept of bit manipulation will be used so 
    //  solve it (Although I was not able to come up with anything because of fear of BIT -> which I have to remove)

/**************************************************************** C++ ****************************************************************/


//Approach-1 (Starting from num1 and then forming result)
//T.C : O(log(n))
//S.C : O(1)

class Solution {
public:

    bool isSet(int x, int bit){
        return x & (1<<bit);
    }

    void setBit(int& x, int bit){
        x |= (1 << bit);
    }

    void unSet(int& x, int bit){
        x &= ~(1 << bit);
    }


    int minimizeXor(int num1, int num2) {
        int  x = num1;
        int requiredSetBits = __builtin_popcount(num2);
        int currSetBits = __builtin_popcount(num1);

        int bit = 0;
        if(currSetBits < requiredSetBits){
            while(currSetBits < requiredSetBits){
                if(!isSet(x, bit)){
                    setBit(x, bit);
                    currSetBits++;
                }
                bit++;
            }
        }
        else if(currSetBits > requiredSetBits){
            while(currSetBits > requiredSetBits){
                if(isSet(x, bit)){
                    unSet(x, bit);
                    currSetBits--;
                }
                bit++;
            }
        }

        return x;
    }
};

/********************************************************************************************************************************/


// Solve Approach - 2 => in Future will solve it use video.... 
//Approach-2 (Directly build result)
//T.C : O(log(n))
//S.C : O(1)

