double myPow1(double x, int n) {
  if (n <= 8) {
    double ret = 1;
    for (int i=0; i<n; i++) {
      ret = ret * x;
    }
    return ret;
  }
  double tmp = myPow1(x, n/2);

  if ((n%2)==1) {
    return tmp * tmp * x;
  }
  return tmp * tmp;
}

double myPow(double x, int n) {
  if (n==0) return 1;
  if (n<0) {
    if (n==INT_MIN) { // 因为补码的负数表示范围比正数大1个
      return 1/myPow1(x, INT_MAX) * 1/x;
    }
    return 1 / myPow1(x, -n);
  }
  return myPow1(x, n);
}
