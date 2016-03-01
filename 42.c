// 求出每个格子能存的雨量，然后累加
// 求每个格子的存雨量，需要找到它两边的，比它高的格子的较小的一个
// 左边的比它大的最大值，右边的比它大的最大值，分开进行计划
// n跟n+1之间有相互关系，可以用动态规划!

int trap(int* height, int heightSize) {
  int left[heightSize], right[heightSize];
  left[0] = 0;
  for (int i=1; i<heightSize; i++) {
    left[i] = left[i-1] > height[i-1] ? left[i-1] : height[i-1];
  }
  right[heightSize-1] = 0;
  for (int i=heightSize-2; i>=0; i--) {
    right[i] = right[i+1] > height[i+1] ? right[i+1] : height[i+1];
  }
  int ret = 0;
  for (int i=0; i<heightSize; i++) {
    int x = left[i] < right[i] ? left[i] : right[i];
    if (x > height[i]) {
      ret += (x-height[i]);
    }
  }
  return ret;
}
