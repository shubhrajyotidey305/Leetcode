class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k; i++)
            pq.push({abs(arr[i]-x), i});
        
        for(int i=k; i<n; i++){
            int diff = abs(arr[i]-x);
            if(pq.top().first>diff){
                pq.pop();
                pq.push({diff, i});
            }
        }
        
        vector<int> v;
        while(!pq.empty()){
            v.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};