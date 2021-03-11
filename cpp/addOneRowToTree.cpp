#include <queue>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root==nullptr)
            return nullptr;
        
        if (d==1)
        {
            TreeNode* node = new TreeNode(v, root, nullptr);
            return node;
        }
        
        TreeNode* tempNode;
        TreeNode* tempParent = nullptr;
        
        // traverse the tree in level order
        // create q and push all nodes in the next level 
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        // traverse one level at a time
        int depth = 1;
        while(!q.empty())
        {
            // current node
            tempNode = q.front();
            q.pop();

            
            if (depth==d-1 && tempNode != nullptr)
            {
                TreeNode* node = new TreeNode(v, tempNode -> left, nullptr);
                tempNode -> left = node;    
            
                node = new TreeNode(v, nullptr, tempNode -> right);
                tempNode -> right = node;    
                continue;
                
            }
            else if (depth >= d)
            {
                break;
            }
            
            // current level completed
            if (tempNode == nullptr)
            {
                // put marker for next level
                if(!q.empty())
                    q.push(nullptr);
                depth++;
            }
            else
            {
                if(tempNode -> left != nullptr)
                    q.push(tempNode -> left);
                
                if(tempNode -> right != nullptr)
                    q.push(tempNode -> right);
            }
        }
        return root;
    }
};