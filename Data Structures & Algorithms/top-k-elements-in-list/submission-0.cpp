class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<int> ans;

        while (k > 0) {
            int maxFreq = 0;
            int maxNum = 0;

            for (auto x : mp) {
                if (x.second > maxFreq) {
                    maxFreq = x.second;
                    maxNum = x.first;
                }
            }

            ans.push_back(maxNum);

            mp.erase(maxNum);

            k--;
        }

        return ans;
    }
};