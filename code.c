#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
struct node* deleteatstart(struct node* head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
   return head;
    
}
struct node* deleteatend(struct node* head){
    struct node *ptr=head;
    struct node *p=head->next;
   while(p->next !=NULL){
       ptr=ptr->next;
       p=p->next;
       
   }
   ptr->next=NULL;
     
    free(p);
    
   return head;
    
}
struct node* deleteatindex(struct node* head,int index){
    struct node *ptr=head;
    struct node* p=head->next;
  int  i=0;
  while(i!=index-1){
      ptr=ptr->next;
      p=p->next;
      i++;
  }
    ptr->next=p->next;
    free(p);
   return head;
    
}

struct node * insertatfirst(struct node *p,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=p;
    ptr->data=data;
    return ptr;
}
struct node *insertatindex(struct node *head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node * insertatend(struct node *head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
     struct node* p=head;
    int i=0;
    while(p->next!=NULL){
        p=p->next;
       
    }
    p->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
    
}
struct node * insertafternode(struct node *head,int data,struct node* index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
   
    ptr->next=index->next;
     index->next=ptr;
    ptr->data=data;
    return head;
    
    
    
}

int
main ()
{//creating nodes
  struct node *head;
  struct node *second;
  struct node *third; 
  //dynamic memory allocation from heap 
  head=(struct node*)malloc(sizeof(struct node));
  second=(struct node*)malloc(sizeof(struct node));
  third=(struct node*)malloc(sizeof(struct node));
  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 4;
  third->next = NULL;
  traversal(head);
  
  head=deleteatend(head);
  traversal(head);

  return 0;
}
