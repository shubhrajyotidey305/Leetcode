class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0 ;
        int high = n - 1 ;
        
        if(n == 1) return 0;
        
        while(low<=high){
            
            long long mid = low + (high-low)/2 ;
            
            //if peak is in starting point
            if(mid == 0){
                
                if(nums[0] > nums[1]){
                    return 0;
                }else{
                    return 1 ;
                }
                
            }
            
            //if peak is in between array
            else if(mid > 0 && mid < n - 1){
                
                //if mid is greater than both side than mid is peak
                
                if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]){
                    return mid ;
                }
                
                else if(nums[mid-1] > nums[mid]){
                    high = mid - 1 ;
                }
                
                else{
                    low = mid + 1 ;
                }
            }
            
              // if peak is in end point
            
            else if(mid == n-1){
                if(nums[n - 1] > nums[n - 2]){
                    return n - 1 ;
                }else{
                    return n - 2 ;
                }
            }
        }
        return 0;
    }
};