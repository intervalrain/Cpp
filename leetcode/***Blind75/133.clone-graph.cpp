#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
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
public:
    unordered_set<Node*> visited;
    unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        traverse(node);
        return map[node];
    }
    void traverse(Node* node){
        if (visited.count(node)) return;
        Node* cloned = new Node(node->val);
        map[node] = cloned;
        visited.insert(node);
        for (Node* next: node->neighbors){
            traverse(next);
            cloned->neighbors.push_back(map[next]);
        }
    }
};
// @lc code=end

