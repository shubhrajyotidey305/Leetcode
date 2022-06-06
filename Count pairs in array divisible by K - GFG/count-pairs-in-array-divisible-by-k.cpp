// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        //code here
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            a[i] %= k;
            mp[a[i]]++;
        }
        
        long long ans = 0;
        
        for(auto &it:mp) {
            if(it.first == 0) {
                long long x = it.second;
                ans += x*(x-1)/2;
            }
            else if(it.first == k - it.first) {
                long long x = it.second;
                ans += x*(x-1)/2;
            }
            else if(mp.count(k - it.first)) {
                ans += mp[it.first] * mp[k - it.first];
                mp.erase(k - it.first);
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends