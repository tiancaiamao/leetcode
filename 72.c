int minDistance(char* word1, char* word2) {
  int len1, len2, size;
  int *cache;
  int i, j, min, v1, v2;
    
  len1 = strlen(word1)+1;
  len2 = strlen(word2)+1;
    
  //    if (len1 == 1) return len2-1;
  //    if (len2 == 1) return len1-1;
        
  size = len1 * len2 * sizeof(int);
  cache = (int*)malloc(size);
  memset(cache, 0, size);
    
  for (i=0; i<len1; i++) {
    cache[i*len2+0] = i;
  }
  for (j=0; j<len2; j++) {
    cache[0*len2+j] = j;
  }
    
  for (i=1; i<len1; i++) {
    for (j=1; j<len2; j++) {
      min = cache[(i-1)*len2+(j-1)];
      if (word1[i-1]!=word2[j-1]) {
        min++;
      }
      v1 = cache[(i-1)*len2+j] + 1;
      v2 = cache[i*len2+j-1] + 1;
      min = min < v1 ? min : v1;
      min = min < v2 ? min : v2;
      cache[i*len2+j] = min;
    }
  }
  return cache[(len1-1)*len2+(len2-1)];
}
