#include <iostream>
#include "CourseStudent.h"

Course::Course() : members(0){
  // El vector se inicializa por su cuenta al instanciar;
}

Course::~Course(){
  // El destructor del vector se encarga de destruir sus elementos. El destructor de shared_ptr los settea a nullptr;
}


// TODO en addStudent y removeStudent sacar el curso de su lista de cursos
void Course::addStudent(shared_ptr<Student> newStudent, int grade){
  if (members == 20){
    throw runtime_error("El curso está lleno, no se puede agregar más estudiantes");
  }
  participants.push_back(make_pair(newStudent, grade));
  members++;

  newStudent->courses.push_back(make_pair(make_shared<Course>(this), grade));
}

void Course::removeStudent(shared_ptr<Student> student){
  int presence = checkPresence(student->getLegacy());
  if(presence == -1) return;
  else{
    participants.erase(participants.begin() + presence);
    members--;

    for (auto it = student->courses.begin(); it != student->courses.end(); ++it) {
      if (it->first.get() == this) {
        student->courses.erase(it);
        break;
      }
    }
  };
};

bool Course::isFull(){
  if(members >= 20){
    return true;
  } else return false;
};

/*
  Retorna el índice en el que está el estudiante buscado.
  Retorna -1 si no está.
  */
int Course::checkPresence(int searchedLegacy){
  
  int i = 0;
  for (auto& x : participants){
    if (x.first->getLegacy() == searchedLegacy){
      return i;
    }
    i++;
  }

  return -1;
};


Student::Student(string name, int legacy): name(name), legacy(legacy){}

string Student::getName(){
  return name;
};

int Student::getLegacy(){
  return legacy;
}

double Student::getMean(){

  if(courses.empty()) return 0;

  double result = 0;
  double counter = 0;

  for(auto& i : courses){
    result += i.second;
    counter+=1;
  }
  return result/counter;
}


