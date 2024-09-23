#include <stdio.h>
// Function to return the maximum of two integers
int max(int a, int b) {
return (a > b) ? a : b;
}
// Function to solve the 0/1 Knapsack problem
void knapsack(int W, int wt[], int val[], int n) {
int i, w;
int K[n + 1][W + 1];
// Build table K[][] in bottom up manner
for (i = 0; i <= n; i++) {
for (w = 0; w <= W; w++) {
if (i == 0 || w == 0) {
K[i][w] = 0;
} else if (wt[i - 1] <= w) {
K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
} else {
K[i][w] = K[i - 1][w];
}
}
}
// Print the table K
printf("KnapSack Table:\n");
for (i = 0; i <= n; i++) {
for (w = 0; w <= W; w++) {
printf("%d\t", K[i][w]);
}
printf("\n");
}
// Print the result
printf("Maximum value that can be obtained: %d\n", K[n][W]);
// To find which items are included
int res = K[n][W];
w = W;
printf("Items included:\n");
for (i = n; i > 0 && res > 0; i--) {
if (res == K[i - 1][w])
continue;
else {
printf("Item %d (Weight: %d, Value: %d)\n", i, wt[i - 1], val[i - 1]);
res = res - val[i - 1];
w = w - wt[i - 1];
}
}
}
int main() {
int n, W;
printf("Enter the number of items: ");
scanf("%d", &n);
int val[n], wt[n];
printf("Enter the values of the items:\n");
for (int i = 0; i < n; i++) {
printf("Value of item %d: ", i + 1);
scanf("%d", &val[i]);
}
printf("Enter the weights of the items:\n");
for (int i = 0; i < n; i++) {
printf("Weight of item %d: ", i + 1);
scanf("%d", &wt[i]);
}
printf("Enter the maximum capacity of the knapsack: ");
scanf("%d", &W);
knapsack(W, wt, val, n);
return 0;
}