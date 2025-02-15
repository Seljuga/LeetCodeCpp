class Solution {
private:
    bool fun(int index, string str, int sizeOfStr, int num, vector<string>& ans) {
        if (index == sizeOfStr) {
            int sum = 0;
            for (auto it : ans) sum += stoi(it);
            return sum == num;
        }

        for (int i=index; i<sizeOfStr; i++) {
            ans.push_back(str.substr(index, i-index+1));
            bool check = fun(i+1, str, sizeOfStr, num, ans);
            ans.pop_back();
            if (check) return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        vector<string> ans;
        int sum = 0;

        for (int num = 1; num <= n; num++) {
            ans.clear();
            int square = num*num;
            string str = to_string(square);
            if (fun(0, str, str.length(), num, ans)) sum += square;
        }
        return sum;
    }
};
