int maxRecur(struct TreeNode *n, int *rootMax) {
  int leftMax, rightMax, leftRoot, rightRoot;
  int ret, tmp;

  
  if (n->left) {
    leftMax = maxRecur(n->left, &leftRoot);
  } else {
    leftRoot = 0;
    leftMax = INT_MIN;
  }

  if (n->right) {
    rightMax = maxRecur(n->right, &rightRoot);
  } else {
    rightRoot = 0;
    rightMax = INT_MIN;
  }

  ret = n->val;
  if (leftRoot > 0) {
    ret += leftRoot;
  }
  if (rightRoot > 0) {
    ret += rightRoot;
  }
  if (rightMax > ret) {
    ret = rightMax;
  }
  if (leftMax > ret) {
    ret = leftMax;
  }

  tmp = (n->val + leftRoot) > (n->val + rightRoot) ? (n->val + leftRoot) : (n->val + rightRoot);
  *rootMax = (tmp > n->val) ? tmp : n->val;

  return ret;
}

int maxPathSum(struct TreeNode* root) {
  int ignore;
  if (root == NULL) return 0;
  return maxRecur(root, &ignore);
}
