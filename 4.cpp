#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  int score;
  Node *next;
}*head, *tail;

Node *CreateNode(int data){
  Node *temp=(Node*)malloc(sizeof(Node));
  temp->score=data;
  temp->next=NULL;
  return temp;
}

void push(int value, Node** curr_node) {
    Node* temp = CreateNode(value);
    temp->next = *curr_node;
    *curr_node = temp;
}

void Nicole(Node *h){
  Node *flag1; Node *flag2; Node *duple;
  flag1=h;
  while(flag1!=NULL && flag1->next!=NULL)
  {
    flag2=flag1;
    while(flag2->next !=NULL)
    {
      if(flag1->score != flag2->next->score)
      {
        flag2=flag2->next;
      }
      else{
        duple=flag2->next;
        flag2->next=flag2->next->next;
        delete (duple);
      }
    }
    flag1=flag1->next;
  }
}

void printall(Node *x){
  while(x!=NULL)
  {
    printf("%d\n",x->score);
    x=x->next;
  }
}

int main(){
  Node *a=NULL;
  push(20, &a);
  push(20, &a);
  push(20, &a);
  push(30, &a);
  push(30, &a);
  push(30, &a);
  push(30, &a);
  push(40, &a);
  push(40, &a);
printall(a);
Nicole(a);
puts("");
printall(a);
  return 0;
}
