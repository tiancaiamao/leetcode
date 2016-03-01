static char *
generate(char *str) {
  int cap = strlen(str) + 10;
  char* ret = malloc(cap);
  memset(ret, 0, cap);
  int pos = 0;

  char prev = '-';
  int count = 0;
  while(*str != '\0') {
    if (*str == prev) {
      count++;
    } else {
      if (prev != '-') {
        if (pos+3 >= cap) {
          cap = cap * 2;
          ret = realloc(ret, cap);
        }

        int n = sprintf(ret+pos, "%d%c", count, prev);
        pos += n;
        // printf("%d%c", count, prev);
      }
      prev = *str;
      count = 1;
    }
    str++;
  }
  
  if (pos+3 >= cap) {
    cap = cap * 2;
    ret = realloc(ret, cap);
  }
  sprintf(ret+pos, "%d%c", count, prev);
  return ret;
}

char* countAndSay(int n) {
  char *ret = "1";
  for (int i=1; i<n; i++) {
    ret = generate(ret);
  }
  return ret;
}
