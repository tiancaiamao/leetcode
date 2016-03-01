// 规律：
// 1-9 => 1-9
// 10-19 => 1-9
// ...
int addDigits(int num) {
  if (num == 0) return 0;
    
  int x = num % 9;
  if (x == 0) x = 9;
  return x;
}
