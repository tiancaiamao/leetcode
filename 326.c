// 3的指数的最大数，能否整除这个数
bool isPowerOfThree(int n) {
  return n > 0 && (1162261467 % n == 0);    
}
