char* longestPalindrome(char* s) {
  int len = strlen(s);
  if (len==0) return s;
  char *ret;
  int max = 0;
  int i, j, mid;
  for (mid=0; mid<len; mid++) {
    i = mid;
    j = mid;
    while(i>=0 && j<len && s[i] == s[j]) {
      i--;
      j++;
    }
    if (j-i-1 > max) {
      max = j-i-1;
      ret = s+i+1;
    }
        
    i=mid;
    j=mid+1;
    if (i<len && j<len && s[i]==s[j]) {
      while(i>=0 && j<len && s[i] == s[j]) {
        i--;
        j++;
      }
      if (j-i-1 > max) {
        max = j-i-1;
        ret = s+i+1;
      }
    }
  }
  ret[max]='\0';
  return ret;
}
