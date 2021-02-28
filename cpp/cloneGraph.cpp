#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==nullptr)
            return nullptr;
        
        // set that will have all the visited nodes
        // returns false if already visited node is 
        // inserted in the set
        std::unordered_set<Node*> visited;
        
        unordered_map<Node*, Node*> nodeMap;
        
        queue<Node*> nodeQ;
        nodeQ.push(node);
        
        while(!nodeQ.empty()){
            Node* curr_node = nodeQ.front(); nodeQ.pop();
            if (visited.count(curr_node)) continue;
            visited.insert(curr_node);
            
            // check if current node already has
            // a copy in the map
            if(!nodeMap.count(curr_node))
                nodeMap[curr_node] = new Node(curr_node->val);
                
            Node* cloned_curr_node = nodeMap[curr_node];
            
            for (auto nn: curr_node->neighbors){
                if(!nodeMap.count(nn))
                    nodeMap[nn] = new Node(nn->val);
                nodeQ.push(nn);
                cloned_curr_node->neighbors.push_back(nodeMap[nn]);
            }
        }
        return nodeMap[node];
    }
};