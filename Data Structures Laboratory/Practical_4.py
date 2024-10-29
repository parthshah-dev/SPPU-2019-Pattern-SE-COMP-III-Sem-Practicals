def linear_srch(target, list):
    for i in list:
        if i == target:
            return 1
            
def sentinal_srch(target, list):
    n = len(list)
    last = list[n-1]
    list[n-1] = target #replace the last element with search 
    
    index = 0
    while(list[index]!=target):
        index+=1
    list[n-1] = last #restore original value
    
    if index < list[n-1] or list[n-1] == target:
        return 1
    else:
        return -1
    
def binary_srch(target, list):
    list.sort() #only works on sorted list
    low = 0
    high = len(list)-1
    
    while low<=high:
        mid = (low+high)/2
        if list[mid]==target:
            return mid
        elif list[mid] < target:
            low = mid+1
        else: 
            high = mid-1
    return -1
    
def fibbo_srch(target, list):
    list.sort() #only works on sorted list
    n = len(list)
    
    fibMm2 =0
    fibMm1 =1
    fibM = fibMm2 + fibMm1
    
    while(fibM<n):
        fibMm2 = fibMm1
        fibMm1 = fibM
        fibM = fibMm2+fibMm1
    offset = -1
    
    while(fibM>1):
        i = min(offset+fibMm2, n-1)
        if(list[i]<target):
            fibM = fibMm1
            fibMm1 = fibMm2
            fibMm2 = fibM - fibMm1
            offset = i
            
        elif(list[i]>target):
            fibM = fibMm2
            fibMm1 = fibMm1 - fibMm2
            fibMm2 = fibM - fibMm1
        
        else:
            return i
        
        if(fibMm1 and list[offset+1] == target):
            return offset+1
        else:
            return -1
    
def main():
    stud = []
    n = int(input("Enter number of student: "))
    for i in range(n):
        stu_roll = int(input(f"Enter roll number of student {i+1}: "))
        stud.append(stu_roll)
        
    roll_no = int(input("Enter the roll no to search: "))
    
    print("\n====== CHOOSE SEARCH TYPE ====== \n1. Linear Search \n2. Sentinel Search \n3. Binary Search \n4. Fibbonacci Search")
    
    ch = int(input("Enter your choice: "))
    
    if(ch==1):
        res = linear_srch(roll_no, stud)
        if res == -1:
            print(f"Roll number {roll_no} was not present")
        else:
            print(f"Roll number {roll_no} attended training program")
            
    elif(ch==2):
        res = sentinal_srch(roll_no, stud)
        if res == -1:
            print(f"Roll number {roll_no} was not present")
        else:
            print(f"Roll number {roll_no} attended training program")
            
    elif(ch==3):
        res = binary_srch(roll_no, stud)
        if res == -1:
            print(f"Roll number {roll_no} was not present")
        else:
            print(f"Roll number {roll_no} attended training program")
            
    elif(ch==4):
        res = fibbo_srch(roll_no, stud)
        if res == -1:
            print(f"Roll number {roll_no} was not present")
        else:
            print(f"Roll number {roll_no} attended training program")
            
    else:
        print("\nInvalid choice!")
        
main()
