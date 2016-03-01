int lengthOfLastWord(char* s) {
  int len = strlen(s);
  char *p = s+len-1;
  while(p>=s && *p==' ') p--;
  int ret = 0;
  while(p>=s && *p!=' ') {
    p--;
    ret++;
  }
  return ret;
}
