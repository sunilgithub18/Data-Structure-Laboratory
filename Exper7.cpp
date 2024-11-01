/*
AIM:
club member‘s information using singly linked list. 
Store student PRN and Name. 
Write functions to: 
a) Add and delete the members as well as president or even secretary. 
b) Compute total number of members of club 
c) Display members
d) Two linked lists exists for two divisions. 
   Concatenate two lists

INPUT: 
    1. Student PRN and Name

OUTPUT:
    1. Display Members list for SE-A and SE-B divisions
	2. Add Member to SE-A and SE-B divisions
	3. Delete Member from SE-A and SE-B divisions
	4. Concatenate two lists

AUTHOR: Dr. Sunil Rathod
DATE: 03.09.2024
*/
#include<iostream>
using namespace std;
//ADT of Student Club Member
typedef struct Member{
	
	string PRN;// Student PRN
	string Name;// Student name
	string memberType;// Member type, regular or president or secretary
	struct Member *next;
}STUD;

//Implementation class of Club Members
class ClubMember{
	
	public:
		STUD *head1,*head2;//Two header pointers for SE-A & SE-B

		ClubMember(){
			head1=NULL;
			head2=NULL;
		}
		
		//1. Function to add student in the list
		STUD * addMember(STUD *head,string prn,string name, string mtype){
			STUD *p;
			p=new STUD;
			p->PRN=prn;
			p->Name=name;
			p->memberType=mtype;
			p->next=NULL;
			if(head==NULL)
			{
				head=p;
				cout<<"\n"<<head->PRN<<"  "<<head->Name<<"  "<<head->memberType;
			}
			else{
				STUD *cur;
				cur=head;
				while(cur->next != NULL)
					cur=cur->next;
				
				cur->next=p;
				cout<<"\n"<<cur->PRN<<"  "<<cur->Name<<"  "<<cur->memberType;
			}//end else
			
			return head;
		}
		
		//2. Function to display student list
		void displayList(STUD *head){
			STUD *cur;
			cur=head;
			cout<<"["<<head<<"]->";
			while(cur != NULL){
				cout<<"["<<cur->PRN<<"|"<<cur->Name<<"|"<<cur->memberType<<"|"<<cur->next<<"]->";
				cur=cur->next;
			}
			cout<<"NULL";
		}
		
		//3. Function to delete student from the list
		STUD* deleteStudent(STUD* head,string key){
			
			STUD *cur,*f;
			cur=head;
			while(cur != NULL){
				if(cur->Name == key)
					break;
				f=cur;
				cur=cur->next;
			}
			
			if(cur){
				if(cur==head && cur->next == NULL)
					head=NULL;
				else if(cur==head && cur->next != NULL)
					head=cur->next;
				else if(cur !=head && cur->next != NULL)
					f->next=cur->next;
				else if(cur !=head && cur->next == NULL)
					f->next=cur->next;
				
				delete cur;
			}
			else
				cout<<"\nName not found!!";
		 return head;
		}
		
		//4. Function to Concatenate two lists
		void concatenate(){
			STUD *cur;
			cur=head1;
			while(cur->next != NULL)
				cur=cur->next;
			
			cur->next=head2;
			head2=NULL;
		}
		
};

//Driver Code
int main(){
	int choice=0,memberShip, cho;
	string PRN,name,mtype;
	ClubMember club;
	while(choice != 5){
		cout<<"\n************STUDENT CLUB**************";
		cout<<"\n1. Add Member";
		cout<<"\n2. Display Member List";
		cout<<"\n3. Delete Member";
		cout<<"\n4. Concatenate two lists";
		cout<<"\n5. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter PRN of student:";
				cin>>PRN;
				cout<<"\nEnter name of student:";
				cin>>name;
				cout<<"\n*********MemberShip of Student*********";
				cout<<"\n1. Regular";
				cout<<"\n2. Secretary";
				cout<<"\n3. President";
				cout<<"\nEnter membership of student:";
				cin>>memberShip;
				if (memberShip==1)
					mtype="Regular";
				else if(memberShip==2)
					mtype="Secretary";
				else if(memberShip==3)
					mtype="President";
				
				cout<<"\n*********Division of Student*********";
				cout<<"\n1. Add to SE-A"; 
				cout<<"\n2. Add to SE-B";
				cout<<"\nWhich list::";
				cin>>cho;
				if(cho==1)
					club.head1=club.addMember(club.head1,PRN,name,mtype);
				else
					club.head2=club.addMember(club.head2,PRN,name,mtype);
				
				break;
			case 2:
				cout<<"\nList-A:";
					club.displayList(club.head1);
					
				cout<<"\nList-B:";
					club.displayList(club.head2);
				break;
			case 3:
				cout<<"\nEnter name of student to be deleted:";
				cin>>name;
				cout<<"\n1. Delete from SE-A"; 
				cout<<"\n2. Delete from SE-B";
				cout<<"\nWhich list::";
				cin>>cho;
				if(cho==1)
					club.head1=club.deleteStudent(club.head1,name);
				else
					club.head2=club.deleteStudent(club.head2,name);
				break;
			
			case 4:
				club.concatenate();
				break;
			case 5:
				cout<<"\nGood Buy!!";
				break;
			
		}//end switch
		
	}//end while
	
}//end main