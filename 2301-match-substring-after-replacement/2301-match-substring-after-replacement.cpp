class Solution {
public:
     bool can(string& a,string& b,vector<unordered_set<char> >& m,int j){
        int x=0;
        for(int i=j;i<a.length();i++){
            if(a[i]!=b[x]&&(m[b[x]].find(a[i])==m[b[x]].end())) return false;
            x++;
        }
        return true;
    }
    bool matchReplacement(string &s, string& sub, vector<vector<char>>& mappings) {        
        int k = sub.length();
        string a="";
        for(int i=0;i<k;i++) {
           a+=s[i];
        }
        int j=0;
        vector<unordered_set<char> > m(150);
        for(auto x:mappings) m[x[0]].insert(x[1]);
        if(can(a,sub,m,j)) return true;
        for(int i=k;i<s.length();i++){
            a+=s[i];
            if(can(a,sub,m,++j)) return true;
        }
        return false;
        
    }
};