// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
         pair<int, int> res = {0, 0};
         int n = matrix.size();
         int m=matrix[0].size();
         int i=0,j=0;
         
         bool left=false,right=false,down=false,up=false;
         
         right=true;
         int prevI = 0;
           int prevJ = 0;
         while(i>-1 && j>-1 && i<n && j<m)
         {
               prevI = i;
               prevJ = j;
             if(matrix[i][j]==1)
             {
                 matrix[i][j]=0;
                 
                 if(right)
                 {
                     right=false;
                     down=true;
                 }
                 else if(down)
                 {
                     left=true;
                     down=false;
                 }
                 else if(left)
                 {
                     left=false;
                     up=true;
                 }
                 else if(up)
                 {
                     right=true;
                     up=false;
                 }
                 
             }
             if(matrix[i][j]==0)
             {
                 if(right)
                 {
                     j=j+1;
                     
                 }
                 else if(down)
                 {
                     i=i+1;
                    
                 }
                 else if(left)
                 {
                     j=j-1;
                    
                 }
                 else if(up)
                 {
                      i=i-1;
                    
                 }
             }
             
         }
         res = {prevI,prevJ};
         return res;
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends