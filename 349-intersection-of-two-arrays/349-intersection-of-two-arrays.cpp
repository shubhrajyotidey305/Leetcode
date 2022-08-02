class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while(i<n and j<m) {
            if(i>0 and nums1[i-1] == nums1[i]) {
                i++;
                continue;
            }
            if(j>0 and nums2[j-1] == nums2[j]) {
                j++;
                continue;
            }
            
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }           
            
        }
        return ans;
    }
};