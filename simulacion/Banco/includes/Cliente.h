#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
  bool esPremier;

public:
  Cliente();
  Cliente(bool premier);
  bool getEsPremier();
};

#endif
