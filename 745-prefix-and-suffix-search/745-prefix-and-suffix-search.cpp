class WordFilter {
public:
    unordered_map <string,int> preSufCombos;
    
    WordFilter(vector<string>& words) {
        
        int indx=1;
        for(auto &word:words){
            
            for(int i=1;i<=word.size();i++){
                
                for(int j=word.size()-1;j>=0;j--){
                    
                    preSufCombos[word.substr(0,i)+'#'+word.substr(j)]=indx;
                    
                }
                
            }
            
         indx++;   
        }
        
        
        
    }
    
    int f(string prefix, string suffix) {
       
        
        int indx=preSufCombos[prefix+'#'+suffix];
        
        return (indx==0)?-1:indx-1;
        
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */