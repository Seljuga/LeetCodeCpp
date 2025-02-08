class NumberContainers {
    unordered_map<int, set<int>> numIndicies;
    unordered_map<int, int> indNum;
public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (indNum.count(index)) {
            int prevNum = indNum[index];
            numIndicies[prevNum].erase(index);
            if (numIndicies[prevNum].empty()) numIndicies.erase(prevNum);
        }
        indNum[index] = number;
        numIndicies[number].insert(index);
    }
    
    int find(int number) {
        if (numIndicies.count(number)) return *numIndicies[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
