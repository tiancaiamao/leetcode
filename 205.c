bool isIsomorphic(char* s, char* t) {
  char table[256];
  bool unique[256];
  memset(&table, 0, 256);
  memset(&unique, 0, 256);
    
  while(*s!='\0') {
    if (table[*s] == '\0') {
      if (unique[*t]!=false) return false;
      table[*s] = *t;
      unique[*t] = true;
    } else {
      if (table[*s] != *t) return false;
    }
    s++;
    t++;
  }
  return true;
}
