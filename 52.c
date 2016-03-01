bool conflict(int *array, int step, int y) {
  int i, dx, dy;
  
  for (i=0; i<step; i++) {
    if (array[i] == y) {
      return true;
    }
    dx = step - i;
    dy = array[i] - y;
    if (dx == dy || dx == -dy) {
      return true;
    }
  }
  return false;
}

void recur(int *array, int step, int n, int* count) {
  int i, j;

  if (step == n) {
    *count = (*count) + 1;
    return;
  }

  for (i=0; i< n; i++) {
    if (!conflict(array, step, i)) {	  
      array[step] = i;
      recur(array, step+1, n, count);
    }
  }
}

int totalNQueens(int n) {
  int ret;
  int *array;

  array = (int*)malloc(sizeof(int) * n);
  ret = 0;

  recur(array, 0, n, &ret);

  free(array);
  return ret;    
}
