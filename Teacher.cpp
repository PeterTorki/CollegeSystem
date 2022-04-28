#include<iostream>
#include "College.h"
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

void Ch_Teacher(){
    int Reg_sign;
    //print(15, ' ');
    setcolor(1);
    print(40, ' ') << "Teacher Login Page : \n\n";
    print(40, ' ') << string(20, '-') << "\n";
    setcolor(2);
    cout << string(40, ' ') <<char(201);      for(int i=0; i< 18; i++){cout << char(205);}      cout << char(187) << endl;

    cout << string(40, ' ') <<char(186) << "  1- Sign in      " << char(186) << endl;
    setcolor(12);
    cout << string(40, ' ') <<char(186) << "  2- Return Back  " << char(186) << endl;
    cout << string(40, ' ') <<char(200);      for(int i=0; i<18; i++){cout << char(205);}      cout << char(188) << endl;
    setcolor(2);
    print(30, ' ') << "choice : ";
    setcolor(6);
    cin >> Reg_sign;
    Teacher thisTeacher;
    if(Reg_sign == 1){
        Directing();
        int id;         char pass[20];
        for (int i = 0; i < 19; i++) pass[i] = '\0';
       // print(15, ' ');
       setcolor(1);
        print(40, ' ') << "Teacher Page : \n\n";
        print(40, ' ') << string(20, '-') << "\n";
        setcolor(2);
        print(25, ' ') << "Enter: \n\n" ;
        print(35, ' ') << "ID: ";
        setcolor(6);
        cin >> id;
        setcolor(2);
        print(35, ' ') << "Password: ";
        setcolor(6);
        set_Password(pass);

        Directing();

        bool found = 0;
        Teacher t1;
        fstream teacherFile;
        teacherFile.open("Teachers.txt", ios::in);
        if (!teacherFile.is_open()) {
            cout << "\aerror here, Please first create a student from admin screen";
            press_any();
            Returning();
            return ;
        }
        teacherFile.read((char*)&t1, sizeof(t1));
        while (!teacherFile.eof()){
            bool flag = (!strcmp(t1.password, pass) && (t1.id == id));
            if(flag){

                found = 1;
                thisTeacher = t1;
                break;
            }
            teacherFile.read((char*)&t1, sizeof(t1));
        }
        teacherFile.close();
        Directing();
        if(!found) {
            print(15, ' ');
            setcolor(12);
            Beep(500,500);
            cout <<  string(25, ' ') << "The ID or Password is wrong!!!\n";
            return Returning();
        }
        do{
            int Teac_choice;
           // print(15, ' ');
            setcolor(1);
            print(40, ' ') << "Teacher Page : \n\n";
            print(40, ' ') << string(20, '-') << "\n";
            setcolor(2);
            cout << string(40, ' ') <<char(201);      for(int i=0; i< 21; i++){cout << char(205);}      cout << char(187) << endl;
            cout << string(40, ' ') <<char(186) << "  1- Show my Info    " << char(186) << endl;
            cout << string(40, ' ') << char(186) <<"  2- Show my students"<< char(186) << endl;
            cout << string(40, ' ') << char(186) <<"  3- Update password "<< char(186) << endl;
            setcolor(12);
            cout << string(40, ' ') << char(186) <<"  4- Logout          "<< char(186) << endl;
            cout << string(40, ' ') <<char(200);      for(int i=0; i<21; i++){cout << char(205);}      cout << char(188) << endl;

            setcolor(2);
            print(35, ' ') << "Choice : ";
            setcolor(6);
            cin >> Teac_choice;
            Directing();

            if(Teac_choice == 1){
                // Show my Info
                //print(15, ' ');
                setcolor(1);
                print(40, ' ') << "Teacher Page : \n\n";
                print(40, ' ') << string(20, '-') << "\n";
                setcolor(2);
                print(35, ' ') << "ID: ";
                setcolor(6);
                cout<< thisTeacher.id << "\n";
                setcolor(2);
                print(35, ' ') << "Password: ";
                setcolor(6);

                cout<< thisTeacher.password << "\n";
                setcolor(2);
                print(35, ' ') << "Name: ";
                setcolor(6);
                cout<< thisTeacher.name << "\n";
                setcolor(2);
                print(35, ' ') << "Age: ";
                setcolor(6);
                cout<< thisTeacher.age << "\n\n\n";
                setcolor(5);
                print(35, ' ') << "Press Any key to return...";
                _getch();
                Directing();
            }

            else if(Teac_choice == 2){
                // Show my students
               // print(15, ' ');
                setcolor(1);
                print(40, ' ') << "Teacher Page : \n\n";
                print(40, ' ') << string(20, '-') << "\n";
                if (thisTeacher.NumOfStudents == -1) {
                    setcolor(5);
                    Beep(500,500);
                    cout << "NO STudents here\n";
                    getch();
                }
                setcolor(2);
                print(35, ' ') << "ID\t" << "Name\t" << "age\n";
                print(35, ' ') << "---\t----\t---\n";
                setcolor(6);
                for (int i = 0; i <= thisTeacher.NumOfStudents; i++) {

                    print(35, ' ') << thisTeacher.Tec_Stu[i].id << "\t" << thisTeacher.Tec_Stu[i].name << "\t" << thisTeacher.Tec_Stu[i].age << endl;
                }
                setcolor(5);
                print(35, ' ') << "Press Any key to return... ";
                _getch();
                Directing();
            }

            else if(Teac_choice == 3){
                // Update password
                print(15, ' ');
                setcolor(2);
                print(35, ' ') << "Enter the new Password: ";
                setcolor(6);
                set_Password(thisTeacher.password);
                setcolor(5);
                //print(20, ' ');
                Beep(500,500);
                cout << "\n" << string(35, ' ') << "Password Changed\n\n";
                Teacher t2;
                fstream TeacherUpdate;
                TeacherUpdate.open("Teachers.txt", ios::in | ios::out);

                if (!TeacherUpdate.is_open()) {
                    setcolor(5);
                    Beep(500,500);
                    cout << "Error When open Teachers.txt ...\n";
                    getch();
                    return ;
                }

                TeacherUpdate.read((char*)&t2, sizeof(t2));
                while (!TeacherUpdate.eof()) {
                    if (thisTeacher == t2) {
                        int currPos = TeacherUpdate.tellg();
                        int teaSize = sizeof(t2);
                        TeacherUpdate.seekp(currPos - teaSize, ios::beg);
                        TeacherUpdate.write((char*)& thisTeacher, sizeof(thisTeacher));
                        break;
                    }
                    TeacherUpdate.read((char*)&t2, sizeof(t2));
                }
                TeacherUpdate.close();
            }
            else if(Teac_choice == 4){
                // Logout
                break;
            }
        }while(1);
    }
    Returning();
}
