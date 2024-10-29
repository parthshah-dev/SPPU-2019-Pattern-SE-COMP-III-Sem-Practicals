def selec_sort(list):
    n = len(list)
    for i in range(n):
        min = i
        for j in range(i+1, n):
            if list[j] < list[min]:
                min = j
        list[i], list[min] = list[min], list[i]
    return list
        
def bubble_sort(list):
    n = len(list)
    for i in range(n-1):
        for j in range(n-i-1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
    return list

def top_five(list):
    bubble_sort(list)
    top = list[-5:]
    print("Top five scores of the class are: ", top)
    
def main():
    stud_mark = []
    n = int(input("Enter number of student: "))
    for i in range(n):
        mark = float(input(f"Enter percentage of student {i+1}: "))
        stud_mark.append(mark)
         
    print("\n====== CHOOSE SORTING TYPE ====== \n1. Selection Sort \n2. Bubble Sort \n3. Display Top Five Scores")
    
    ch = int(input("\nEnter your choice: "))
    
    if(ch==1):
        print("\nPercentages sorted using Selection Sort:", selec_sort(stud_mark))
            
    elif(ch==2):
        print("\nPercentages sorted using Bubble Sort:", bubble_sort(stud_mark))
        
    elif(ch==3):
        top_five(stud_mark)
            
    else:
        print("\nInvalid choice!")
        
main()
