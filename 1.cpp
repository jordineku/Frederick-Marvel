#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  Node *next;
  int score;
}*head,*tail;

Node *CreateNode(int value){
  Node *temp= new Node;
  temp -> score = value;
  temp -> next = NULL;
  return temp;
}

void dorong(Node **skr_node, int value){
  Node *temp= CreateNode(value);
  temp -> next = *skr_node;
  *skr_node = temp;
}

void dorongujung(int value){
  Node *temp= CreateNode(value);
  if(tail ==NULL)
  {
    head = tail = temp;
  }
  else {
    tail -> next = temp;
    tail = temp;
  }
}
void tukeran(Node* node1, Node* node2) {
    Node* tempa = node1, * tempb = node2;
    while (temp1 && temp2) {
        if (tempa->score < tempb->score) {
            // push(temp2->nilai, final);
            dorongujung(tempa->score);
            tempa = tempa->next;
        }
        else {
            // push(temp1->nilai, final);
            dorongujung(tempb->score);
            tempb = tempb->next;
        }
    }
    while (tempa) {
        // push(temp1->nilai, final);
        dorongujung(tempa->score);
        tempa = tempa->next;
    }
    while (tempb) {
        // push(temp2->nilai, final);
        dorongujung(tempb->score);
        tempb = tempb->next;
    }
}

void printall(Node *skr_node){
  while(skr_node)
  {
    if(skr_node -> next ==NULL)
    {
      printf("%d\n",skr_node->score);
      skr_node= skr_node->next;
    }
    else{
      printf("%d --> ",skr_node->score);
      skr_node=skr_node-> next;

    }
  }
}

int main(){
  Node *x=NULL;
  Node *y =NULL;
  dorong(&x, 30);
  dorong(&x, 20);
  dorong(&x, 10);
  dorong(&x, 5);
  printall(x);
  dorong(&y,60);
  dorong(&y,55);
  dorong(&y,45);
  dorong(&y,35);
  printall(y);
  tukeran(x, y);
  printall(head);
  return 0; 
}
