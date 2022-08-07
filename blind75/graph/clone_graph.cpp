#include <iostream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(){
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val){
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    };
};

class Solution{
public:
    unordered_set<Node*> visited;
    unordered_map<Node*> map;

    Node* cloneGraph(Node* node){
        if (node == NULL) return NULL;
        traverse(node);
        return map[node];
    }

    void traverse(Node* node){
        if (visited.count(node)) return;
        Node* cloned = new Node(node->val);
        visited.insert(node);
        map[node] = cloned;
        for (Node* n : node->neighbors){
            traverse(n);
            cloned->neighbors.push_back(map[n]);
        }
    }
};


