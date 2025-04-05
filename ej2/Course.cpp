#include <iostream>
#include "Course.h"
#include "Student.h"

// Constructor de la clase Course. Inicializa el curso con una materia y sin miembros.
Course::Course(string subject) : subject(subject), members(0)
{
  // El vector se inicializa por su cuenta al instanciar;
}

// Destructor de la clase Course. Libera los recursos asociados al vector y los shared_ptr.
Course::~Course()
{
  // El destructor del vector se encarga de destruir sus elementos. El destructor de shared_ptr los settea a nullptr;
}

// Agrega un estudiante al curso con una calificación. Lanza excepciones si el curso está lleno o si el estudiante ya está inscrito.
void Course::addStudent(shared_ptr<Student> newStudent, int grade)
{
  if (members == 20)
  {
    throw runtime_error("El curso está lleno, no se puede agregar al estudiante");
  }

  if (!(checkPresence(newStudent->getLegacy()) == -1))
  {
    throw runtime_error("El estudiante ya está inscrito en el curso");
  }
  participants.push_back(newStudent);
  members++;

  newStudent->enrollCourse(shared_from_this(), grade);
}

// Elimina un estudiante del curso. No hace nada si el estudiante no está inscrito.
void Course::removeStudent(shared_ptr<Student> student)
{
  int presence = checkPresence(student->getLegacy());
  if (presence == -1)
    return;
  else
  {
    participants.erase(participants.begin() + presence);
    members--;
  };
  student->leaveCourse(shared_from_this());
};

// Sobrecarga, Elimina el estudiante indicado por número de legajo.

void Course::removeStudent(int studentLegacy)
{
  int presence = checkPresence(studentLegacy);
  if (presence == -1){
    return;
  }
  auto leavingStudent = (participants.begin() + presence);
  participants.erase(participants.begin() + presence);
  members--;

  (*leavingStudent)->leaveCourse(shared_from_this());
};

// Verifica si el curso está lleno (20 miembros o más).
bool Course::isFull()
{
  if (members >= 20)
  {
    return true;
  }
  else
    return false;
};

/*
  Retorna el índice en el que está el estudiante buscado.
  Retorna -1 si no está.
*/
int Course::checkPresence(int searchedLegacy)
{

  int i = 0;
  for (auto &x : participants)
  {
    if (x->getLegacy() == searchedLegacy)
    {
      return i;
    }
    i++;
  }

  return -1;
};

// Retorna la materia del curso.
const string Course::getSubject() const
{
  return subject;
}

// Cambia la materia del curso.
void Course::setSubject(string newSubject) {
  subject = newSubject;
}

// Retorna el número de miembros en el curso.
const int Course::getMembers(){
  return members;
}

