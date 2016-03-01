void recur(char *data, int pos, int size, int val, char ***ret, int *retsize, int *cap) {
  char *tmp;

  if (val < 0) {
    return;
  }

  if (pos == size) {
    if (val == 0) {
      if (*cap == *retsize) {
        (*cap) = (*cap) * 2;
        (*ret) = realloc((*ret), sizeof(char*) * (*cap));	
      }
      tmp = malloc(size+1);
      strcpy(tmp, data);
      (*ret)[*retsize] = tmp;
      (*retsize) = (*retsize) + 1;
    }
    return;
  }

  data[pos] = '(';
  recur(data, pos+1, size, val+1, ret, retsize, cap);
  data[pos] = ')';
  recur(data, pos+1, size, val-1, ret, retsize, cap);
  return;
}

char** generateParenthesis(int n, int* returnSize) {
  char **ret;
  char *data;
  int cap;

  cap = 100;
  *returnSize = 0;
  ret = malloc(sizeof(char*) * cap);

  data = malloc(2*n+1);
  data[2*n] = '\0';
  recur(data, 0, 2*n, 0, &ret, returnSize, &cap);
  return ret;
}
