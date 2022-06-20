// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long helper(int n, int sum, int size, int k) {
       if (size == k) {
           if (sum == 0) return 1;
           return 0;
       }
       if (n == 0)
           return 0;
       long ans = 0;
       for (int i = 1; i <= n; i++) {
           if (sum - i >= 0)
               ans += helper(n, sum - i, size + 1, k);
       }
       return ans;
   }
   long posIntSol(string s)
   {
       int count = 1;
       for (int i = 0; i < s.size(); i++)  if (s[i] == '+') count++;
       string ksum = "";
       for (int i = s.size() - 1; i >= 0; i--) {
           if (s[i] == '=')
               break;
           ksum = s[i] + ksum;
       }
       int sum = stoi(ksum);
      
       long ans = 0;
       
       return ans = helper(sum - (count - 1), sum, 0, count);
       
       
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends