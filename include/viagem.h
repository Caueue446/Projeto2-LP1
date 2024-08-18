#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include "cidade.h"
#include "transporte.h"
#include "passageiro.h"

class Viagem {
public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, double distancia_total);

    Transporte* getTransporte() const;
    Cidade* getOrigem() const;
    Cidade* getDestino() const;
    std::vector<Passageiro*> getPassageiros() const;
    double getDistanciaTotal() const;
    double getHorasPassadas() const; 
    void setHorasPassadas(double horas);
    void setStatus(bool concluida);
    bool getStatus() const;

private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    double distancia_total;
    bool concluida;
    double horas_passadas;
};

#endif
