#define memory (node*)malloc(sizeof(node))
typedef struct node
{
	int data;
	struct node*next,*prev;
}node;
node *create(node*head)
{
	struct node*newnode,*temp;
	int i, n,num;
	printf("enter limit:");
	scanf("%d",&n);
   for(i=0;i<n;i++)
	{
	newnode=memory;
	printf("enter value::");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else
	{
		temp->next=newnode;
	    newnode->prev=temp;
		temp=newnode;
	}
}
	return head;
}
node *disp(node*head)
{
	node*temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
node *delbyval(node*head,int num)
{
	node*temp,*temp1;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==num)
		{
			break;
		}
	}
	for(temp1=head;temp1->next!=temp;temp1=temp1->next);
	temp1->next=temp->next;
	free(temp);
	return head;
}
 node*reverse(node *head)
  {
    node *temp = NULL;
    node *current = head;
    node *next = NULL;

    while (current != NULL) 
	{
        next = current->next;
        current->next = temp;
        temp = current;
        current = next;
    }

    head =temp ;
    return head;
}
node *insertbegin(node*head,int num)
{
	node *newnode;
	newnode=memory;
	newnode->data=num;
	newnode->next=head;
    head->prev=newnode;
    head=newnode;
	return head;
}
node *insertend(node*head,int num)
{
	node *newnode,*temp;
	newnode=memory;
	newnode->data=num;
	newnode->next=NULL;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	newnode->prev=temp;
	return head;
}
node *insertmid(node*head,int num,int pos)
{
	node *newnode,*temp,*temp1;
	int i;
	newnode=memory;
	newnode->data=num;
	for(i=1,temp=head;i<(pos-1)&&temp!=NULL;i++,temp=temp->next);
    temp1=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=temp1;
	temp1->prev=newnode;
	return head;
}
node *delbegin(node *head)
{
	node *temp;
	temp=head;
	head=head->next;
	free(temp);
	return head;
}
node *delend(node *head)
{
	node *temp,*temp1;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	return head;
}
node *delmid(node *head,int pos)
{
	node *temp,*temp1;
	int i;
	for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
	temp1=temp->next;
	temp->next=temp1->next;
	temp1->next->prev=temp;
	free(temp1);
	return head;
}
node *insertcommon(node *head,int num,int pos)
{
	node *newnode,*temp,*temp1;
	int i;
	newnode=memory;
	newnode->data=num;
	if(pos==1)
	{
		newnode->next=head;
	    head->prev=newnode;
		head=newnode;
	}
	else
	{
      	for(i=1,temp=head;i<(pos-1)&&temp!=NULL;i++,temp=temp->next);
     	temp1=temp->next;
	    temp->next=newnode;
     	newnode->prev=temp;
	    newnode->next=temp1;
	    temp1->prev=newnode;
	}
	return head;
}
node *delcommon(node *head,int pos)
{
	node *temp1,*temp;
	int i;
	if(pos==1)
	{
		temp=head;
		head=head->next;
	    free(temp);
	}
	else
	{
      	for(i=1,temp=head;i<(pos-1)&&temp!=NULL;i++,temp=temp->next);
     	temp1=temp->next;
	    temp->next=temp1->next;	
	    temp1->next->prev=temp;
	    free(temp1);
	}
	return head;
}
node *search(node *head,int num)
{
	node *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==num)
		{
			return temp;
		}
	}
   return NULL;
}
int findmax(node *head)
{
	node *temp;
	int max=head->data;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data>max)
		{
			max=temp->data;
		}
	}
	return max;
}
node *sort(node *head)
{
	node *i,*j;
	int t;
	for(i=head;i!=NULL;i=i->next)
	{
		for(j=head;j!=NULL;j=j->next)
		{
	    	if(i->data<j->data)
	       {
		   
			 t=i->data;
	    	 i->data=j->data;
	         j->data=t;
     	   }
   	    }
    }
    return head;
}

