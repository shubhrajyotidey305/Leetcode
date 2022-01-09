// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]!=0){
                    if(!isSafe(i, j, mat[i][j], mat)){
                        return 0;
                    }    
                }
            }
        }
        return 1;
    }
    
    bool isSafe(int row, int col, int num, const vector<vector<int>> &mat){
        for(int i=0; i<9; i++){
            if(i!=col and mat[row][i]==num) return false;
        }
        
        for(int i=0; i<9; i++){
            if(i!=row and mat[i][col]==num) return false;
        }
        
        int rw = row - row%3;
        int cl = col - col%3;
        
        for(int i=rw; i<rw+3; i++){
            for(int j=cl; j<cl+3; j++){
                if(i!=row and j!=col and mat[i][j] == num) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends