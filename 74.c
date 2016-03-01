bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  int min, mid, max, tmp, idx;
  min = 0;
  max = matrixRowSize-1;
  while(min < max) {
    mid = min+(max-min)/2;
    tmp = matrix[mid][0];
    if (tmp > target) {
      max = mid-1;
    } else if (tmp < target) {
      min = mid+1;
    } else {
      return true;
    }
  }
  idx = min;
  if (matrix[idx][0] > target) {
    if (idx == 0) return false;
    idx--;
  }
  min = 0;
  max = matrixColSize-1;
  while(min <= max) {
    mid = min+(max-min)/2;
    tmp = matrix[idx][mid];
    if (tmp > target) {
      max = mid-1;
    } else if (tmp < target) {
      min = mid+1;
    } else {
      return true;
    }
  }
  return false;
}
