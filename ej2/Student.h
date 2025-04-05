#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <list>
#include <vector>
#include <memory>
using namespace std;

class Course;

class Student
{
private:
  string name;
  int legacy;
  list<pair<weak_ptr<Course>, double>> courses;

public:
  Student(string, int);
  string getName() const;
  int getLegacy() const;
  double getMean() const;
  void enrollCourse(shared_ptr<Course>, int grade);
  void leaveCourse(shared_ptr<Course>);

  bool operator<(const Student &other) const;
};



#endif // STUDENT_H