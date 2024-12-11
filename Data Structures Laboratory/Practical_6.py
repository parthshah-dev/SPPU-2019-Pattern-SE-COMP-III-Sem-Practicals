#Program to sort floating point numbers in ascending order using Quick Sort

def quick_sort(lst, start, end):
    if(start >= end): #if reaches single element or start less than end
        return
    pivot = partition(lst, start, end)
    quick_sort(lst, start, pivot - 1) #left subarray
    quick_sort(lst, pivot + 1, end) #right subarray

def partition(lst, start, end):
    pos = start
    for i in range(start, end + 1): 
        if(lst[i] <= lst[end]):
            lst[i], lst[pos] = lst[pos], lst[i]
            pos = pos + 1
    return pos - 1 #returning position of pivot

def top_five(arr):
    n = len(arr)
    quick_sort(arr, 0, n - 1)  # Sort using Quick Sort
    print("Top five scores of the class are:")
    for i in range(n - 5, n):
        if i >= 0:  
            print(arr[i])

def main():
    stud_mark = []
    n = int(input("Enter number of students: "))
    for i in range(n):
        mark = float(input(f"Enter percentage of student {i+1}: "))
        stud_mark.append(mark)
    
    print("\n====== QUICK SORT ======")
    
    # Sorting the list using Quick Sort
    quick_sort(stud_mark, 0, len(stud_mark) - 1)
    print("\nPercentages sorted using Quick Sort:", stud_mark)
    
    # Displaying top five scores
    top_five(stud_mark)

# Run the main function
main()
