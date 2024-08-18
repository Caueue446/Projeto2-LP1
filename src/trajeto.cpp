#include "trajeto.h"

Trajeto::Trajeto(Cidade* origem, Cidade* destino, std::string tipo, double distancia)
    : origem(origem), destino(destino), tipo(tipo), distancia(distancia) {}

Cidade* Trajeto::getOrigem() const {
    return origem;
}

Cidade* Trajeto::getDestino() const {
    return destino;
}

double Trajeto::getDistancia() const {
    return distancia;
}

std::string Trajeto::getTipo() const {
    return tipo;
}