class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>u;
        if(t.size()!=s.size()){
            return false;
        }
        for(int i=0;i<t.size();i++){
            u[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(u.find(s[i])==u.end() || u[s[i]] == 0){
                return false;
            }
            else{
                u[s[i]]--;
            }
        }
        return true;
    }
};
