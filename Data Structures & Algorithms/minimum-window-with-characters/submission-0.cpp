class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int left =0;
        int start =0;
        int minlen = INT_MAX;
        int count = t.size();

        for(char c:t){
            mp[c]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]] >0)
            count--;

            mp[s[i]]--;
            while(count ==0){
                if(i-left+1 < minlen){
                    minlen = i-left+1;
                    start =left;
                }
            
                mp[s[left]]++;
                if(mp[s[left]] >0){
                    count++;
                }
            
                left++;
            }
            
        }
            if(minlen == INT_MAX) return "";
        
        return s.substr(start , minlen);
    }
};