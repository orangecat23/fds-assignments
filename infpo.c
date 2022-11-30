/* infix to postfix evaluation without segmentation fault*/

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct abc
{
  char data;
  struct abc *next;

}; struct abc *top = NULL;

int stack[20], top1=-1;

//push
void push (char op)
{
  struct abc *new;
  new = (struct abc *) malloc (sizeof (struct abc));
  new->data = op;
  new->next = NULL;

  if (top == NULL)
    {
      top = new;
    }
  else
    {
      new->next = top;
      top = new;
    }
}

//precedence
int precedence (char op)
{
  switch (op)
    {
    case '^':
      return 3;
      break;
    case '*':
      return 2;
      break;
    case '/':
      return 2;
      break;
    case '+':
      return 1;
      break;
    case '-':
      return 1;
      break;
      default:
      return 0;
      break;
    }
}
// pop
  char pop ()
  {
    char ch;
    struct abc *temp;
    if (top == NULL)
      {
printf ("underflow\n");
      }
    else if (top->next == NULL)
      {
temp = top;
ch = top->data;
top = NULL;
free (temp);
      }
    else
      {
temp = top;
ch = top->data;
top = top->next;
free (temp);
      }
    return ch;
  }
 //push1 
      void push1(int op)
      {
      top1++;
      stack[top1]=op;}
      
      // pop1
      int pop1()
      {
      int op;
      op=stack[top1];
      top1--;
      
      return op;
      }
      
      
//evaluate
void evaluate(char postfix[])
{ int i=0,num,n1,n2,n3;
while(postfix[i]!='\0')
{ if (isdigit(postfix[i]))
	{ num=postfix[i]-48;
	push1(num);
	}
	else {
		n1=pop1();
		n2=pop1();
		
		switch(postfix[i])
		{ 
			case '^':
			n3= pow(n2,n1);
    	  		push1(n3);
      		break;
    			case '*':
     	 	n3=n2*n1;
     	 	push1(n3);
      		break;
   			 case '/':
     		 n3=n2/n1;
      		push1(n3);
      		break;
   			 case '+':
     		 n3=n2+n1;
     	 	push1(n3);
      		break;
    			case '-':
      		n3=n2-n1;
      		push1(n3);
      		break;
      
      		}
      	}	
      i++;
 }
  printf("evaluated answer: %d", pop1());}
     
      
      
  int main ()
  {
    char infix[20], postfix[20];
    printf ("\nEnter infix expression: ");
    scanf ("%s", infix);
    int i = 0, j = 0;
    while (infix[i] != '\0')
      {
if (isalnum (infix[i]))
 {
   postfix[j++] = infix[i];
 }
else
 {
   if (top == NULL)
     {
push (infix[i]);
     }
   else
     {
while (top != NULL && (precedence (top->data) >= precedence (infix[i])))
 {
   postfix[j] = pop ();
   j++;
 }
push (infix[i]);

     }
 }
i++;
      }
    while (top != NULL)
      {
postfix[j++] = pop ();


      }
      postfix[j]='\0';
    printf (" postfix expression: %s\n", postfix);
    evaluate(postfix);
  }
