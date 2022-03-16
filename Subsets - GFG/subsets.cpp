// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& a){
        //code here
        res.clear();
        vector<int> temp;
        solve(temp, a, 0);
        
        sort(res.begin(), res.end());
        return res;
    }
    
    void solve(vector<int> &temp, vector<int> &a, int i){
        res.push_back(temp);
        
        for(int j=i; j<a.size(); j++){
            temp.push_back(a[j]);
            solve(temp, a, j+1);
            temp.pop_back();
        }
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends