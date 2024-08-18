#ifndef GESTAO_H
#define GESTAO_H

#include <vector>
#include "cidade.h"
#include "trajeto.h"
#include "transporte.h"
#include "passageiro.h"
#include "viagem.h"

void cadastrarCidade(std::vector<Cidade*>& cidades);
void cadastrarTrajeto(std::vector<Cidade*>& cidades, std::vector<Trajeto*>& trajetos);
void cadastrarTransporte(std::vector<Cidade*>& cidades, std::vector<Transporte*>& transportes);
void cadastrarPassageiro(std::vector<Cidade*>& cidades, std::vector<Passageiro*>& passageiros);
void iniciarViagem(std::vector<Cidade*>& cidades, std::vector<Trajeto*>& trajetos, std::vector<Transporte*>& transportes, std::vector<Passageiro*>& passageiros, std::vector<Viagem*>& viagens);
void avancarHoras(std::vector<Viagem*>& viagens, double horas);
void mostrarRelatorio(const std::vector<Transporte*>& transportes, const std::vector<Passageiro*>& passageiros, const std::vector<Viagem*>& viagens);

#endif
