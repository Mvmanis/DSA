    // Leetcode Link               : https://leetcode.com/problems/letter-tile-possibilities/description/
    // Video                       : https://www.youtube.com/watch?v=cD0D-QSKG20

    // Note - I have taken a bit of help from chatgpt and solved using STriver way, we can use the video in future if stuck 
    // but with MIK way





/**************************************************************** C++ ****************************************************************/


//Approach-1 
//T.C : O(n!)
//S.C : O(n * n!), total possible sequences = n! and each having n length

class Solution {
    public:
    
        void solve(int index, string tiles, string s, unordered_set<int>&m, unordered_set<string>&st){
            if(index == tiles.size()){
                if(s != ""){
                    st.insert(s);
                }
                return;
            }
    
            for(int i = 0;i<tiles.size();i++){
                if(m.find(i) == m.end()){
                    m.insert(i);
                    solve(index+1, tiles, s + tiles[i], m , st);
                    m.erase(i);
                }
                else{
                    solve(index+1, tiles, s, m, st);
                }
               
               
            }
        }
    
        int numTilePossibilities(string tiles) {
            unordered_set<string>st;
            unordered_set<int>s;
            solve(0, tiles, "", s, st);
            return st.size();
        }
    };
    
    
    
    /********************************************************************************************************************************/
    
    
    //Approach-2 (Using count of characters + backtracking)
    //T.C : O(n!)
    //S.C : O(n), total possible sequences = n! and each having n length
 
    // will solve in future 
    
  