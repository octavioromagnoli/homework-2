#ifndef NUMERO_ENTERO_H
#define NUMERO_ENTERO_H

#include "Numero.h"

class Entero : public Numero
{
private:
  int valor;

public:
  Entero(int val);

  int getValor() const;
  void setValor(int valor);

  unique_ptr<Numero> suma(const Numero *otro) override;
  unique_ptr<Numero> resta(const Numero *otro) override;
  unique_ptr<Numero> multiplica(const Numero *otro) override;
  unique_ptr<Numero> divide(const Numero *otro) override;

  string toString() override;
};

#endif