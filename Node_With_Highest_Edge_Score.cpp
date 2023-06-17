class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<long long int,long long int> mp;

        for(int i = 0;i<edges.size();i++){
            mp[edges[i]]+=i;
        }

        int ans = 0;
        int node = -1;
        for(auto it : mp){
            if(it.second>ans){
                ans=it.second;
                node=it.first;
            }
        }
        return node;
    }
};