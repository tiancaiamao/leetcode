int countDigitOne(int n) {
  int ret = 0;
  for (long k = 1; k <= n; k *= 10) {
    long r = n / k;
    long m = n % k;
    ret += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
  }
  return ret;
}
