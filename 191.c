int hammingWeight(uint32_t n) {
  int i, ret;
  ret = 0;
  for (i=0; i<32; i++) {
    if (((n >> i) & 1) != 0) {
      ret++;
    }
  }
  return ret;
}
