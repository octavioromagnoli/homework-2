#include <iostream>
#include "CourseStudent.h"
#include <algorithm>
using namespace std;

/*
Consigna c)
Las clases Course y Estudiantes están relacionadas mediante agegación. La clasifico así
considerando que están relacionadas mediante punteros (Course tiene vector de punteros a Student y viceversa).
La clase Course (whole) "tiene" Student (parts) pero no controla su ciclo de vida, es decir pueden existir independientemente (lo que exluye que sea composición)
*/

ostream &operator<<(ostream &os, const Course &course)
{
  vector<Student> sortedParticipants;
  for (const auto &studentPtr : course.participants)
  {
    sortedParticipants.push_back(*studentPtr);
  }
  sort(sortedParticipants.begin(), sortedParticipants.end());
  for (auto &student : sortedParticipants)
  {
    os << student.getName() << " - Legajo: " << student.getLegacy() << endl;
  }
  return os;
}

int main()
{
  string nombresDePrueba[19] = {
      "Juan", "María", "Carlos", "Ana", "José",
      "Lucía", "Miguel", "Sofía", "Pedro", "Valentina",
      "Martín", "Camila", "Jorge", "Florencia", "Diego",
      "Carolina", "Luis", "Julieta", "Fernando"};

  shared_ptr<Course> matematica;
  try
  {
    matematica = Course::create("Matemática");
  }
  catch (const bad_alloc &e)
  {
    cerr << "Error al crear el curso: " << e.what() << endl;
    return 1;
  }

  int counter = 0;
  for (string name : nombresDePrueba)
  {
    matematica->addStudent(make_shared<Student>(name, counter), (counter + 7) % 11);
    counter++;
  }

  cout << "Se creó el aula de matemáticas, y tiene estos estudiantes: " << endl
       << *matematica;

  int option;

  cout << endl;
  shared_ptr<Course> quimica;
  try
  {
    quimica = Course::create(*matematica);
  }
  catch (const bad_alloc &e)
  {
    cerr << "Error al crear el curso: " << e.what() << endl;
    return 1;
  }

  cout << "Se creó el aula de química, copiando a matemática: " << endl
       << *quimica;

  do
  {
    cout << "\nMenu para manipular Matemática:\n";
    cout << "1. Agregar un alumno\n";
    cout << "2. Sacar un alumno\n";
    cout << "3. Chequear si un alumno está en la clase, segun legajo\n";
    cout << "4. Chequear si la clase está llena\n";
    cout << "5. Ver lista de estudiantes\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> option;

    switch (option)
    {
    case 1:
      {
        string name;
        int legacy;
        int grade;
        cout << "Ingrese el nombre del alumno: ";
        cin >> name;
        cout << "Ingrese el legajo del alumno: ";
        cin >> legacy;
        cout << "Ingrese la nota del alumno: ";
        cin >> grade;
        try
        {
          auto newStudent = make_shared<Student>(name, legacy);
          matematica->addStudent(newStudent, grade);
        }
        catch (const bad_alloc &e)
        {
          cerr << "Error al agregar el alumno: no se pudo asignar memoria." << endl;
          throw;
        }
        catch (const runtime_error &e)
        {
          cerr << e.what() << endl;
        }
        break;
      }
      case 2:
      {
        int legacy;
        cout << "Ingrese el legajo del alumno a eliminar: ";
        cin >> legacy;
        matematica->removeStudent(legacy);
        cout << endl
            << "El alumno fue removido del curso";
        break;
      }
      case 3:
      {
        int legacy;
        cout << "Ingrese el legajo del alumno a buscar: ";
        cin >> legacy;

        if(matematica->checkPresence(legacy) == -1){
          cout<<endl<<"El alumno no pertenece al curso"<<endl;
        }
        else{
          cout<<endl<<"El alumno pertenece al curso!"<<endl;
        }
        break;
      }
      case 4:
      {
        if(matematica->isFull()){
          cout << endl << "El curso está lleno" << endl;
        } else{
          cout << endl << "El curso aún tiene espacio" << endl;
        }
        break;
      }
      case 5:
      {
        cout<<endl<<*matematica<<endl;
        break;
      }
      case 6:
      {
        cout << "Saliendo del menú.\n";
        break;
      }  
      default:
        cout << "Opción inválida. Saliendo del programa.\n";
        return 0;
    }
  } while (option != 6);

  return 0;
}