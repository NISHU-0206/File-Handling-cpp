#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class Student{
    int studentID;
    string name;
    int age;
    string grade;
    double marks[5];

    public:
    Student(){
        return;
    }

    Student(int id,string n,int a,string g,double m[5]){
        studentID=id;
        name=n;
        age=a;
        grade=g;
        marks[5]=m[5];
    }

    void getdata(void){
        cout<<"Enter student ID :";cin>>studentID;
        cout<<"Enter name :";cin>>name;
        cout<<"Enter student age :";cin>>age;
        cout<<"Enter grade :";cin>>grade;
        cout<<"Enter marks :";cin>>marks[5];
    }
};

int main(){
    Student s2;
    double mark[5]={89.0,90.0,91.0,88.0,95.0};
    string nam="Aman Kumar";
    string grd="A+";
    Student s1(101,nam,18,grd,mark);
    Student s3;
    fstream file1;
    file1.open("student_database.txt");
    file1.write((char*)&s1,sizeof(s1));
    file1.close();

    cout<<"Enter new student details\n";
    s2.getdata();
    file1.open("student_database.txt",ios::app);
    file1.write((char*)&s2,sizeof(s2));
    file1.close();

    cout<<"READING THE FILE.\n\n";

    const int n=100;
    char line[n];
    file1.open("student_database.txt",ios::in);
    file1.seekg(0);
    while(file1)
    {
        file1.getline(line,n);
        cout<<line;
    }
    file1.close();

    cout<<"UPDATING THE FILE.";

    cout<<"Enter ID of the student to be updated:";
    int id;
    cin>>id;
    char ch;
    cin.get(ch);
    int location=(id-1)*sizeof(s3);
    if(file1.eof())
    file1.clear();
    file1.seekp(location);
    cout<<"Enter new data."<<endl;
    s3.getdata();
    cin.get(ch);
    file1.write((char*)&s3,sizeof(s3))<<flush;

    cout<<"UPDATED FILE.";

    file1.seekg(0);
    while(file1){
        file1.getline(line,n);
        cout<<line;
    };
    file1.close();
}