/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, unordered_map<Node*, Node*>& nodeMap) {
        for (auto& neighbour : node->neighbors) {
            if (nodeMap.find(neighbour) == nodeMap.end()) {
                nodeMap[neighbour] = new Node(neighbour->val);
                dfs(neighbour, nodeMap);
            }
            nodeMap[node]->neighbors.push_back(nodeMap[neighbour]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[node] = new Node(node->val);
        dfs(node, nodeMap);
        return nodeMap[node];
    }
};
