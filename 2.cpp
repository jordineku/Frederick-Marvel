#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
int data;
Node *next;
int tanda;

}*head, *tail;

void dorong(struct Node  **scr_node, int baru){
    struct Node *temp= (Node*)malloc(sizeof(Node));
    temp->data= baru;
    temp->tanda=0;
    temp->next=(*scr_node);
    (*scr_node)=temp;
}


bool LoopGaLoop(Node *h)
{
    while (h!=NULL)
    {
        if(h->tanda==1) return true;
        h->tanda=1;
        h=h->next;
    }
    
}

int main(){
 Node* a = NULL;
 
    dorong(&a, 15);
    dorong(&a, 23);
    dorong(&a, 40);
    dorong(&a, 50);  

    head->next->next->next->next = head;
 
    return 0;
}
