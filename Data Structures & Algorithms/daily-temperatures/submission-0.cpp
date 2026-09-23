class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        stack<int> st;
        vector<int> result(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
                int prev = st.top();
                result[prev] = i-prev;
                st.pop();
            }
            st.push(i);

        }
        return result;
        
    }
};
