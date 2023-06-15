class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }else if(nums.size()==0){
            return -1;
        }
        if(nums[lo]!=nums[lo+1]){
            return nums[lo];
        }

        if(nums[hi]!=nums[hi-1]){
            return nums[hi];
        }
        while(lo<=hi){
            int mid = (lo+hi)/2;

            if((mid>=0 && mid<nums.size()) && nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]){
                return nums[mid];
            }

                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    int sl = mid-lo+1;

                    if(sl%2==1){
                        hi = mid-2;
                    }else{
                        lo = mid+1;
                    }
                }else if(mid+1<nums.size() && nums[mid+1]==nums[mid]){
                    int sl = mid-lo+1;

                    if(sl%2==1){
                        lo = mid+2;
                    }else{
                        hi = mid-1;
                    }
                }
            
        }
        return -1;
        
    }
};