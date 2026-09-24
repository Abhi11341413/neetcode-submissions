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
    vector<int> result;
    void postorder(TreeNode* root)
    {
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
       stack<TreeNode*> st1;
       stack<TreeNode*> st2;
       vector<int> result;
       st1.push(root);
        if(root==NULL) return result;
       while(!st1.empty())
       {
          auto temp=st1.top();
          st2.push(temp);
          st1.pop();
          if(temp->left)
          {
            st1.push(temp->left);
          }
          if(temp->right)
          {
            st1.push(temp->right);
          }
       }
       while(!st2.empty())
       {
        result.push_back(st2.top()->val);
        st2.pop();
       }
       return result;
    }
};