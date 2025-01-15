class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size(), current = 0, start = 0, previous = 0;
        for (int i=0; i<size; i++) {
            current += (gas[i] - cost[i]);
            if (current < 0) {
                start = i + 1;
                previous += current;
                current = 0;
            }
        }
        return (current + previous >= 0) ? start : -1;
    }
};
