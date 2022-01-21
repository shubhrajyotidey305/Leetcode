class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 1){
            if(gas[0]>=cost[0])
                return 0;
            else
                return -1;
        }
        
        int str = 0, end = 1;
        int cg = gas[str] - cost[str];
        
        while(str != end || cg < 0){
            while(str != end && cg < 0){
                cg -= (gas[str] - cost[str]);
                str = (str+1)%n;
                
                if(str == 0)
                    return -1;
            }
            cg += (gas[end] - cost[end]);
            end = (end+1)%n;
        }
        return str;
    }
};