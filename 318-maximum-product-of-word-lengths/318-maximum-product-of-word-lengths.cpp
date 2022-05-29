class Solution {
public:
    
    int getMask(char &ch){
        return (1<<(ch-97));    
    }
    
    bool doShareCommonLetters(int &bits1, int &bits2){
        
        for(int i=31;i>=0;i--){
            int bit1 = (bits1>>i)&1;
            int bit2 = (bits2>>i)&1;
            if( bit1 && bit2 ) return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        
        int ans=0, n=words.size();
        int bits[n], lens[n];
        memset(bits, 0, sizeof(bits));
        
        for(int i=0;i<n;i++){
            lens[i] = words[i].length();
            for(auto &ch : words[i]){
                bits[i] = (bits[i] | getMask(ch));
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( doShareCommonLetters(bits[i], bits[j]) == false )
                    ans = max(ans, lens[i]*lens[j]);
            }
        }
        return ans;
    }
};