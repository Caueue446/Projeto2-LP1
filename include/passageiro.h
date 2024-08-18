#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "cidade.h"
#include <string>

class Passageiro {
private:
    std::string name;
    Cidade* localizacao_atual;

public:
    Passageiro(std::string nome, Cidade* localizacao_inicial);

    std::string getName() const;
    Cidade* getLocalizacao() const; 
    void setLocalizacao(Cidade* nova_localizacao);
};

#endif