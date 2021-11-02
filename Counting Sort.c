#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t


void prepararCountingSort(int k,int tamanhoDoVetor);
void countingSort(int *a, int k,int tamanhoDoVetor, int *QtdOperacoesDeComparacao);
void printarVetor(int vetor[]);
int main()
{
    prepararCountingSort(99999,1000);
    prepararCountingSort(99999,10000);
    prepararCountingSort(99999,100000);
    prepararCountingSort(99999,1000000);
    return 0;
}

void prepararCountingSort(int k,int tamanhoDoVetor){
    
    clock_t tempo;
    int QtdOperacoesDeComparacao = 0;
    
    int vetor[tamanhoDoVetor]; //O tamanho do vetor é definido na chamada da função

    
    //geração dos vetores de forma aleatório e conforme o tamanho fornecido

    //utiliza o timestamp atual como semente para a função "rand()", que é responsável por gerar valores aleatórios
    srand((unsigned)time(NULL));
    for(int i=0;i<tamanhoDoVetor;i++){
        vetor[i] = rand()%k;
        
    }

    tempo = clock();
    countingSort(vetor,k,tamanhoDoVetor,&QtdOperacoesDeComparacao);
    tempo = clock()-tempo;

    

    printf ("O tempo de execuçao para %d elementos foi de  ",tamanhoDoVetor);
    printf(" %f segundos",((float)tempo)/((CLOCKS_PER_SEC)));
    
    

}


//optei por usar ponteiros no a e no QtdOperacoesDeComparacao. Nesse último o fiz pq a variável precisa ser acessada diretamente no endereço em que está
void countingSort(int *a, int k,int tamanhoDoVetor, int *QtdOperacoesDeComparacao){
    
    //Vetor de armazenamento temporário com tamanho K
    int c[k];
    //Vetor que armazena a ordem de saído
    int b[tamanhoDoVetor];

    
    for(int i=0;i<k;i++){
        c[i] =0;
    }
   
    //Ainda que no slide se peça para fazer começando com i=1, vou fazer começando com 0 pq os arrays contam a partir de 0
    for(int i=0;i<tamanhoDoVetor;i++){
        int pos = a[i];
        c[a[i]]= c[a[i]]+1;
        
    }
    

    //cada valor a partir da casa 0 se soma com o valor anterior, e assim se vai acumulando a soma de todos
    for(int i=1;i<k;i++){
        c[i] = c[i]+c[i-1];
    }

    
    
    //Ele vai decrementar até o zero, e não até o 1, porque o array se conta a partir de 0
    for(int i=tamanhoDoVetor-1;i>=0;i--){
        
       
        
        b[c[a[i]]] = a[i];
        
        c[a[i]] = c[a[i]]-1;
    }

    
    //acessa o endereço de memória da variável "vetor" e faz com que os valores sejam ordenados da mesma forma como na variável "c" que está dentro dessa atual função
    for(int i=0;i<tamanhoDoVetor;i++){
        a[i]=b[i];
    }
    
}

void printarVetor(int vetor[]){
    for(int i=0;i<sizeof(vetor);i++){
        printf("%d\n",vetor[i]);
    }
}
