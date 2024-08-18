#include "passageiro.h"

Passageiro::Passageiro(std::string nome, Cidade* localizacao_inicial)
    : name(nome), localizacao_atual(localizacao_inicial) {}

std::string Passageiro::getName() const {
    return name;
}

Cidade* Passageiro::getLocalizacao() const {
    return localizacao_atual;
}

void Passageiro::setLocalizacao(Cidade* nova_localizacao) {
    localizacao_atual = nova_localizacao;
}