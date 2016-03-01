/**
   /**
   * Return an array of arrays.
   * Note: The returned array must be malloced, assume caller calls free().
   */
int** generateMatrix(int n) {
  int** ret = malloc(sizeof(int*) * n);
  int i;
  for (i=0; i<n; i++) {
    ret[i] = malloc(sizeof(int) * n);
  }
  int s = 0;
  int l = n;
  int v = 1;
  while(s < l) {
    for (i=s; i<l; i++) ret[s][i] = v++;
    for (i=s+1; i<l; i++) ret[i][l-1] = v++;
    for (i=l-2; i>=s; i--) ret[l-1][i] = v++;
    for (i=l-2; i>s; i--) ret[i][s] = v++;
    s++;
    l--;
  }

  return ret;
}
