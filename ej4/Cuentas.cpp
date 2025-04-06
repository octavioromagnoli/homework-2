#include <iostream>
#include <memory>
#include "Cuentas.h"
using namespace std;

Cuenta::Cuenta(double balance, string titularCuenta) : balance(balance), titularCuenta(titularCuenta) {}

Cuenta::~Cuenta() {
}


void Cuenta::depositar(double amount)
{
  if (amount < 0)
  {
    throw invalid_argument("Error, la cantidad ingresada debe ser positiva");
  }
  balance += amount;
}

CajaAhorro::CajaAhorro(double balance, string titular) : Cuenta(balance, titular), consultas(0) {}

bool CajaAhorro::retirar(double cantidad)
{
  if (cantidad <= 0)
  {
    cout << "Error: la cantidad a retirar debe ser positiva" << endl;
    return false;
  }

  if (cantidad > balance)
  {
    cout << "Error: Fondos insuficientes en la Caja de Ahorro." << endl;
    return false;
  }

  balance -= cantidad;
  return true;
}

void CajaAhorro::mostrarInfo()
{
  consultas++;
  cout << "=== Caja de Ahorro ===" << endl;
  cout << "Titular: " << titularCuenta << endl;
  cout << "Balance: $" << balance << endl;
  cout << "Tipo de cuenta: Caja de Ahorro" << endl;

  // El descuento se aplica cada 2 consultas
  if (consultas > 2)
  {
    consultas = 0;
    balance -= 20;
    cout << "Se aplicó un cargo de $20 por exceso de consultas." << endl;
    cout << "Nuevo balance: $" << balance << endl;
  }
}

CuentaCorriente::CuentaCorriente(double balance, string titular, CajaAhorro *cajaAsociada) : Cuenta(balance, titular), cajaAsociada(cajaAsociada) {}

bool CuentaCorriente::retirar(double cantidad)
{
  if (cantidad <= 0)
  {
    cout << "Error, la cantidad a retirar debe ser positiva" << endl;
    return false;
  }

  double diferencia = cantidad - balance;
  if (cantidad > balance)
  {
    if (cajaAsociada && diferencia < cajaAsociada->balance)
    {
      cout << "Al no haber suficiente dinero disponible, se retirarán $" << diferencia << " de la caja de ahorro asociada." << endl;

      balance = 0;
      cajaAsociada->balance = cajaAsociada->balance - diferencia;
      return true;
    }
    else
    {
      cout << "Error: No hay suficiente dinero en la cuenta corriente ni en la caja de ahorro asociada para retirar esa cantidad." << endl;
      return false;
    }
  }
  else
  {
    balance -= cantidad;
  }
  return true;
}

void CuentaCorriente::mostrarInfo() {
  std::cout << "=== Información de Cuenta Corriente ===" << std::endl;
  std::cout << "Titular: " << titularCuenta << std::endl;
  std::cout << "Balance: $" << balance << std::endl;
  std::cout << "Tipo de cuenta: Cuenta Corriente" << std::endl;
  
  if (cajaAsociada != nullptr) {
      std::cout << "Caja de Ahorro asociada - Balance: $" << cajaAsociada->balance << std::endl;
  } else {
      std::cout << "No hay Caja de Ahorro asociada." << std::endl;
  }
}

CuentaCorriente::~CuentaCorriente() {
  // No es explicitamente necesario porque se destruye el objeto, 
  // pero para remarcar que el objeto no tiene ownership de la caja Asociada
  cajaAsociada = nullptr;
}
