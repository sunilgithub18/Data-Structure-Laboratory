'''
AIM:
Write a Python program to store first year percentage of students in self.iSortListay.
Write function for sorting self.iSortListay of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and 
c) Display top five scores.

INPUT: 
    1. Number of students in First Year
    2. First year percentage of students

OUTPUT:
    1. Display sorted list of students using Insertion sort
    2. Display sorted list of students using Shell sort
    3. Display top five scores

AUTHOR: Dipali Junankar
DATE: 01.08.2024
'''

#Implementation class
class FEStudent:
    def __init__(self):
        self.N=0 # Number of students in FE
        self.studentList=[] #List of students in FE
        self.iSortList=[] # Sorted list for Insertion sort
        self.sSortList=[] # Sorted list for Shell sort
    
    
    def initialize(self):
        self.N=0 # Number of students in FE
        self.studentList=[] #List of students in FE
        self.iSortList=[] # Sorted list for Insertion sort
        self.sSortList=[] # Sorted list for Shell sort
    
    #1. Read Student percentage
    def getStudentPercentage(self,nos):
        self.N=nos
        for i in range(self.N):
            print("Enter percentage of student",i+1)
            percent=float(input())
            self.studentList.append(percent)
            self.iSortList.append(percent)
            self.sSortList.append(percent)
        
    #2. Display Student percentage
    def displayStudentList(self,List):
        print("\nThe percentage of FE students")
        for i in range(self.N):
            print(List[i],end=" ")

    #3. Display List of students in acending order of percentage using Insertion Sort
    # Traverse through 1 to len(self.iSortList)
    def insertionSort(self):
        for i in range(1, len(self.iSortList)):
            print("\nThe nos. after ",i," pass")
            key = self.iSortList[i]
            j = i - 1
            
            # Move elements of self.iSortList[0..i-1], that are greater than key,
            # to one position ahead of their current position
            while j >= 0 and key < self.iSortList[j]:
                self.iSortList[j + 1] = self.iSortList[j]
                j -= 1
            
            self.iSortList[j + 1] = key   
            
            for k in range(self.N):
                print(self.iSortList[k],end=" ")

    #4. Display List of students in acending order of percentage using shell Sort
    
    def shellSort(self):
        d = self.N // 2
        p=1 #number of passes
        while d > 0:
            print("\nThe nos. after ",p," pass")
            for i in range(d, self.N):
                temp = self.sSortList[i]
                j = i
                while j >= d and self.sSortList[j - d] > temp:
                    self.sSortList[j] = self.sSortList[j - d]
                    j -= d
                self.sSortList[j] = temp
            d = d // 2
            p+=1 #increase the number of passes value
            for k in range(self.N):
                print(self.iSortList[k],end=" ")


    #5. Top 5 score
    def topFiveScores(self):
        if(len(self.iSortList)==0):
            print("Student List Empty!!")
        elif(len(self.iSortList) < 5):
            print("Top Scores::",self.iSortList[-1:-(len(self.iSortList)+1):-1])
        elif(len(self.iSortList) >= 5):
            print("Top Scores::",self.iSortList[-1:-6:-1])
            
        
        
#Driver Code
std=FEStudent()
choice=0

while(choice != 6):
    print("\n*************DEPARTMENT stdRARY****************")
    print("1. Read Student Percentage Marks")
    print("2. Display Student Percentage Marks")
    print("3. Sort Students List using Insertion sort")
    print("4. Sort Students List using shell sort")
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
        std.insertionSort()
        std.displayStudentList(std.iSortList)
    elif (choice ==4):
        std.shellSort()
        std.displayStudentList(std.sSortList)
    elif (choice ==5):
        std.insertionSort()
        std.topFiveScores()
    elif (choice ==6):
        print("Good By")
        break
    else:
        print("Wrong Choice")
