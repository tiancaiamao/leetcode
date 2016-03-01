int longestValidParentheses(char* s) {
  int len = strlen(s);
  if (len<=1) return 0;

  int match[len]; // 记录最长匹配的位置
  match[0] = -1;
  for (int i=1; i<len; i++) {
    if (s[i]=='(') {
      match[i] = -1;
      continue;
    }
        
    int pos = i-1;
    while(pos>=0) {
      if (s[pos]=='(') {
        if (pos>=1 && match[pos-1]!=-1) {
          match[i] = match[pos-1];
        } else {
          match[i] = pos;
        }
        break;
      }
            
      if (match[pos]==-1) {
        match[i] = -1;
        break;
      }
            
      pos = match[pos]-1;
    }
    if (pos<0) match[i] = -1;
  }
    
  int ret = 0;
  for (int i=0; i<len; i++) {
    //        printf("%d ", match[i]);
    if (match[i]>=0 && i-match[i]+1>ret) {
      ret = i-match[i]+1;
    }
  }
  printf("\n");
    
  return ret;
}
