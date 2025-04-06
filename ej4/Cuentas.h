#include <iostream>
#include <memory>
using namespace std;

class CuentaCorriente;

class Cuenta
{
protected:
  double balance;
  string titularCuenta;
// Establezco el balance y el titular como protected para que puedan ser accedidos por subclases derivadas
// sin hacerlos públicos. Así la subclase puede utilizarlos pero el usuario no puede acceder.
public:
  Cuenta(double balance, string titularCuenta);
  void depositar(double amount);
  virtual bool retirar(double amount) = 0;
  virtual void mostrarInfo() = 0;

  virtual ~Cuenta();
};

class CajaAhorro : public Cuenta
{
public:
  friend class CuentaCorriente;
  CajaAhorro(double balance, string titular);
  bool retirar(double amount) override;
  void mostrarInfo() override;

private:
  int consultas;
  // El número de consultas solo debe ser modificado por el propio objeto, por lo que lo establezco privado.
};

class CuentaCorriente : public Cuenta
{
public:
  CuentaCorriente(double balance, string titular, CajaAhorro *cajaAsociada = nullptr);
  bool retirar(double amount) override;
  void mostrarInfo() override;

  ~CuentaCorriente() override;

private:
  CajaAhorro *cajaAsociada;
  // La caja de ahorro asociada solo debe accederse en el propio objeto, por lo que la establezco como privadas.

};