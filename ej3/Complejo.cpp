#include <iostream>
#include <sstream>
using namespace std;

#include "Complejo.h"

Complejo::Complejo(double realPart, double imagPart) : valor(realPart, imagPart) {}

double Complejo::getRealPart() const
{
  return valor.first;
}

double Complejo::getImaginaryPart() const
{
  return valor.second;
}

void Complejo::setRealPart(double newReal)
{
  valor.first = newReal;
}

void Complejo::setImaginaryPart(double newReal)
{
  valor.second = newReal;
}

unique_ptr<Numero> Complejo::suma(const Numero *otro)
{
  const Complejo *otroComplejo = dynamic_cast<const Complejo *>(otro);
  if (!otroComplejo)
  {
    throw invalid_argument("Se esperaba un número Complejo");
  }
  return make_unique<Complejo>(this->valor.first + otroComplejo->getRealPart(), this->valor.second + otroComplejo->getImaginaryPart());
}

unique_ptr<Numero> Complejo::resta(const Numero *otro)
{
  const Complejo *otroComplejo = dynamic_cast<const Complejo *>(otro);
  if (!otroComplejo)
  {
    throw invalid_argument("Se esperaba un número Complejo");
  }
  return make_unique<Complejo>(this->valor.first - otroComplejo->getRealPart(), this->valor.second - otroComplejo->getImaginaryPart());
}

unique_ptr<Numero> Complejo::multiplica(const Numero *otro)
{
  const Complejo *otroComplejo = dynamic_cast<const Complejo *>(otro);
  if (!otroComplejo)
  {
    throw invalid_argument("Se esperaba un número Complejo");
  }

  double a = this->getRealPart();
  double b = this->getImaginaryPart();
  double c = otroComplejo->getRealPart();
  double d = otroComplejo->getImaginaryPart();

  return make_unique<Complejo>(a * c - b * d, a * d + b * c);
}

unique_ptr<Numero> Complejo::divide(const Numero *otro)
{
  const Complejo *otroComplejo = dynamic_cast<const Complejo *>(otro);
  if (!otroComplejo)
  {
    throw invalid_argument("Se esperaba un número Complejo");
  }

  double a = this->getRealPart();
  double b = this->getImaginaryPart();
  double c = otroComplejo->getRealPart();
  double d = otroComplejo->getImaginaryPart();

  double coefRealPart = ((a*c)+(b*d)) / ((c*c)+(d*d));
  double coefImagPart = ((b*c)-(a*d)) / ((c*c)+(d*d));

  return make_unique<Complejo>(coefRealPart, coefImagPart);
}


string Complejo::toString()
{
  ostringstream oss;
  oss << valor.first << " + " << valor.second << "i";
  return oss.str();
}