class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int size = words.size(), index = 0;
        while (index < size) {
            int lineLen = words[index].size();
            int last = index + 1;
            while (last < size && lineLen + words[last].size()+last-index <= maxWidth) {
                lineLen += words[last].size();
                last++;
            }
            int gaps = last - index - 1;
            string line = words[index];

            if (last == size || gaps == 0) {
                for (int i=index+1; i<last; i++) line += " "+words[i];
                line += string(maxWidth-line.size(), ' ');
            }
            else {
                int spaces = (maxWidth-lineLen)/gaps;
                int extraSpace = (maxWidth-lineLen)%gaps;
                for (int i=index+1; i<last; i++) {
                    line += string(spaces+(extraSpace-- >0 ? 1 : 0), ' ');
                    line+=words[i];
                }
            }
            ans.push_back(line);
            index=last;
        }
        return ans;
    }
};
