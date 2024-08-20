/*Create a CC++ class named "Exam" designed to manage student exam records, complete with a
shallow copy implementation? Define attributes such as student name, exam date, and score within the
class, and include methods to set these attributes and display exam details. As part of this exercise,
intentionally omit the implementation of the copy constructor and copy assignment operator. Afterward,
create an instance of the "Exam" class, generate a shallow copy, and observe any resulting issues?*/
/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
#include <cstring>
using namespace std;

class Exam
{
    private:
     char * ST_name;
     float ExamScore;

    public:
    Exam(char * name,float score)
    {
       ST_name = new char[strlen(name) + 1];
       this->ExamScore=score;
       strcpy(ST_name, name);
       
    }

    void update(char* name,float score)
    {
        delete[] ST_name;
        ST_name = new char[strlen(name) + 1];
        strcpy(ST_name,name);
        ExamScore=score;
    }

    void Display()
    {
        cout<<"Displaying student details\n";
        cout<<"Student name: "<<ST_name<<endl;
        cout<<"Student score: "<<ExamScore<<endl;
    }

    ~Exam()
    {
        delete[] ST_name;
    }

};

int main()
{
    Exam st1("Sara",97);
    Exam st2("Ali",98);
    Exam st3=st2;

    cout<<"Orignal details of Students\n\n"<<"Student 1:\n";
    st1.Display();
    cout<<"\nStudent 2:\n";
    st2.Display();
    cout<<"\nStudent 3:\n";
    st3.Display();

    st1.update("Sara",99);
    cout<<"\nDetails of Student 1 after upadte:\n";
    st1.Display();

    return 0;
}

