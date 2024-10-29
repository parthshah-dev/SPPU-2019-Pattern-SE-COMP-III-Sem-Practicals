/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member's information using singly linked list, Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
*/

#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int prn;
    string name;
    Node* next;
};

//class to manage Pinnacle club
class PinnacleClub {
    Node* head;

    public:
        PinnacleClub(){
            head = nullptr;
        }

        //function to add president(at beginning)
        void addPresident(int prn, string name){
            if (head != nullptr) {
                cout << "President already exists. Cannot add another president.\n";
                return;
            }
            Node* newPresident = new Node;
            newPresident->prn = prn;
            newPresident->name = name;
            newPresident->next = head;
            head = newPresident;
        }

        //function to add secretary(at the end)
        void addSecretary(int prn, string name){
            if (head == nullptr) {
                cout << "Add a president first before adding a secretary.\n";
                return;
            }
            Node* newSecretary = new Node;
            newSecretary->prn = prn;
            newSecretary->name = name;
            newSecretary->next = nullptr;

            //adding secretary node at the end by traversing the LL
               Node* temp = head;
               while (temp->next!=nullptr){
                    temp = temp->next;
               }
               temp->next = newSecretary;
        }     

        //function to add members(in the middle)
        void addMembers(int prn, string name){
            if (head == nullptr || head -> next == nullptr) {
                cout << "Add a president and secretary before adding members.\n";
                return;
            }

            Node* newMember = new Node;
            newMember->prn = prn;
            newMember->name = name;
            newMember->next = nullptr;

            // Traverse to find the node just before the secretary
            Node* temp = head;
            while (temp->next->next!=nullptr){ //traverse to last second node
                temp = temp->next;
            }

            //Inserting new member just before the secretary
            newMember->next = temp->next; //points to secretary
            temp->next = newMember; //previous member points to new one
        }  

        //function to delete a member
        void deleteMember(int prn){
            if(head==nullptr){
                cout << "No members are there in the club\n";
                return;
            }
            
            Node* temp = head;
            Node* prev = nullptr;

            //search the member to be deleted
            while(temp!=nullptr && temp->prn!=prn){
                prev = temp;
                temp = temp->next;
            }

            //if member not found
            if(temp==nullptr){
                cout << "Member with PRN " << prn << " not found!\n";
            }

            //unlink the node and delete it 
            prev->next = temp->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted!\n";
        }

        // Function to compute total number of members
        int total(){
            Node* temp = head;
            int count = 0;
            while(temp!=nullptr){
                count++;
            }
            return count;
        }

        // Function to display all members
        void displayMembers(){
            Node* temp = head;
            if(temp == nullptr){
                cout << "No members in the club!\n";
            }
            while (temp!=nullptr)
            {
                cout << "=====================\n";
                cout << "PRN: " << temp->prn << " \n" << "Name: " << temp->name << "\n";
                cout << "=====================";
                temp = temp->next;
            }
        }

        // Function to concatenate two LL
        void concatenate(PinnacleClub& otherclub){
            if(head==nullptr){
                head = otherclub.head;
            }
            Node* temp = head;
            while(temp!=nullptr){
                temp = temp->next;
            }
            temp->next = otherclub.head;
        }
};

int main() {
    PinnacleClub club;
    int choice;
    int prn;
    string name;

    do {
        cout << "\n****** Welcome to Pinnacle Club ******\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete Member\n";
        cout << "5. Display Members\n";
        cout << "6. Compute Total Members\n";
        cout << "7. Concatenate with Another Division\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN for President: ";
                cin >> prn;
                cout << "Enter Name for President: ";
                cin >> name;
                club.addPresident(prn, name);
                break;

            case 2:
                cout << "Enter PRN for Secretary: ";
                cin >> prn;
                cout << "Enter Name for Secretary: ";
                cin >> name;
                club.addSecretary(prn, name);
                break;

            case 3:
                cout << "Enter PRN for Member: ";
                cin >> prn;
                cout << "Enter Name for Member: ";
                cin >> name;
                club.addMembers(prn, name);
                break;

            case 4:
                cout << "Enter PRN of Member to Delete: ";
                cin >> prn;
                club.deleteMember(prn);
                break;

            case 5:
                club.displayMembers();
                break;

            case 6:
                cout << "Total number of members: " << club.total();
                cout << endl;
                break;

            case 7: {
                PinnacleClub otherClub;
                int numMembers;
                cout << "How many members to add to the other division? ";
                cin >> numMembers;

                for (int i = 0; i < numMembers; ++i) {
                    cout << "Enter PRN for Member " << (i + 1) << ": ";
                    cin >> prn;
                    cout << "Enter Name for Member " << (i + 1) << ": ";
                    cin >> name;
                    otherClub.addMembers(prn, name);
                }
                club.concatenate(otherClub);
                cout << "Other division concatenated successfully.\n";
                break;
            }

            case 8:
                cout << "Thank you for using the program!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}




