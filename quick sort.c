#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
}
// Partition function
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
if (arr[j] < pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
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
fptr = fopen("quicksort_times.csv", "w");
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
quickSort(arr, 0, n - 1);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
fprintf(fptr, "%d,%f\n", n, cpu_time_used);
free(arr);
}
fclose(fptr);
printf("Time data written to quicksort_times.csv\n");
return 0;
}