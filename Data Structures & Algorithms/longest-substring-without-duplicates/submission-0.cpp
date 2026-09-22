class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left =0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]] >1){
                mp[s[left]]--;
                left++;
            }
            maxlen = max( maxlen , i-left+1);
        }
        return maxlen;
    }
};
