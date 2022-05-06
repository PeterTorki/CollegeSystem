#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <vector>
#include <conio.h>
#include <queue>
#include <windows.h>
#include <string.h>
#define print(x, ch) cout << string(x + 20, ch) 
using namespace std;
void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

void press_any() {
    setcolor(5);
    cout << "\n" << string(55, ' ') << "Press any key to return back...";
    getch();
}

void print_logo(string s, int size = 50){
        
        cout << string(15, '\n');
        print(size, ' ') << char(201);
        for (int i = 0; i < s.size() + 10; i++)
        {
            cout << char(205);
        }
        cout << char(187) << endl;
        print(size, ' ') << char(186) << "     " << s << ("     ") << char(186) << endl;
        print(size, ' ') << char(200);
        for (int i = 0; i < s.size() + 10; i++)
        {
            cout << char(205);
        }
        cout << char(188) << endl;
        cout << string(3, '\n');
}

void Directing(){
    setcolor(6);
    cout << "\n" << string(55, ' ') << "Redicrecting";
    Sleep(250); cout << "."; Sleep(250); cout << ".";
    Sleep(250); cout << "."; Sleep(250); cout << "!";
    system("CLS");
}

void Returning(){
    setcolor(4);
    cout << "\n" << string(55, ' ') << "Returning";
    Sleep(250); cout << "."; Sleep(250); cout << ".";
    Sleep(250); cout << "."; Sleep(250); cout << "!";
    Sleep(1000);
    system("CLS");
}

void set_Password(char *get_in){
    for (int i = 0; i < 19;) {
        char ch = getch();
        if (ch == 13) {
            get_in[i] = '\0';
            break;
        }
        else if(ch != 8){
            get_in[i] = ch;
            putch('*');
            i++;
        }
        else if(i > 0)
            cout << "\b \b",get_in[i] = '\0' ,i--;
    }
    cout << "\n";
}

class Human{
    public:
        char name[20];
        char password[20];
        int id, age;
        Human() {
            for (int i = 0; i < 19; i++) name[i] = '\0';
            for (int i = 0; i < 19; i++) password[i] = '\0';
        }
};


class Admin : public Human{

};

class Course{
    public:
        int c_id;
        char c_Name[20];
        // Mina == overload update v 1.1
        Course() {
            c_id = 0;
            for (int i = 0; i < 19; i++) c_Name[i] = '\0';
        }
        bool operator==(const Course& rhs) const {
            return c_id == rhs.c_id && (strcmp(c_Name,rhs.c_Name) == 0);
        }
};

class Student : public Human{
    public:
        Course courses[10];
        int NumOfCourses;
        char Dep[3];
        int level;
        Student() {
            NumOfCourses = -1;
            level = 0;
            for (int i = 0; i < 2; i++) Dep[i] = '\0';
        }
        void addCourse(Course course1) {

            //c1.push_back(course1);
            courses[++NumOfCourses] = course1;
        }
        // Mina == overload update v1.0
        bool operator==(const Student &rhs) const {
            return strcmp(name, rhs.name) == 0 && id == rhs.id && age == rhs.age && strcmp(Dep, rhs.Dep) == 0 && level == rhs.level;
        }
};


class Teacher : public Human{
    public:
        Student Tec_Stu[200];
        int NumOfStudents;
        Course course;
        Teacher() {
            NumOfStudents = -1;
        }
        bool operator==(const Teacher &rhs) const {
            return strcmp(name, rhs.name) == 0 && id == rhs.id && age == rhs.age;
        }
        void addStudent(Student s1) {
            Tec_Stu[++NumOfStudents] = s1;
        }
};


priority_queue<int, vector<int>, greater<int>> students_ids, teachers_ids;
bool existance_student_id[205], existance_teacher_id[105];

void init_student_ids() {
    fstream file("Student.txt", ios::in);
    Student s1;
    file.read((char*)&s1, sizeof(s1));
    while (file) {
        existance_student_id[s1.id] = 1;
        file.read((char*)&s1, sizeof(s1));
    }
    for (int i = 1; i <= 200; i++) {
        if (!existance_student_id[i])
            students_ids.push(i);
    }
}

void init_teacher_ids() {
    fstream file("Teachers.txt", ios::in);
    Teacher t1;
    file.read((char*)&t1, sizeof(t1));
    while (file) {
        existance_teacher_id[t1.id] = 1;
        file.read((char*)&t1, sizeof(t1));
    }
    for (int i = 1; i <= 100; i++) {
        if (!existance_teacher_id[i])
            teachers_ids.push(i);
    }
}


/*
teacher <-> course


// now
        i removed the Course from inhertence of Student

*/
#endif // COLLEGE_H
