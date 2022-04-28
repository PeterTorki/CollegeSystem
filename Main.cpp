#include <iostream>
#include <queue>
#include <conio.h>
#include <windows.h>
#include "Student_Part.cpp"
#include "Teacher.cpp"
#include "Admin.cpp"
#include "College.h"
using namespace std;

int main(){
    init_student_ids();
    init_teacher_ids();
    do{
        setcolor(2);
        int choice;
        cout << string(15, '\n');
        cout << string(50, ' ') <<char(201);      for(int i=0; i< 21; i++){cout << char(205);}      cout << char(187) << endl;
        cout << string(50, ' ') <<char(186) << "    College System   " << char(186) << endl;
        cout << string(50, ' ') <<char(200);      for(int i=0; i<21 ; i++){cout << char(205);}      cout << char(188) << endl;

        cout << string(3, '\n');

        cout << string(30, ' ') << "   Choose who are you: \n\n";
        cout << string(50, ' ') <<char(201);      for(int i=0; i< 15; i++){cout << char(205);}      cout << char(187) << endl;
        cout << string(50, ' ') <<char(186) << "  1- Student   " << char(186) << endl;
        cout << string(50, ' ') << char(186) <<"  2- Teacher   "<< char(186) << endl;
        cout << string(50, ' ') << char(186) <<"  3- Admin     " << char(186) << endl;
        setcolor(12);
        cout << string(50, ' ') <<char(186) << "  4- Exit      "<< char(186) << endl;
        setcolor(2);

        cout << string(50, ' ') <<char(200);      for(int i=0; i<15; i++){cout << char(205);}      cout << char(188) << endl;

        cout << string(35, ' ') << "Choise : ";
        setcolor(6);
        cin >> choice;
        cout << "\n" << string(35, ' ');
        (choice > 3 ? Returning() : Directing());
        system("CLS");

        if(choice == 1) // 1 1
            Ch_Student();

        else if(choice == 2) // 2 2
            Ch_Teacher();

        else if(choice == 3)
            Ch_Admin();
        else
            return 0;
    }while(1);
}
