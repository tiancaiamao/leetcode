/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
  if (preorderSize == 0) {
    return NULL;
  }
  if (preorderSize != inorderSize) return NULL;
  struct TreeNode *n = malloc(sizeof(struct TreeNode));
  n->val = preorder[0];
  int found = -1;
  for (int i=0; i<inorderSize; i++) {
    if (inorder[i] == preorder[0]) {
      found = i;
      break;
    }
  }
  n->left = buildTree(preorder+1, found, inorder, found);
  n->right = buildTree(preorder+1+found, preorderSize-found-1, inorder+found+1, inorderSize-found-1);
  return n;
}
