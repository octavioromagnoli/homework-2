#include <iostream>
#include <memory>
using namespace std;

class CuentaCorriente;

class Cuenta
{
protected:
  double balance;
  string titularCuenta;

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
};