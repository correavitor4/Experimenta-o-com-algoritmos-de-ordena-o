#include <stdio.h>
#include <stdlib.h>

void prepararCountingSort(int k,int tamanhoDoVetor);
int main()
{
    prepararCountingSort(99999,1000);
    return 0;
}

void prepararCountingSort(int k,int tamanhoDoVetor){
    float tempo =0;
    int QtdOperacoesDeComparacao = 0;
    int vetor[tamanhoDoVetor]; //O tamanho do vetor é definido na chamada da função

    
    //geração dos vetores de forma aleatório e conforme o tamanho fornecido

    //utiliza o timestamp atual como semente para a função "rand()", que é responsável por gerar valores aleatórios
    srand((unsigned)time(NULL));
    for(int i=0;i<tamanhoDoVetor;i++){
        vetor[i] = rand()%k;
        printf("%d\n",vetor[i]);
    }
}