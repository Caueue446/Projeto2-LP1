#include <gestao.h>
#include <iostream>
#include <save.h>
using namespace std;


int main() {
    vector<Cidade*> cidades;
    vector<Trajeto*> trajetos;
    vector<Transporte*> transportes;
    vector<Passageiro*> passageiros;
    vector<Viagem*> viagens;

    carregarCidades(cidades);
    carregarTrajetos(trajetos, cidades);
    carregarTransportes(transportes, cidades);
    carregarPassageiros(passageiros, cidades);

    
    int opcao;
    do {
        cout << "1. Cadastrar Cidade" << endl;
        cout << "2. Cadastrar Trajeto" << endl;
        cout << "3. Cadastrar Transporte" << endl;
        cout << "4. Cadastrar Passageiro" << endl;
        cout << "5. Iniciar viagem" << endl;
        cout << "6. Avançar horas" << endl;
        cout << "7. Mostrar relatório" << endl;
        cout << "8. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cadastrarCidade(cidades);
                salvarCidades(cidades);
                break;
            case 2:
                cadastrarTrajeto(cidades, trajetos);
                salvarTrajetos(trajetos);
                break;
            case 3:
                cadastrarTransporte(cidades, transportes);
                salvarTransportes(transportes);
                break;
            case 4:
                cadastrarPassageiro(cidades, passageiros);
                salvarPassageiros(passageiros);
                break;
            case 5:
                iniciarViagem(cidades, trajetos, transportes, passageiros, viagens);
                break;
            case 6:
                double horas;
                cout << "Digite o número de horas a avançar: ";
                cin >> horas;
                avancarHoras(viagens, horas);
                break;
            case 7:
                mostrarRelatorio(transportes, passageiros, viagens);
                break;
            case 8:
                cout << "Finalizando..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 8);

    salvarCidades(cidades);
    salvarTrajetos(trajetos);
    salvarTransportes(transportes);
    salvarPassageiros(passageiros);

    return 0;
}

