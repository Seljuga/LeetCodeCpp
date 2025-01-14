class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> vec;
        map<int, int> mpp;
        int size = A.size(), count=0;
        for (int i = 0; i < size; i++) {
            mpp[A[i]]++;
            if (mpp[A[i]] == 2) {
                mpp[A[i]]=0;
                count++;
            }
            mpp[B[i]]++;
            if (mpp[B[i]]==2) {
                mpp[B[i]]=0;
                count++;
            }
            vec.push_back(count);
        }
        return vec;
    }
};
