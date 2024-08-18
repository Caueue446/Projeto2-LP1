#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include "cidade.h"
#include <string>

class Transporte {
public:
    Transporte(std::string nome, std::string tipo, int capacidade, double velocidade, double distancia_descanso, double tempo_descanso, Cidade* localizacao_atual);

    std::string getTipo() const;
    std::string getName() const;
    Cidade* getLocalizacao() const;
    double getVelocidade() const;
    void setLocalizacao(Cidade* localizacao);
    double getDistancia_descanso();
    double getTempo_descanso();
    int getCapacidade();

private:
    std::string name;
    std::string tipo;
    int capacidade;
    double velocidade;
    double distancia_descanso;
    double tempo_descanso;
    Cidade* localizacao_atual;
};

#endif