#include <iostream>
#include <sstream>
using namespace std;

#include "Entero.h"

Entero::Entero(int val) : valor(val) {}

int Entero::getValor() const
{
  return valor;
}

void Entero::setValor(int newValue)
{
  valor = newValue;
}

unique_ptr<Numero> Entero::suma(const Numero *otro)
{
  const Entero *otroEntero = dynamic_cast<const Entero *>(otro);
  if (!otroEntero)
  {
    throw std::invalid_argument("Se esperaba un Entero");
  }
  return make_unique<Entero>(this->valor + otroEntero->getValor());
}

unique_ptr<Numero> Entero::resta(const Numero *otro)
{
  const Entero *otroEntero = dynamic_cast<const Entero *>(otro);
  if (!otroEntero)
  {
    throw std::invalid_argument("Se esperaba un Entero");
  }
  return make_unique<Entero>(this->valor - otroEntero->getValor());
}

unique_ptr<Numero> Entero::multiplica(const Numero *otro)
{
  const Entero *otroEntero = dynamic_cast<const Entero *>(otro);
  if (!otroEntero)
  {
    throw std::invalid_argument("Se esperaba un Entero");
  }
  return make_unique<Entero>(this->valor * otroEntero->getValor());
}

unique_ptr<Numero> Entero::divide(const Numero *otro)
{
  const Entero *otroEntero = dynamic_cast<const Entero *>(otro);
  if (!otroEntero)
  {
    throw std::invalid_argument("Se esperaba un Entero");
  }
  if (otroEntero->getValor() == 0)
  {
    throw std::invalid_argument("División por cero no permitida");
  }
  return make_unique<Entero>(this->valor / otroEntero->getValor());
}

string Entero::toString()
{
  ostringstream oss;
  oss << valor;
  return oss.str();
}