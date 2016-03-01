/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
  int lh, rh;
  if (root == NULL) {
    return 0;
  }

  lh = maxDepth(root->left);
  rh = maxDepth(root->right);
  return 1 + (lh > rh ? lh : rh);
}
