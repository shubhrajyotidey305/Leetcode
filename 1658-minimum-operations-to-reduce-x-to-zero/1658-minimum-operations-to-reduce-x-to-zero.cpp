class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        int req=sum-x;
        if(req==0){
            return n;
        }
        unordered_map<int,int> mp;
        int maxi=-1;
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            if(temp==req){
                maxi=max(maxi,i+1);
            }else{
                if(mp.find(temp-req)!=mp.end()){
                    maxi=max(maxi,i-mp[temp-req]);
                }
            }
            
            mp[temp]=i;
        }
        
        if(maxi==-1){
            return -1;
        }else{
            return n-maxi;
        }
        
    }
};