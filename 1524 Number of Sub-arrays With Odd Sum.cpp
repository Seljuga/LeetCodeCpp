class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int m = (int)1e9 +7;
        int ans = 0;
        int prefixSum = 0;
            int oddCounter = 0;
            int evenCounter = 1;
       
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
              if(prefixSum % 2 == 0){
                ans = (ans + oddCounter) % m;
                evenCounter++;
            }
            else{
                ans = (ans + evenCounter) % m;
                oddCounter++;
            }}
        
     return ans;
    }
};
