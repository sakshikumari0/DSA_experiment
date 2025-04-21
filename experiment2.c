#include <stdio.h>
 

 int linearSearch(int arr[], int n, int key) {
     for(int i = 0; i < n; i++) {
         if(arr[i] == key)
             return i;
     }
     return -1;
 }
 
 // Function for Binary Search (array must be sorted)
 int binarySearch(int arr[], int n, int key) {
     int low = 0, high = n - 1;
 
     while(low <= high) {
         int mid = (low + high) / 2;
 
         if(arr[mid] == key)
             return mid;
         else if(arr[mid] < key)
             low = mid + 1;
         else
             high = mid - 1;
     }
     return -1;
 }
 
 // Function to sort the array for binary search
 void sortArray(int arr[], int n) {
     for(int i = 0; i < n-1; i++) {
         for(int j = 0; j < n-i-1; j++) {
             if(arr[j] > arr[j+1]) {
                 // Swap
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
 }
 
 int main() {
     int arr[100], n, choice, key, result;
 
     printf("Enter the number of elements in the array: ");
     scanf("%d", &n);
 
     printf("Enter %d elements:\n", n);
     for(int i = 0; i < n; i++) {
         scanf("%d", &arr[i]);
     }
 
     printf("Enter the value to search: ");
     scanf("%d", &key);
 
     printf("\nChoose Search Method:\n");
     printf("1. Linear Search\n");
     printf("2. Binary Search (Array will be sorted)\n");
     printf("Enter your choice (1 or 2): ");
     scanf("%d", &choice);
 
     switch(choice) {
         case 1:
             result = linearSearch(arr, n, key);
             break;
         case 2:
             sortArray(arr, n);
             result = binarySearch(arr, n, key);
             break;
         default:
             printf("Invalid choice!\n");
             return 1;
     }
 
     if(result != -1)
         printf("Value %d found at index %d (0-based indexing).\n", key, result);
     else
         printf("Value %d not found in the array.\n", key);
 
     return 0;
 }
