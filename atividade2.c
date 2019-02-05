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



void insertionSort (char *vet, int tam){
	int i, j, x;
	for (i=2; i<=tam; i++){
		x = vet[i];
		j=i-1;
		vet[0] = x; 
		while (x < vet[j]){
			vet[j+1] = vet[j];
			j--;
		}
	vet[j+1] = x;
	}
}




int main(){

	int numero;
	clock_t t1, t2, t3, t4, t5, t6;
	char url[]="texto.txt";
	char ch;
	char *vet;
	int fileSize = 1;
	FILE *arq;
	int count = 0;
	int number;
    
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


		printf("Para ordenar com BUBBLE SORT, digite 1 \n");        
		printf("Para ordenar com SELECTION SORT, digite 2 \n");
		printf("Para ordenar com QUICK SORT, digite 3 \n");
		scanf("%i", &number);

		switch(number){

			case 1:
				vet[count]='\0';
				printf("\n--->BUBBLE SORT<---\n\n");	    
		    		printf("-Antes de ordenar o vetor:-\n%s",vet);
		    		t1 = clock();
		    		bubbleSort(vet,fileSize-1);
		    		t2 = clock();
		    		printf("\n\n-Apos ordenar o vetor com BUBBLE SORT:-\n%s",vet);
		    		float diff = (((float)t2 - (float)t1) / 1000000.0F ); // mile segundos
		    		printf("\nTempo para ordenar:\n--%f mile segundos--\n\n\n",diff);
				break;	
	


			case 2:
				printf("\n--->SELECTION SORT<---\n\n");	    
				t3= clock();
				printf("-Antes de ordenar o vetor:-\n%s",vet);
				selectionSort(vet,fileSize-1);
				printf("\n\n-Apos ordenar o vetor com SELECTION SORT:-\n%s",vet);
				t4 = clock();
				float difff = (((float)t4 - (float)t3) / 1000000.0F ); // mile segundos
				printf("\nTempo para ordenar:\n--%f mile segundos--\n\n\n",difff);
				break;


			case 3:
				printf("\n--->INSERTION SORT<---\n\n");	    
				t5= clock();
				printf("-Antes de ordenar o vetor:-\n%s",vet);
				insertionSort(vet,fileSize-1);
				printf("\n\n-Apos ordenar o vetor com INSERTION SORT:-\n%s",vet);
				t6 = clock();
				float diffff = (((float)t6 - (float)t5) / 1000000.0F ); // mile segundos
				printf("\nTempo para ordenar:\n--%f mile segundos--\n\n\n",diffff);
				break;
	
		}
    

	}


	fclose(arq);
	return 0;


}


























