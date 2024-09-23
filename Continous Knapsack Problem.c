#include <stdio.h>
int main() {
float weight[50], profit[50], ratio[50], Totalvalue = 0.0, temp, capacity;
int n, i, j;
// Read the number of items
printf("Enter the number of items: ");
scanf("%d", &n);
// Read the weight and profit of each item
for (i = 0; i < n; i++) {
printf("Enter Weight and Profit for item[%d]: ", i);
scanf("%f %f", &weight[i], &profit[i]);
}
// Read the capacity of the knapsack
printf("Enter the capacity of knapsack: ");
scanf("%f", &capacity);
// Calculate the ratio (profit/weight)
for each item
for (i = 0; i < n; i++) {
ratio[i] = profit[i] / weight[i];
}
// Sort the items based on the ratio in descending order
for (i = 0; i < n - 1; i++) {
for (j = i + 1; j < n; j++) {
if (ratio[i] < ratio[j]) {
// Swap ratios
temp = ratio[j];
ratio[j] = ratio[i];
ratio[i] = temp;
// Swap weights
temp = weight[j];
weight[j] = weight[i];
weight[i] = temp;
// Swap profits
temp = profit[j];
profit[j] = profit[i];
profit[i] = temp;
}
}
}
// Calculate the maximum value that can be carried
printf("Knapsack problems using Greedy Algorithm:\n");
for (i = 0; i < n; i++) {
if (weight[i] > capacity)
break;
else {
Totalvalue += profit[i];
capacity -= weight[i];
}
}
// If there's still capacity left, take the fraction of the next item
if (i < n) {
Totalvalue += ratio[i] * capacity;
}
printf("\nThe maximum value is: %.2f\n", Totalvalue);
return 0;
}