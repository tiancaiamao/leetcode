int maxArea(int* height, int heightSize) {
  int i, j, max, tmp;
  i = 0;
  j = heightSize - 1;
  max = 0;
  while(i<j) {
    tmp = (height[i]<height[j]?height[i]:height[j]) * (j-i);
    if (tmp > max) {
      max = tmp;
    }
    if (height[i] < height[j]) {
      i++;
    } else {
      j--;
    }
  }
  return max;
}
