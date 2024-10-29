def quick_sort(arr, low, high):
    if low < high:
        # Get the partition index
        pi = partition(arr, low, high)
        
        # Recursively sort the elements before and after partition
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)
        
def partition(arr, low, high):
    pivot = arr[high]  # Choose the last element as pivot
    i = low - 1  # Index of smaller element
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements
            
    # Swap the pivot element with the element at index i + 1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1  # Return the partition index

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
