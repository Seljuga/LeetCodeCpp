class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int size = derived.size(), temp = 0;
        for (int i=0; i<size; i++) temp ^= derived[i];
        return (temp == 0) ? true : false;
    }
};
