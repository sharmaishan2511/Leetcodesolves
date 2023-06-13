class Solution {
public:
    string longestPalindrome(string s) {
        string ans;

        for(int i = 0;i<s.size();i++){
            string curr;
            int lo = i;
            int hi = i;
            while(lo>=0 && hi<s.size() && s[lo]==s[hi]){
                curr = s.substr(lo,hi-lo+1);
                lo--;hi++;
            }
            
            if(curr.size()>ans.size()){
                ans= curr;
            }
            curr.clear();
            lo = i;
            hi = i+1;
            while(lo>=0 && hi<s.size() && s[lo]==s[hi]){    
                curr = s.substr(lo,hi-lo+1);
                lo--;hi++;
            }
            
            //return curr;
            if(curr.size()>ans.size()){
                ans = curr;
            }

        }
        return ans;
    }
};