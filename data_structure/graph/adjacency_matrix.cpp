#include <iostream>
using namespace std;


/*
 * graph, represented by adjacency matrix
 */
class Graph {

   private:
      int n;
      int **matrix;

   public:
      /*
       * create n-by-n matrix, assume n is positive
       */
      Graph(int n) {
         this->n = n;
         matrix = new int* [n];
         for(int i = 0; i < n; i++) {
            matrix[i] = new int [n];
            for(int j = 0; j < n; j++) {
               matrix[i][j] = 0;
            }
         }
      }
      ~Graph() {
         for(int i = 0; i < n; i++) {
               delete[] matrix[i];
         }
         delete[] matrix;
      }
      /*
       * insert unweighted edge
       */
      void addEdge(int src, int dst) {
         addEdge(src, dst, 1);
      }
      /*
       * insert weighted edge
       */
      void addEdge(int src, int dst, int weight) {
         if(src > n || dst > n || src < 0 || dst < 0) {
            cout << "[Error]: invalid edge" << endl;
         }
         else {
            matrix[src][dst] = weight;
         }  
      }
      /*
       * print graph
       */
      void printGraph() {
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
               cout << matrix[i][j] << ' ';
            }
            cout << endl;
         }
      }
};


int main(int argc, char *argv[]) {
   Graph graph(5);

   graph.addEdge(0, 1);
   graph.addEdge(0, 4, 2);
   graph.addEdge(1, 2, 3);
   graph.addEdge(1, 3, 4);
   graph.addEdge(1, 4, 5);
   graph.addEdge(2, 3, 6);
   graph.addEdge(3, 4, 7);

   graph.printGraph();
   return 0;
}