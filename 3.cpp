#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  int score;
  struct Node *next;
}*head, *tail;

Node *CreateNode(int value){
  Node *temp= new Node;
  temp -> score = value;
  temp -> next = NULL;
  return temp;
}

// void dorong(Node **skr_node, int value){
//   Node *temp= CreateNode(value);
//   temp -> next = *skr_node;
//   *skr_node = temp;
// }
void dorong(Node **skr_node, int data){
  Node *temp= new Node;
  temp->score=data;
  temp->next=(*skr_node);
  (*skr_node)=temp;
}

void PrintTengah(Node *head){
  Node *sl_ptr=head;
  Node *fs_ptr=head;
  if(head!=NULL)
  {
    while(fs_ptr!=NULL && fs_ptr->next != NULL)
    {
      sl_ptr=sl_ptr-> next;
      fs_ptr=fs_ptr-> next->next;
    }
    printf("Middle: %d\n",sl_ptr->score);
  }
  else return;
}

int main(){
  Node *a=NULL;
 for(int i=5;i>0;i--)
 {
   dorong(&a, i);

 }
  PrintTengah(a);
  return 0;
}
