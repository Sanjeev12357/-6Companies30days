class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans; 
        ans.push_back(envelopes[0]);

        for (int i = 1; i < envelopes.size(); i++) {
            if (envelopes[i][0] > ans.back()[0] && envelopes[i][1] > ans.back()[1]) {
                
                ans.push_back(envelopes[i]);
            } else {
               
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i], [](const vector<int>& a, const vector<int>& b) {
                    return a[1] < b[1];
                }) - ans.begin();
                ans[index] = envelopes[i];
            }
        }

        return ans.size(); 
    }
};
