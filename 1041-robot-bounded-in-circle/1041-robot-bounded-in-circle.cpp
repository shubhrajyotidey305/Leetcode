class Solution {
public:
    bool isRobotBounded(string s) {
        int dirx = 0, diry = 1;
        
        int x = 0, y = 0;
        
        for(auto &i:s){
            if(i=='G'){
                x+=dirx;
                y+=diry;
            }
            else if(i=='L'){
                int temp = dirx;
                dirx = -1*diry;
                diry = temp;                
            }
            else{
                int temp = dirx;
                dirx = diry;
                diry = -1*temp;
            }
        }
        
        return ((x == 0 and y == 0) or (dirx!=0 or diry!=1));
    }
};