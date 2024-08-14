'''
AIM:
Write a Python program 
1. To store students PRNs with date and month (year) of birth. 
List_A and List_B be the two list for two SE Computer divisions. 
2. Lists are sorted on date and month.
3. Merge these two lists into third list “List_SE_Comp_DOB”
resulting in sorted information about Date of Birth of SE Computer students

INPUT: 
    1. Student PRN, Day & Month (year) for SE-A & SE-B

OUTPUT:
   2. Sorted List of SE_Comp

AUTHOR: Dr. Sunil D. Rathod
DATE: 23.07.2024
'''
import datetime

#ADT of Student
class Student:
    def __init__(self):
        self.PRN=None
        self.dob=datetime.date

#Implementation Class
class SEComputer:
    def __init__(self):
        self.n1=0 #No. of students in SE-A
        self.n2=0 #No. of students in SE-B
        self.n3=0 #No. of students in SE Computer
        self.SEAList=[] #SE-A division list
        self.SEBList=[] #SE-B division list
        self.SECOMPList=[] #SE-A& SE-B division list, SE Computer
        
    #Function/Method for reading Student information SE-A
    def readStudentdataSEA(self):
        self.n1=int(input("Enter the no. of students for SE-A:"))
        for i in range(self.n1):
            s=Student()
            print("Enter information for student-",i+1)
            s.PRN=input("Enter your PRN::")
            day=int(input("Enter day of the birth::"))
            month=int(input("Enter month of the birth::"))
            year=int(input("Enter year of the birth, 4-digits::"))
            s.dob=datetime.date(year,month,day)
            self.SEAList.append(s)
            
    #Function/Method for reading Student information SE-B
    def readStudentdataSEB(self):
        self.n2=int(input("Enter the no. of students for SE-B:"))
        for i in range(self.n2):
            s=Student()
            print("Enter information for student-",i+1)
            s.PRN=input("Enter your PRN::")
            day=int(input("Enter day of the birth::"))
            month=int(input("Enter month of the birth::"))
            year=int(input("Enter year of the birth, 4-digits::"))
            s.dob=datetime.date(year,month,day)
            self.SEBList.append(s)
            
    #Function/Method for displaying book information SE-A
    def displayStudentListSEA(self):
        for i in range(self.n1):
            print("\n\t",self.SEAList[i].PRN,"  ",str(self.SEAList[i].dob))
    
    #Function/Method for displaying book information SE-B
    def displayStudentListSEB(self):
        for i in range(self.n2):
            print("\n\t",self.SEBList[i].PRN,"  ",str(self.SEBList[i].dob))
    
    #Function/Method for displaying book information SE Computer
    def displayStudentListSECOMP(self):
        for i in range(self.n3):
            print("\n\t",self.SEBList[i].PRN,"  ",str(self.SEBList[i].dob))
        
    def sortStudentList(self,nos,List):#Actual parameters
        for i in range(nos-1):
            for j in range(0,nos-i-1):
                if List[j].dob > List[j+1].dob:
                    temp=List[j]
                    List[j] = List[j+1] 
                    List[j+1]=temp
    
    def mergeList(self):
        self.SECOMPList=[]
        #list SE-A & SE-B are empty
        if (self.n1==0 and self.n2==0):
            print("No students found in SE-A & SE-B")
        elif(self.n1==0): #list SE-A is empty then copy list SE-B 
            for i in range(self.n2):
                SECOMPList.append(self.SEBList[i])
        elif(self.n2==0): #list SE-B is empty then copy list SE-A 
            for i in range(self.n1):
                SECOMPList.append(self.SEBList[i])
        elif(self.n1 >0 and self.n2 >0):#list SE-A & SE-B have students
            #copy SE-A students
            for i in range(self.n2):
                SECOMPList.append(self.SEBList[i])
            #copy SE-A students
            for i in range(self.n1):
                SECOMPList.append(self.SEBList[i])


#Driver Code
obj=SEComputer()
choice=0
while(choice != 5):
    print("\n***************SE COMPUTER STUDENT *******************")
    print("1. Read SE-A/SE-B Student Lists")
    print("2. Display SE-A/SE-B  Student Lists")
    print("3. Sort SE-A/SE-B Student Lists ")
    print("4. Merge SE-A/SE-B  Student Lists ")
    print("5. Exit Application")
    choice=int(input("Enter your choice:"))
        
    if(choice == 1):
        print("Enter SE-A student information")
        obj.readStudentdataSEA()
        print("Enter SE-B student information")
        obj.readStudentdataSEB()
        
    elif(choice == 2):
        print("List of SE-A")
        obj.displayStudentListSEA()
        
        print("List of SE-B")
        obj.displayStudentListSEB()
        
    elif(choice == 3):
        choice1=0
        print("1. Sort SE-A")
        print("2. Sort SE-B")
        print("3. Sort SEComputer")
        choice1=int(input("Enter your choice:"))
        
        if(choice1==1):
            obj.sortStudentList(obj.n1,obj.SEAList)#SE-A formal parameters
        elif(choice1==2):
            obj.sortStudentList(obj.n2,obj.SEBList)#SE-B  
        
    elif(choice == 4):
        obj.mergeList()
        print("List of SE-COMPUTER")
        obj.displayStudentListSECOMP()
    
    elif(choice == 5):
        print("Good By!!")
        break
    
    else:
        print("Wrong Choice!!!")
