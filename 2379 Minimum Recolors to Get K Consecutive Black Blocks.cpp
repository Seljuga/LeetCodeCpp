class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cntW = 0;
        int len = blocks.length();

        for(int i=0; i<k; i++){
            if(blocks[i] == 'W'){
                cntW++;
            }
        }
        int ans = cntW;

        for(int i=k; i<len; i++){
            if(blocks[i] == 'W'){
                cntW++;
            }
            if(blocks[i-k] == 'W'){
                cntW--;
            }
            ans = min(ans, cntW);
        }
       
        return ans;
    }
};
