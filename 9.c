bool isPalindrome(int x) {
  int n, tmp, low, high, j;
    
  if (x < 0) return false;
    
  n = 1;
  for (tmp=x;tmp>=10;tmp/=10) {
    n *= 10;
  }

  j = 1;
  while (j<n) {
    high = (x/n)%10;
    low = (x/j)%10;
    if (high != low) return false;
    n /= 10;
    j *= 10;
  }   
  return true;
}
