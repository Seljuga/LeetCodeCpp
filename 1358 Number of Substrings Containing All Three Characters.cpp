class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        for(int i = 0, dp[3] = {0}, cnt = 0, r = 0; i < s.size(); i++){
            while(r < s.size() && cnt < 3) cnt += !dp[s[r++] - 'a']++;
            ans += s.size() - r + (cnt == 3);
            cnt -= !--dp[s[i] - 'a'];
        }
        return ans;
    }
};
