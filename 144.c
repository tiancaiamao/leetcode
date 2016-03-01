/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
  struct TreeNode* stack[2000];
  int idx;
  struct TreeNode* tmp;
  int *ret;

  *returnSize = 0;
  if (root == NULL)  return NULL;

  ret = (int*)malloc(500*sizeof(int));

  stack[idx] = root;
  idx++;
  while(idx != 0) {
    idx--;
    tmp = stack[idx];

    ret[*returnSize] = tmp->val;
    *returnSize = (*returnSize) + 1;

    if (tmp->right) {
      stack[idx] = tmp->right;
      idx++;
    }

    if (tmp->left) {
      stack[idx] = tmp->left;
      idx++;
    }
  }

  return ret;
}
