#include <stdio.h>
#include <stdbool.h>
void printSubset(int set[], int subset[], int size) {
printf("Found a subset with the given sum: { ");
for (int i = 0; i < size; i++) {
printf("%d ", subset[i]);
}
printf("}\n");
}
void printTable(bool subset[][10], int n, int sum) {
printf(" ");
for (int j = 0; j <= sum; j++) {
printf("%4d", j);
}
printf("\n -------------------------------------\n");
for (int i = 1; i <= n; i++) { // Start from 1 since row 0 is removed
printf("%2d |", i);
for (int j = 0; j <= sum; j++) {
printf("%4s", subset[i][j] ? "T" : "F");
}
printf("\n");
}
printf("\n");
}
int main() {
int set[] = {3, 34, 4, 12, 5, 2};
int sum = 9;
int n = sizeof(set) / sizeof(set[0]);
bool subset[n + 1][sum + 1];
// Initialize the subset table
for (int i = 0; i <= n; i++) { // Include row 0
subset[i][0] = true;
}
for (int i = 1; i <= sum; i++) {
subset[0][i] = false;
}
// Fill the subset table iteratively
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= sum; j++) {
if (j < set[i - 1]) {
subset[i][j] = subset[i - 1][j];
} else {
subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
}
}
printf("After including element %d (set[%d]):\n", set[i - 1], i - 1);
printTable(subset, n, sum);
}
if (!subset[n][sum]) {
printf("No subset with the given sum\n");
return 0;
}
// Find and print the subset with steps
int foundSubset[n];
int size = 0;
int i = n, j = sum;
printf("Building the subset iteratively:\n");
while (i > 0 && j > 0) {
if (subset[i][j] && !subset[i - 1][j]) {
foundSubset[size++] = set[i - 1];
printf("Added %d to subset, new subset: { ", set[i - 1]);
for (int k = 0; k < size; k++) {
printf("%d ", foundSubset[k]);
}
printf("}\n");
j -= set[i - 1];
}
i--;
}
printSubset(set, foundSubset, size);
return 0;
}
