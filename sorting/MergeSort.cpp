#include <iostream>
using namespace std;

/*
 * MergeSort
 * 
 *    1. Divide the unsorted list into n sublists, each containing 1 element 
 *       (a list of 1 element is considered sorted).
 *    2. Repeatedly merge sublists to produce new sorted sublists until there
 *       is only 1 sublist remaining. This will be the sorted list.
 *
 */
class MergeSort {
   private:
      /*
       * split array in half
       */
      static void sort(int *a, int *aux, int lo, int hi) {
         if(hi - lo <= 1)
            return;
         
         int mid = lo + (hi-lo)/2;
         
         sort(a, aux, lo, mid);
         sort(a, aux, mid, hi);
         merge(a, aux, lo, mid, hi);
      }

      /*
       * bottom up sort
       */
      static void merge(int *a, int *aux, int lo, int mid, int hi) {
         int i = lo, j = mid;
         for(int k = lo; k < hi; k++) {
            if     (i == mid)       aux[k] = a[j++];  // left arr done
            else if(j == hi)        aux[k] = a[i++];  // right arr done
            else if(a[j] < a[i])    aux[k] = a[j++];  // left smaller
            else                    aux[k] = a[i++];  // right smaller
         }

         // merge
         for(int k = lo; k < hi; k++) {
            a[k] = aux[k];
         }
      }

   public:
      /*
       * static method for merge sort
       *    need explicit length because you cannot length from a pointer e.g.
       *    length = sizeof(list) / sizeof(list[0]) does not work
       */
      static void sort(int *a, int len) {
         int *aux = new int [len];
         sort(a, aux, 0, len);
         delete [] aux;
      }
};

int main(int argc, char * argv[]) {
   int arr[10] = {10,11,8,-12,6,5,-99,3,0,13};
   cout << "before: ";
   for(int i = 0; i < 10; i++) {
      cout << arr[i] << ' ';
   }   
   MergeSort::sort(arr, 10);
   cout << "\nafter:  ";
   for(int i = 0; i < 10; i++) {
      cout << arr[i] << ' ';
   }   

   return 0;
}