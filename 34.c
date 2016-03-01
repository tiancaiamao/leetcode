/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int beg = 0;
    int end = numsSize-1;
    int mid;
    while(beg<=end) {
        mid = (beg+end) / 2;
        if (nums[mid] > target) {
            end = mid-1;
        } else if(nums[mid] < target) {
            beg = mid+1;
        } else {
            break;
        }
    }
    if (beg<=end) {
        int start = mid;
        int end = mid;
        while(start>=0 && nums[start]==nums[mid]) start--;
        start = (start<0) ? 0 : start+1;
        while(end<numsSize && nums[end]==nums[mid]) end++;
        end = end>=numsSize ? numsSize-1 : end-1;

            *returnSize = 2;
            int *ret = malloc(sizeof(int));
            ret[0] = start;
            ret[1] = end;
            return ret;
    }
    int* ret = malloc(2*sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    return ret;
}
