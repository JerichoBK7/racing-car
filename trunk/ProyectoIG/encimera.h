#ifndef ENCIMERA_H
#define ENCIMERA_H

#include <superficie.h>

class encimera
{
private:
    superficie e;
    vector<superficie> juntas;
    // texturas
    BMPClass *e_;
public:
    encimera();
    void construir(void);
};

#endif // ENCIMERA_H
