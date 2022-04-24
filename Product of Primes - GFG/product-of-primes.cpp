// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPrime(long long int n)
    {
     
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
      
        if (n % 2 == 0 || n % 3 == 0)
            return false;
      
        for (long long int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
      
        return true;
    }
    long long primeProduct(long long L, long long R){
        // code here
        long long int mod = pow(10,9) + 7;
        long long int result = 1;
        for(long long int i=L;i<=R;i++){
            if(isPrime(i)){
                result *= i;
                result = result % mod;
            }
        }
        return result%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends