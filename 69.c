int mySqrt(int x) {
  if (x <= 0) return 0;
  int beg = 1;
  int end = x;
  if (end > 46340) end = 46340; // sqrt(INT_MAX)=46340
  while(beg <= end) {
    int mid = (beg+end)/2;
    int tmp = mid*mid;
    if (tmp<x) {
      beg = mid+1;
    } else if (tmp > x) {
      end = mid-1;
    } else {
      return mid;
    }
  }
  return end;
}
