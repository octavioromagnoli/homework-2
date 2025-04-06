#ifndef COURSE_STUDENT_H
#define COURSE_STUDENT_H

#include <iostream>
#include <list>
#include <vector>
#include <memory>
using namespace std;

class Student;

/*
¿Por qué uso enable shared from this? declarar la clase de esta manera
permite que en los métodos addStudent y removeStudent compartan un puntero
del propio objeto a student, para que este se guarde en su lista de cursos.

Alternativas a usar esto que encontre charlando con compañeros son:
  - pasar el puntero al curso como parámetro -> genera funcionalidades no deseadas
  (si se pasa el puntero a otro curso, se inserta en su lista un curso incorrecto del cual el usuario puede no ser parte)
  - resolver por separado en el main (agregar por separado el usuario al curso y el curso al usuario) -> rompe el encapsulamiento

Lo que logra shared_from_this es "exportar" un shared_pointer del propio objeto, a costo de que
la instanciación del objeto DEBE ser un shared_pointer.

Para asegurarme que NO se pueda instanciar incorrectamente, oculto el constructor y creo un método estático
que lo llame utilizando shared pointers.

Para el deepcopy, en vez de sobrecargar el constructor, Sobrecargo el método estático para crear! Así ya evito del todo que se instancie el objeto incorrectamente.

*/

class Course : public std::enable_shared_from_this<Course>
{

private:
  string subject;
  int members;
  vector<shared_ptr<Student>> participants;
  Course(string);

public:
  static shared_ptr<Course> create(string subjName)
  {
    return shared_ptr<Course>(new Course(subjName));
  }

  /* Realizo una deep copy del objeto Course (reservando un nuevo espacio en memoria)
    pero hago shallow copy de los objetos estudiantes dentro del vector (paso el propio puntero a cada estudiante).
    Decidí hacer esto ya que al copiar el curso, la copia debe de poder diferenciarse y ser
    independiente, pero los estudiantes son los mismos. No tendría sentido duplicar al estudiante 
    siendo que se trata de la misma persona.
    */
  static shared_ptr<Course> create(const Course &original)
  {
    auto newCourse = create(original.getSubject());
    for (auto &estudiante : original.participants)
    {
      newCourse->addStudent(estudiante, 10); //Inicialmente, todos tienen 10, 
    }
    return newCourse;
  }

  Student& getStudent(int) const;
  void addStudent(shared_ptr<Student>, int);
  void removeStudent(shared_ptr<Student>);
  void removeStudent(int);
  void setSubject(string);
  const string getSubject() const;
  const int getMembers();
  int checkPresence(int);
  bool isFull();

  friend ostream &operator<<(ostream &os, const Course &course);

  ~Course();
};


#endif // COURSE_STUDENT_H