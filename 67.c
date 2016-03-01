static void
reverse(char *p, char *q) {
  char tmp;
  while(p<q) {
    tmp = *p;
    *p = *q;
    *q = tmp;
    p++;
    q--;
  }
}

char* addBinary(char* a, char* b) {
  int la = strlen(a);
  int lb = strlen(b);
  char *ret = malloc(1+(la>lb?la:lb));
  char *r = ret;
  char *p = a + la - 1;
  char *q = b + lb - 1;
  int v = 0;
  while(p>=a || q>=b || v>0) {
    if (p>=a) v += ((*p)-'0');
    if (q>=b) v += ((*q)-'0');
    (*r) = '0'+(v%2);
    v /= 2;
    p--; q--; r++;
  }
  *r = 0;
  reverse(ret, r-1);
  return ret;
}
