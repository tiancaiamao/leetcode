char* convert(char* s, int numRows) {
  if(numRows == 1) return s;
  int len = strlen(s);
  int interval = 2*numRows-2;

  char *res = malloc(len+1);
  res[len] = '\0';
        
  int k = 0;
  for(int i=0; i<len ; i+=interval)//处理第一行
    res[k++] = s[i];
  for(int i=1; i<numRows-1; i++) {//处理中间行
    int inter = i*2;
    for(int j=i; j<len; j+=inter) {
      res[k++] = s[j];
      inter = interval - inter;
    }
  }
  for(int i=numRows-1; i<len ; i+=interval)//处理最后一行
    res[k++] = s[i];
  return res;
}
