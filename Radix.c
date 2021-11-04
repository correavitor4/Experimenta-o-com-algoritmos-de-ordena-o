#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

void radixSort(int *vetor, int tamanhoDoVetor,int *qtdOperacoesDeComparacao);
void prepararRadixSort(int k,int tamanhoDoVetor);
int main(int argc, char const *argv[])
{

    prepararRadixSort(99999,1000);
    prepararRadixSort(99999,10000);
    prepararRadixSort(99999,100000);
    prepararRadixSort(99999,1000000);
    return 0;
}

void prepararRadixSort(int k,int tamanhoDoVetor){
    clock_t tempo;
    int QtdOperacoesDeComparacao = 0;

    int *vetor ;
    vetor= (int*) calloc(tamanhoDoVetor,sizeof(int));
 

    
    //geração dos vetores de forma aleatório e conforme o tamanho fornecido

    //utiliza o timestamp atual como semente para a função "rand()", que é responsável por gerar valores aleatórios
    srand((unsigned)time(NULL));
    for(int i=0;i<tamanhoDoVetor;i++){
        vetor[i] = rand()%k;
        
    }
  
    tempo= clock();
    radixSort(vetor,tamanhoDoVetor,&QtdOperacoesDeComparacao);
    tempo = clock()-tempo;

    printf ("O tempo de execucao para %d elementos foi de  ",tamanhoDoVetor);
    printf(" %f milisegundos",((double)tempo)/((CLOCKS_PER_SEC)/1000));
    printf(". A quantidade de operacoes de comparacao realizadas ehde %d\n",QtdOperacoesDeComparacao);
    /*
    for(int i=0;i<tamanhoDoVetor;i++){
        printf("%d\n",vetor[i]);
    }
    */
}


void radixSort(int *vetor, int tamanhoDoVetor,int *qtdOperacoesDeComparacao){
    int *output = (int *) calloc(tamanhoDoVetor,sizeof(int));
    int maior = vetor[0];
    int digitoSignificativoAtual=1;
    //definir a variável "maior"
    for(int i=0;i<tamanhoDoVetor;i++,*qtdOperacoesDeComparacao+=1){
        
        if(vetor[i]>maior){
            maior=vetor[i];
        }

        *qtdOperacoesDeComparacao+=1;
    }

    while(maior/digitoSignificativoAtual>0){
        int bucket[10] = { 0 };

        for(int i=0;i<tamanhoDoVetor;i++,*qtdOperacoesDeComparacao+=1){
            bucket[(vetor[i]/digitoSignificativoAtual)%10]++;
        }

        for(int i=1;i<10;i++,*qtdOperacoesDeComparacao+=1){
            bucket[i]= bucket[i]+bucket[i-1];
        }

        for(int i=tamanhoDoVetor-1;i>=0;i--,*qtdOperacoesDeComparacao+=1){
            output[--bucket[(vetor[i]/digitoSignificativoAtual)%10]]=vetor[i];
        }

        for(int i=0;i<tamanhoDoVetor;i++,*qtdOperacoesDeComparacao+=1){
            vetor[i]=output[i];
        }

        digitoSignificativoAtual*=10;

    }

    
}




