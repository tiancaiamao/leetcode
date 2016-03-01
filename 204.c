int countPrimes(int n) {
  bool *map = malloc(n);
  memset(map, 0, n);
    
  int ret = 0;
  for (int i=2; i<n; i++) {
    if (map[i]==false) {
      ret++;
      for (int j=2; i*j<n; j++) {
        map[i*j] = true;
      }
    }
  }
  return ret;
}
