/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recur(int *nums, int begin, int end) {
  int mid;
  struct TreeNode *ret;

  if (begin == end) {
    return NULL;
  }
  mid = (begin + end) / 2;
  ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  ret->val = nums[mid];
  ret->left = recur(nums, begin, mid);
  ret->right = recur(nums, mid+1, end);
  return ret;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
  return recur(nums, 0, numsSize);
}
