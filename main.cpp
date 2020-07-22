#include <iostream>
using namespace std;

using std::cin;
    void ordenacao_bubble(int *vetor, int tam){
        for(int i = 0; i < (tam - 1); i++){
            for(int j = 0; j < (tam - i - 1); j++){
             if(vetor[j + 1] < vetor[j]){
                 int copia = vetor[j + 1];
                    vetor[j + 1] = vetor[j];
                    vetor[j] = copia;
                }
            }
        }
    }

void ordenacao_insertion(int *vetor, int tam){
    for(int i = 1; i < tam; i++){
        int menor_valor = vetor[i];
        int j = (i - 1);

        while((j >= 0) && (vetor[j] > menor_valor)){
            vetor[j + 1] = vetor[j];
            j = (j - 1);
        }

        vetor[j + 1] = menor_valor;
    }
}

void ordenacao_selection(int *vetor, int tam){
    for(int i = 0; i < (tam - 1); i++){
        int posicao_menor =  i;

        for(int j = (i + 1); j < tam; j++){
            if(vetor[j] < vetor[posicao_menor]){
                posicao_menor = j;
            }
        }

        int copia = vetor[posicao_menor];
        vetor[posicao_menor] = vetor[i];
        vetor[i] = copia;
    }
}
//MÉTODO DE VERIFICAR ORDENAÇÃO
 bool verificar_ordenacao(int vetor[], unsigned int tamanho_vetor) {
        for(unsigned int i = 1; i < tamanho_vetor; ++i) {
            if(vetor[i-1] > vetor[i]) {
                return false;
            }
        }

        return true;
    }

void preenche_vetor(int vetor[], int tamanho_vetor){
  int i = 0;
    for(i =0; i < tamanho_vetor; i ++){
        vetor[i] = tamanho_vetor-i;
    }
}

//COMEÇ0 DA MAIN
int main() {
    unsigned int tamanho_vetor = 10;
    int *vetor_selection, *vetor_insertion, *vetor_bubble;

    //cin >> tamanho_vetor;

    // São necessarios três vetores para podermos alterá-los nas funções de
    // ordenação sem prejudicar as próximas chamadas.
    vetor_selection = new int[tamanho_vetor];
    vetor_insertion = new int[tamanho_vetor];
    vetor_bubble    = new int[tamanho_vetor];

    for(unsigned int i = 0; i < tamanho_vetor; ++i) {
        cin >> vetor_selection[i];

        // Os três vetores devem ter os mesmos elementos
        vetor_bubble[i] = vetor_insertion[i] = vetor_selection[i];
    }


    //*** Chamar as ordenacoes e contabilizar o tempo aqui ***//

        clock_t inicio, fim;
        double tempo_decorrido;

        // Imediatamente antes da execução
        inicio = clock();
        preenche_vetor(vetor_bubble, tamanho_vetor);
            ordenacao_bubble(vetor_bubble, tamanho_vetor);
        // !!! Chamar função que queremos medir o tempo !!! //

        bool verifica_bubble = verificar_ordenacao(vetor_bubble, tamanho_vetor);
        cout << "tempo do bubble foi" << verifica_bubble ;


        // Imediatamente depois da execução
        fim = clock();
            tempo_decorrido = 1000.0 * double(fim - inicio) / CLOCKS_PER_SEC;
            cout << " Tempo decorrido do Bubble sort :" << tempo_decorrido << endl;


        inicio = clock();
        preenche_vetor(vetor_insertion, tamanho_vetor);
            ordenacao_insertion(vetor_insertion, tamanho_vetor);
            // !!! Chamar função que queremos medir o tempo !!! //
            bool verifica_insertion = verificar_ordenacao(vetor_insertion, tamanho_vetor);
            cout << "tempo do insertion foi" << verifica_insertion;

            // Imediatamente depois da execução
        fim = clock();
            tempo_decorrido = 1000.0 * double(fim - inicio) / CLOCKS_PER_SEC;
            cout << " Tempo decorrido do Insertion sort :" << tempo_decorrido<< endl;

            //outo algoritmo de ordenação


            inicio = clock();
            preenche_vetor( vetor_selection, tamanho_vetor);
            ordenacao_selection(vetor_selection, tamanho_vetor);
            // !!! Chamar função que queremos medir o tempo !!! //
            bool verifica_selection = verificar_ordenacao(vetor_selection, tamanho_vetor);
            cout << "tempo do selection foi" << verifica_selection;


            // Imediatamente depois da execução
        fim = clock();
            tempo_decorrido = 1000.0 * double(fim - inicio) / CLOCKS_PER_SEC;
            cout << " Tempo decorrido do Selection sort :" << tempo_decorrido<< endl;






    delete[] vetor_selection;
    delete[] vetor_insertion;
    delete[] vetor_bubble;

    return 0;
}
