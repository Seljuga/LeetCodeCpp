class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxI = 0, size = citations.size();
        sort(citations.begin(), citations.end());
        for(int i=0; i<size; i++) {
            if (citations[i] >= size-i) maxI = max(maxI, size-i);
        }
        return maxI;
    }
};
