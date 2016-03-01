bool isPalindrome(char* s) {
  int len = strlen(s);
  char *p = s+len-1;
  while(s<p) {
    while(s<p && !isalnum(*s)) s++;
    while(s<p && !isalnum(*p)) p--;
    if (tolower(*s)!=tolower(*p))
      return false;
    s++;
    p--;
  }
  return true;
}
