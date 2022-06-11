// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    double getEquilibrium(int l, int r, double magnets[], int n) {
        double low = 1.0*l, high = 1.0*r;
        while(high-low >= 0.000001) {
            double fLeft = 0.0, fRight = 0.0;
            double m = (high+low)/2;
            for(int i=0; i<n; i++) {
                if(i <= l) fRight += 1.0/(m-magnets[i]);
                else fLeft += 1.0/(magnets[i]-m);
            }
            if(fLeft < fRight)
                low = m;
            else
                high = m;
        }
        return low;
    }
    void nullPoints(int n, double magnets[], double getAnswer[]) {
        for(int i=0; i<n-1; i++) {
            getAnswer[i] = getEquilibrium(magnets[i], magnets[i+1], magnets, n);
        }
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends