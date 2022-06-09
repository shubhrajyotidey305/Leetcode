class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            auto it = lower_bound(arr.begin()+i+1, arr.end(), target - arr[i]);
            if(it!=arr.end() and *it + arr[i] == target) {
                int idx1 = i + 1;
                int idx2 = it - arr.begin() + 1;
                return {idx1, idx2};
            }
        }
        return {};
    }
};