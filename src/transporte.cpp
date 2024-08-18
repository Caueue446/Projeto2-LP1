#include "transporte.h"

Transporte::Transporte(std::string nome, std::string tipo, int capacidade, double velocidade, double distancia_descanso, double tempo_descanso, Cidade* localizacao_atual)
    : name(nome), tipo(tipo), capacidade(capacidade), velocidade(velocidade), distancia_descanso(distancia_descanso), tempo_descanso(tempo_descanso), localizacao_atual(localizacao_atual) {}

std::string Transporte::getTipo() const {
    return tipo;
}

std::string Transporte::getName() const {
    return name;
}

Cidade* Transporte::getLocalizacao() const {
    return localizacao_atual;
}

double Transporte::getVelocidade() const {
    return velocidade;
}
double Transporte::getDistancia_descanso() {
    return distancia_descanso;
}
double Transporte::getTempo_descanso() {
    return tempo_descanso;
}

void Transporte::setLocalizacao(Cidade* localizacao) {
    localizacao_atual = localizacao;
}

int Transporte::getCapacidade() {
    return capacidade;
}
