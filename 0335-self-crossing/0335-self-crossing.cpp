class Solution {
public:
    bool isSelfCrossing(vector<int>& arr) {
        int n = arr.size();
        
        if(n <= 3) {
            return false;
        }
        
        arr.insert(arr.begin(), 0);
        
        for(int i=3; i<arr.size(); i++) {
            if(arr[i] >= arr[i-2] and arr[i-3] >= arr[i-1]) {
                return true;
            }
            
            if(i >= 5) {
                if(arr[i-1] <= arr[i-3] and arr[i-1] >= arr[i-3] - arr[i-5] and arr[i-2] >= arr[i-4] and arr[i-2] <= arr[i] + arr[i-4]) {
                    return true;
                }
            }
        }
        return false;
    }
};