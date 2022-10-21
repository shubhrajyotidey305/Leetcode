//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&matrix)  {
        vector<int> v;
        int left=0,right=matrix[0].size()-1;
        int top=0,bottom=matrix.size()-1;
        int d=0;
        while(left<=right&&bottom>=top){
            if(d==0){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                }
                top++;
                d++;
            }else if(d==1){
                for(int i=top;i<=bottom;i++){
                    v.push_back(matrix[i][right]);
                }
                right--;
                d++;
            }else if(d==2){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);                
                }
                bottom--;
                d++;
            }else if(d==3){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);                 
                }
                left++;d=0;
            }
        }
        reverse(v.begin(),v.end());
    return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends