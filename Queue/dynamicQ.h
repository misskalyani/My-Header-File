
struct node
{
   int data;
   struct node *next;
};
  struct node *r;
void init()
{
    r=NULL;
}
int isempty()
{
    if(r==NULL)
       return 1;
    else
       return 0;
}
void Add(int num)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(r==NULL)
     {
       r=newnode;
       r->next=r;
     }
    else
     {
       newnode->next=r->next;
       r->next=newnode;
       r=r->next;
     }
}
int Delete()
{
    int num;
    struct node *temp;
    temp=r->next;
    if(r==temp->next)
    {  
      r=NULL;
    }
    else
    {
      r->next=temp->next;
    }
     num=temp->data;
    free(temp);
    return (num);
}
int peek()
{
    return r->next->data;
}

