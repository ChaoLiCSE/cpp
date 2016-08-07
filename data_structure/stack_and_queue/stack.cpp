#include <iostream>
using namespace std;

struct elmt {
   int val;
   elmt *next;
};

/*
 * Stack, element node implementation
 */
class Stack {

   private:
      elmt *top;

   public:
      Stack() {
         top = NULL;
      }
      ~Stack() {
         elmt *p;
         while(top) {
            p = top;
            top = top->next;
            delete p;
         }
      }

      void push(int i) {
         elmt *e = new elmt;
         e->val  = i;
         e->next = top;
         top = e;
      }

      elmt* pop() {
         if(top == NULL) {
            return NULL;
         }

         elmt *e = top;
         top = top->next;
         e->next = NULL;
         return e;
      }

      elmt* peek() {
         elmt *e = new elmt;
         e->val = top->val;
         e->next = NULL;
         return e;
      }

      bool isEmpty() {
         return top == NULL;
      }
};


int main(int argc, char *arcv[]) {

   Stack stack;

   for(int i = 0; i < 20; i += 2) {
      stack.push(i);
      
      elmt *e = stack.peek();
      cout << "stack.peek(): [" << e->val << "]" << endl;
      delete e;
   }
   cout << endl;

   while(!stack.isEmpty()) {
      elmt *e = stack.pop();
      cout << "stack.pop(): [" << e->val << "]" << endl;
      delete e;  
   }

   return 0;
}


