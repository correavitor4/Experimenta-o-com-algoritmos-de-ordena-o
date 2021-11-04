
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
 
// Protótipo da função de ordenação
// Ordination function prototype
void quick_sort(int *a, int left, int right,int *qtdOperacoesDeComparacao);
 void prepararQuickSort(int k,int tamanhoDoVetor);
// Função main
// Main Function
int main(int argc, char** argv)
{
 
    prepararQuickSort(99999,1000);
    prepararQuickSort(99999,10000);
    prepararQuickSort(99999,100000);
    prepararQuickSort(99999,1000000);

}
void prepararQuickSort(int k,int tamanhoDoVetor){
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
    quick_sort(vetor,0,tamanhoDoVetor,&QtdOperacoesDeComparacao);
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

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(int *a, int left, int right,int *qtdOperacoesDeComparacao)
{

    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        *qtdOperacoesDeComparacao+=1;
        while(a[i] < x && i < right) {
            *qtdOperacoesDeComparacao+=1;
            i++;
        }
        while(a[j] > x && j > left) {
            *qtdOperacoesDeComparacao+=1;
            j--;
        }
        *qtdOperacoesDeComparacao+=1;
        if(i <= j) {
            
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
    *qtdOperacoesDeComparacao+=1;
    if(j > left) {
        quick_sort(a, left, j,qtdOperacoesDeComparacao);
    }
    *qtdOperacoesDeComparacao+=1;
    if(i < right) {
        quick_sort(a, i, right,qtdOperacoesDeComparacao);
    }
}
