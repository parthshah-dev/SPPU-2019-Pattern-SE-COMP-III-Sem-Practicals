def average(l1):
    sum = count = 0
    for i in l1:
        if(i!=-1):
            sum+=i
            count = count+1
    average = (sum/count)
    print("\nThe Average of class is: ", average)
    
def high_low(l1):
    high_score = max(l1)
    low_score = min(l1)
    print("\nHighest score of class: ", high_score)
    print("\Lowest score of class: ", low_score)
    
def absent_count(l1):
    count = 0
    for i in l1:
        if(i==-1):
            count = count+1
    print("Number of students absent for test: ", count)

def high_frequency(l1):
    frequency = {}
    for i in l1:
        if i != -1: 
            if i in frequency:
                frequency[i] += 1
            else:
                frequency[i] = 1
    
    if frequency:
        max_freq = max(frequency.values())
        most_frequent_scores = [score for score, freq in frequency.items() if freq == max_freq]
        print("Mark(s) with highest frequency:", most_frequent_scores, "with frequency:", max_freq)
    else:
        print("No valid scores to calculate frequency.") 
    
    
def menu():
    marks = []
    num = int(input("Enter number of students: "))
    for i in range(num):
        mark = int(input(f"Enter marks of student {i+1} (-1 for absent): "))
        marks.append(mark)
        print()
    print("\n====== MENU ====== \n1. Average score of class \n2. Highest score and lowest score of class \n3. Count of student absent for test \n4. Marks with highest frequency")
    
    ch = int(input("Enter your choice: "))
    if(ch==1):
        average(marks)
    elif(ch==2):
        high_low(marks)
    elif(ch==3):
        absent_count(marks)
    elif(ch==4):
        high_frequency(marks)
    else:
        print("Invalid choice")
    
menu()