#define MAX 5
struct Queue
{
	int a[MAX];
	int front,rear;
}q;
void init()
{
	q.front=-1;
	q.rear=-1;
}
int isempty()
{
	if(q.front==-1 || q.front>q.rear)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(q.rear==MAX-1)
	return 1;
	else
	return 0;
}
void enqueue(int num)
{

	if(isfull())
	{
		printf("queue is overflow:");
	}
	else
	{
		if(q.front==-1)
		
			q.front=0;
	
		q.rear++;
		q.a[q.rear]=num;
	}
}
void reverse()
{
	int i;
	for(i=q.rear;i>=q.front;i--)
	{
	printf("%d\t",q.a[i]);
	}
}
void dequeue()
{
	int val;
	if(isempty())
	{
		printf("queue is underflow");
	}
	else
	{
		val=q.a[q.front];
		q.front++;
	printf("%d\t ",val);
	}
	
}
int peek()
{
     return q.a[q.rear];
}

	
void display()
{
	int i;
	for(i=q.front;i<=q.rear;i++)
	{
		printf("%d\t",q.a[i]);
	}
}
