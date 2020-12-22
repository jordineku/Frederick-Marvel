#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  int score;
  Node *next;
}*head,*tail;

Node *CreateNode(int data){
  Node *temp=(Node*)malloc(sizeof(Node));
  temp->score= data;
  temp->next=NULL;
  return temp;
}

void push(int value, Node **skr_nd){
  Node *temp=CreateNode(value);
  temp->next= *skr_nd;
  *skr_nd=temp;
}

void FindPrint(Node *head, int n){
  int lent=0;
  Node *temp =head;
  while(temp!=NULL)
  {
    temp=temp->next;
    lent++;
  }
  if(lent<n) return;
  temp=head;
  for(int i=1;i<lent-n+1;i++)
  {
    temp=temp->next;
  }
  printf("%d\n",temp->score);
}


int main(){
Node *a=NULL;
push(20, &a);
push(40,&a);
push(30,&a);
push(50,&a);
FindPrint(a, 3);
  return 0;
}
