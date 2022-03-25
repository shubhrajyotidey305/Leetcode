// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    // Complete the function
    vector<int> v(arr,arr+n);
    sort(begin(v),end(v));
    for(int i=0;i<n;i++){
        int x=upper_bound(begin(v),end(v),arr[i])-begin(v);
        if(x==n) arr[i]=-10000000;
        else arr[i]=v[x];
    }
    return arr;

}
