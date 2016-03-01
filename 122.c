int maxProfit(int* prices, int pricesSize) {
  int i, sum;
  for(i=pricesSize-1; i>0; i--) {
    prices[i] = prices[i] - prices[i-1];
  }
  sum = 0;
  for(i=1; i<pricesSize; i++) {
    if (prices[i] > 0) {
      sum += prices[i];
    }
  }
  return sum;
}
