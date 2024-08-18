#include <fstream>
#include <sstream>
#include "cidade.h"
#include "trajeto.h"
#include "transporte.h"
#include "passageiro.h"
#include <vector>
using namespace std;


// Função para salvar os dados de uma cidade
void salvarCidades(const vector<Cidade*>& cidades) {
    std::ofstream arquivo("cidades.txt");
    if (arquivo.is_open()) {
        for (const auto& cidade : cidades) {
            arquivo << cidade->getName() << std::endl;
        }
        arquivo.close();
    }
}

// Função para salvar os dados de um trajeto
void salvarTrajetos(const vector<Trajeto*>& trajetos) {
    std::ofstream arquivo("trajetos.txt");
    if (arquivo.is_open()) {
        for (const auto& trajeto : trajetos) {
            arquivo << trajeto->getOrigem()->getName() << ","
                    << trajeto->getDestino()->getName() << ","
                    << trajeto->getTipo() << ","
                    << trajeto->getDistancia() << std::endl;
        }
        arquivo.close();
    }
}

// Função para salvar os dados de um passageiro
void salvarPassageiros(const vector<Passageiro*>& passageiros) {
    std::ofstream arquivo("passageiros.txt");
    if (arquivo.is_open()) {
        for (const auto& passageiro : passageiros) {
            arquivo << passageiro->getName() << ","
                    << passageiro->getLocalizacao()->getName() << std::endl;
        }
        arquivo.close();
    }
}

// Função para salvar os dados de um transporte
void salvarTransportes(const vector<Transporte*>& transportes) {
    std::ofstream arquivo("transportes.txt");
    if (arquivo.is_open()) {
        for (const auto& transporte : transportes) {
            arquivo << transporte->getName() << ","
                    << transporte->getTipo() << ","
                    << transporte->getCapacidade() << ","
                    << transporte->getVelocidade() << ","
                    << transporte->getDistancia_descanso() << ","
                    << transporte->getTempo_descanso() << ","
                    << transporte->getLocalizacao()->getName() << std::endl;
        }
        arquivo.close();
    }
}

//carregar

void carregarCidades(vector<Cidade*>& cidades) {
    std::ifstream arquivo("cidades.txt");
    std::string linha;

    while (std::getline(arquivo, linha)) {
        cidades.push_back(new Cidade(linha));
    }
    arquivo.close();
}

// Função para carregar os dados de um trajeto
void carregarTrajetos(vector<Trajeto*>& trajetos, const vector<Cidade*>& cidades) {
    std::ifstream arquivo("trajetos.txt");
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string origem, destino, tipo;
        double distancia;

        std::getline(ss, origem, ',');
        std::getline(ss, destino, ',');
        std::getline(ss, tipo, ',');
        ss >> distancia;

        Cidade* cidadeOrigem = nullptr;
        Cidade* cidadeDestino = nullptr;
        for (auto& cidade : cidades) {
            if (cidade->getName() == origem) {
                cidadeOrigem = cidade;
            }
            if (cidade->getName() == destino) {
                cidadeDestino = cidade;
            }
        }
        if (cidadeOrigem && cidadeDestino) {
            trajetos.push_back(new Trajeto(cidadeOrigem, cidadeDestino, tipo, distancia));
        }
    }
    arquivo.close();
}

// Função para carregar os dados de um passageiro
void carregarPassageiros(vector<Passageiro*>& passageiros, const vector<Cidade*>& cidades) {
    std::ifstream arquivo("passageiros.txt");
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome, localizacao;
        
        std::getline(ss, nome, ',');
        std::getline(ss, localizacao, ',');

        Cidade* cidadeLocalizacao = nullptr;
        for (auto& cidade : cidades) {
            if (cidade->getName() == localizacao) {
                cidadeLocalizacao = cidade;
                break;
            }
        }

        if (cidadeLocalizacao) {
            passageiros.push_back(new Passageiro(nome, cidadeLocalizacao));
        }
    }
    arquivo.close();
}

// Função para carregar os dados de um transporte
void carregarTransportes(vector<Transporte*>& transportes, const vector<Cidade*>& cidades) {
    std::ifstream arquivo("transportes.txt");
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string nome, tipo, localizacao;
        int capacidade;
        double velocidade, distancia_descanso, tempo_descanso;

        std::getline(ss, nome, ',');
        std::getline(ss, tipo, ',');
        ss >> capacidade;
        ss.ignore();
        ss >> velocidade;
        ss.ignore();
        ss >> distancia_descanso;
        ss.ignore();
        ss >> tempo_descanso;
        ss.ignore();
        std::getline(ss, localizacao, ',');

        Cidade* cidadeLocalizacao = nullptr;
        for (auto& cidade : cidades) {
            if (cidade->getName() == localizacao) {
                cidadeLocalizacao = cidade;
                break;
            }
        }

        if (cidadeLocalizacao) {
            transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distancia_descanso, tempo_descanso, cidadeLocalizacao));
        }
    }
    arquivo.close();
}



