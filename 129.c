/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
static void
path(struct TreeNode *n, int sum, void (*visit)(int *sum, int v), int *data) {
  if (n==NULL) return;
  if (n->left==NULL && n->right==NULL) {
    int v = sum*10+n->val;
    printf("%d\n", v);
    visit(data, v);
    return;
  }
  sum = sum*10 + n->val;
  path(n->left, sum, visit, data);
  path(n->right, sum, visit, data);
}

static void 
visit(int *sum, int v) {
  *sum = (*sum) + v;
}

int sumNumbers(struct TreeNode* root) {
  int ret = 0;
  path(root,0, visit, &ret);
  return ret;
}
