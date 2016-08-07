#include <iostream>
using namespace std;


/*
 * QuickSort
 *
 *    1. Pick an element, called a pivot, from the array.
 *    2. Partitioning: reorder the array so that all elements with values less
 *       than the pivot come before the pivot, while all elements with values
 *       greater than the pivot come after it (equal values can go either way).
 *       After this partitioning, the pivot is in its final position. This is 
 *       called the partition operation.
 *    3. Recursively apply the above steps to the sub-array of elements with 
 *       smaller values and separately to the sub-array of elements with greater
 *       values.
 *
 */
class QuickSort {

   private:
      /*
       * sort left and right array partitioned by j-th position
       */
      static void sort(int *a, int lo, int hi) {
         if(hi <= lo) {
            return;
         }
         int j = partition(a, lo, hi); // j-th position is sorted
         sort(a, lo, j-1);    // sort left
         sort(a, j+1, hi);    // sort right
      }

      /*
       * partition the subarray a[lo..hi] so that 
       * a[lo..j-1] <= a[j] <= a[j+1..hi] and return the index j.
       */
      static int partition(int *a, int lo, int hi) {
         int i = lo;
         int j = hi + 1;
         int v = a[0];
         while(true) {
            // find item on lo to swap
            while(a[++i] < v) {
               if(i == hi) {
                  break;
               }
            }
            // find item on hi to swap
            while(v < a[--j]) {
               if(j == lo) {
                  break;
               }
            }
            if(i >= j) {
               break;
            }

            exch(a, i, j);
         }

         // put partitioning item v at a[j]
         exch(a, lo, j);

         // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
         return j;
      }

      static void exch(int *a, int i, int j) {
         int tmp = a[i];
         a[i] = a[j];
         a[j] = tmp;
      }

   public:
      static void sort(int *a, int len) {
         sort(a, 0, len-1);
      }
};



int main(int argc, char * argv[]) {
   int arr[10] = {10,11,8,-12,6,5,-99,3,0,13};
   cout << "before: ";
   for(int i = 0; i < 10; i++) {
      cout << arr[i] << ' ';
   }   
   QuickSort::sort(arr, 10);
   cout << "\nafter:  ";
   for(int i = 0; i < 10; i++) {
      cout << arr[i] << ' ';
   }   

   return 0;
}