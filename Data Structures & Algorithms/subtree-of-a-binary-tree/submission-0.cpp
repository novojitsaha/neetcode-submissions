/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot){
            return root == subRoot;
        }
 
            if (isSameTree(root, subRoot)){
                return true;
            } else{
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); 
            }
        

    }


    bool isSameTree(TreeNode *p, TreeNode *q){
        if (!p || !q) return p == q;
        if(isSameNode(p,q)){
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        } else {
            return false; 
        }


    }

    bool isSameNode(TreeNode *p, TreeNode *q){
        if (!p || !q){
            return p == q;
        } else {
            return p->val == q->val;
        }
    }

};
