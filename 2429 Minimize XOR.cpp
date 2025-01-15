class Solution {
public:
    int count(int n) {
        int cnt = 0;
        while (n!=0) {
            if(n&1) cnt++;
            n=n>>1;
        }
        return cnt;
    }
    int minimizeXor(int num1, int num2) {
        int cnt2 = count(num2), ans = 0;
        for (int i=31; i>=0 && cnt2>0; i--) {
            if(((1<<i)&num1)!=0) {
                ans=ans|(1<<i);
                cnt2--;
            }
        }
        for (int i=0; i<31 && cnt2>0; i++) {
            if(((1<<i)&num1)==0) {
                ans=ans|(1<<i);
                cnt2--;
            }
        }
        return ans;
    }
};
