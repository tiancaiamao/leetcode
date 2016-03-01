int maxProfit(int* prices, int pricesSize) {
  int i, min, profit;

  profit = 0;
  min = prices[0];
  for (i=1; i<pricesSize; i++) {
    if (prices[i] < min) {
      min = prices[i];
    }
    if (prices[i] - min > profit) {
      profit = prices[i] - min;
    }
  }
  return profit;
}
