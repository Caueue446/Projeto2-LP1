#include <gestao.h>
#include "viagem.h"
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void cadastrarCidade(vector<Cidade*>& cidades) {
    cout << "Digite o nome da cidade: ";
    string nome;
    getline(cin, nome);
    cidades.push_back(new Cidade(nome));
    cout << "Cidade cadastrada!" << endl;
}

void cadastrarTrajeto(vector<Cidade*>& cidades, vector<Trajeto*>& trajetos) {
    int index_origem, index_destino;
    string tipo;
    double distancia;

    cout << "Cidades disponíveis:" << endl;
    for (size_t i = 0; i < cidades.size(); ++i) {
        cout << i + 1 << ". " << cidades[i]->getName() << endl;
    }

    cout << "Digite o número da cidade de origem: ";
    while (!(cin >> index_origem) || index_origem < 1 || index_origem > static_cast<int>(cidades.size())) {
        cout << "Índice inválido. Digite um número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Cidade* origem = cidades[index_origem - 1];

    cout << "Digite o número da cidade de destino: ";
    while (!(cin >> index_destino) || index_destino < 1 || index_destino > static_cast<int>(cidades.size())) {
        cout << "Índice inválido. Digite um número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Cidade* destino = cidades[index_destino - 1];

    cout << "Digite o tipo de trajeto: ";
    cin.ignore();
    getline(cin, tipo);

    cout << "Digite a distância em km: ";
    while (!(cin >> distancia) || distancia <= 0) {
        cout << "Distância inválida. Digite um valor positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Trajeto* novo_trajeto = new Trajeto(origem, destino, tipo, distancia);
    trajetos.push_back(novo_trajeto);

    cout << "Trajeto cadastrado com sucesso!" << endl;
}

void cadastrarPassageiro(vector<Cidade*>& cidades, vector<Passageiro*>& passageiros) {
    cout << "Digite o nome do passageiro: ";
    string nome;
    getline(cin, nome);

    cout << "Cidades disponíveis:" << endl;
    for (size_t i = 0; i < cidades.size(); ++i) {
        cout << i + 1 << ". " << cidades[i]->getName() << endl;
    }

    int escolha_cidade;
    cout << "Escolha a cidade de localização atual (número): ";
    while (!(cin >> escolha_cidade) || escolha_cidade < 1 || escolha_cidade > static_cast<int>(cidades.size())) {
        cout << "Índice inválido. Digite um número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    Cidade* cidade_atual = cidades[escolha_cidade - 1];

    passageiros.push_back(new Passageiro(nome, cidade_atual));
    cout << "Passageiro cadastrado!" << endl;
}

void cadastrarTransporte(vector<Cidade*>& cidades, vector<Transporte*>& transportes) {
    string nome, tipo;
    int capacidade;
    double velocidade, distancia_descanso, tempo_descanso;
    int escolha_cidade;
    
    if (cidades.empty()) {
        cout << "Nenhuma cidade cadastrada." << endl;
        return;
    }

    cout << "Cidades disponíveis:" << endl;
    for (size_t i = 0; i < cidades.size(); ++i) {
        cout << i + 1 << ". " << cidades[i]->getName() << endl;
    }
    cout << "Escolha a cidade onde o transporte está localizado (número): ";
    cin >> escolha_cidade;

    if (escolha_cidade < 1 || escolha_cidade > static_cast<int>(cidades.size())) {
        cout << "Cidade inválida. Tente novamente." << endl;
        return;
    }
    
    Cidade* localizacao_atual = cidades[escolha_cidade - 1];

    cout << "Digite o nome do transporte: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o tipo de transporte: ";
    getline(cin, tipo);
    cout << "Digite a capacidade de passageiros: ";
    cin >> capacidade;
    cout << "Digite a velocidade em km/h: ";
    cin >> velocidade;
    cout << "Digite a distância entre descansos em km: ";
    cin >> distancia_descanso;
    cout << "Digite o tempo de descanso em horas: ";
    cin >> tempo_descanso;

    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distancia_descanso, tempo_descanso, localizacao_atual));
    cout << "Transporte cadastrado com sucesso!" << endl;
}

void iniciarViagem(vector<Cidade*>& cidades, vector<Trajeto*>& trajetos, vector<Transporte*>& transportes, vector<Passageiro*>& passageiros, vector<Viagem*>& viagens) {
    int escolha_origem, escolha_destino, escolha_transporte;

    cout << "Cidades disponíveis:" << endl;
    for (size_t i = 0; i < cidades.size(); ++i) {
        cout << i + 1 << ". " << cidades[i]->getName() << endl;
    }
    cout << "Escolha a cidade de origem (número): ";
    cin >> escolha_origem;
    if (escolha_origem < 1 || escolha_origem > static_cast<int>(cidades.size())) {
        cout << "Cidade de origem inválida. Tente novamente." << endl;
        return;
    }

    cout << "Escolha a cidade de destino (número): ";
    cin >> escolha_destino;
    if (escolha_destino < 1 || escolha_destino > static_cast<int>(cidades.size())) {
        cout << "Cidade de destino inválida. Tente novamente." << endl;
        return;
    }

    cout << "Transportes disponíveis:" << endl;
    for (size_t i = 0; i < transportes.size(); ++i) {
        cout << i + 1 << ". " << transportes[i]->getName() << endl;
    }
    cout << "Escolha o transporte (número): ";
    cin >> escolha_transporte;
    if (escolha_transporte < 1 || escolha_transporte > static_cast<int>(transportes.size())) {
        cout << "Transporte inválido. Tente novamente." << endl;
        return;
    }

    Cidade* cidade_origem = cidades[escolha_origem - 1];
    Cidade* cidade_destino = cidades[escolha_destino - 1];
    Transporte* transporte_escolhido = transportes[escolha_transporte - 1];

    if (transporte_escolhido->getLocalizacao() != cidade_origem) {
        cout << "O transporte selecionado não está na cidade de origem." << endl;
        return;
    }

    map<Cidade*, Trajeto*> predecessores;
    map<Cidade*, double> distancias;
    map<Cidade*, Trajeto*> caminhos;
    set<Cidade*> visitados;
    queue<Cidade*> fila;

    for (Cidade* c : cidades) {
        distancias[c] = numeric_limits<double>::max();
        caminhos[c] = nullptr;
    }

    distancias[cidade_origem] = 0.0;
    fila.push(cidade_origem);

    while (!fila.empty()) {
        Cidade* atual = fila.front();
        fila.pop();
        
        for (Trajeto* trajeto : trajetos) {
            if (trajeto->getOrigem() == atual && trajeto->getTipo() == transporte_escolhido->getTipo()) {
                Cidade* destino = trajeto->getDestino();
                if (distancias[atual] + trajeto->getDistancia() < distancias[destino]) {
                    distancias[destino] = distancias[atual] + trajeto->getDistancia();
                    caminhos[destino] = trajeto;
                    fila.push(destino);
                }
            }
        }
    }

    if (distancias[cidade_destino] == numeric_limits<double>::max()) {
        cout << "Nenhum trajeto encontrado entre as cidades selecionadas." << endl;
        return;
    }

    vector<Trajeto*> trajetos_conectados;
    Cidade* atual = cidade_destino;
    while (atual != cidade_origem) {
        Trajeto* t = caminhos[atual];
        if (t) {
            trajetos_conectados.push_back(t);
            atual = t->getOrigem();
        } else {
            cout << "Não foi possível encontrar um caminho." << endl;
            return;
        }
    }
    reverse(trajetos_conectados.begin(), trajetos_conectados.end());

    double distancia_total = 0.0;
    for (Trajeto* t : trajetos_conectados) {
        distancia_total += t->getDistancia();
    }

    vector<Passageiro*> passageiros_escolhidos;

    cout << "Passageiros disponíveis:" << endl;
    for (size_t i = 0; i < passageiros.size(); ++i) {
        cout << i + 1 << ". " << passageiros[i]->getName() << " - Localização: " << passageiros[i]->getLocalizacao()->getName() << endl;
    }

    char adicionar_passageiro;
    do {
        int escolha_passageiro;
        cout << "Escolha um passageiro para adicionar à viagem (número): ";
        cin >> escolha_passageiro;

        if (escolha_passageiro < 1 || escolha_passageiro > static_cast<int>(passageiros.size())) {
            cout << "Passageiro inválido. Tente novamente." << endl;
            continue;
        }

        Passageiro* passageiro_escolhido = passageiros[escolha_passageiro - 1];

        if (passageiro_escolhido->getLocalizacao() == cidade_origem) {
            passageiros_escolhidos.push_back(passageiro_escolhido);
            cout << "Passageiro " << passageiro_escolhido->getName() << " adicionado à viagem." << endl;
        } else {
            cout << "O passageiro " << passageiro_escolhido->getName() << " não está na cidade de origem." << endl;
        }

        cout << "Deseja adicionar mais passageiros? (s/n): ";
        cin >> adicionar_passageiro;
        cin.ignore();
    } while (adicionar_passageiro == 's' || adicionar_passageiro == 'S');

    Viagem* nova_viagem = new Viagem(transporte_escolhido, passageiros_escolhidos, cidade_origem, cidade_destino, distancia_total);
    viagens.push_back(nova_viagem);

    transporte_escolhido->setLocalizacao(nullptr);
    for (Passageiro* p : passageiros_escolhidos) {
        p->setLocalizacao(nullptr);
    }

    cout << "Viagem conectada de " << cidade_origem->getName() << " para " << cidade_destino->getName() << " iniciada!" << endl;
}

void avancarHoras(vector<Viagem*>& viagens, double horas) {
    for (Viagem* viagem : viagens) {
        if (!viagem->getStatus()) { 
            Transporte* transporte = viagem->getTransporte();
            double distancia_total = viagem->getDistanciaTotal();
            double velocidade = transporte->getVelocidade();
            double distancia_por_descanso = transporte->getDistancia_descanso();
            double tempo_descanso = transporte->getTempo_descanso();

            double tempo_viaje = distancia_total / velocidade;
            double numero_descansos = std::ceil(distancia_total / distancia_por_descanso);
            double tempo_total = tempo_viaje + (numero_descansos * tempo_descanso);

            double tempo_restante = tempo_total - viagem->getHorasPassadas();

            if (horas >= tempo_restante) {
                viagem->setStatus(true);
                transporte->setLocalizacao(viagem->getDestino());

                for (Passageiro* p : viagem->getPassageiros()) {
                    p->setLocalizacao(viagem->getDestino());
                }
            } else {
                viagem->setHorasPassadas(viagem->getHorasPassadas() + horas);

                transporte->setLocalizacao(nullptr);
                for (Passageiro* p : viagem->getPassageiros()) {
                    p->setLocalizacao(nullptr);
                }
            }
        }
    }
}

void mostrarRelatorio(const vector<Transporte*>& transportes, const vector<Passageiro*>& passageiros, const vector<Viagem*>& viagens) {
    cout << "Relatório de Localizações e Viagens em Andamento:" << endl;
    cout << "----------------------------------------------" << endl;

    cout << "Transportes:" << endl;
    for (const Transporte* transporte : transportes) {
        if (transporte->getLocalizacao()) {
            cout << transporte->getName() << " está em " << transporte->getLocalizacao()->getName() << endl;
        } else {
            cout << transporte->getName() << " está em trânsito." << endl;
        }
    }
    cout << "----------------------------------------------" << endl;

    cout << "Passageiros:" << endl;
    for (const Passageiro* passageiro : passageiros) {
        if (passageiro->getLocalizacao()) {
            cout << passageiro->getName() << " está em " << passageiro->getLocalizacao()->getName() << endl;
        } else {
            cout << passageiro->getName() << " está em trânsito." << endl;
        }
    }
    cout << "----------------------------------------------" << endl;


    bool tem_viagem_em_andamento = false;
    cout << "Viagens em Andamento:" << endl;
    for (const Viagem* viagem : viagens) {
        if (!viagem->getStatus()) {  
            tem_viagem_em_andamento = true;
            Transporte* transporte = viagem->getTransporte();
            double distancia_total = viagem->getDistanciaTotal();
            double velocidade = transporte->getVelocidade();
            double distancia_por_descanso = transporte->getDistancia_descanso();
            double tempo_descanso = transporte->getTempo_descanso();
            double tempo_viaje = distancia_total / velocidade;
            double numero_descansos = std::ceil(distancia_total / distancia_por_descanso);
            double tempo_total = tempo_viaje + (numero_descansos * tempo_descanso);

            cout << "Viagem de " << viagem->getOrigem()->getName()
                 << " para " << viagem->getDestino()->getName()
                 << " com o transporte " << viagem->getTransporte()->getName()
                 << " está em andamento. Horas passadas: " << viagem->getHorasPassadas() 
                 << " de " << tempo_total 
                 << " horas necessárias." << endl;
        }
    }

    if (!tem_viagem_em_andamento) {
        cout << "Não há nenhuma viagem em andamento." << endl;
    }
    cout << "----------------------------------------------" << endl;
}