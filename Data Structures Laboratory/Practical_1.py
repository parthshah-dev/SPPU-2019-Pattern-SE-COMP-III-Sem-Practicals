'''
Experiment No. 1 : In a second year computer engineering class, group A students play cricket, group B students play
                   badminton and group C students play football.
                   Write a python program using functions to compute following:
                   a) List of students who play both cricket and badminton.
                   b) List of students who play either cricket or badminton but not both.
                   c) Number of students who play neither cricket nor badminton.
                   d) Number of students who play cricket and football but not badminton.
(NOTE : While realising the group, duplicate entries should be avoided. Do not use SET built-in functions)
'''

#function to remove duplicates 
def removeDupliactes(d):
    list=[]
    for i in d:
        if i not in list:
            list.append(i)
    return list


#function for finding union of two sets
def setUnion(set1, set2):
    set3 = set1.copy()
    for i in set2:
        if i not in set3:
            set3.append(i)
    return set3


#function for finding intersection of two sets
def setIntersection(set1, set2):
    set3 = []
    for i in set1:
        if i in set2:
            set3.append(i)
    return set3


#function for finding difference of two sets
def setDifference(set1, set2):
    set3 = []
    for i in set1:
        if i not in set2:
            set3.append(i)
    return set3

#function for finding symmetric difference of two sets
def setSymDiff(set1, set2):
    set3 = []
    for i in set1:
        if i not in set2:
            set3.append(i)
            
    for i in set2:
        if i not in set1:
            set3.append(i)
    return set3


#function to find list of students who play both cricket and badminton
def CB(set1, set2):
    cblist = setUnion(set1, set2)
    print("List of students who play both cricket and badminton is: ", cblist)
    
    
#function to find list of students who play either cricket or badminton but not both
def eCeB(set1, set2):
    lst = setSymDiff(set1, set2)
    print("List of students who play either cricket or badminton but not both is: ", lst)
    
    
#function to find number of students who play neither cricket nor badminton
def nCnB(secomp, cric, badm):
    lst = setDifference(secomp, setUnion(cric, badm))
    print("Number of students who play neither cricket nor badminton is: ", len(lst))
    
    
#function to find number of students who play cricket and football but not badminton
def CFnB(foot, cric, badm):
    lst = setDifference(setUnion(foot, cric, badm), badm)
    print("Number of students who play cricket and football but not badminton is: ", len(lst))
    
    
#Main function

#creating an empty list for students in SE Comp
SEComp = []
n = int(input("Enter number of students in SE Comp: "))
for i in range(n):
    print("Enter ",i+1, " name(Press ENTER after entering): ")
    ele = input()
    SEComp.append(ele)
print("Original list of SE Comp is: ", str(SEComp))


#creating a list for students who play cricket
Cricket = []
n = int(input("Enter number of students who play cricket: "))
for i in range(n):
    print("Enter ",i+1, " name(Press ENTER after entering): ")
    ele = input()
    Cricket.append(ele)
print("Original list of students who play cricket is: ", str(Cricket))
Cricket = removeDupliactes(Cricket)
print("The list of students playing cricket after removing duplicates is: ", str(Cricket))


#creating a list for students who play football
Football = []
n = int(input("Enter number of students who play football: "))
for i in range(n):
    print("Enter ",i+1, " name(Press ENTER after entering): ")
    ele = input()
    Football.append(ele)
print("Original list of students who play football is: ", str(Football))
Football = removeDupliactes(Football)
print("The list of students playing football after removing duplicates is: ", str(Football))


#creating a list for students who play badminton
Badminton = []
n = int(input("Enter number of students who play badminton: "))
for i in range(n):
    print("Enter ",i+1, " name(Press ENTER after entering): ")
    ele = input()
    Badminton.append(ele)
print("Original list of students who play badminton is: ", str(Badminton))
Badminton = removeDupliactes(Badminton)
print("The list of students playing badminton after removing duplicates is: ", str(Badminton))



flag = 1
while flag == 1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. List of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit\n")
    ch = int(input("Enter your choice(1 to 5): "))
    
    if ch == 1:
        CB(Cricket, Badminton)
        a = input("Do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
            
    elif ch == 2:
        eCeB(Cricket, Badminton)
        a = input("Do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
            
    elif ch == 3:
        nCnB(SEComp, Cricket, Badminton)
        a = input("Do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
            
    elif ch == 4:
        CFnB(Football, Cricket, Badminton)
        a = input("Do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")
            
    elif ch == 5:
            flag = 0
            print("Thanks for using this program!")
            
    else:
        flag = 0
        print("Invalid choice!.......")
        
#End of Program