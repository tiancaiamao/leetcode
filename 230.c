/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int inorder(struct TreeNode *root, int *cur, int *found, int k) {
  int ret;
  // 空则返回
  if (root == NULL) return 0;
  // 左树中找
  ret = inorder(root->left, cur, found, k);
  if (*found) return ret;
  // 当前结点
  *cur = *cur + 1;
  if (*cur == k) {
    *found = 1;
    return root->val;
  }
  // 右树中找
  return inorder(root->right, cur, found, k);
}

int kthSmallest(struct TreeNode* root, int k) {
  int cur, found;
  cur = 0;
  found = 0;
  return inorder(root, &cur, &found, k);
}
