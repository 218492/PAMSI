#include "tabd.h"
#include "interfejsstosu.h"

class stos: public interfejsstosu, private tabd{
int rozmiarstosu;
public:
virtual void push(int element);
virtual void pop();
virtual int rozmiarstsu();
stos();
};
