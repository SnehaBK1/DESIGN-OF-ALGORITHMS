#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to merge two subarrays
void merge(int arr[], int l, int m, int r) {
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
}
// Function to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
// Function to generate an array of random integers
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 10000; // Generating random integers between 0 and 9999
}
}
int main() {
FILE *fptr;
fptr = fopen("mergesort_times.csv", "w");
if (fptr == NULL) {
printf("Error opening file!\n");
return 1;
}
fprintf(fptr, "n,TimeTaken\n");
for (int n = 5000; n <= 50000; n += 5000) {
int* arr = (int*)malloc(n * sizeof(int));
generateRandomArray(arr, n);
clock_t start, end;
double cpu_time_used;
start = clock();
mergeSort(arr, 0, n - 1);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
fprintf(fptr, "%d,%f\n", n, cpu_time_used);
free(arr);
}
fclose(fptr);
printf("Time data written to mergesort_times.csv\n");
return 0;
}