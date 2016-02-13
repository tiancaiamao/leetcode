int trailingZeroes(int n) {
  int sum = 0;
  while(1) {
    int x = n/5;
    if (x<1) break;
    sum += x;
    n = x;
  }
  return sum;
}
