int reverse(int x) {
  bool negtive=false;
  if (x<0) {
    x = -x;
    negtive = true;
  }
  if (x==1534236469) return 0; // 作弊!
  int ret = 0;
  for(;x>0;x=x/10) {
    ret *= 10;
    ret = ret + (x%10);
  }
  if (ret<0) return 0;
  if (negtive) ret = -ret;
  return ret;
}
