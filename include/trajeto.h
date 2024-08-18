#ifndef TRAJETO_H
#define TRAJETO_H

#include "cidade.h"
#include <string>

class Trajeto {
private:
    Cidade* origem;
    Cidade* destino;
    std::string tipo;
    double distancia;

public:
    Trajeto(Cidade* origem, Cidade* destino, std::string tipo, double distancia);

    Cidade* getOrigem() const;
    Cidade* getDestino() const;
    double getDistancia() const;
    std::string getTipo() const;
};

#endif
