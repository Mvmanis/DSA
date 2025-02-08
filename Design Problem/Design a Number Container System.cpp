    // Leetcode Link               : https://leetcode.com/problems/design-a-number-container-system/description/
    // Video                       : https://www.youtube.com/watch?v=689qj769Gt4





/**************************************************************** C++ ****************************************************************/


// Approach - 1  (Brute Force ) - TLE - using one map

//T.C : O(N) => here we are talking in terms of 1 query worst case time.  
//S.C : O(N) space used 

class NumberContainers {
    public:
        unordered_map<int, int>m; // this is map of index , element
        NumberContainers() {
        }
        
        void change(int index, int number) {
            m[index] = number;
        }
        
        int find(int number) {
            int minIndex = INT_MAX;
            for(auto x : m){
                if(x.second == number){
                    minIndex = min(minIndex, x.first);
                }
            }
            return minIndex == INT_MAX ? -1 : minIndex;
        }
    };
    
    
    
    /********************************************************************************************************************************/
    
    
    // Approach - 2  (Optimal - 1) -> (Using two maps : map of int, int and map of int, set)
    
   //T.C : O(log(n))
    //S.C : O(n)
    
    class NumberContainers {
        public:
            //Space : O(n)
            unordered_map<int, int> idxToNum;
            unordered_map<int, set<int>> numToIdx;
        
            NumberContainers() {
                //do nothing    
            }
            
            void change(int index, int number) {
                if(idxToNum.count(index)) { //O(1)
                    int prevNum = idxToNum[index];
                    numToIdx[prevNum].erase(index); //O(log(n))
                    if(numToIdx[prevNum].empty()) {
                        numToIdx.erase(prevNum); //O(1)
                    }
                }
        
        
                idxToNum[index] = number;
                numToIdx[number].insert(index); //O(log(n))
        
            }
            
            int find(int number) {
                if(numToIdx.count(number)) { //O(1)
                    return *numToIdx[number].begin(); //O(1)
                }
        
                return -1;    
            }
        };
        
    /********************************************************************************************************************************/
    
    
    //Approach-3 (Optimal - 2)(Using two maps : map of int, int and map of int, min-heap)
    //T.C : O(log(n) + k*logn)
    //S.C : O(n)
    class NumberContainers {
        public:
            //Space : O(n)
            unordered_map<int, int> idxToNum;
            unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;
        
            NumberContainers() {
                //do nothing    
            }
            
            void change(int index, int number) {
                idxToNum[index] = number; //O(1)
        
                numToIdx[number].push(index); //O(log(n))
            }
            
            int find(int number) {
                if(!numToIdx.count(number)) {
                    return -1;
                }
        
                auto& pq = numToIdx[number];
        
                while(!pq.empty()) { //O(k * logn)
                    int idx = pq.top(); //O(1)
        
                    if(idxToNum[idx] == number) {
                        return idx;
                    }
        
                    pq.pop(); //O(log(n))
                }
        
                return -1;
            }
        };