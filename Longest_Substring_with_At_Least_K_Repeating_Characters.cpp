class Solution {
public:
    int f(string s,int st,int end,int k){
        if(end-st<k){
            return 0;
        }

        unordered_map<char,int> mp;
        for(int i = st;i<end;i++){
            mp[s[i]]++;
        }

        for(int i = st;i<end;i++){
            if(mp[s[i]]<k){
                int j = i+1;

                while(j<end && mp[s[j]]<k){
                    j++;
                }

                return max(f(s,st,i,k),f(s,j,end,k));
            }
        }
        return end-st;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        return f(s,0,n,k);
    }
};