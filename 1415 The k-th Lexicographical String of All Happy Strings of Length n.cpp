class Solution {
public:
    string getHappyString(int n, int k) {
        vector<int> occurrencesPerPlace(n);
        vector<std::vector<char>> nextChar = {{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
        string result(n, ' ');
        
        for (int i = 0; i < n; i++) {
            occurrencesPerPlace[i] = 1 << (n - i - 1); // Compute 2^(n-i-1)
        }
        
        if (k > 3 * (1 << (n - 1))) return ""; // If k exceeds possible happy strings
        k--; // Convert to 0-based index

        for (int i = 0; i < n; i++) {
            if (i == 0)
                result[0] = std::vector<char>{'a', 'b', 'c'}[k / occurrencesPerPlace[i]];
            else 
                result[i] = nextChar[result[i - 1] - 'a'][k / occurrencesPerPlace[i]];
            k %= occurrencesPerPlace[i];
        }
        
        return result;
    }
};
