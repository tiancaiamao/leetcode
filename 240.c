bool search(int **matrix, int rowMin, int rowMax, int colMin, int colMax, int target) {
  int mid, tmp;
  int saveMax;

  if (rowMin >= rowMax || colMin >= colMax) {
    return false;
  }

  while (rowMin < rowMax) {
    mid = (rowMin + rowMax ) / 2;
    tmp = matrix[mid][colMin];
    if (tmp > target) {
      rowMax = mid;
    } else if (tmp < target) {
      rowMin = mid + 1;
    } else {
      return true;
    }
  }
  
  if (rowMin == 0) {
    return false;
  }

  saveMax = colMax;
  while (colMin < colMax) {
    mid = (colMin + colMax) / 2;
    tmp = matrix[rowMin-1][mid];
    if (tmp > target) {
      colMax = mid;
    } else if (tmp < target) {
      colMin = mid+1;
    } else {
      return true;
    }
  }

  return search(matrix, 0, rowMin, colMin, saveMax, target);
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  return search(matrix, 0, matrixRowSize, 0, matrixColSize, target);
}
