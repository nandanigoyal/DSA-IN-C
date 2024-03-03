#include <stdio.h>
#include <stdlib.h>
struct node*head;
struct node
{
    struct node*pre;
    int data;
    struct node*next;
};
struct node*head;
struct node*adding_node(struct node*head)
{
    struct node*new_node;
    struct node*ptr1=head;
    //making new node....
    new_node=malloc(sizeof(struct node));
    new_node->pre=NULL;
    printf("enter the value to insert");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=new_node;
    new_node->pre=ptr1;
    ptr1=new_node;
    return new_node;
}

void adding_node_atbeg(struct node** head)
{   struct node*new_head;
  new_head=malloc(sizeof(struct node));
    printf("enter the value to enter at beginning");
    scanf("%d",&new_head->data);
    new_head->pre=NULL;
    new_head->next = *head;
    (*head)->pre = new_head;
    *head= new_head;
    
}

void add_node_atlast(struct node*head)
{
    struct node*last_node,*ptr;
    last_node=malloc(sizeof(struct node));
    last_node->pre=NULL;
    printf("ente  the value to be entered at last");
    scanf("%d",&last_node->data);
    last_node->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
  ptr->next=last_node;
  last_node->pre=ptr;
  }

//function to add node at specific position
void adding_afterthisenterednodes(struct node*head)
{   int pos;
    struct node*new,*ptr2;//ptr2 it points the next node which comes after node to be added
       struct node*ptr1=head;//will point the node comes before node to be added
    new=malloc(sizeof(struct node));
    new->pre=NULL;
    new->next=NULL;
    printf("enter the data to be inserted");
    scanf("%d",&new->data);
    printf("enter the pos after which u want to neter it");
    scanf("%d",&pos);
    while(pos!=1)
    {
      ptr1=ptr1->next;
      pos--;
    }
     if(ptr1->next==NULL)
     {
         ptr1->next=new;
         new->pre=ptr1;
         new->next=NULL;
    }
    else{
    ptr2=ptr1->next;
    ptr1->next=new;
    ptr2->pre=new;
    new->pre=ptr1;
    new->next=ptr2;}
}

void deleting_thrfirst_node(struct node**head)
{
    struct node *pointer=*head;
    *head=(*head)->next;
    free(pointer);
    (*head)->pre=NULL;
}
 
void deleting_the_lastnode(struct node*head)
{
  struct node*ptr1,*ptr2;
  ptr1=head;
  while(ptr1->next!=NULL)
  {
    ptr1=ptr1->next;
  }
  ptr2=ptr1->pre;
  free(ptr1);
  ptr2->next=NULL;
} 
//function to delter the specific node
void deletethis_specific_posnode(struct node *head)
{   int pos;
    struct node*prenode;
    struct node*delnode;
    delnode = head;
    printf("enter the position at which u want deletion(not 1)");
    scanf("%d",&pos);
   
    while(pos>1)
    {
        delnode=delnode->next;
        pos--;
    }
    prenode=delnode->pre;
    prenode->next=delnode->next;
    delnode->next->pre=prenode;
    // prenode->next=delnode->next;

}

void reverse_the_list(struct node **head)
{
    struct node*ptr1,*ptr2;
    ptr1=*head;
    ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->pre=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->pre=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->pre;
    }
    *head=ptr1;

}
int main()
{  
     int n,choice;
    struct node*head;
    struct node*ptr=head;
    head=malloc(sizeof(struct node));
    printf("enter the value of node 1");
    scanf("%d",&head->data);
    head->pre=NULL;
    head->next=NULL;
    do{
    printf("1.create the list\n 2.add node at beginning \n 3.adding node at last\n 4.adding node after a specific position\n 5.deleting the first node\n 6.deleting the  last node\n");
    printf("7.deletion at specific position\n 8.reverse the list\n");
    printf("select your choice");
    scanf("%d",&choice);
    
     
     switch(choice)
     {
     //creating the list
     case 1: printf("enter number of nodes to add after node 1");
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      { ptr=adding_node(head);}
    ptr=head;
      while(ptr!=NULL)
       {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
       }
    break;
    //adding at the beginning
    case 2:
    adding_node_atbeg(&head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    //ptr=head;
    break;
     case 3: add_node_atlast(head);
     ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;
    //adding a node between nodes at a specific position
    case 4: 
    adding_afterthisenterednodes(head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;

    case 5:deleting_thrfirst_node(&head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;

     case 6:deleting_the_lastnode(head);
     ptr=head;
     while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;
    case 7: deletethis_specific_posnode(head);
     ptr=head;
     while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;

   case 8: reverse_the_list(&head);
   ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr= ptr->next;
    }
    break;

     case 9: default:
     printf("exit");
     }

    }while(choice!=8);
    
    
    return 0;
}
