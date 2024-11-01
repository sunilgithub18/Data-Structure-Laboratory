/*
AIM:
Write C++ program for double ended DQueue.
Write functions to add  element to DQueue or delete  from DQueue at both the end.

INPUT: 
    1. Any value as an Element 
	
OUTPUT:
	a) Add Begin
	b) Delete Begin
	a) Add End
	b) Delete End
	c) Display DQueue
	
AUTHOR:  Sunil
DATE: 14.10.2024
*/
#include<iostream>
#define MAX 3
using namespace std;
//ADT Dobule Ended Queue
class DQueue{
	private:
		int Q[MAX];//DQueue using array of objects
		int front,rear;//pointer to the first element and last element of a DQueue
	public:
		DQueue(){
			front=rear=-1;//DQueue empty means front and rear point to invalid location
		}
		
			
		//Add element in DQueue at begin
		void addBeginDQueue(int val){
				if(front!=0){
					//check whether it is first job to be added in DQueue
					if(front == -1){
						front=rear=0;
						Q[front]=val;
					}//More jobs in DQueue
					else
						Q[--front]=val;
				}
				else
					cout<<"\nDQueue is full at front!!";
		}
		
		//Remove element at the front DQueue
		void delBeginDQueue(){
				
				if(front != -1){
					//check whether it is a last job to be removed from DQueue
					if(front == rear){
						cout<<Q[front]<<"  is deleted from DQueue";
						front=rear=-1;
					}//more jobs in DQueue
					else{
						cout<<Q[front]<<"  is deleted from DQueue";
						front++;
					}	
				}
				else
					cout<<"\nDQueue is Empty!!";
		}
		
		//Add element in DQueue at rear
		void addEndDQueue(int val){
				if(rear!=MAX-1){
					//check whether it is first job to be added in DQueue
					if(front == -1){
						front=rear=0;
						Q[rear]=val;
					}//More jobs in DQueue
					else
						Q[++rear]=val;
				}
				else
					cout<<"\nDQueue is full at the rear!!";
		}
		
		//Remove element at the end DQueue
		void delEndDQueue(){
				
				if(rear !=-1){
					//check whether it is a last job to be removed from DQueue
					if(front == rear){
						cout<<"\n"<<Q[rear]<<"  is deleted from DQueue";
						front=rear=-1;
					}//more jobs in DQueue
					else{
						cout<<Q[rear]<<"  is deleted from DQueue";
						rear--;
					}	
				}
				else
					cout<<"\nDQueue is Empty!!";
		}
		//Display DQueue contents
		void displayDQueue(){
			int i;
			if(front != -1){
				cout<<"\nJob DQueue is:\n";
				for (i=front;i<=rear; i++)
					cout<<Q[i]<<" ";
			}
			else
				cout<<"\n DQueue Empty!!";
		}
};

//Driver Code
int main(){
	int choice=0,val;
	DQueue obj ;
	while(choice != 6){
		cout<<"\n***************Doulbe Ended Queue*****************";
		cout<<"\n1. Add element at Begin";
		cout<<"\n2. Delete element at Begin";
		cout<<"\n3. Add element at End";
		cout<<"\n4. Delete element at End";
		cout<<"\n5. Display DQueue";
		cout<<"\n6. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Job ID:";
				cin>>val;
				obj.addBeginDQueue(val);
				break;
			case 2:
				obj.delBeginDQueue();
				break;
			case 3:
				cout<<"\nEnter Job ID:";
				cin>>val;
				obj.addEndDQueue(val);
				break;
			case 4:
				obj.delEndDQueue();
				break;
			case 5:
				obj.displayDQueue();
				break;
			case 6:
				cout<<"\nGood By!!";
				break;
			
		}//end switch
	}//end while
	return 0;
}//end main