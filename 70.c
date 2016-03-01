int climbStairs(int n) {
  int a, b, tmp, i;
  a = 1;
  b = 2;

  if (n==1) {
    return a;
  }
  if (n==2) {
    return b;
  }

  for (i=0; i<n-2; i++) {
    tmp = b;
    b = a+b;
    a = tmp;
  }
  return b;
}
