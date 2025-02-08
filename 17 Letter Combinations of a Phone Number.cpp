class Solution {
public:
    void combine(string digits, string keypad[], vector<string> & ans, int index, string output) {
        if (index>=digits.length()){
            ans.push_back(output);
            return ;
        }
        string value = keypad[digits[index]-'0'];
        for (int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            combine(digits, keypad, ans, index+1, output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        if (digits.length()==0){
            return ans;
        }
        int index=0;
        string keypad[10]= {"", "", "abc", "def", "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
        combine(digits, keypad, ans, index, output);
        return ans;
    }
};
