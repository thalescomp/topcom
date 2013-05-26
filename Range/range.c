#include <stdio.h>

int r[50010];
int mm[50010][18]; // or n and log(n) +1

#define max(a,b) ((a) > (b)) ? a : b

void construct(int n)
{
  int i, j, b;
  for (i = 0; i < n; i++) mm[i][0]=r[i];

  for (i = 1; i < 18; i++) {
    for (j = 0; (j + (1<<i) - 1) < n; j += (1<<i))
      mm[j][i] = max(mm[j][i - 1], mm[j + (1<<(i - 1))][i - 1]);
  }
}

int getmax(int a, int b)
{
  int i;
  if (a > b) return -1;
  for (i = 17; i >= 0; i--) {
    if ((a % (1<<i)) == 0 && (a + (1<<i) - 1) <= b)
      return max(mm[a][i], getmax(a + (1<<i), b));
  }
}

int main()
{
  int n, m, i, a, b;
  while (1) {
    scanf ("%d ", &n);
    if (!n) break;
    for (i = 0; i < n; i++) {
      scanf ("%d ", &r[i]);
    }
    construct(n);
    scanf ("%d ", &m);
    for (i = 0; i < m; i++) {
      scanf ("%d %d ", &a, &b);
      printf ("%d\n", getmax(a, b));
    }
  }
  return 0;
}
