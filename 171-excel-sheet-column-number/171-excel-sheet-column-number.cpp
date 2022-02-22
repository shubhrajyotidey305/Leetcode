class Solution {
public:
    int titleToNumber(string columnTitle) {
        int index = 0;
        long long k=1;
        for(int i = columnTitle.size()-1; i>=0; i--){
            index += ((columnTitle[i] - 'A') + 1) * k;
            k *= 26;
        }
        return index;
    }
};