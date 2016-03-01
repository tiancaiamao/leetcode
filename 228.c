static char *
generate(int a, int b, char* str) {
    int n;
    if (a == b) {
        n = sprintf(str, "%d", a);
    } else {
        n = sprintf(str, "%d->%d", a, b);
    }
    char *ret = malloc(n+1);
    memcpy(ret, str, n);
    ret[n] = '\0';
    return ret;
}

static char**
append(char** arr, int* pos, int *cap, char *item) {
    if (*pos == *cap) {
        *cap = *cap * 2;
        arr = realloc(arr, *cap * sizeof(char*));
    }
    arr[*pos] = item;
    (*pos)++; 
    return arr;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int cap = 16;
    int pos = 0;
    char **ret = malloc(sizeof(char*) * cap);
    char tmp[100];
    
    int i, beg = 0;
    for (i=1; i<numsSize; i++) {
        if (nums[i] != nums[i-1] + 1) {
            char *item = generate(nums[beg], nums[i-1], tmp);
            ret = append(ret, &pos, &cap, item);
            beg = i;
        }
    }
    char *item = generate(nums[beg], nums[i-1], tmp);
    ret = append(ret, &pos, &cap, item);

    *returnSize = pos;
    return ret;
}
