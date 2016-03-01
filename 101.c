/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool sym(struct TreeNode *n1, struct TreeNode *n2) {
  if (!n1) return !n2;
  if (!n2) return !n1;
  return n1->val == n2->val && sym(n1->left, n2->right) && sym(n1->right, n2->left);
}

bool isSymmetric(struct TreeNode* root) {
  if (root == NULL) return true;
  return sym(root->left, root->right);
}
