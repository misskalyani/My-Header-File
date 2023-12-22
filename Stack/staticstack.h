
#define MAX 25
struct stack
{
   char a[MAX];
   int top;
}s1;
void init()
{
        s1.top=-1;
}
int isempty()
{
        if(s1.top==-1)
        return 1;
        else
        return 0;
}
int isfull()
{
        if(s1.top==MAX-1)
        return 1;
        else
        return 0;
}
void push(char x)
{
        if(isfull())
        printf("Stack Is Full Now");
        else
        {
           s1.top++;
           s1.a[s1.top]=x;
        }
}
char pop()
{
        char ch;
        if(isempty())
        printf("Stack Is Empty Now");
        else
        {
          ch=s1.a[s1.top];
          s1.top--;
          return ch;
        }
}

 void disp()
{
	int i;
		for(i=s1.top;i>=0;i--)
	{
		printf("%c",s1.a[i]);
	}
}
   

