#include "Cliente.h"

Cliente::Cliente() : esPremier(false) {}
Cliente::Cliente(bool premier) : esPremier(premier) {}
bool Cliente::getEsPremier() { return esPremier; }
