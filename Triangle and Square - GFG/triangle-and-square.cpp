// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int countSquare(int B)
    {
	    // code here 
	    if(B==0 || B==1 || B==2 || B==3){
     return 0;
 }
 int base = B/2;
 int height = B/2;
 int h2=height-1;
 int count = base*h2/2;
 return count;
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int B,count;
    	cin>>B;
    	Solution ob;
    	count = ob.countSquare(B);
    	cout<<count<<endl;
    }
}  // } Driver Code Ends