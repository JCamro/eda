#include <iostream>
#include <string>

using namespace std;

class Dispositivo { };
class Camara { };
class Smartphone : public Dispositivo, public Camara { };
