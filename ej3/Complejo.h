#ifndef NUMERO_COMPLEJO_H
#define NUMERO_COMPLEJO_H

#include "Numero.h"
#include <utility>
using namespace std;

class Complejo : public Numero
{
private:
  pair<double, double> valor;

public:
  Complejo(double realPart, double imagPart);

  double getRealPart() const;
  double getImaginaryPart() const;
  void setRealPart(double realPart);
  void setImaginaryPart(double imagPart);

  unique_ptr<Numero> suma(const Numero *otro) override;
  unique_ptr<Numero> resta(const Numero *otro) override;
  unique_ptr<Numero> multiplica(const Numero *otro) override;
  unique_ptr<Numero> divide(const Numero *otro) override;

  string toString() override;
};

#endif // NUMERO_COMPLEJO_H