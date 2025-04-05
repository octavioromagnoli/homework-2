#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
#include "Numero.h"
#include "Entero.h"
#include "Real.h"
#include "Complejo.h"

using namespace std;

void printTitulo(const string &title)
{
  cout << "\n"
       << string(50, '=') << endl;
  cout << title << endl;
  cout << string(50, '-') << endl;
}

void testEntero()
{
  printTitulo("PRUEBAS CON NÚMEROS ENTEROS");

  unique_ptr<Entero> num1;
  unique_ptr<Entero> num2;
  try
  {
    num1 = make_unique<Entero>(10);
    num2 = make_unique<Entero>(5);
  }
  catch (const std::bad_alloc &e)
  {
    cout << "Error de asignación de memoria: " << e.what() << endl;
  }

  cout << "Entero 1: " << num1->toString() << endl;
  cout << "Entero 2: " << num2->toString() << endl;

  cout << "\nOperaciones:" << endl;
  cout << num1->toString() << " + " << num2->toString() << " = ";
  cout << num1->suma(num2.get())->toString() << endl;

  cout << num1->toString() << " - " << num2->toString() << " = ";
  cout << num1->resta(num2.get())->toString() << endl;

  cout << num1->toString() << " * " << num2->toString() << " = ";
  cout << num1->multiplica(num2.get())->toString() << endl;

  cout << num1->toString() << " / " << num2->toString() << " = ";
  cout << num1->divide(num2.get())->toString() << endl;

  try
  {
    auto num3 = make_unique<Entero>(0);
    cout << "\nIntentando división por cero: " << num1->toString() << " / " << num3->toString() << endl;
    auto result = num1->divide(num3.get());
    cout << "Resultado: " << result->toString() << endl;
  }
  catch (const exception &e)
  {
    cout << "Error capturado: " << e.what() << endl;
  }
}

void testReal()
{
  printTitulo("PRUEBAS CON NÚMEROS REALES");

  unique_ptr<Real> num1;
  unique_ptr<Real> num2;
  try
  {
    num1 = make_unique<Real>(10.5);
    num2 = make_unique<Real>(3.25);
  }
  catch (const std::bad_alloc &e)
  {
    cout << "Error de asignación de memoria: " << e.what() << endl;
  }

  cout << "Real 1: " << num1->toString() << endl;
  cout << "Real 2: " << num2->toString() << endl;

  cout << "\nOperaciones:" << endl;
  cout << num1->toString() << " + " << num2->toString() << " = ";
  cout << num1->suma(num2.get())->toString() << endl;

  cout << num1->toString() << " - " << num2->toString() << " = ";
  cout << num1->resta(num2.get())->toString() << endl;

  cout << num1->toString() << " * " << num2->toString() << " = ";
  cout << num1->multiplica(num2.get())->toString() << endl;

  cout << num1->toString() << " / " << num2->toString() << " = ";
  cout << num1->divide(num2.get())->toString() << endl;
}

void testComplejo()
{
  printTitulo("PRUEBAS CON NÚMEROS COMPLEJOS");

  unique_ptr<Complejo> num1;
  unique_ptr<Complejo> num2;
  try
  {
    num1 = make_unique<Complejo>(3.0, 4.0);
    num2 = make_unique<Complejo>(1.0, 2.0);
  }
  catch (const std::bad_alloc &e)
  {
    cout << "Error de asignación de memoria: " << e.what() << endl;
  }

  cout << "Complejo 1: " << num1->toString() << endl;
  cout << "Complejo 2: " << num2->toString() << endl;

  cout << "\nOperaciones:" << endl;
  cout << num1->toString() << " + " << num2->toString() << " = ";
  cout << num1->suma(num2.get())->toString() << endl;

  cout << num1->toString() << " - " << num2->toString() << " = ";
  cout << num1->resta(num2.get())->toString() << endl;

  cout << num1->toString() << " * " << num2->toString() << " = ";
  cout << num1->multiplica(num2.get())->toString() << endl;

  cout << num1->toString() << " / " << num2->toString() << " = ";
  cout << num1->divide(num2.get())->toString() << endl;
}

int main()
{
  cout << "DEMOSTRACIÓN DE CLASES NUMÉRICAS" << endl;

  testEntero();
  testReal();
  testComplejo();

  printTitulo("DEMOSTRACIÓN DE POLIMORFISMO");

  vector<unique_ptr<Numero>> numeros;
  numeros.push_back(make_unique<Entero>(42));
  numeros.push_back(make_unique<Real>(3.14159));
  numeros.push_back(make_unique<Complejo>(1.0, 1.0));

  cout << "El vector tiene diferentes tipos de números:" << endl;
  for (const auto &num : numeros)
  {
    cout << "- " << num->toString() << endl;
  }

  return 0;
}