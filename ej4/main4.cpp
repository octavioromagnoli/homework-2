#include <iostream>
#include "Cuentas.h"
using namespace std;

int main()
{
  // Crear instancias
  CajaAhorro caja(1000, "Juan Pérez");
  CuentaCorriente cuenta(500, "Juan Pérez", &caja);

  cout << "=== Prueba de CajaAhorro ===" << endl;
  caja.mostrarInfo(); // Primera consulta
  caja.mostrarInfo(); // Segunda consulta
  caja.mostrarInfo(); // Tercera consulta (debe aplicarse el cargo)

  cout << "\n=== Prueba de retiro de CajaAhorro ===" << endl;
  caja.retirar(500); // Debe permitir el retiro
  caja.mostrarInfo();
  caja.retirar(5000); // Debe rechazar el retiro por fondos insuficientes

  cout << "\n=== Prueba de CuentaCorriente ===" << endl;
  cuenta.mostrarInfo();
  cuenta.retirar(300); // Debe permitir el retiro
  cuenta.mostrarInfo();

  cout << "\n=== Prueba de retiro excediendo el balance de CuentaCorriente ===" << endl;
  cuenta.retirar(500); // Debe intentar retirar de la caja de ahorro
  cuenta.mostrarInfo();
  caja.mostrarInfo();

  cout << "\n=== Prueba de retiro excediendo Ambos balances ===" << endl;
  cuenta.retirar(2000);

  return 0;
}