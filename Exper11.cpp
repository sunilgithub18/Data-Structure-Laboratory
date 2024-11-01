 /*
AIM:
Write C++ program for simulating job queue.
Write functions to add job and delete job from queue.

INPUT: 
    1. Job information (ID & Name)
	
OUTPUT:
	a) Add Job in Queue
	b) Delete Job from Queue
	c) Display Queue
	
AUTHOR:  Sunil
DATE: 13.10.2024
*/
#include<iostream>
#define MAX 3
using namespace std;
//ADT Job
typedef struct Job{
	int ID;//ID number of a job
	string name;//Name of Job
	
}JOB;

//ADT Queue with all operations
class Queue{
	private:
		JOB Q[MAX];//Queue using array of objects
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
		
		//Add element in Queue 'enQueue Operation'
		void enQueue(JOB j){
				if(! isQueueFull()){
					//check whether it is first job to be added in queue
					if(front == -1){
						front=rear=0;
						Q[rear]=j;
					}//More jobs in queue
					else
						Q[++rear]=j;
				}
				else
					cout<<"\nQueue is full!!";
		}
		
		//Remove element from Queue 'dQueue Operation'
		void dQueue(){
				
				if(!isQueueEmpty()){
					//check whether it is a last job to be removed from queue
					if(front == rear){
						cout<<"\n"<<Q[front].ID<<"  is deleted from Queue";
						front=rear=-1;
					}//more jobs in queue
					else{
						cout<<"\n"<<Q[front].ID<<"  is deleted from Queue";
						front++;
					}	
				}
				else
					cout<<"\nQueue is Empty!!";
		}
		
		//Display Queue contents
		void displayQueue(){
			int i;
			if(!isQueueEmpty()){
				cout<<"\nJob Queue is:\n";
				for (i=front;i<=rear; i++)
					cout<<"|"<<Q[i].ID<<"-"<<Q[i].name<<"| ";
			}
			else
				cout<<"\n Queue Empty!!";
		}
};

//Driver Code
int main(){
	int choice=0;
	JOB j;//object to get job information
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
				cout<<"\nEnter Job ID:";
				cin>>j.ID;
				cout<<"\nEnter Job Name:";
				cin>>j.name;
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