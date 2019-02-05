#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(char *vet, int tam) {
    int i, j, temp;
    for (i = 0; i < tam - 1; i++){
        for (j = (i+1); j < tam; j++){
            if (vet[j] < vet[i]){
               temp = vet[i];
               vet[i] = vet[j];
               vet[j] = temp;
           }
        }
    }
}
    int main (void){
    clock_t t1, t2, t3, t4;
    char url[]="texto.txt";
    char ch;
    char *vet;
    int fileSize = 1;
    FILE *arq;
    int count = 0;
    
    arq=fopen(url, "r");
    
    if(arq == NULL)
        printf("Erro, nao foi possivel abrir o arquivo");
    
    else{
        fseek(arq, 0, SEEK_END);
        fileSize = ftell(arq);
        printf("Tamanho do vetor: %d\n",fileSize);
        rewind(arq);
        vet = (char *) malloc(fileSize * sizeof(char));
        
        while((ch=fgetc(arq))!=EOF){
            vet[count] = ch;
            count++;
        }
        
    vet[count]='\0';
    printf("--->BUBBLE SORT<---\n");
    
    printf("Antes de ordenar o vetor: %s\n",vet);
    t1 = clock();
    bubbleSort(vet,fileSize-1);
    t2 = clock();
    printf("Apos ordenar o vetor com bubble sort: %s \n",vet);
    float diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
    printf("%f\n\n\n",diff);
    
    
    printf("--->SELECTION SORT<---\n");
    
    t3= clock();
    printf("Antes de ordenar o vetor: %s\n",vet);
    selectionSort(vet,fileSize-1);
    printf("Apos ordenar o vetor com selection sort: %s \n",vet);
    t4 = clock();
    float difff = (((float)t4 - (float)t3) / 1000000.0F ); // mile segundos
    printf("%f\n\n\n",difff);
}
fclose(arq);
return 0;
}
void selectionSort(char *vet, int tam) {
  int i, j, min, aux;
  
  for (i = 0; i < (tam-1); i++){
    min = i;
    for (j = (i+1); j < tam; j++) {
       if(vet[j] < vet[min])
         min = j;
    }
    if (vet[i] != vet[min]) {
       aux = vet[i];
       vet[i] = vet[min];
       vet[min] = aux;
    }
  }
}
