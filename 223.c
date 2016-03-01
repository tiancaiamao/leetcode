int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int sub;
  if (A>=G || C<=E || F>=D || H<=B) {
    sub = 0;
  } else {
    int t1 = A>E ? A:E;
    int t2 = C<G ? C:G;    
    int width = t2-t1;
    t1 = B>F ? B:F;
    t2 = D<H ? D:H;
    int height = t2-t1;
    sub = width*height;
  }
    
  return (C-A)*(D-B) + (G-E)*(H-F) - sub;
}
