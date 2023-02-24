//                                              "A C++ PROGRAM OF LEARNING MANAGEMENT SYSTEM (LMS) SUBMITTED BY MUHAMMAD DAWOOD BILAL REGNUM=2022365"



#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
using namespace std;

enum lms 
{
    student, teacher, admin
};

void lmsuser();
void studentServices();
void teacherServices(); 
void adminServices();
void addNewCourse();
void removeCourse(); 
void updateCourse(); 
void checkcourses(); 
void checkTeachers();
void allocateCourseToTeacher();
void checkTeacherPersonalData();
void deallocateCourseofTeacher(); 
void unenrollStudentfromCourse();
void addNewStudent(); 
void removeStudent(); 
void checkStudentsRecords();
void updateStudentDetail(); 
void addNewTeacher();
void removeTeacher(); 
void updateTeacherDetail(); 
void choiceAfterService_teacher();
void checkAllocatedCoursesToTeacher();
void listOfStudentsEnrolledInCourse();
void assignGradeToStudent();
void seeTopStudent();
void gradeWiseDivision();
void choiceAfterService_student(); 
void checkStudentPersonalData(); 
void enrollInCourse(); 
void seeListOfEnrolledCourses();
void seeListOfDroppedCourses(); 
void seeListOfCompletedCourses(); 
void seeFinalGrade(); 
void seeListOfTeachers();
void choiceAfterService_admin(); 

lms user;
int totalcourses= 0;
int student= 0;
int teacherC= 0;

struct teachers 
{
    string name;
    int age;
    int teacherId;
    string courses[5]; 
    int courseNumber = 0;
}; teachers t[20];

struct students 
{
    int coursesNum = 0; 
    int age; 
    int reg_num; 
    string name;
    string faculty; 
    string courses[10]; 
    string grd;
}; students s[100];


struct courses 
{
    string name;
    int creditHours;
    string students[200];
    int studentsNum = 0;
}; courses c[50];


void lmsuser()
{
    int x;
    cout<<endl<<"WELCOME TO MAIN MENU OF LMS "<<endl;
    cout<<"PLEASE KINDLY CHOOSE THE PERSON USING THIS LMS"<<endl<<"PLEASE SELECT 1 FOR STUDENT, 2 FOR TEACHER, 3 FOR ADMIN: ";
    cin>>x;
    switch (x) 
    {
        case 1:
            user = student; 
            studentService(); break;
        case 2:
            user = teacher; 
            teacherService(); break;
        case 3:
            user = admin; 
            adminService(); break;
        default: 
            cout<<endl<<"Please enter a number between 1 and 3 only"<<endl<<endl;
            lmsuser(); 
            break;
    }
}

void studentService()
{
    int x;
    cout<<endl<<"This is the STUDENT service menu"<<endl;
    cout<<"Please choose a service from the following: "<<endl;
    cout<<"1) Check personal data"<<endl;
    cout<<"2) Enroll in available course"<<endl;
    cout<<"3) See final grade"<<endl;
    cout<<"4) See list of teachers"<<endl;
    cout<<"5) See list of enrolled courses"<<endl;
    cout<<"6) See list of dropped courses"<<endl;
    cout<<"7) See list of completed courses"<<endl;
    cout<<"8) Return to main menu";
    cout<<"Enter service number: ";
    cin>>x;

    switch (x) 
    {
        case 1: checkStudentPersonalData(); break;
        case 2: enrollInCourse(); break;
        case 3: seeFinalGrade(); break;
        case 4: seeListOfTeachers(); break;
        case 5: seeListOfEnrolledCourses(); break;
        case 6: seeListOfDroppedCourses(); break;
        case 7: seeListOfCompletedCourses(); break;
        case 8: lmsuser(); break;
        default:
            cout<<"PLEASE SELECT OPTION YOU WANT TO PROCEED TO"<<endl<<endl;
            studentService(); break;
    }
    choiceAfterService_student();
}

void choiceAfterService_student() {
    cout<<"\n\n";
    int choice;
    cout<<"\n1) Continue in student menu"<<endl<<"2) Go to MAIN MENU"<<"\nChoose one of the above options: ";
    cin>>choice;
    switch(choice) {
        case 1: studentService(); break;
        case 2: lmsuser(); break;
        default: cout<<"PLEASE SELECT A NUMBER BETWEEN 1 OR 2\n"; 
        choiceAfterService_student();
    }
}

void teacherService(){
    int serviceNumber;
    cout<<endl<<"This is the TEACHER service menu"<<endl;
    cout<<"Please choose a service from the following: "<<endl;
    cout<<"1) Check personal data"<<endl;
    cout<<"2) Check list of courses allocated to you"<<endl;
    cout<<"3) See list of students enrolled in a specific course of yours"<<endl;
    cout<<"4) Assign grade to each student"<<endl;
    cout<<"5) See top student in a course of yours"<<endl;
    cout<<"6) Grade-wise division of students in a course you teach"<<endl;
    cout<<"7) return to MAIN MENU"<<endl;
    cout<<"Enter service number: ";
    cin>>serviceNumber;

    switch (serviceNumber) {
        case 1: checkTeacherPersonalData(); break;
        case 2: checkAllocatedCoursesToTeacher(); break;
        case 3: listOfStudentsEnrolledInCourse(); break;
        case 4: assignGradeToStudent(); break;
        case 5: seeTopStudent(); break;
        case 6: gradeWiseDivision(); break;
        case 7: lmsuser(); break;
        default:
            cout<<"PLEASE SELECT AN OPTION FROM 1 TO 6"<<endl;
            teacherService();
            break;
    }
    choiceAfterService_teacher();
}
void choiceAfterService_teacher() {
    cout<<"\n\n";
    int choice;
    cout<<"\n1) Continue in teacher menu"<<endl<<"2) Go to MAIN MENU"<<"\nChoose one of the above options: ";
    cin>>choice;
    switch(choice) {
        case 1: teacherService(); break;
        case 2: lmsuser(); break;
        default: cout<<"Please choose a number between 1 and 2\n"; choiceAfterService_teacher();
    }
}

void adminService(){
    int B;
    cout<<endl<<"This is the ADMIN service menu"<<endl;
    cout<<"Please choose a service from the following: "<<endl;
    cout<<"1) Add new student in system"<<endl;
    cout<<"2) Remove student from system"<<endl;
    cout<<"3) Update student detail"<<endl;
    cout<<"4) Check record of all students"<<endl;
    cout<<"5) Unenroll student from course"<<endl;
    cout<<"6) Add new teacher in system"<<endl;
    cout<<"7) Remove teacher from system"<<endl;
    cout<<"8) Update teacher detail"<<endl;
    cout<<"9) Check record of all teachers"<<endl;
    cout<<"10) Add a course in system"<<endl;
    cout<<"11) Remove course from system"<<endl;
    cout<<"12) Update course detail"<<endl;
    cout<<"13) Check record of all courses"<<endl;
    cout<<"14) Allocate a course to teacher"<<endl;
    cout<<"15) Deallocate a course from teacher"<<endl;
    cout<<"16) return to MAIN MENU"<<endl;
    cout<<"Enter service number: ";
    cin>>B;

    switch (B) {
        case 1: addNewStudent(); break;
        case 2: removeStudent(); break;
        case 3: updateStudentDetail(); break;
        case 4: checkStudentsRecords(); break;
        case 5: unenrollStudentfromCourse(); break;
        case 6: addNewTeacher(); break;
        case 7: removeTeacher(); break;
        case 8: updateTeacherDetail(); break;
        case 9: checkTeachersRecords(); break;
        case 10: addNewCourse(); break;
        case 11: removeCourse(); break;
        case 12: updateCourseDetail(); break;
        case 13: checkCoursesRecords(); break;
        case 14: allocateCourseToTeacher(); break;
        case 15: deallocateCourseFromTeacher(); break;
        case 16: lmsuser(); break;
        default:
            cout<<"PLEASE SELECT AN OPTION FROM 1 TO 15"<<endl<<endl;
            adminService(); break;
    }
    choiceAfterService_admin();
}

void admin() {
    cout<<"\n\n";
    int Y;
    cout<<"\n1) Continue in admin menu"<<endl<<"2) Go to MAIN MENU"<<"\nChoose one of the above options: ";
    cin>>Y;
    switch(Y) {
        case 1: adminService(); break;
        case 2: lmsuser(); break;
        default: cout<<"PLEASE SELECT AN OPTION FROM 1 OR 2\n"; 
        choiceAfterService_admin();
    }
}



void addNewStudent() {
    cout<<"\n\n";
    string name; int age; string faculty;cin.ignore();
    cout<<"Please enter student name: "; getline(cin, name);
    cout<<"Please enter student age: "; cin>>age;
    cout<<"Please enter student faculty: "; cin>>faculty;
    s[student].name = name;
    s[student].age = age;
    s[student].faculty = faculty;
    s[student].reg_num = stoi("2022-" + to_string(student));
    cout<<"Student added successfully with reg number <<< " << s[student].reg_num << " >>>";
    student++;
}

void removeStudent() {
    cout<<"\n\n";
    int studentReg;
    cout<<"The reg numbers of the current students are following: "; 
    for (int i = 0; i < student; i++){
        cout << s[i].reg_num << ", ";
    }
    cout<<endl<<"Enter the reg number of student to remove"<<endl<<"Enter ONLY last digits of reg number after 2022: ";
    cin>>studentReg;
    for (int i = studentReg; i < student; i++){
        s[studentReg] = s[studentReg + 1];
    }
    s[student].name = "";
    s[student].age = 0;
    s[student].faculty = "";
    s[student].reg_num = 0;
    student--;
    cout<<"Student removed successfully."<<endl;
}

void updateStudentDetail() {
    cout<<"\n\n";
    int studentReg;
    cout<<"The reg numbers of the current students are the following: ";
    for (int i = 0; i < student; i++){
        cout << s[i].reg_num << ", ";
    }
    cout<<endl<<"Enter the reg nnumber of the student to update their detail."<<endl<<"Enter ONLY the digits after 2022: ";
    cin>>studentReg;
    cout<<"The student you selected has the following information: "<<endl;
    cout<<"Name: "<< s[studentReg].name << ", age: " << s[studentReg].age << ", faculty: " << s[studentReg].faculty << ", reg number: "<<s[studentReg].reg_num<<endl;
    cout<<"What of the following do you want to change about this student?"<<endl;
    cout<<"1) Name"<<endl<<"2) Age"<<endl<<"3) Faculty"<<endl<<"Choose one of the above options: ";
    int option, age; string name, faculty;
    cin>>option;
    switch (option) {
        case 1:
            cout<<"Enter student's updated name: "; cin>>name; s[studentReg].name = name; break;
        case 2:
            cout<<"Enter student's updated age: "; cin>>age; s[studentReg].age = age; break;
        case 3:
            cout<<"Enter student's updated faculty: "; cin>>faculty; s[studentReg].faculty = faculty; break;
        default:
            cout<<"Enter between 1 and 3 only"; updateStudentDetail(); break;
    }
}
void checkStudentsRecords() {
    cout<<"\n\n";
    for (int i = 0; i < student; i++) {
        cout<<s[i].reg_num<<" "<<s[i].name<<" "<<s[i].age<<" "<<s[i].faculty<<endl;
    }
}

void unenrollStudentfromCourse() {
        cout<<"\n\n";
    if (totalcourses == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"The student "<< s[student].name << "is enrolled in the following courses: "<<endl;
        for (int j = 0; j < s[student].coursesNum; j++){
            cout<< j+1 << ") " << s[student].courses[j]<< endl;
        }
        cout<<"Enter number of course you wish to unenroll this student from: ";
        int course_remove; cin>>course_remove; course_remove--;
        for (int i = course_remove; i < s[student].coursesNum; i++){
            c[course_remove].name = c[course_remove + 1].name;
        }
        s[student].coursesNum--;
        cout<<"Student removed from course successfully."<<endl;
    }
}

void addNewTeacher() {
    cout<<"\n\n";
    string name; int age;int courseNum; cin.ignore();
    cout<<"Please enter teacher name: "; getline(cin, name);
    cout<<"Please enter teacher age: "; cin>>age;
    t[teacherC].name = name;
    t[teacherC].age = age;
    t[teacherC].teacherId = teacherC;
    cout<<"Teacher added successfully with teacher ID <<< " << t[teacherC].teacherId << " >>>";
    teacherC++;
}

void removeTeacher() {
    cout<<"\n\n";
    int teacherId;
    cout<<"The teacher IDs of the current teachers are the following: "; 
    for (int i = 0; i < teacherC; i++){
        cout << t[i].teacherId << ", ";
    }
    cout<<endl<<"Enter the teacher ID of the teacher to be removed: ";
    cin>>teacherId;
    for (int i = teacherId; i < teacherC; i++){
        t[teacherId] = t[teacherId + 1];
    }
    t[teacherC].name = "";
    t[teacherC].age = 0;
    t[teacherC].teacherId = 0;
    teacherC--;
    cout<<"Teacher removed successfully."<<endl;
}
void updateTeacherDetail() {
    cout<<"\n\n";
    int teacherId;
    cout<<"The teacher IDs of the current teachers are the following: ";
    for (int i = 0; i < teacherC; i++){
        cout << t[i].teacherId << ", ";
    }
    cout<<endl<<"Enter the teacher ID of the student to update their detail.";
    cin>>teacherId;
    cout<<"The teacher you selected has the following information: "<<endl;
    cout<<"Name: "<< t[teacherId].name << ", age: " << t[teacherId].age <<endl;
    cout<<"What of the following do you want to change about this teacher?"<<endl;
    cout<<"1) Name"<<endl<<"2) Age"<<endl<<"Choose one of the above options: ";
    int option, age; string name;
    cin>>option;
    switch (option) {
        case 1:
            cout<<"Enter teachers's updated name: "; cin>>name; t[teacherId].name = name; break;
        case 2:
            cout<<"Enter teacher's updated age: "; cin>>age; t[teacherId].age = age; break;
        default:
            cout<<"Enter between 1 and 2 only"; updateStudentDetail(); break;
    }
}

void checkTeachersRecords() {
    cout<<"\n\n";
    for (int i = 0; i < teacherC; i++) {
        cout<<t[i].teacherId<<" "<<t[i].name<<" "<<t[i].age<<endl;
    }
}

void addNewCourse() {
    cout<<"\n\n";
    switch (totalcourses) {
        case 0: cout<<"There are no courses in the system right now"<<endl;
        default:
            cout<< "The courses already added in the system are: "<<endl;
            for (int i = 0; i < totalcourses; i++){
                cout<<c[i].name<<" | ";
            }
    }
    cout<<"\n\nEnter the name of course you wish to add: ";
    string course; int creditHrs; cin>>course;
    bool alreadyAdded = false;
    for (int i = 0; i < totalcourses; i++){
        if (c[i].name == course){
            cout<<"Course already added"<<endl;
            alreadyAdded = true;
        }
    }
    if (alreadyAdded == false) {
        c[totalcourses].name = course;
        cout<<"Enter credit hours for this course: "; cin>>creditHrs; c[totalcourses].creditHours = creditHrs;
        totalcourses++;
    }
}

void removeCourse() {
    cout<<"\n\n";
    int courseIndex;
    cout<<"The courses currently added are the following: "; 
    for (int i = 0; i < totalcourses; i++){
        cout << i << ") " <<c[i].name << ", ";
    }
    cout<<endl<<"Enter the number of the course to be removed: ";
    cin>>courseIndex; courseIndex--;
    for (int i = courseIndex; i < totalcourses; i++){
        c[courseIndex].name = c[courseIndex + 1].name;
        c[courseIndex].creditHours = c[courseIndex + 1].creditHours;
    }
    totalcourses--;
    cout<<"Course removed successfully."<<endl;
}

void updateCourseDetail() 
{
    cout<<"\n\n";
    int courseIndex, creditHrs;
    cout<<"The courses currently added are the following: "; 
    for (int i = 0; i < totalcourses; i++){
        cout << i+1 << ") " <<c[i].name << ", ";
    }
    cout<<endl<<"Enter the number of the course to update its detail: ";
    cout<<"The current credit hours of the course is "<< c[courseIndex-1].creditHours<<endl;
    cout<<"Enter the updated credit hours of "<<c[courseIndex-1].name<<": ";
    cin>>creditHrs;
    c[courseIndex-1].creditHours = creditHrs;
    cout<<"Course detail updated successfully."<<endl;
}

void checkCoursesRecords() {
    for (int i = 0; i < totalcourses; i++){
        cout<<c[i].name<<" "<<c[i].creditHours<<endl;
    }
}

void allocateCourseToTeacher() {
    cout<<"\n\n";
    int teacher, course;
    if (teacher > 0 && totalcourses > 0){
        cout<<"The teachers in system are: "<<endl;
        for (int i = 0; i < teacher; i++){
            cout << i+1 << ") " << t[i].name<<endl;
        }
        cout<<"Which teacher do you want to allocate course? "; cin>>teacher;
        if (t[teacher-1].courseNumber = 0){
            cout<<"Which of the following courses to want to allocate to the teacher "<<t[teacher-1].name<<"? "<<endl;
            for (int i = 0; i < totalcourses; i++){
                cout << i+1 << ") " << c[i].name;
            } cout<<"Enter number of course you want to allocate to teacher: ";int whichCourse; cin>>whichCourse;
            t[teacher-1].courses[0] = c[whichCourse-1].name;
        }
        else if (t[teacher-1].courseNumber < 5){
            cout<<"The following courses are already added for "<<t[teacher].name<<": \n";
            for (int i = 0; i < t[teacher-1].courseNumber; i++){
                cout << i+1 << ") " << t[teacher-1].courses[i]<<endl;  
            }
            if (totalcourses == t[teacher-1].courseNumber){
                cout<<"All the courses that were available are allocated to "<<t[teacher-1].name<<endl;
            }
            else {
                string courses_names[totalcourses];
                for (int i = 0; i <totalcourses; i++) {
                    courses_names[i] = c[i].name;
                }
                int sizeA =  sizeof(courses_names)/sizeof(courses_names[0]);
                int sizeC = 0;
                string available_courses [sizeA];
                for (int i = 0; i < sizeA; i++){
                    bool found = false;
                    for (int j = 0; j < t[teacher-1].courseNumber; j++){
                        if (courses_names[i] == t[teacher-1].courses[j]){
                            found = true; break;
                        } 
                    }
                    if (!found) {
                        available_courses[sizeC] = courses_names[i];
                        sizeC++;
                    }
                }
                cout<<"The courses available for " << t[teacher-1].name << "to be allocated are the following: "<<endl;
                for (int i = 0; i < sizeC; i++){
                    cout<< i+1 << ") "<< available_courses[i]<<endl;
                }
                cout<<"Enter the number of course to allocate to " << t[teacher-1].name<<endl;
                int choiceNum; cin>>choiceNum;
                if (choiceNum > sizeC) {
                    cout<<"Please choose a number between 1 and " << sizeC<< "\n\n"; allocateCourseToTeacher();
                }
                else {
                    t[teacher-1].courses[t[teacher-1].courseNumber] = available_courses[choiceNum-1];
                    t[teacher-1].courseNumber++;
                    cout<<"Course added successfully.\n";
                    cout<<"The total courses allocated to " << t[teacher-1].name << " are: "<<endl;
                    for (int i = 0; i < t[teacher-1].courseNumber; i++){
                        cout<<t[teacher-1].courses[i]<<", ";
                    }
                    cout<<endl;
                }
            }
        }
        else {
            cout<<"Already 5 courses have been allocated to this teacher. That is the maximum courses limit"<<endl;
        }
    }
    else if (totalcourses > 0) {
        cout<<"Please add available courses first"<<endl;
    }
    else if (totalcourses > 0){
        cout<<"Please add teachers to the system first"<<endl;        
    }
}

void deallocateCourseFromTeacher() {
    cout<<"\n\n";
    if (teacher > 0) {
        int teacher;
        cout<<"The following teachers are in the system: "<<endl;
        for (int i = 0; i < teacherC; i++){
            cout<< i << ") " << t[i].name<<endl;
        }
        cout<<"Enter number of teacher you want to deallocate course from: "; cin >> teacher;
        if (t[teacher-1].courseNumber == 0){
            cout<< "There are no courses allocated to " << t[teacher-1].name << " yet." <<endl;
        }
        else {
            cout<<"The courses allocated to " << t[teacher-1].name << " are: "<<endl;
            for (int i = 0; i < t[teacher-1].courseNumber; i++){
                cout<< i+1 << ") " << t[teacher-1].courses[i] << endl;
            }
            cout<<"Enter course number to deallocate from " << t[teacher-1].name << ": ";
            int courseNUM; cin>>courseNUM; courseNUM--;
            for (int i = courseNUM; i < t[teacher-1].courseNumber; i++){
                t[teacher-1].courses[courseNUM] = t[teacher-1].courses[courseNUM + 1];
            }
            t[teacher-1].courseNumber--;
            cout<<"Course deallocated successfully"<<endl;
        }
    }
    else {
        cout<<"There are no teachers added to the system"<<endl;
    }
}

void checkTeacherPersonalData() {
    cout<<"\n\n";
    if (teacherC == 0) {
        cout<<"There are no teachers added to the system yet"<<endl;
    }
    else {
        cout<<"The teachers added in the system are: "<<endl;
        for (int i = 0; i < teacherC; i++){
            cout<< i+1 << ") " <<t[i].name << endl;
        }
        cout<<"Enter the number of your name: "<<endl;
        int teacher; cin>>teacher; teacher--;
        cout<<"---------------------"<<endl;
        cout<< "Teacher ID: " << t[teacher].teacherId << "\nTeacher name: " << t[teacher].name <<endl;
        cout<< "Teacher age: " << t[teacher].age << "\nTeacher courses: ";
        if (t[teacher].courseNumber == 0) {
            cout<< "< There are no courses allocated to you yet >"<< endl;
        }
        else {
            for (int i = 0; i < t[teacher].courseNumber; i++){
                cout<<t[teacher].courses[i]<<", ";
            }
        }
        cout<<endl<<"--------------------"<<endl;
    }
}

void checkAllocatedCoursesToTeacher() {
    cout<<"\n\n";
    if (teacherC== 0) {
        cout<<"There are no teachers added to the system yet"<<endl;
    }
    else {
        cout<<"The teachers added in the system are: "<<endl;
        for (int i = 0; i < teacherC; i++){
            cout<< i+1 << ") " <<t[i].name << endl;
        }
        cout<<"Enter the number of your name: "<<endl;
        int teacher; cin>>teacher; teacher--;
        cout<<"---------------------"<<endl;
        if (t[teacher].courseNumber == 0) {
            cout<< "There are no courses allocated to you yet"<< endl;
        }
        else {
            cout << "Teacher allocated courses: ";
            for (int i = 0; i < t[teacher].courseNumber; i++){
                cout<<t[teacher].courses[i]<<", ";
            }
            cout<<endl<<"--------------------"<<endl;
        }
    }
}

void listOfStudentsEnrolledInCourse() {
    cout<<"\n\n";
    if (teacherC == 0) {
        cout<<"There are no teachers added to the system yet"<<endl;
    }
    else {
        cout<<"The teachers added in the system are: "<<endl;
        for (int i = 0; i < teacherC; i++){
            cout<< i+1 << ") " <<t[i].name << endl;
        }
        cout<<"Enter the number of your name: "<<endl;
        int teacher; cin>>teacher; teacher--;
        if (t[teacher].courseNumber == 0) {
            cout<< "There are no courses allocated to you yet"<< endl;
        }
        else {
            cout<< "The courses you teach are: ";
            for (int i = 0; i < t[teacher].courseNumber; i++){
                cout<< i+1 << ") " <<t[teacher].courses[i]<<endl;
            }
            cout<<"Enter the number of one of the above courses to see students enrolled: ";
            int num; cin>>num; num--;
            string name_of_course = t[teacher].courses[num];
            for (int i = 0; i < totalcourses; i++){
                if (name_of_course == c[i].name) {
                    if (c[i].studentsNum == 0) {
                        cout<< "There are no students enrolled in this course"<<endl;
                    }
                    else {
                        cout<<"--------------------"<<endl;
                        cout<<"The students enrolled in this course are: "<<endl;
                        for (int j = 0; j < c[i].studentsNum; j++){
                            cout<<c[i].students[j]<<", ";
                        }
                    }
                }
            } 
        }
        cout<<endl<<"--------------------"<<endl;
    }
}

void assignGradeToStudent() {
    cout<<"\n\n";
    if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"The students added in the system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name << endl;
        }
        cout<<"Enter the number of student's name: "<<endl;
        int student; cin>>student; student--;
        cout<<"Assign grade to student from the following: "<<endl;
        cout<<"1) A\n2) A-\n3) B+\n4) B\n5) B-\n6) C+\n7) C\n8) C-\n9) D+\n10) D\n11) F\n";
        cout<<"Enter number of grade to be assigned to student: ";
        int stu_grade; cin>>stu_grade;
        switch (stu_grade)
        {
        case 1: s[student].grd = "A" ;break;
        case 2: s[student].grd = "A-" ;break;
        case 3: s[student].grd = "B+" ;break;
        case 4: s[student].grd = "B" ;break;
        case 5: s[student].grd = "B-" ;break;
        case 6: s[student].grd = "C+" ;break;
        case 7: s[student].grd = "C" ;break;
        case 8: s[student].grd = "C-" ;break;
        case 9: s[student].grd = "D+" ;break;
        case 10: s[student].grd = "D" ;break;
        case 11: s[student].grd = "F" ;break;
        default: cout<<"Enter a number between 1 and 11 only"; assignGradeToStudent(); break;
        }
        cout<<endl<<"--------------------"<<endl;
    }
}

void seeTopStudent(){
    cout<<"\n\n";
    if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        for (int i = 0; i < student; i++){
            if (s[i].grd == "A") {
                cout<<s[i].name << "is the top student";
                break;
            }
        }
    }
}

void gradeWiseDivision(){
    cout<<"\n\n";
    string a_students[50]; int a_counter = 0;
    string a_neg_students[50]; int a_neg_counter = 0;
    string b_pos_students[50]; int b_pos_counter = 0;
    string b_students[50]; int b_counter = 0;
    string b_neg_students[50]; int b_neg_counter = 0;
    string c_pos_students[50]; int c_pos_counter = 0;
    string c_students[50]; int c_counter = 0;
    string c_neg_students[50]; int c_neg_counter = 0;
    string d_pos_students[50]; int d_pos_counter = 0;
    string d_students[50]; int d_counter = 0;
    string f_students[50];int f_counter = 0;
    if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        for (int i = 0; i < student; i++){
            if (s[i].grd == "A") { a_students[a_counter] = s[i].name; a_counter++;}
            else if (s[i].grd == "A-") { a_neg_students[a_neg_counter] = s[i].name; a_neg_counter++;}
            else if (s[i].grd == "B+") { b_pos_students[b_pos_counter] = s[i].name; b_pos_counter++;}
            else if (s[i].grd == "B") { b_students[b_counter] = s[i].name; b_counter++;}
            else if (s[i].grd == "B-") { b_neg_students[b_neg_counter] = s[i].name; b_neg_counter++;}
            else if (s[i].grd == "C+") { c_pos_students[c_pos_counter] = s[i].name; c_pos_counter++;}
            else if (s[i].grd == "C") { c_students[c_counter] = s[i].name; c_counter++;}
            else if (s[i].grd == "C-") { c_neg_students[c_neg_counter] = s[i].name; c_neg_counter++;}
            else if (s[i].grd == "D+") { d_pos_students[d_pos_counter] = s[i].name; d_pos_counter++;}
            else if (s[i].grd == "D") { d_students[d_counter] = s[i].name; d_counter++;}
            else if (s[i].grd == "F") { f_students[f_counter] = s[i].name; f_counter++;}
        }
    }
}

void checkStudentPersonalData() {
    cout<<"\n\n";
    if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"The students added in the system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name << endl;
        }
        cout<<"Enter the number of your name: "<<endl;
        int student; cin>>student; student--;
        cout<<"---------------------"<<endl;
        cout<< "Student Registration Number: " << s[student].reg_num << "\nStudent name: " << s[student].name <<endl;
        cout<< "Student age: " << s[student].age << "\nStudent courses: ";
        if (s[student].coursesNum == 0){
            cout<<"< No courses enrolled yet >";
        }
        else {
            for (int i = 0; i < s[student].coursesNum; i++){
            cout<<s[student].courses[i]<<", ";
            }
        }
        
        cout<<endl<<"--------------------"<<endl;
    }
}

void enrollInCourse() {
    cout<<"\n\n";
    if (student == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"Courses in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<c[i].name<<endl;
        }
        cout<<"Enter number of course you want to enroll in from the above list: ";
        int cour; cin>>cour; cour--;

        s[student].courses[s[student].coursesNum] = c[cour].name;
        s[student].coursesNum++;
        c[cour].students[c[cour].studentsNum] = s[student].name;
        c[cour].studentsNum++;
    }
}

void seeListOfTeachers(){
    cout<<"\n\n";
    if (teacherC == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else {
        cout<<"Your teachers  are: "<<endl;
        for (int i = 0; i < teacherC; i++){
            cout<< i+1 << ") " <<t[i].name<<endl;
        }
}}

void seeListOfEnrolledCourses() {
    cout<<"\n\n";
    if (totalcourses == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"---------------------"<<endl;
        cout<<"The student " << s[student].name << " is enrolled in the following courses: "<<endl;
        for (int i = 0; i < s[student].coursesNum; i++){
            cout<< s[student].courses[i]<<", ";
        }
        cout<<"---------------------"<<endl;
    }
}

void seeListOfDroppedCourses() {
    cout<<"\n\n";
        if (totalcourses == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else if (totalcourses == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"---------------------"<<endl;
        cout<<"There are no dropped courses"<<endl;
        cout<<"---------------------"<<endl;
    }
}
void seeListOfCompletedCourses() {
        cout<<"\n\n";
        if (totalcourses == 0) {
        cout<<"There are no courses added to the system yet"<<endl;
    }
    else if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"---------------------"<<endl;
        cout<<"There are no completed courses"<<endl;
        cout<<"---------------------"<<endl;
    }
}

void seeFinalGrade() {
    cout<<"\n\n";
    if (student == 0) {
        cout<<"There are no students added to the system yet"<<endl;
    }
    else {
        cout<<"Students in system are: "<<endl;
        for (int i = 0; i < student; i++){
            cout<< i+1 << ") " <<s[i].name<<endl;
        }
        cout<<"Enter number of student from the above list: ";
        int student; cin>>student; student--; cout<<endl;

        cout<<"---------------------"<<endl;
        cout<<"The final grade is "<< s[student].grd<<endl;
        cout<<"---------------------"<<endl;
    }
}

int main(){

    cout<<"Welcome to GIKI LMS"<<endl<<endl;
    lmsuser();

    return 0;
}
