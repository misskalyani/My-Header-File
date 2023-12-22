struct node
{
  int data;
  struct node *next;
};

struct node *f;
struct node *r;
initq()
{
	f=r=NULL;
}
void enqueue (int d)			
{
  struct node *n;
  n = (struct node *) malloc (sizeof (struct node));
  n->data = d;
  n->next = NULL;
  if ((r == NULL) && (f == NULL))
    {
      f = r = n;
      r->next = f;
    }
  else
    {
      r->next = n;
      r = n;
      n->next = f;
    }
}

void dequeue ()			
{
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else if (f == r)
    {
      f = r = NULL;
      free (t);
    }
  else
    {
      f = f->next;
      r->next = f;
      free (t);
    }


}

void display ()
{
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else
    { 
      printf ("Circular Queue: ");
      do
	{
	  printf (" %d", t->data);
	  t = t->next;
	}
      while (t != f);
    }
}


