/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool child(struct TreeNode* p, struct TreeNode* q) {
  if (p == NULL) return false;
  if (p == q) {
    return true;
  } 
  return child(p->left, q) || child(p->right, q);
}
 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  if (child(root->left, p) && child(root->left, q)) {
    return lowestCommonAncestor(root->left, p, q);
  }
  if (child(root->right, p) && child(root->right, q)) {
    return lowestCommonAncestor(root->right, p, q);
  }
  
  return root;
}
