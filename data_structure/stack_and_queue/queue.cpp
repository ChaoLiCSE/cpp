#include <iostream>
using namespace std;


struct elmt {
   int val;
   elmt *next;
};

/*
 * Queue, element node implementation
 */
class Queue {
   private:
      elmt *head, *tail;

   public:
      Queue() {
         head = tail = NULL;
      }
      ~Queue() {
         elmt *p;
         while(head) {
            p = head;
            head = head->next;
            delete p;
         }
      }

      void enqueue(int val) {
         elmt *e = new elmt;
         e->val = val;
         e->next = NULL;
         if(head == NULL) {
            head = tail = e;
         }
         else {
            tail->next = e;
            tail = e;
         }
      }

      elmt* dequeue() {
         if(head == NULL) {
            return NULL;
         }

         elmt *e = head;
         if(head == tail) {
            head = tail = NULL;
         }
         else {
            head = head->next;
         }
         return e;
      }

      bool isEmpty() {
         return head == NULL;
      }
};

int main(int argc, char *argv[]) {

   Queue queue;

   for(int i = 0; i < 20; i += 2) {
      cout << "queue.enqueue(" << i << ")" << endl;
      queue.enqueue(i);
   }
   cout << endl;
   
   while(!queue.isEmpty()) {
      elmt *e = queue.dequeue();
      cout << "queue.dequeue(): [" << e->val << "]" << endl;
      delete e;  
   }

   return 0;
}