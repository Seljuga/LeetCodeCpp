class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positivecount=0;
        int negativecount=0;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            positivecount++;
            if(nums[i]<0)
            negativecount++;
        }
        return max(positivecount,negativecount);
    }
};
