int ctoi(char s) {
  int ret;
  switch (s) {
  case 'I': ret = 1; break;
  case 'V': ret = 5; break;
  case 'X': ret = 10; break;
  case 'L': ret = 50; break;
  case 'C': ret = 100; break;
  case 'D': ret = 500; break;
  case 'M': ret = 1000; break;
  }
  return ret;
}

int romanToInt(char* s) {
  int ret, prev, cur;
  
  ret = 0;
  prev = 0;
  while(*s) {
    cur = ctoi(*s);
    if (cur > prev) {
      ret -= prev;
    } else {
      ret += prev;
    }
    prev = cur;
    s++;
  }
  ret += prev;
  return ret;
}
