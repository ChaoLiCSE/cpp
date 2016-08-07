#include <iostream>
using namespace std;


struct vertex {
   int id;
   int weight;
   struct vertex *next;
};

/*
 * graph, represented by adjacency list
 */
class Graph {
   private:
      int v;
      struct vertex *list;

   public:
      Graph(int v) {
         this->v = v;
         list = new vertex [v];
         for(int i = 0; i < v; i++) {
            list[i].id = i;
            list[i].next = NULL;
         }
      }
      ~Graph() {
         for(int i = 0; i < v; i++) {
            vertex *p = list[i].next;
            vertex *q = p;
            while(p) {
               q = p->next;
               delete p;
               p = q;
            }
         }
         delete[] list;
      }

      /*
       * insert unweighted edge, default value := 1
       */
      void addEdge(int src, int dst) {
         addEdge(src, dst, 1);
      }
      /*
       * insert weighted edge
       */
      void addEdge(int src, int dst, int weight) {
         if(src > v || dst > v || src < 0 || dst < 0) {
            cout << "[Error]: invalid edge" << endl;
         }
         else {
            vertex *v1 = new vertex;
            v1->weight = weight;
            v1->id = dst;
            v1->next = list[src].next;
            list[src].next = v1;

            vertex *v2 = new vertex;
            v2->weight = weight;
            v2->id = src;
            v2->next = list[dst].next;
            list[dst].next = v2;
         }
      }

      vertex * neighbors(int src) {
         if(src < 0 || src > v-1) {
            return NULL;
         }
         return list[src].next;
      }

      /*
       * print graph without weights
       */
      void printGraph() {
         for(int n = 0; n < v; n++) {
            vertex *p = list[n].next;
            cout << "Adjacency list of vertex [" << n << "]:";
            while(p) {
               cout << " -> " << p->id << "(" << p->weight << ")";
               p = p->next; 
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

   cout << "Vertex 0's neighbors: ";
   vertex *p = graph.neighbors(0);
   while(p) {
      cout << " -> " << p->id;
      p = p->next;
   }

   cout << "\nVertex 1's neighbors: "; 
   p = graph.neighbors(1);
   while(p) {
      cout << " -> " << p->id;
      p = p->next;
   }
   return 0;
}