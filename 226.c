/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
  struct TreeNode *tmp;

  if (root != NULL) {
    tmp = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(tmp);
  }

  return root;  
}
