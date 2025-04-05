#ifndef NUMERO_H
#define NUMERO_H

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Numero
{
public:
  virtual unique_ptr<Numero> suma(const Numero *otro) = 0;
  virtual unique_ptr<Numero> resta(const Numero *otro) = 0;
  virtual unique_ptr<Numero> multiplica(const Numero *otro) = 0;
  virtual unique_ptr<Numero> divide(const Numero *otro) = 0;

  virtual string toString() = 0;

  virtual ~Numero() = default;
};

#endif // NUMERO_H