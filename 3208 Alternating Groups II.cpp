class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int i = 0, j = 1, size = colors.size();
        while(j < size+k-1) //if a group starts with last element of colors, it will end at (k-1)th element from start
        {
            if(colors[j%size] == colors[(j-1)%size]) // '%' for maintaning circular property, i.e. for preventing out of bound errors at j>=n
            {
                if(j-i >= k)
                ans += j - i - k + 1;
                i=j;
            }
            j++;
        }
        if(j-i >= k)
        ans += j - i - k + 1;
        return ans;
    }
};
