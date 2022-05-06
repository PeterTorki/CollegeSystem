#include <iostream>
#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <fstream>
#include "College.h"
using namespace std;

void Student_profile_menu()
{

    print(0, '\n');
    setcolor(1);
    print(40, ' ') << "Student Page : \n\n";
    print(40, ' ') << string(20, '-') << "\n";
    setcolor(2);
    cout << string(25, ' ') << "Choose : \n\n";
    cout << string(40, ' ') << char(201);
    for (int i = 0; i < 21; i++)
    {
        cout << char(205);
    }
    cout << char(187) << endl;
    cout << string(40, ' ') << char(186) << "  1- Show my Info    " << char(186) << endl;
    cout << string(40, ' ') << char(186) << "  2- Add a new course" << char(186) << endl;
    cout << string(40, ' ') << char(186) << "  3- Show my courses " << char(186) << endl;
    cout << string(40, ' ') << char(186) << "  4- Update password " << char(186) << endl;
    setcolor(12);
    cout << string(40, ' ') << char(186) << "  5- Logout          " << char(186) << endl;
    setcolor(2);
    cout << string(40, ' ') << char(200);
    for (int i = 0; i < 21; i++)
    {
        cout << char(205);
    }
    cout << char(188) << endl;

    cout << string(25, ' ') << "Choise : ";
}

void Ch_Student()
{

    int Reg_sign;
    print(0, '\n');
    setcolor(1);
    print(40, ' ') << "Student Page : \n\n";
    print(40, ' ') << string(20, '-') << "\n";
    setcolor(2);
    cout << string(25, ' ') << "Choose : \n\n";
    cout << string(40, ' ') << char(201);
    for (int i = 0; i < 18; i++)
    {
        cout << char(205);
    }
    cout << char(187) << endl;

    cout << string(40, ' ') << char(186) << "  1- Register     " << char(186) << endl;
    cout << string(40, ' ') << char(186) << "  2- Sign in      " << char(186) << endl;
    setcolor(12);
    cout << string(40, ' ') << char(186) << "  3- Return Back  " << char(186) << endl;
    cout << string(40, ' ') << char(200);
    for (int i = 0; i < 18; i++)
    {
        cout << char(205);
    }
    cout << char(188) << endl;

    setcolor(2);
    print(25, ' ') << "Choise : ";
    setcolor(6);
    cin >> Reg_sign;

    if (Reg_sign == 3)
        return Returning();
    Directing();
    bool found = 0;
    Student thisStudent;
    if (Reg_sign == 1)
    {
        // register screen
        setcolor(2);
        found = 1;
        fstream fileRegister;

        fileRegister.open("Student.txt", ios::out | ios::app);
        setcolor(1);
        print(40, ' ') << "Student Register Page : \n\n";

        print(40, ' ') << string(20, '-') << "\n";
        setcolor(2);
        print(35, ' ') << "Name: ";
        setcolor(6);
        cin.ignore();
        cin.getline(thisStudent.name, 19);
        setcolor(2);
        print(35, ' ') << "Age: ";
        setcolor(6);
        cin >> thisStudent.age;
        setcolor(2);
        print(35, ' ') << "Department: ";
        setcolor(6);
        cin.ignore();
        cin.getline(thisStudent.Dep, 4);
        setcolor(2);
        print(35, ' ') << "Level: ";
        setcolor(6);
        cin >> thisStudent.level;
        setcolor(2);
        print(35, ' ') << "Password: ";
        setcolor(6);
        set_Password(thisStudent.password);
        thisStudent.id = students_ids.top();
        students_ids.pop();
        Beep(500, 500);
        print(25, ' ') << "\nRegistration Completed ... Your ID is: " << thisStudent.id << "\n";
        press_any();
        fileRegister.write((char *)&thisStudent, sizeof(thisStudent));
        fileRegister.close();
    }
    else if (Reg_sign == 2)
    {
        // sign in
        setcolor(2);
        int id;
        char pass[20];
        for (int i = 0; i < 19; i++)    pass[i] = '\0';
        print(0, '\n');
        cout << string(25, ' ') << "Enter: \n\n";
        print(35, ' ') << "ID: ";
        setcolor(6);
        cin >> id;
        setcolor(2);
        print(35, ' ') << "Password: ";
        setcolor(2);
        set_Password(pass);
        fstream studentsFile;
        Student s1;
        studentsFile.open("Student.txt", ios::in);
        studentsFile.read((char *)&s1, sizeof(s1));
        while (studentsFile)
        {
            bool flag = ((s1.id == id) && strcmp(pass, s1.password) == 0);
            if (flag)
            {
                found = 1;
                thisStudent = s1;
                break;
            }
            studentsFile.read((char *)&s1, sizeof(s1));
        }
        studentsFile.close();
    }
    Directing();
    if (!found)
    {
        print(0, '\n');
        setcolor(12);
        Beep(500, 500);

        cout << string(25, ' ') << "\aThe ID or the Password is wrong, Please try Aagin!\n";
        press_any();
        return Returning();
    }
    // student singed in menu
    do
    {
        int Stu_choice;
        Student_profile_menu();
        setcolor(6);
        cin >> Stu_choice;
        // logout
        if (Stu_choice == 5)
        {
            return Returning();
        }
        Directing();
        if (Stu_choice == 1)
        {
            setcolor(2);
            // Show my information
            print(0, '\n');
            print(40, ' ') << "Student Profile Page : \n\n";
            print(40, ' ') << string(20, '-') << "\n";
            print(35, ' ') << "Name: ";
            setcolor(6);
            cout << thisStudent.name << endl;
            setcolor(2);
            print(35, ' ') << "Age: ";
            setcolor(6);
            cout << thisStudent.age << endl;
            setcolor(2);
            print(35, ' ') << "Level: ";
            setcolor(6);
            cout << thisStudent.level << endl;
            setcolor(2);
            print(35, ' ') << "Department: ";
            setcolor(6);
            cout << thisStudent.Dep << endl;
            press_any();
        }
        else if (Stu_choice == 2)
        {
            // Add a new course
            char anotherCourse;
            do
            {
                // List Courses
                setcolor(2);
                int course_ch;
                print(0, '\n');
                print(40, ' ') << "Student Page : \n\n";
                print(40, ' ') << string(20, '-') << "\n";
                cout << string(25, ' ') << "Choose a course : \n\n";
                int courseNum = 0;
                Teacher t1;
                fstream fileTeachers;
                fileTeachers.open("Teachers.txt", ios::in);
                if (!fileTeachers.is_open())
                {
                    setcolor(12);
                    Beep(500, 500);
                    cout << "\aError when open Teachers.txt for update new course\n";
                    getch();
                }
                fileTeachers.read((char *)&t1, sizeof(t1));
                while (fileTeachers)
                {
                    bool haveCourse = 0;
                    for (auto &courseStudent : thisStudent.courses)
                    {
                        haveCourse |= (t1.course == courseStudent);
                    }
                    if (!haveCourse)
                    {
                        courseNum++;
                        setcolor(6);
                        print(35, ' ') << t1.id << "- " << t1.course.c_Name << endl;
                    }
                    fileTeachers.read((char *)&t1, sizeof(t1));
                }
                fileTeachers.close();
                /// IF YOU HAVE APPLIED IN ALL COURSES
                if (courseNum == 0)
                {
                    setcolor(12);
                    Beep(500, 500);
                    print(35, ' ') << "\aThere is no available courses for you now!\n";
                    press_any();
                    break;
                }
                setcolor(2);
                print(25, ' ') << "Choice : ";
                setcolor(6);
                cin >> course_ch;
                // SEARCHING FOR THE CHOOSEN COURSE
                // ADD THE COURSE FOR THE STUDENT AND ADD THIS STUDENT FOR THE TEACHER OF THE COURSE
                
                fstream fileTeachers2, Temp;
                fileTeachers2.open("Teachers.txt", ios::in | ios::out );
                Temp.open("TeachersCopy.txt", ios::out);
                fileTeachers2.read((char *)&t1, sizeof(t1));
                courseNum = 1;
                while (fileTeachers2)
                {
                    if (course_ch == t1.id)
                    {
                        thisStudent.addCourse(t1.course);
                        t1.addStudent(thisStudent);
                        // int currPos = fileTeachers2.tellg();
                        // int sizeTec = sizeof(t1);
                        // fileTeachers2.seekp(currPos - sizeTec, ios::beg);
                        // fileTeachers2.write((char *)&t1, sizeof(t1));
                    }
                    Temp.write((char *)&t1, sizeof(t1));
                    fileTeachers2.read((char *)&t1, sizeof(t1));
                }
                Temp.close();
                fileTeachers2.close();
                remove("Teachers.txt");
                rename("TeachersCopy.txt", "Teachers.txt");
                
                // PUT THE CHOOSEN COURSE IN YOUR RECORD
                Student s2;
                fstream studentFileToUpdate;
                studentFileToUpdate.open("Student.txt", ios::in | ios::out);
                if (!studentFileToUpdate.is_open())
                {
                    setcolor(12);
                    Beep(500, 500);
                    print(25, ' ') << "\aError here ... There is no Studnt!, Please Read the Readme.txt file and try again\n";
                    getch();
                    return;
                }
                studentFileToUpdate.read((char *)&s2, sizeof(s2));
                while (studentFileToUpdate)
                {
                    if (thisStudent == s2)
                    {
                        int currPos = studentFileToUpdate.tellg();
                        int studSize = sizeof(s2);
                        studentFileToUpdate.seekp(currPos - studSize, ios::beg);
                        studentFileToUpdate.write((char *)&thisStudent, sizeof(thisStudent));
                        break;
                    }
                    studentFileToUpdate.read((char *)&s2, sizeof(s2));
                }
                studentFileToUpdate.close();
                setcolor(2);
                cout << string(25, ' ') << "Do you want to Add an another Course? (Y/N): ";
                setcolor(6);
                cin >> anotherCourse;
                if (tolower(anotherCourse) != 'n')
                    Directing();
            } while (tolower(anotherCourse) != 'n');
        }
        else if (Stu_choice == 3)
        {
            setcolor(2);
            // Show my courses
            print(0, '\n');
            print(40, ' ') << "Student's Courses Page : \n\n";
            print(40, ' ') << string(20, '-') << "\n\n";
            if (thisStudent.NumOfCourses == -1)
            {
                setcolor(12);
                Beep(500, 500);
                print(35, ' ') << "\ayou haven't applied to any courses yet!\n";
            }
            else
            {
                print(35, ' ') << "ID\t\t\tName\n";
                print(35, ' ') << "--\t\t\t----\n";
                for (int i = 0; i <= thisStudent.NumOfCourses; i++)
                {
                    auto course1 = thisStudent.courses[i];
                    setcolor(6);
                    print(35, ' ') << course1.c_id << "\t\t\t" << course1.c_Name << endl;
                }
            }
            press_any();
        }
        else if (Stu_choice == 4)
        {
            setcolor(2);
            // Update password
            print(0, '\n');
            print(35, ' ') << "Enter the new Password: ";
            setcolor(6);
            set_Password(thisStudent.password);
            setcolor(5);
            Beep(500, 500);
            cout << "\n"
                 << string(35, ' ') << "Password Changed\n";
            Student s2;
            fstream studentFileToUpdate;
            studentFileToUpdate.open("Student.txt", ios::in | ios::out);
            if (!studentFileToUpdate.is_open())
            {
                setcolor(12);
                Beep(500, 500);
                cout << "\aError When open student.txt file to add course...\n";
                getch();
                return;
            }
            studentFileToUpdate.read((char *)&s2, sizeof(s2));
            while (studentFileToUpdate)
            {
                if (thisStudent == s2)
                {
                    int currPos = studentFileToUpdate.tellg();
                    int studSize = sizeof(s2);
                    studentFileToUpdate.seekp(currPos - studSize, ios::beg);
                    studentFileToUpdate.write((char *)&thisStudent, sizeof(thisStudent));
                    break;
                }
                studentFileToUpdate.read((char *)&s2, sizeof(s2));
            }
            studentFileToUpdate.close();
        }
        Directing();
    } while (1);
}
