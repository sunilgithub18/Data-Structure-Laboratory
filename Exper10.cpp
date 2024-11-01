/*
AIM:
Implement C++ program for expression conversion 
as infix to postfix 
and its evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/' operators are expected

INPUT: 
    1. Infix Expression
	
OUTPUT:
	1) Display postfix expression
	

AUTHOR:  Sunil
DATE: 15.10.2024
*/
#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;

//ADT Stack
class Stack{
	private:
		char S[MAX];//Stack array
		int top;//pointer to the top element of a stack
	public:
		Stack(){
			top=-1;//Stack empty means top points to invalid location
		}
		
		//check if stack is empty
		bool isStackEmpty(){
			if (top == -1)
				return true;
			else
				return false;
		}
		
		//check if stack is full
		bool isStackFull(){
			if (top == MAX-1)
				return true;
			else
				return false;
		}
		
		//Add element in stack 'Push Operation'
		void push(char token){
				if(! isStackFull())
					S[++top]=token;
				else
					cout<<"\nStack is full!!";
		}
		
		//Remove element from stack 'Pop Operation'
		char pop(){
				if(!isStackEmpty()){
					cout<<"\n"<<S[top]<<"  is popped from Stack";
					return S[top--];
				}
				else
					cout<<"\nStack is Empty!!";
				
				return '\0';
		}
		
		//Top()
		char Top(){
			return S[top];
		}
		
		//Display stack contents
		void displayStack(){
			int i;
			if(!isStackEmpty()){
				for (i=top;i>=0; i--)
					cout<<"\n"<<S[i];
			}
			else
				cout<<"\n Stack Empty!!";
		}
};


//Implementation class
class ExpressionConversion{
	private:
		char E[20];//an array to store an infix expression
		Stack stk;
	public:
		ExpressionConversion(){
		}
		
		void readExpression(){
			strcpy(E,"");
			cin>>E;
		}
		
		void displayExpression(){
			cout<<"\nThe input infix expression is:"<<E;
		}
		
		//Function to calculate Incoming priority of an operator
		int ICP(char t)
		{
			int v;
			switch(t)
			{
				case '+':
				case '-':
					v=1;
					break;
				case '*':
				case '/':
					v=2;
					break;
				case '^':
					v=3;
					break;
				case '(':
					v=4;
					break;
			}
			return v;
		}
		
		//Function to calculate In-Stack priority of an operator
		int ISP(char t)
		{
			int v;
			switch(t)
			{
				case '+':
				case '-':
					v=1;
					break;
				case '*':
				case '/':
					v=2;
					break;
				case '^':
					v=3;
					break;
				case '(':
					v=0;
					break;
			}
			return v;
		}
	
		//Function to perform the infix to postfix
		void in2Post()
		{
			
			char POST[20];
			int i,j=0;
			i=0;
			//Till end of the expression
			while(E[i] != '\0')
			{
				if(E[i]=='+' || E[i]=='-' ||E[i]=='*' ||E[i]=='/' |E[i]=='^' ||E[i]=='(')
				{
					//if stack is empty then push the operator unconditionally
					if(stk.isStackEmpty())
					{
						stk.push(E[i]);
					}
					else
					{
						//Pop all the operators in stack 
						//having priority >= to the incoming operator priority
						while(ICP(E[i]) <= ISP(stk.Top()) && !stk.isStackEmpty())
							POST[j++]=stk.pop();
			  
						stk.push(E[i]);//Push the incoming operator unconditionally
					}
				}
				else
					if(E[i] == ')')//if right bracket comes then pop everything from the stack till '(' comes
					{
						while(stk.Top() != '(')
							POST[j++]=stk.pop();
						
						stk.pop();//pop ')' from the stack
					}
					else
						POST[j++]=E[i];//the token is operand, so push it on stack

					i++;//go to the next token in the expression
			}
  
			//After scanning entire expression pop everything from stack and save it to the output expression
			while(!stk.isStackEmpty())
				POST[j++]=stk.pop();//here I wrote E
  
			POST[j]='\0';//Store end of the expression 'NULL' character at the end
			//print the Postfix expression
			cout<<"\nThe prefix expression is ::"<<POST;
		}

};//end class

//Driver Code
int main(){
	int choice=0;

	ExpressionConversion obj ;
	while(choice != 4){
		cout<<"\n***************INFIX to POSTFIX*****************";
		cout<<"\n1. Read Infix Expression";
		cout<<"\n2. Display Infix Expression";
		cout<<"\n3. Convert Expression";
		cout<<"\n4. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Infix Parenthesized Expression:";
				obj.readExpression();
				break;
			case 2:
				obj.displayExpression();
				break;
			case 3:
				obj.in2Post();
				break;
			case 4:
				cout<<"\nGood By!!";
				break;
			
		}//end switch
	}//end while
	return 0;
}//end main
