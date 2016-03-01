/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* n, int *height) {
  int h1, h2, diff;
  if (n == NULL) {
    *height = 0;
    return true;
  }
    
  if (!helper(n->left, &h1))  return false;
  if (!helper(n->right, &h2)) return false;
  *height = 1+(h1>h2?h1:h2);
  diff = (h1>h2) ? (h1-h2) : (h2-h1);
  return diff <= 1;
}
 
bool isBalanced(struct TreeNode* root) {
  int ignore;
  return helper(root, &ignore);
}
