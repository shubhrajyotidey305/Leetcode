class node
{
    public:
    char data;
    unordered_map<char,node*>children;
    bool terminal;
    int index;
    node(char d)
    {
        data=d;
        terminal=false;
    }

};


class Trie
{
    public:
    node* root;
    int cnt;
    Trie()
    {
        root=new node('\0');
        cnt=0;
    }
    bool insert(string w)
    {
        node* temp=root;
        for(int i=0;i<w.length();i++)
        {
            char ch=w[i];
            if(temp->children.count(ch))
            {
                temp=temp->children[ch];
            }
            else{
                node* n=new node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        if(temp->children.size()==0 and temp->terminal==false){
            temp->terminal=true;
            return true;
        }
        return false;
        cnt++;
    }
 
};
bool cmp(string a,string b){
    return a.length()>b.length();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        int cnt=0;
        Trie t;
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size();i++){
                string temp=words[i];
                reverse(temp.begin(),temp.end());
            bool flag=t.insert(temp);
            if(flag){
                cout<<words[i]<<endl;
                ans+=words[i].length();
                cnt++;
            }
            
        }
        ans+=cnt;
        return ans;
                              
    }
};