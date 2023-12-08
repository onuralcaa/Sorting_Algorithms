#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct lnode {
    int data;
    lnode* next;
};

lnode* iter = NULL;


void push(int data){
     if(iter==NULL){
                   // printf("yeni node bos stack");
                    iter = (lnode * ) malloc(sizeof(lnode));
                    iter->next=NULL;
     }
    // printf("yeni node dolu stack");
     iter->data = data;
     lnode * yeni = (lnode * )malloc(sizeof(lnode));
     yeni->next = iter;
     iter=yeni;
}
int pop(){
    if(iter->next==NULL)
                  return -1;
 int result = iter->next->data;
 lnode *temp = iter;
 iter=iter->next;
 free(temp);
 return result;   
}
void printStack(){
     printf("\n");
     lnode *temp = iter;
     while(temp!=NULL){
                       printf("%d _ ",temp->data);
                       temp=temp->next;
     }
}
int main(){
 push(10);
 printStack();
 push(20);
  printStack();
  push(30);
   printStack();
   printf("\npop> %d",pop());
     printStack();
      printf("\npop> %d",pop());
        printStack();
       // push(50);
        printStack();
         printf("\npop> %d",pop());
           printStack();
            printf("\npop> %d",pop());
              printStack();
  getch();
  
  return 0;
    
    
}
