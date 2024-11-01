/*
AIM:
Write C++ program for storing appointment schedule for day.
Appointments are booked randomly using linked list.
Set start and end time and min and max duration for visit slot.
Write functions for:
a) Display free slots 
b) Book appointment 
c) Cancel appointment (check validity, time bounds, availability etc.) 
d) Sort list based on time
e) Sort list based on time using pointer manipulation

INPUT: 
    1. Name of visitor
	2. hourOfDay, start and end time 
	3. min and max duration for visit slot

OUTPUT:
	a) Display free slots 
	b) Book appointment
	c) Cancel appointment (check validity, time bounds, availability etc.) 
	d) Sort list based on time
	e) Sort list based on time using pointer manipulation

AUTHOR: Dr. Sunil Rathod
DATE: 19.09.2024
*/
#include<iostream>
using namespace std;

//ADT of Appointment
typedef struct Appointment{
	struct Appointment *prev;//pointer to previous node
	int tokenID;//Slot ID
	string Name;//name of visitor
	int hourOfDay;
	int startTime;//24 hours format
	int endTime;
	int minDuration;// in minutes
	int maxDuration;
	bool booked;//appointment booking status, 'true' if booked otherwise 'false'
	struct Appointment *next;//pointer to next node
}APPT;

//Implementation class
class AppointmentSchedular{
	private:
		APPT *head,*tail;//pointers to first and last node respectively
		int countID;	//Track number of slots	
	public:
		AppointmentSchedular(){
			head=NULL;
			tail=NULL;
			countID=0;
		}
		
		//1. Function to Add free slots
		void addFreeSlot(int hod,int stime,int etime, int min, int max){
			APPT *p;
			p=new APPT;
			p->prev=NULL;
			p->tokenID=++countID;
			p->Name="";
			p->hourOfDay=hod;//hour of day
			p->startTime=stime;//as minutes
			p->endTime=etime;//as minutes
			p->minDuration=min;
			p->maxDuration=max;
			p->booked=false;
			p->next=NULL;
			
			if(head==NULL)
				head=tail=p;
			else{
				tail->next=p;
				p->prev=tail;
				tail=tail->next;
			}//end else
		}
	
		//2. Function to display student list
		void displayList(){
			APPT *cur;
			cur=head;
			cout<<"["<<head<<"]->\n";
			cout<<"\nID\tName\tHoday\tsTime\teTime\tminD\tmaxD\tBooked";
			while(cur != NULL){
				cout<<"\n"<<cur->tokenID<<"\t"<<cur->Name<<"\t"<<cur->hourOfDay<<"\t"<<cur->startTime<<"\t"<<cur->endTime<<"\t"<<cur->minDuration<<"\t"<<cur->maxDuration<<"\t"<<cur->booked;
				cur=cur->next;
			}
			cout<<"\n->NULL";
		}
		
		//3. Functio to Book the appointment
		void bookAppointment(int id,string name){
			APPT *cur;
			cur=head;
			while(cur != NULL){
				if(cur->tokenID==id ){
					if(cur->booked ==0){
					cur->Name=name;
					cur->booked=true;
					}
					else
						cout<<"\nSlot already booked";
					break;
				}
				cur=cur->next;
			}
			if(cur == NULL)
				cout<<"\nNo slot "<<id<<" available";	
		}
		
		//4. Sort list based on time
		void sortList(){
			APPT *i,*j,*temp;
			temp=new APPT;
			
			for (i=head; i!=NULL; i=i->next){
				
				for (j=i->next;j!=NULL;j=j->next) {
					
					if (i->hourOfDay > j->hourOfDay){
						temp->tokenID=i->tokenID;
						temp->Name=i->Name;
						temp->hourOfDay=i->hourOfDay;//hour of day
						temp->startTime=i->startTime;//as minutes
						temp->endTime=i->endTime;//as minutes
						temp->minDuration=i->minDuration;
						temp->maxDuration=i->maxDuration;
						temp->booked=i->booked;
						
						i->tokenID=j->tokenID;
						i->Name=j->Name;
						i->hourOfDay=j->hourOfDay;//hour of day
						i->startTime=j->startTime;//as minutes
						i->endTime=j->endTime;//as minutes
						i->minDuration=j->minDuration;
						i->maxDuration=j->maxDuration;
						i->booked=j->booked;
						
						j->tokenID=temp->tokenID;
						j->Name=temp->Name;
						j->hourOfDay=temp->hourOfDay;//hour of day
						j->startTime=temp->startTime;//as minutes
						j->endTime=temp->endTime;//as minutes
						j->minDuration=temp->minDuration;
						j->maxDuration=temp->maxDuration;
						j->booked=temp->booked;
						
					}
				}//end for loop j
			}	//end for loop i		
		}//end function
		
		//5. Sort list based on time using pointer manipulation
		void sortListPhysical(){
			
		}//end function
};

//Driver Code
int main(){
	int choice=0;
	string name;
	int hod;
	int stime;
	int etime;
	int min;
	int max;
	int id;
	AppointmentSchedular sch;
	while(choice != 6){
		cout<<"\n***************APPOINTMENT SCHEDULER*****************";
		cout<<"\n1. Add free slots";
		cout<<"\n2. Display free slots ";
		cout<<"\n3. Book appointment";
		cout<<"\n4. Sort list based on time";
		cout<<"\n5. Sort list based on time using pointer manipulation";
		cout<<"\n6. Exit Application";
		cout<<"\nWhat is your choice::";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\nEnter hour of a day 24 hours format (0 to 23):";
				cin>>hod;
				cout<<"\nEnter start time of an hour:";
				cin>>stime;
				cout<<"\nEnter end time of an hour:";
				cin>>etime;
				cout<<"\nEnter minimum availability as minutes:";
				cin>>min;
				cout<<"\nEnter minimum availability as minutes:";
				cin>>max;
				sch.addFreeSlot(hod,stime,etime,min,max);
				break;
			case 2:
				sch.displayList();
				break;
			case 3:
				sch.displayList();
				cout<<"\nEnter slot number to be booked :";
				cin>>id;
				cout<<"\nEnter your Name :";
				cin>>name;
				sch.bookAppointment(id,name);
				break;
			case 4:
				sch.sortList();
				break;
			case 5:
				sch.sortListPhysical();
				break;
			case 6:
				cout<<"\nGood By!!";
				break;
			
		}//end switch
	}//end while
	return 0;
}//end main


/*
D:\student_programs>g++ Exper8.cpp

D:\student_programs>a

***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::1

Enter hour of a day 24 hours format (0 to 23):8

Enter start time of an hour:12

Enter end time of an hour:45

Enter minimum availability as minutes:12

Enter minimum availability as minutes:22

***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::2
[0x1027310]->

ID      Name    Hoday   sTime   eTime   minD    maxD    Booked
1               8       12      45      12      22      0
->NULL
***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::1

Enter hour of a day 24 hours format (0 to 23):13

Enter start time of an hour:5

Enter end time of an hour:35

Enter minimum availability as minutes:10

Enter minimum availability as minutes:20

***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::2
[0x1027310]->

ID      Name    Hoday   sTime   eTime   minD    maxD    Booked
1               8       12      45      12      22      0
2               13      5       35      10      20      0
->NULL
***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::1

Enter hour of a day 24 hours format (0 to 23):10

Enter start time of an hour:15

Enter end time of an hour:55

Enter minimum availability as minutes:15

Enter minimum availability as minutes:35

***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::2
[0x1027310]->

ID      Name    Hoday   sTime   eTime   minD    maxD    Booked
1               8       12      45      12      22      0
2               13      5       35      10      20      0
3               10      15      55      15      35      0
->NULL
***************APPOINTMENT SCHEDULER*****************
1. Add free slots
2. Display free slots
3. Book appointment
4. Sort list based on time
5. Sort list based on time using pointer manipulation
6. Exit Application
What is your choice::
*/