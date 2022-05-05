
void Edit_Student()
{
    Student s1;
    fstream inFile;
    inFile.open("Student.txt", ios::in | ios::out);
    if (!inFile.is_open())
    {
        setcolor(12);
        return void(cout << "\aFile cannot be oppend :)");
    }
    int stu_id;
    setcolor(2);

    print(15, '\n');
    print(35, ' ') << "Enter the ID of the student to Edit: ";
    setcolor(6);
    cin >> stu_id;
    bool exist = 0;
    inFile.read((char *)&s1, sizeof(s1));
    while (!inFile.eof())
    {
        if (stu_id == s1.id)
        {
            setcolor(2);
            print(35, ' ') << "Enter student's Age: ";
            setcolor(6);
            cin >> s1.age;
            setcolor(2);
            print(35, ' ') << "Enter student's Level: ";
            setcolor(6);
            cin >> s1.level;
            setcolor(2);
            print(35, ' ') << "Enter student's Department: ";
            setcolor(6);
            cin >> s1.Dep;
            
            int curPos = inFile.tellg();
            int stuSz = sizeof(s1);
            inFile.seekp(curPos - stuSz, ios::beg);
            inFile.write((char *)&s1, sizeof(s1));
            inFile.seekg(curPos - stuSz, ios::beg);
            setcolor(2);
            print(35, ' ') << "ID\t\tPassword\tName\t\tAge\t\tLevel\t\tDepartment\n";
            print(35, ' ') << "--\t\t--------\t----\t\t---\t\t-----\t\t----------\n";
            setcolor(6);
            print(35, ' ') << s1.id << "\t\t" << s1.password << "\t\t" << s1.name << "\t\t" << s1.age << "\t\t" << s1.level << "\t\t" << s1.Dep, exist = 1;
            exist = 1;
            break;
        }
        inFile.read((char *)&s1, sizeof(s1));
    }
    if (exist)
    {
        fstream to_edit("Teachers.txt", ios::in | ios::out);
        Teacher t1;

        to_edit.read((char *)&t1, sizeof(t1));
        while (to_edit)
        {
            for (int i = 0; i <= t1.NumOfStudents; i++)
            {
                if (t1.Tec_Stu[i].id == stu_id)
                {
                    t1.Tec_Stu[i] = s1;
                    int curPos = to_edit.tellg();
                    int stuSz = sizeof(t1);
                    to_edit.seekp(curPos - stuSz, ios::beg);
                    to_edit.write((char *)&t1, sizeof(t1));
                    break;
                }
            }
            to_edit.read((char *)&t1, sizeof(t1));
        }
        to_edit.close();
    }
    setcolor(12);
    if (!exist && cout << "\aNot found\n")
        inFile.close();
    system("CLS");
    Directing();
}
