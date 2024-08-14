'''
AIM:
Write a Python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble Sort and 
c) Display top five scores.

INPUT: Book Information
    1. Number of students in First Year
    2. First year percentage of students

OUTPUT:
    1. Display sorted list of students using Selection sort
    2. Display sorted list of students using Bubble sort
    3. Display top five scores

AUTHOR: Dr. Sunil D. Rathod
DATE: 01.08.2024
'''

#Implementation class
class FEStudent:
    def __init__(self):
        self.N=0 # Number of students in FE
        self.studentList=[] #List of students in FE
        self.bSortList=[] # Sorted list for Bubble sort
        self.sSortList=[] # Sorted list for Selection sort
    
    
    def initialize(self):
        self.N=0 # Number of students in FE
        self.studentList=[] #List of students in FE
        self.bSortList=[] # Sorted list for Bubble sort
        self.sSortList=[] # Sorted list for Selection sort
    
    #1. Read Student percentage
    def getStudentPercentage(self,nos):
        self.N=nos
        for i in range(self.N):
            print("Enter percentage of student",i+1)
            percent=float(input())
            self.studentList.append(percent)
            self.bSortList.append(percent)
            self.sSortList.append(percent)
        
    #2. Display Student percentage
    def displayStudentList(self,List):
        print("\nThe percentage of FE students")
        for i in range(self.N):
            print(List[i],end=" ")

    #3. Display List of students in acending order of percentage using Bubble Sort
    def bubbleSort(self):
        for i in range(self.N-1):
            print("\nThe nos. after ",i+1," pass")
            for j in range(0,self.N-i-1):
                if self.bSortList[j] > self.bSortList[j+1]:
                    temp=self.bSortList[j]
                    self.bSortList[j] = self.bSortList[j+1] 
                    self.bSortList[j+1]=temp
                    
            for k in range(self.N):
                print(self.bSortList[k],end=" ")
    
    #4. Display List of students in acending order of percentage using Selection Sort
    def selectionSort(self):
        for i in range(self.N-1):
            print("\nThe nos. after ",i+1," pass")
            for j in range(i+1,self.N):
                if self.sSortList[i] > self.sSortList[j]:
                    temp=self.sSortList[i]
                    self.sSortList[i] = self.sSortList[j] 
                    self.sSortList[j]=temp
           for k in range(self.N):
                print(self.bSortList[k],end=" ") 
    
        
#Driver Code
std=FEStudent()
choice=0

while(choice != 6):
    print("\n*************SORTING ALGORITHMS****************")
    print("1. Read Student Percentage Marks")
    print("2. Display Student Percentage Marks")
    print("3. Sort Students List using Selection sort")
    print("4. Sort Students List using Bubble sort")
    print("5. Display top five scores")
    print("6. Exit Application")
    choice=int(input("What operation::"))
    
    if (choice ==1):
        std.initialize()
        n=int(input("Enter number of Students in FE::"))
        std.getStudentPercentage(n)
    elif (choice ==2):
        std.displayStudentList(std.studentList)
    elif (choice ==3):
        std.selectionSort()
        std.displayStudentList(std.sSortList)
    elif (choice ==4):
        std.bubbleSort()
        std.displayStudentList(std.bSortList)
    elif (choice ==5):
        pass
    elif (choice ==6):
        print("Good By")
        break
    else:
        print("Wrong Choice")
