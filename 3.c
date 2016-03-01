int lengthOfLongestSubstring(char* s) {
  int hash[256];
  memset(hash, 0, 256*sizeof(int));
  char *p = s;
  char *q = s;
  int ret = 0;
  while(*q != '\0') {
    if (hash[*q] != 0) {
      while(p<q) {
        if ((*p)==(*q)) {
          p++;
          q++;
          break;
        }
        hash[*p] = 0;
        p++;
      }
    } else {
      hash[*q] = 1;
      q++;
      if (q-p > ret) ret = q-p;
    }
  }
  return ret;
}
