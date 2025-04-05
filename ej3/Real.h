#ifndef NUMERO_REAL_H
#define NUMERO_REAL_H

#include "Numero.h"

class Real : public Numero
{
private:
  double valor;

public:
  Real(double val);

  double getValor() const;
  void setValor(double valor);

  unique_ptr<Numero> suma(const Numero *otro) override;
  unique_ptr<Numero> resta(const Numero *otro) override;
  unique_ptr<Numero> multiplica(const Numero *otro) override;
  unique_ptr<Numero> divide(const Numero *otro) override;

  string toString() override;
};

#endif // NUMERO_REAL_H