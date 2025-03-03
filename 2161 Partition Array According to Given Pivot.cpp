class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small,large;
        int eq = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                small.push_back(nums[i]);
            } else if(nums[i]>pivot){
                large.push_back(nums[i]);
            } else {
                eq++;
            }
        }
        int i=0;
        for(int num:small)nums[i++]=num;
        while(eq!=0){
            nums[i++]=pivot;
            eq--;
        }
        for(int num:large)nums[i++]=num;
        return nums;
    }
};
