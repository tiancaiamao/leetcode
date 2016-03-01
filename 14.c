char* longestCommonPrefix(char** strs, int strsSize) {
  char *ret;
  int i, j, pos;

  if (strsSize == 0) {
    pos = 0;
    goto out;
  }

  pos = 0;
  for (j=0; ;j++) {
    for (i=0; i<strsSize; i++) {
      if (strs[i][j] == '\0' || strs[i][j] != strs[0][j]) {
        pos = j;
        goto out;
      }
    }
  }
 out:
  ret = malloc(pos+1);
  for (i=0; i<pos; i++) {
    ret[i] = strs[0][i];
  }
  ret[pos] = '\0';
  return ret;
}
