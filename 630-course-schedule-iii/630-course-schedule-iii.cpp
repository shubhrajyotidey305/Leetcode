class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if( a[1] == b[1] ) return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), comp);
        int totalDays = 0, count=0;
        priority_queue<int> maxHeap;
        
        for(auto &crs : courses){
            
            if( (totalDays + crs[0]) > crs[1] ){
                while( maxHeap.empty()==false && maxHeap.top() > crs[0] && (totalDays + crs[0]) > crs[1] ){
                    totalDays -= maxHeap.top();
                    maxHeap.pop();
                }
                if( (totalDays + crs[0]) <= crs[1] ) maxHeap.push(crs[0]), totalDays += crs[0];
            }
            else{
                maxHeap.push(crs[0]), totalDays += crs[0];
            }
        }
        return maxHeap.size();
    }
};