class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        map<vector<int>,int> mp1;
        map<vector<int>,int> mp2;

        for(int i = 0;i<n;i++){
            mp1[grid[i]]++;
        }

        for(int i = 0;i<n;i++){
            vector<int> col;
            for(int j = 0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            mp2[col]++;
        }
        for(auto it1 : mp1){
            for(auto it2 : mp2){
                if(it1.first==it2.first){
                    ans+=it1.second*it2.second;
                }
            }
        }
        return ans;
    }
};