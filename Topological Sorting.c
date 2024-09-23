#include <stdio.h>
#define MAX 10
// Function prototype for the topological sort function
void fnTopological(int a[MAX][MAX], int n);
int main(void) {
int n = 6; // Number of vertices
// Predefined adjacency matrix for the graph
int a[MAX][MAX] = {
{0, 1, 1, 0, 0, 0},
{0, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0}
};
printf("Topological Sorting Algorithm -\n");
// Call the topological sorting function
fnTopological(a, n);
printf("\n");
return 0;
}
void fnTopological(int a[MAX][MAX], int n) {
int in[MAX] = {0}; // Array to store in-degrees of vertices
int out[MAX]; // Array to store the topological order of vertices
int stack[MAX]; // Stack to store vertices with in-degree zero
int top = -1; // Stack top pointer
int i, j, k = 0; // Loop counters
// Step 1: Calculate in-degree of each vertex
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
if (a[j][i] == 1) { // There is an edge from j to i
in[i]++; // Increment in-degree of vertex i
}
}
}
// Step 2: Perform topological sorting
while (1) {
// Find all vertices with in-degree zero
for (i = 0; i < n; i++) {
if (in[i] == 0) { // Vertex i has in-degree zero
stack[++top] = i; // Push vertex i onto the stack
in[i] = -1; // Mark vertex i as visited
}
}
if (top == -1) // Check if the stack is empty
break;
out[k] = stack[top--]; // Pop a vertex from the stack and add it to the
topological order
// Decrease in-degree of all adjacent vertices of the popped vertex
for (i = 0; i < n; i++) {
if (a[out[k]][i] == 1) { // There
is an edge from out[k] to i
in[i]--; // Decrement in-degree of vertex i
}
}
k++; // Move to the next position in the topological order array
}
// Step 3: Print the topological order
printf("Topological Sorting (JOB SEQUENCE) is:- \n");
for (i = 0; i < k; i++)
printf("%d ", out[i]);
printf("\n");
}