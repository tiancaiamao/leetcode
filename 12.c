char*** t;
char* t0[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char* t1[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char* t2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char* t3[] = {"", "M", "MM", "MMM", "", "", "", "", "", ""};


void init() {
  int i, j;
  t = malloc(sizeof(char**) * 4);
  t[0] = t0;
  t[1] = t1;
  t[2] = t2;
  t[3] = t3;
}

char* intToRoman(int num) {
  int i;
  int v[10];
  char *ret, *ptr;

  init();

  i = 0;
  do {
    v[i] = num % 10;
    num = num / 10;
    i++;
  } while(num > 0);
  
  ret = (char*)malloc(100);
  ptr = ret;

  i--;
  for (;i>=0; i--) {
    strcpy(ptr, t[i][v[i]]);
    ptr += strlen(t[i][v[i]]);
  }
  *ptr = '\0';
  return ret;
}
