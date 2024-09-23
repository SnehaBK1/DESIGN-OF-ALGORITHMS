#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateRandomNumbersToFile(int n, const char *filename) {
FILE *file = fopen(filename, "w");
if (file == NULL) {
printf("Error opening file!\n");
return;
}
srand(time(NULL)); // Seed the random number generator
for (int i = 0; i < n; i++) {
int randomNumber = rand() % 10000; // Generate a random number between 0 and
9999
fprintf(file, "%d\n", randomNumber);
}
fclose(file);
printf("%d random numbers have been written to %s\n", n, filename);
}
int main() {
int n;
printf("Enter the number of random numbers to generate (n > 5000): ");
scanf("%d", &n);
if (n <= 5000) {
printf("Please enter a value greater than 5000.\n");
return 1;
}
generateRandomNumbersToFile(n,
"random_numbers.txt");
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform selection sort
void selectionSort(int arr[], int n) {
int i, j, minIdx, temp;
for (i = 0; i < n - 1; i++) {
minIdx = i;
for (j = i + 1; j < n; j++) {
if (arr[j] < arr[minIdx])
minIdx = j;
}
// Swap the found minimum element with the first element
temp = arr[minIdx];
arr[minIdx] = arr[i];
arr[i] = temp;
}
}
// Function to generate random array
void generateRandomArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
}
}
// Function to read array from a file
void readArrayFromFile(int arr[], int n, const char *filename) {
FILE *file = fopen(filename, "r");
for (int i = 0; i < n; i++) {
fscanf(file, "%d", &arr[i]);
}
fclose(file);
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
// Choose to generate random array or read from file
int choice;
printf("Enter 1 to generate random array, 2 to read from file: ");
scanf("%d", &choice);
if (choice == 1) {
generateRandomArray(arr, n);
} else if (choice == 2) {
readArrayFromFile(arr, n, "random_numbers.txt");
} else {
printf("Invalid choice\n");
return 1;
}
// Measure the time taken by selection sort
clock_t start, end;
double cpu_time_used;
start = clock();
selectionSort(arr, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
return 0;
}