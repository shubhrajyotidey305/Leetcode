class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int i=0, j=n-1;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            if(arr[mid] == target){
                return mid;
            }
            
            else if(arr[mid] > target){
                j = mid-1;
            }
            
            else i = mid+1;
        }
        return -1;
    }
};