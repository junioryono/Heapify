// Name: Amer Yono
// Student ID: 200711334
// Email: yono004@cougars.csusm.edu

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int *heap = new int(0);
int heapSize = -1;

void swap(int &x, int &y) {
   int temp = x;
   x = y;
   y = temp;
}
 
void siftUp(int i) {
   while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
      swap(heap[(i - 1) / 2], heap[i]);
      i = (i - 1) / 2;
   }
}
 
void siftDown(int i) {
   int index = i;
   if ((2 * i) + 1 <= heapSize && heap[(2 * i) + 1] > heap[index]) index = (2 * i) + 1;
   if ((2 * i) + 2 <= heapSize && heap[(2 * i) + 2] > heap[index]) index = (2 * i) + 2;
   if (i != index) {
      swap(heap[i], heap[index]);
      siftDown(index);
   }
}
 
void insert(int p) {
   heapSize = heapSize + 1;
   heap[heapSize] = p;
   siftUp(heapSize);
}

int extractMax() {
   int max = heap[0];
   heap[0] = heap[heapSize];
   heapSize = heapSize - 1;
   siftDown(0);
   return max;
}

int removeAt(int i) {
   heap[i] = heap[0] + 1;
   siftUp(i);
   extractMax();
   return 0;
}

void heapify(int A[], int len) {
   for (int i = 0; i < len; i++) insert(A[i]);
}

void heapSort(int A[], int len) {
   for (int i = 1; i < len; i++) {
        int shift = A[i];
        int pivot = i - 1;
        while (pivot >= 0 && A[pivot] > shift) {
            A[pivot + 1] = A[pivot];
            pivot = pivot - 1;
        }
        A[pivot + 1] = shift;
   }
}

void print(int A[], int len) {
    for (int i = 0; i < len; i++)
        if (i == len - 1) cout << A[i] << "\n";
        else cout << A[i] << ", ";
}

int main() {
   // Create Array
   int arr[] = {4,17,3,12,9,6};
   int len = sizeof(arr) / sizeof(arr[0]);

   // Original Array
   cout << "Original Array: ";
   print(arr, len);

   // Sorted Array
   heapSort(arr, len);
   cout << "Sorted Array: ";
   print(arr, len);

   // Create Max Heap From Array
   heapify(arr, len);
   cout << "Max Heap: ";
   print(heap, heapSize);

   // Extract Max Priority
   cout << "Max Priority: " << extractMax() << "\n";
 
   // Max Heap After Extracting Max Priority
   cout << "Max Heap After Extracting Max Priority: ";
   print(heap, heapSize);

   return 0;
}