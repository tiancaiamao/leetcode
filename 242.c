/*
  int select_sort(char *s) {
  int n = strlen(s);
  int i;
  for (i=0; i<n; i++) {
  int j;
  int min = i;
  for (j=i; j<n; j++) {
  if (s[j] < s[min]) {
  min = j;
  }
  }
  char tmp = s[min];
  s[min] = s[i];
  s[i] = tmp;
  }
  return n;
  }
*/

bool isAnagram(char* s, char* t) {
  int hash[256];
  memset(hash, 0, sizeof(int)*256);
  int i;
  for (i=0; s[i]!='\0'; i++) {
    hash[s[i]]++;
  }
  for (i=0; t[i]!='\0'; i++) {
    hash[t[i]]--;
  }
  for (i=0; i<256; i++) {
    if (hash[i] != 0) {
      return false;
    }
  }
    
  return true;
}
