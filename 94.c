/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
void in(struct TreeNode* root, int *ret, int* returnSize) {
  if (root == NULL) return;
  
  in(root->left, ret, returnSize);
  
  ret[*returnSize] = root->val;
  *returnSize = (*returnSize) + 1;
  
  in(root->right, ret, returnSize);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int* ret = malloc(sizeof(int) * 1000);
  in(root, ret, returnSize);
  return ret;
}
