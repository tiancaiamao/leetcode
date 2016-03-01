int titleToNumber(char* s) {
  int i, ret;
  int len = strlen(s);
  
  ret = 0;
  for (i=0; i<len; i++) {
    ret = ret * 26 + (s[i] - 'A') + 1;
  }
  
  return ret;    
}
