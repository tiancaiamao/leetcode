static int
compar(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    if (numsSize<=3) {
        int ret = 0;
        for (int i=0; i<numsSize; i++) {
            ret+= nums[i];
        }
        return ret;
    }
    
    qsort(nums, numsSize, sizeof(int), compar);
    for (int i=0; i<numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int ret = nums[0]+nums[1]+nums[2];
    for (int i=0; i<numsSize-2; i++) {
        int dest = target - nums[i];
        int beg = i+1;
        int end = numsSize-1;
        while(beg<end) {
            int sum = nums[beg]+nums[end];
            int x = sum+nums[i];
            if (abs(x-target) < abs(ret-target)) {
                printf("更新返回值[%d %d %d]=%d\n", beg, end, i, ret);
                ret=x;
            }
            if (sum<dest) {
                beg++;
            } else if (sum>dest) {
                end--;
            } else {
                printf("这里退出了[%d %d %d]\n", beg, end, i);
                return target;
            }
        }
    }
    return ret;
}
