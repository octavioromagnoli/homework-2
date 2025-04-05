#include <iostream>
#include <sstream>
using namespace std;

#include "Real.h"

Real::Real(double val) : valor(val) {}

double Real::getValor() const
{
  return valor;
}

void Real::setValor(double newValue)
{
  valor = newValue;
}

unique_ptr<Numero> Real::suma(const Numero *otro)
{
  const Real *otroReal = dynamic_cast<const Real *>(otro);
  if (!otroReal)
  {
    throw invalid_argument("Se esperaba un número Real");
  }
  return make_unique<Real>(this->valor + otroReal->getValor());
}

unique_ptr<Numero> Real::resta(const Numero *otro)
{
  const Real *otroReal = dynamic_cast<const Real *>(otro);
  if (!otroReal)
  {
    throw invalid_argument("Se esperaba un número Real");
  }
  return make_unique<Real>(this->valor - otroReal->getValor());
}

unique_ptr<Numero> Real::multiplica(const Numero *otro)
{
  const Real *otroReal = dynamic_cast<const Real *>(otro);
  if (!otroReal)
  {
    throw invalid_argument("Se esperaba un número Real");
  }
  return make_unique<Real>(this->valor * otroReal->getValor());
}

unique_ptr<Numero> Real::divide(const Numero *otro)
{
  const Real *otroReal = dynamic_cast<const Real *>(otro);
  if (!otroReal)
  {
    throw invalid_argument("Se esperaba un número Real");
  }
  return make_unique<Real>(this->valor / otroReal->getValor());
}

string Real::toString()
{
  ostringstream oss;
  oss << valor;
  return oss.str();
}