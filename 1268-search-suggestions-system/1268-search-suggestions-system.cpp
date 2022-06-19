class Solution {
public:
// TC: sorting time + O(number of characters in SearchWord * 3)
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> res;
        
        string curr = "";
        for(char ch: searchWord){
            
            curr += ch; // adding current character to my curr string which we need to search
            
            auto posOfFirst = lower_bound(products.begin(), products.end(), curr); // finding the first word iterator which contains curr 
            
            vector<string> currSuggestedList;
            
            for(int i = 0; i< 3 && posOfFirst + i != products.end(); i++){
                
                string suggestedStr = *(posOfFirst + i);
                
//                 if current suggestedStr string doesn't contains this `curr` then no need to check further in products
                if(suggestedStr.find(curr) == string::npos) break;
                
                currSuggestedList.push_back(suggestedStr);
            }
            
            res.push_back(currSuggestedList);
        }
        
        
        return res;
    }
};