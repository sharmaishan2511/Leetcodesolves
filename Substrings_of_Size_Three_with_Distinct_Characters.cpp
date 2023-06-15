class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<int,int> mp;

        //first window
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j<s.size()){
            mp[s[j]]++;
            
            while(mp[s[j]]==2){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }

            if(mp.size()==3){
                ans++;
                break;
            }
            j++;
        }
        
        for(int k = j+1;k<s.size();k++){
            mp[s[k-3]]--;
            mp[s[k]]++;

            if(mp[s[k-3]]==0){
                mp.erase(s[k-3]);
            }

            if(mp.size()==3){
                ans++;
            }
        }
        return ans;

    }
};