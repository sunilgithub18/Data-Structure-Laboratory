'''
AIM:
Write a Python program for department library which has N books, 
write functions for following:
a) Display books in ascending order based on cost of books
b) Delete the duplicate entries
c) Count number of books with cost more than 500.
d) Copy books in a new list which has cost less than 500.
(in Python without using built-in functions)

INPUT: Book Information
    1. Number of books 'N' in department library
    2. Name of book, author, cost for 'N' books

OUTPUT:
    1. Display list Book 
    2. Display List of Books in ascending order of cost
    3. Delete the duplicate entries
    4. Number of books having cost more than 500
    5. Copy books in a new list which has cost less than 500

AUTHOR: Dr. Sunil D. Rathod
DATE: 11.07.2024
'''
#ADT of Book
class Book:
    def __init__(self):
        self.name=None
        self.cost=0

#Implementation class
class DepartmentLibrary:
    def __init__(self):
        self.N=0
        self.bookList=[]
        self.newBookList=[]#Books cost less than 500
    
    def initialization(self):
        self.N=0
        self.bookList=[]
    
    #1. Read Book Details
    def getBookDetail(self,nob):
        for i in range(nob):
            book=Book()
            print("Enter book name and cost for book-",i+1)
            name=input("Enter Name of book::")
            cost=int(input("Enter book cost::"))
            book.name=name
            book.cost=cost
            self.bookList.append(book)
        
        self.N=self.N+nob
        
    #2. Display List Book
    def displayBookList(self):
        print("\n\tName    Cost")
        for i in range(self.N):
            print("\n\t",self.bookList[i].name,"  ",self.bookList[i].cost)

    #3. Display List of Books in acesding order of cost
    def sortBookList(self):
        for i in range(self.N-1):
            for j in range(0,self.N-i-1):
                if self.bookList[j].cost > self.bookList[j+1].cost:
                    temp=self.bookList[j]
                    self.bookList[j] = self.bookList[j+1] 
                    self.bookList[j+1]=temp

    # abcdaebf
    
    #4. Delete the duplicate entries
    def deleteDuplicates(self):
        
        dupList=[]
        i=0
        #Find duplicates
        flag=True
        i=0
        while(flag):
            count=0
            j=i+1
            curLen=len(self.bookList)
            while(j<curLen):
                if self.bookList[i].name==self.bookList[j].name:
                   count+=1
                   if(count>=1):
                        self.bookList.pop(j)
                        curLen=len(self.bookList)
                j+=1
                        
            i+=1
            if(i>=len(self.bookList)):
                flag=False
        #bookList has got its size changed now after deleting Duplicates
        self.N=len(self.bookList)
        
    #5. Number of books having cost more than 500
    def moreCost(self):
        nob=0
        for i in range(len(self.bookList)):
            if(self.bookList[i].cost>500):
                nob+=1
        
        print("Number of books having cost greater than 500::",nob)
     
     #6. Copy books in a new list which has cost less than 500
    def underCostList(self):
        
        for i in range(len(self.bookList)):
            if(self.bookList[i].cost<500):
                self.newBookList.append(self.bookList[i])
        
        for i in range(len(self.newBookList)):
            print("\n\t",self.newBookList[i].name,"  ",self.newBookList[i].cost)
        
        
#Driver Code
lib=DepartmentLibrary()
choice=0

while(choice !=7):
    print("*************DEPARTMENT LIBRARY****************")
    print("1. Read Book Details")
    print("2. Display List Book")
    print("3. Display List of Books in ascending order of cost")
    print("4. Delete the duplicate entries")
    print("5. Number of books having cost more than 500")
    print("6. Copy books in a new list which has cost less than 500")
    print("7. Exit Application")
    choice=int(input("What operation::"))
    
    if (choice ==1):
        n=int(input("Enter number of books to be stored::"))
        lib.getBookDetail(n)
    elif (choice ==2):
        lib.displayBookList()
    elif (choice ==3):
        lib.sortBookList()
    elif (choice ==4):
        lib.deleteDuplicates()
    elif (choice ==5):
        lib.moreCost()
    elif (choice ==6):
        lib.underCostList()
    elif (choice ==7):
        print("Good By")
        break
    else:
        print("Wrong Choice")
