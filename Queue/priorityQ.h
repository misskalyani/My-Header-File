#define MAX 5


int pri_que[MAX];
int front, rear;
 
void insert_by_priority(int);
void delete_by_priority(int);
void init();
void check(int);
void display_pqueue();
 

void init()
{
    front = rear = -1;
}
 

void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
 

void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
 

void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
 
        pri_que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
 

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 
    front = 0;
}



