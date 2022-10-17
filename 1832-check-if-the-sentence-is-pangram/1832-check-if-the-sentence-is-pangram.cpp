class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> v(26, 0);
        for(auto it:s) {
            v[it-'a']++;
        }
        
        for(auto it:v) {
            if(it == 0) {
                return false;
            }
        }
        return true;
    }
};