#include <iostream>

using namespace std;

int *stack;
int stack_size;
int stack_idx=0;

void push(int x)
{
  if (stack_idx==stack_size)
    {
      cout<<"\nOverflow";
    }
  else
    {
      stack[stack_idx++]=x;
    }
}

void pop()
{
  if (stack_idx==0)
    {
      cout<<"\nUnderflow";
    }
  else
    {
      cout<<"\n"<<stack[--stack_idx]<<"deleted";
    }
}

void show()
{
  int i;
  for (i=0; i<stack_idx; i++)
     {
       cout<<stack[i]<<"\n";
     }		
}
  
void topmost()
{
  cout<<"\nTopmost element: "<<stack[stack_idx-1];
}

void bottom()
{
  cout<<"\nBottom element: "<<stack[0];
}

int main(int argc, char *argv[])
{
  cout<<"\nEnter stack size of stack: ";
  cin>>stack_size;
 stack=new int[stack_size];
 int ch, x;
 do
   {
     cout<<"\n0. Exit";
     cout<<"\n1. Push";
     cout<<"\n2. Pop";
     cout<<"\n3. Print";
     cout<<"\n4. Print top element";
     cout<<"\n5. Print Bottom element";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     if (ch==1)
       {
	 cout<<"\nInsert: ";
	 cin>>x;
	 push(x);
       }
     else if (ch==2)
       {
	 pop();
       }
     else if (ch==3)
       {
	 show();
       }
     else if (ch==4)
       {
	 topmost();
       }
     else if (ch==5)
       {
	 bottom();
       }
   }
 while (ch!=0);
 delete[] stack;
  return 0;
}

//<>
