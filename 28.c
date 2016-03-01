// 类似BM的简化算法
static int
generate(char* needle, int* table) {
  for (int j=0; j<256; j++) table[j] = -1;
  int i;
  for (i=0; needle[i]; i++) {
    char c = needle[i];
    table[c] = i;
  }
  return i;
}

int strStr(char* haystack, char* needle) {
  int table[256];
  int limit = strlen(haystack);
  int len = generate(needle, table);
    
  int ret = 0;
  while (ret+len <= limit) {
    int pos = len-1; // pos是在needle中的偏移
    while(pos>=0 && haystack[ret+pos] == needle[pos]) pos--; // pos是发生不匹配的位置
    if (pos < 0) return ret;
    char c = haystack[ret+pos]; // c是发生不匹配的位置的字符
        
    int forward;
    if (table[c]>pos) {
      // 特殊情况
      int j;
      for(j=pos-1; j>=0; j--) {
        if (needle[j]==c) break;
      }
      forward = pos - j;
    } else {
      forward = pos - table[c]; // 可前移量 = 发生不匹配的位置 - 不匹配字符在搜索词中上一出现位置
    }
    ret += forward;
  }
  return -1;
}
