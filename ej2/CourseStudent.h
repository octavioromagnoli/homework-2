#ifndef COURSE_STUDENT_H
#define COURSE_STUDENT_H

#include<iostream>
#include<list>
#include<vector>
#include<memory>
using namespace std;

class Course{
  private:
    int members;
    vector<pair<shared_ptr<Student>, double>> participants;
  public:
   Course();

   void addStudent(shared_ptr<Student>, int);
   void removeStudent(shared_ptr<Student>);
   int checkPresence(int);
   bool isFull();

   ~Course();
};

class Student{
  private:
    string name;
    int legacy;
  public:
    list<pair<shared_ptr<Course>, double>> courses;
  
    Student(string, int);
    string getName();
    int getLegacy();
    double getMean ();
    
};

#endif 