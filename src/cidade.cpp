#include "cidade.h"

Cidade::Cidade(const std::string& nome) : name(nome) {}

std::string Cidade::getName() const {
    return name;
}