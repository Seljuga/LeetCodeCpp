class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxVal = -1;
        for (int num : nums) {
            int sum = digitSum(num);
            if (digitSumMap.count(sum)) {
                maxVal = max(maxVal, num + digitSumMap[sum]);
                digitSumMap[sum] = max(digitSumMap[sum], num); 
            }
            else {
                digitSumMap[sum] = num;
            }
        }
        return maxVal;
    }
};
