def longest_word(str):
    words = str.split()
    longest = max(words, key=len)
    print("Longest word: ", longest)
    
def char_occur(str):
    c = input("Enter a character: ")
    c_count = 0
    for i in str:
        if(c==i):
            c_count = c_count+1
    print(f"Character '{c}' occurs {c_count} in the string")    

def is_palindrome(str):
    str = str.lower()
    reversed_str = str[::-1]
    if(str==reversed_str):
        print("String is a Palindrome")
    else:
        print("String is not a Palindrome")
        
def app_substr(str):
    sub_str = input("Enter a sub-string: ")
    substr_index = str.find(sub_str)
    print(f"Index of first appearance of {sub_str} in {str}: ", substr_index)
    
def word_occur(str):
    words = str.split()
    word_count = {}
    
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    print("Occurrences of each word in string:", word_count)

def menu():
    str = input("Enter the string: ");
    print("\n\nYour string: ", str)
    
    print("\n====== MENU ====== \n1. Word with longest length \n2. Frequency of occurance of a particular character \n3. Check for Palindrome \n4. Index of first appearance of the substring \n5. Occurances of each word in string")
    
    ch = int(input("Enter your choice: "))
    
    if(ch==1):
        longest_word(str)
    elif(ch==2):
        char_occur(str)
    elif(ch==3):
        is_palindrome(str)
    elif(ch==4):
        app_substr(str)
    elif(ch==5):
        word_occur(str)
    else:
        print("\nInvalid choice!")
        
menu()