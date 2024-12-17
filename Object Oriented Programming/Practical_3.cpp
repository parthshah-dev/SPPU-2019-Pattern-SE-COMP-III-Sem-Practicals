/*
Imagine a publishing company that handles marketing for both book and audiocassette versions. Create a base class Publication that stores the title (a string) and price (type float). From this class, derive two classes: Book, which adds a page count (type int), and Tape, which adds a playing time in minutes (type float). Write a program that instantiates the Book and Tape classes, allows the user to enter data for each, and then displays their respective data members. If an exception is caught, replace all the data member values with zero values.
*/

#include<iostream>
#include<string>
using namespace std;

class Publication{
    private: 
        string title;
        float price;

    public:
        void pubAdd(){
            cout << "Enter Publication Information" << endl;
            cout << "Enter Publication Title: ";
            cin >> title;
            cout << "\nEnter Publication Price: ";
            cin >> price;
        }
        void pubDisp(){
            cout << "Publication Title: " << title << endl;
            cout << "Publication Price: " << price << endl;
        }
};
class Book : public Publication{
    private:
        int pageCount;

    public:
        void addBook(){
            try{
                pubAdd();
                cout << "\nEnter Page Count of Book: ";
                cin >> pageCount;

                if(pageCount<=0){
                    throw pageCount;
                }
            }
            catch(...){
                cout << "Invalid page count!";
                pageCount = 0;
            }
        }
        void dispBook(){
            cout << "---------- Book Information ----------" << endl;
            pubDisp();
            cout << "Page count of Book: " << pageCount << endl; 
            cout << "--------------------------------------" << endl;
        }
};
class Tape : public Publication{
    private:
        float playTime;

    public:
        void addTape(){
            try{
                pubAdd();
                cout << "\nEnter Playing Time of Tape";
                cin >> playTime;
                if(playTime<=0){
                    throw playTime;
                }
            }
            catch(...){
                cout << "Invalid playing time!";
                playTime = 0;   
            }
        }
        void dispTape(){
            cout << "---------- Tape Information ----------" << endl;
            pubDisp();
            cout << "Playing Time of Tape: " << playTime << endl;
            cout << "--------------------------------------" << endl; 
        }
};
int main(){
    Book b_obj[10];
    Tape t_obj[10];
    int b_count = 1, t_count = 1, ch;

    do{
        cout << "*********** PUBLICATION DATABASE ***********" << endl;
        cout << "1. Add Book Information" << endl;
        cout << "2. Add Tape Information" << endl;
        cout << "3. Display Book Information" << endl;
        cout << "4. Display Tape Information" << endl;
        cout << "5. Exit\n" << endl;
        int ch;
        cout<< "Enter choice (1 to 5): ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                b_obj[b_count].addBook();
                b_count++;
                break;

            case 2:
                t_obj[t_count].addTape();
                t_count++;
                break;
                
            case 3:
                for(int i=0; i<b_count; i++){
                    b_obj[i].dispBook();
                }
                break;

            case 4:
                for(int i=0; i<t_count; i++){
                    t_obj[i].dispTape();
                }
                break;

            case 5:
                exit(0);
            
            default:
                cout << "Invalid Choice!";
                break;
        }
    }while (ch!=5);

    return 0;
}
