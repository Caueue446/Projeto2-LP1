#include "viagem.h"

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino, double distancia_total)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino), distancia_total(distancia_total), concluida(false), horas_passadas(0) {}

Transporte* Viagem::getTransporte() const {
    return transporte;
}

Cidade* Viagem::getDestino() const {
    return destino;
}

Cidade* Viagem::getOrigem() const {
    return origem;
}

std::vector<Passageiro*> Viagem::getPassageiros() const {
    return passageiros;
}

double Viagem::getDistanciaTotal() const {
    return distancia_total;
}

double Viagem::getHorasPassadas() const {
    return horas_passadas;
}

void Viagem::setHorasPassadas(double horas) {
    horas_passadas = horas;
}

void Viagem::setStatus(bool status) {
    concluida = status;
}

bool Viagem::getStatus() const {
    return concluida;
}