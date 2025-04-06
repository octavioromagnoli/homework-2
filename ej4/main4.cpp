#include <iostream>
#include "Cuentas.h"
using namespace std;

int main()
{
  // Crear instancias
  CajaAhorro caja(1000, "Juan Pérez");
  CuentaCorriente cuenta(500, "Juan Pérez", &caja);

  cout << "=== Prueba de CajaAhorro ===" << endl;
  cout<<endl<<"Se excederan las 2 consultas para comprobar que se aplique el cargo:"<<endl;
  caja.mostrarInfo(); 
  caja.mostrarInfo();
  caja.mostrarInfo();

  cout << "\n=== Prueba de retiro de CajaAhorro ===" << endl;
  cout<<endl<<"Se retirarán $500, un monto costeable por el balance de la caja:"<<endl;
  caja.retirar(500);
  caja.mostrarInfo();
  cout<<endl<<"Se intentará retirar un valor que excede el balance de la caja:"<<endl;
  caja.retirar(5000);

  cout << "\n=== Prueba de CuentaCorriente ===" << endl<<endl;
  cuenta.mostrarInfo();
  cout<<endl<<"Se retiraran 300:"<<endl;
  cuenta.retirar(300);
  cuenta.mostrarInfo();

  cout << "\n=== Prueba de retiro excediendo el balance de CuentaCorriente ===" << endl;
  cout<<endl<<"Estado actual de la cuenta:"<<endl;
  cuenta.mostrarInfo();
  cout<<endl<<"Se intentarán retirar 500:"<<endl;
  cuenta.retirar(500);
  cuenta.mostrarInfo();
  caja.mostrarInfo();

  cout << "\n=== Prueba de retiro excediendo Ambos balances ===" << endl;
  cuenta.retirar(2000);

  return 0;
}