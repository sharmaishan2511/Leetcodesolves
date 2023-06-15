class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size()<p.size()){
            return ans;
        }

        unordered_map<char,int> mp_curr;
        unordered_map<char,int> mp_p;

        int n = p.size();

        for(int i = 0;i<n;i++){
            mp_p[p[i]]++;
            mp_curr[s[i]]++;
        }

        if(mp_curr==mp_p){
            ans.push_back(0);
        }
        for(int i = n;i<s.size();i++){
            mp_curr[s[i-n]]--;
            mp_curr[s[i]]++;
            if(mp_curr[s[i-n]]==0){
                mp_curr.erase(s[i-n]);
            }
            if(mp_curr==mp_p){
                ans.push_back(i-n+1);
            }
            
        }
        return ans;

    }
};