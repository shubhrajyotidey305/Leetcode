class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        
        int no_bits = floor(log2(n))+1;
        int x = (1<<no_bits)-1;
        
        return (x^n);
    }
};