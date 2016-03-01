bool isValid(char* s) {
  char stack[3000];
  int pos = 0;
    
  while(*s != '\0') {
    if (*s=='(' || *s=='{' || *s=='[') {
      stack[pos] = *s;
      pos++;
    } else {
      if (pos<1) return false; 
      pos--;
      if (*s==')' && stack[pos]!='(') return false;
      if (*s==']' && stack[pos]!='[') return false;
      if (*s=='}' && stack[pos]!='{') return false;
    }
    s++;
  }
  return pos == 0;
}
