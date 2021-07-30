#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define TAM 10

int bubble(int *v, int tam);

int main(){
    int valor;
    FILE *fp = fopen("C:/Users/Davi Lima/Desktop/vetor10(1).txt", "r");

    clock_t tempo;
    int i, j = TAM, //contador 
        vetor[TAM],
        trocas; //recebe o numero de trocas


//CASOS DE TESTE SEM ARQUIVO
//-------------------------------------------------------------------------
    /*for(i = 0; i < TAM; i++){//PIOR CASO: ordem decrescente
        vetor[i] = j;
        j--;
    }*/

    /*for(i = 0; i < TAM; i++){//MELHOR CASO: ordem crescente
        vetor[i] = i;
    }*/
//--------------------------------------------------------------------------

//CASOS COM ARQUIVO
    i = 0;
    while((fscanf(fp,"%d\n",&valor)) != EOF){ //colocar os numeros do arquivo dentro de um vetor
        vetor[i] = valor;
        i++;
    }

    tempo = clock();
    trocas = bubble(vetor, TAM);
    tempo = clock() - tempo;

   /*printf("Ordenado: ");
    for(i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }*/
    printf("\nTempo de processamento %lf ms", ((float)tempo)/(CLOCKS_PER_SEC/1000));
    printf("\nNumero de trocas = %d", trocas);
    return 0;
}

int bubble(int *v, int tam){
    int i, j, //contadores 
        aux,  //variavel auxiliar
        nTrocas = 0; //numero de trocas
    bool trocou; //verifica se houve troca

    for(i = 0; i < tam; i++){
        trocou = false;
        for(j = 0; j < tam -1; j++){
            if(v[j] > v[j+1]){
                aux    = v[j];
                v[j]   = v[j+1];
                v[j+1] = aux;
                trocou = true;
            }
             if(trocou)
                nTrocas++;
        }
    }
    return nTrocas;
}
