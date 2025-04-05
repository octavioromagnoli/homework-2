#include "Student.h"
#include "Course.h"
#include <memory>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Constructor de la clase Student. Inicializa el estudiante con un nombre y un legajo.
Student::Student(string name, int legacy) : name(name), legacy(legacy) {}

// Retorna el nombre del estudiante.
string Student::getName() const
{
  return name;
};

// Retorna el legajo del estudiante.
int Student::getLegacy() const
{
  return legacy;
}

// Calcula y retorna el promedio de calificaciones del estudiante en todos los cursos.
double Student::getMean() const
{

  if (courses.empty())
    return 0;

  double result = 0;
  double counter = 0;

  for (auto &i : courses)
  {
    if (!i.first.expired())
    {
      result += i.second;
      counter += 1;
    }
  }
  return counter > 0 ? result / counter : 0;
}

// Sobrecarga del operador < para comparar estudiantes por nombre.
bool Student::operator<(const Student &other) const
{
  return this->name < other.name;
}

// Inscribe al estudiante en un curso con una calificación.
void Student::enrollCourse(shared_ptr<Course> newCourse, int grade)
{
  courses.push_back(make_pair(weak_ptr<Course>(newCourse), grade));
}

// Elimina al estudiante de un curso.
void Student::leaveCourse(shared_ptr<Course> course)
{
  for (auto it = this->courses.begin(); it != this->courses.end(); ++it)
  {
    // Se lockea el weak ptr para comparar
    if (auto sharedCourse = it->first.lock())
    {
      if (sharedCourse.get() == course.get())
      {
        this->courses.erase(it);
        break;
      }
    }
  }
}