// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(string a, string b)
    {
        return a.length()<b.length();
    }
    string check(string s1,string s2)
    {
        string s="";
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[i])
            {
                s+=s1[i];
            }
            else

            {
                return s;
            }
        }
        return s;
    }
    string LCP(string ar[], int n)
    {
        // code here
        sort(ar,ar+n,cmp);
        string str=ar[0];
        for(int i=1;i<n;i++)
        {
            if(check(str,ar[i])=="")
            {
                str="-1";
                return str;
            }
           
            else
            {
                str=check(str,ar[i]);
            }
        }
        return str;
   }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends