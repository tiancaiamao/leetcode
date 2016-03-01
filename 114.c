static struct TreeNode*
preorder(struct TreeNode *root) {
  if (root==NULL) return NULL;
  struct TreeNode *lt = preorder(root->left);
  struct TreeNode *rt = preorder(root->right);
  if (lt) {
    lt->right = root->right;
    root->right = root->left;
    root->left = NULL;
  }  
  if (rt) return rt;
  if (lt) return lt;
  return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
  preorder(root);
  return root;
}
