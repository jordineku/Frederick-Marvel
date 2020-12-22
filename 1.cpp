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
    Node* temp1 = node1, * temp2 = node2;
    while (temp1 && temp2) {
        if (temp1->score < temp2->score) {
            // push(temp2->nilai, final);
            dorongujung(temp1->score);
            temp1 = temp1->next;
        }
        else {
            // push(temp1->nilai, final);
            dorongujung(temp2->score);
            temp2 = temp2->next;
        }
    }
    while (temp1) {
        // push(temp1->nilai, final);
        dorongujung(temp1->score);
        temp1 = temp1->next;
    }
    while (temp2) {
        // push(temp2->nilai, final);
        dorongujung(temp2->score);
        temp2 = temp2->next;
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
