 /*
AIM:
Write program to implement a priority queue in C++ using an inorder list to store the items in the queue.
Create a class that includes the data items 
(which should be template) 
and the priority (which should be int). 
The inorder list should contain these objects
with operator <= overloaded so that the items with highest priority appear at the beginning of the list
(which will make it relatively easy to retrieve the highest item.)
INPUT: 
    1. Item information (Name, Priority)
	
OUTPUT:
	a) Add Item in Priority Queue
	b) Delete Item from Priority Queue
	c) Display Queue
	
AUTHOR:  Sunil
DATE: 13.10.2024
*/
#include<iostream>
#define MAX 3
using namespace std;
//ADT Item
template <class T>
class ITEM{
	public:
	T data;//data item
	int priority;//priority number of an item
	
	//Overloaded operator '<=' function definition
	bool operator <=(ITEM& ob2){
			if (priority <= ob2.priority)
				return true;
			else
				return false; 			
		}
		
};
//ADT Priority Queue 
class Queue{
	private:
		ITEM<string> Q[MAX];//Queue using array of objects
		int front,rear;//pointer to the first element and last element of a Queue
	public:
		Queue(){
			front=rear=-1;//Queue empty means front and rear point to invalid location
		}
		
		//check if Queue is empty
		bool isQueueEmpty(){
			if (front == -1)
				return true;
			else
				return false;
		}
		
		//check if Queue is full
		bool isQueueFull(){
			if (rear == MAX-1)
				return true;
			else
				return false;
		}
		
		//1. Add element in Queue 'enQueue Operation'
		void enQueue(ITEM<string> item){
				int i;
				ITEM<string> temp;
				if(! isQueueFull()){
					//check whether it is first job to be added in queue
					if(front == -1){
						front=rear=0;
						Q[rear]=item;
					}//More jobs in queue
					else
						Q[++rear]=item;
				
					//Maintain priority by sorting queue after every new insertion of job
					for(i=rear;i>0;i--){
						if(Q[i]<=Q[i-1]){
							temp=Q[i];
							Q[i] = Q[i-1];
							Q[i-1]=temp;
						}
					}
				}
				else
					cout<<"\nQueue is full!!";
		}
		
		
		
		//2. Remove element from Queue 
		void dQueue(){
				int i;
				if(!isQueueEmpty()){
					//check whether it is a last job to be removed from queue
					if(front == rear){
						cout<<"\n"<<Q[front].data<<"  is deleted from Queue";
						front=rear=-1;
					}//more jobs in queue
					else{
						cout<<"\n"<<Q[front].data<<"  is deleted from Queue";
					}
					
					//Shift the items to the left after deletion at front
					for (i=0;i<rear;i++)
						Q[i]=Q[i+1];
					
					rear--;
				}
				else
					cout<<"\nQueue is Empty!!";
		}
		
		//3. Display Queue contents
		void displayQueue(){
			int i;
			if(!isQueueEmpty()){
				cout<<"\nJob Queue is:\n";
				for (i=front;i<=rear; i++)
					cout<<"|"<<Q[i].data<<"-"<<Q[i].priority<<"| ";
			}
			else
				cout<<"\n Queue Empty!!";
		}	
};

//Driver Code
int main(){
	int choice=0;
	ITEM<string> j;//object to get job information
	Queue obj ;
	while(choice != 4){
		cout<<"\n***************JOB QUEUE*****************";
		cout<<"\n1. Add Job in Queue";
		cout<<"\n2. Delete Job from Queue";
		cout<<"\n3. Display Job Queue";
		cout<<"\n4. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter Item Name:";
				cin>>j.data;
				cout<<"\nEnter Job priority:";
				cin>>j.priority;
				obj.enQueue(j);
				break;
			case 2:
				obj.dQueue();
				break;
			case 3:
				obj.displayQueue();
				break;
			case 4:
				cout<<"\nGood By!!";
				break;
			
		}//end switch
	}//end while
	return 0;
}//end main