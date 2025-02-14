    // Leetcode Link               : https://leetcode.com/problems/design-a-number-container-system/description/
    // Video                       : https://www.youtube.com/watch?v=Jvu3hd8A2rg
  

    // revise optimal as much




/**************************************************************** C++ ****************************************************************/


//Approach-1 (Brute Force)
//T.C : add() - O(1), getProduct() - O(k)
//S.C : O(n) for the stream

class ProductOfNumbers {
    public:
        vector<int>nums;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            nums.push_back(num);
        }
        
        int getProduct(int k) {
            int n = nums.size();
            int product = 1;
            int i = n-1;
            while(k>0){
                k--;
                product *= nums[i--];
            }
            return product;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */
    
    
    /********************************************************************************************************************************/
    
    
//Approach-2 (Follow up optimal in O(1))
//T.C : O(1) for both methods
//S.C : O(n) for the stream
    
class ProductOfNumbers {
    public:
        vector<int>nums;
        int n;
        ProductOfNumbers() {
            nums.clear();
            n = 0;
        }
        
        void add(int num) {
            if(num == 0){
                nums = {};
                n = 0;
            }
            else{
                if(nums.empty()){
                    nums.push_back(num);
                }
                else{
                    nums.push_back(num * nums[n-1]);
                }
                n++;
            }
        }
        
        int getProduct(int k) {
            if(k>n){
                return 0;
            }
            else if(k == n){
                return nums[n-1];
            }
               return nums[n-1]/nums[n-k-1];
            // }
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */