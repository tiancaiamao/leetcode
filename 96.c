int numTreesRemb(int n, int *array) {
  int i, ret;
  if (array[n] != 0) {
    return array[n];
  }

  ret = 0;
  for (i=0; i<n; i++) {
    ret += numTreesRemb(i, array) * numTreesRemb(n-i-1, array);
  }
  array[n] = ret;

  return ret;
}

int numTrees(int n) {
  int i, ret;
  int array[2000];

  memset(array, 0, sizeof(array));
  array[0] = 1;
  array[1] = 1;
  
  return numTreesRemb(n, array);
}
