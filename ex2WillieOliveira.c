#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int codigo;
	char titulo[255];
	char sinopse[680];
	char diretor[255];
	int ano;
	char genero[255];
}Locadora;
int menu();
void AlterarFilme(Locadora cadastrados[],int *contador);
void listarFilmes(Locadora ListandoCadastrados[],int *contador);
void ListarPorAno(Locadora ListandoCadastrados[],int *contador);
void ProcurarPorNome(Locadora ListandoCadastrados[],int *contador);
Locadora CadastrarFilme(int *contador);


int main(int argc, char *argv[]) {
	int i;
	int escolha;
	Locadora locadora[10];
	
	int *contador;
	int cadastrados=0;
	contador=&cadastrados;
	do{
		escolha=menu();
		switch(escolha){
			case 1:
				locadora[cadastrados]=CadastrarFilme(contador);
				break;
			case 2:
				AlterarFilme(locadora,contador);
				break;
			case 3:
				listarFilmes(locadora,contador);
				break;
			case 4:
				ListarPorAno(locadora,contador);
				break;
			case 5:
				ProcurarPorNome(locadora,contador);
				break;
		}

		
	}while(escolha!=6);
	return 0;
}
int menu(){
	int escolha;
	printf("1-Cadastrar filme\n2-Alterar filme\n3-Listar filme\n4-Listar filme por ano\n5-Procura filme por nome\n6-sair");
	printf("\nDigite a sua opcao: ");
	scanf("%d",&escolha);
    system("cls");
    return(escolha);
}
Locadora CadastrarFilme(int *contador){
	// não foi dito que não podia repetir o codigo ou o filme
	Locadora cadastrando;
	getchar();
	printf("Digite o numero do codigo: ");
	scanf("%d",&cadastrando.codigo);
	getchar();
	printf("Digite o titulo: ");
	gets(cadastrando.titulo);
	printf("Digite a sinopse: ");
	gets(cadastrando.sinopse);
	printf("Digite o nome do diretor: ");
	gets(cadastrando.diretor);
	printf("Digite o genero: ");
	gets(cadastrando.genero);
	printf("Digite o ano do livro(EX 2000): ");
	scanf("%d",&cadastrando.ano);
	*contador=*contador+1;
	 system("PAUSE");
     system("cls");
	return(cadastrando);
	
}
void AlterarFilme(Locadora cadastrados[],int *contador){
	int codigoAlterado;
	int i;
	if(*contador==0){
		printf("Ainda não tivemos registro de nenhum filme\n");
	}else{
	
    printf("Digite o codigo do filme que vc quer alterar: ");
    scanf("%d",&codigoAlterado);
    for(i=0;i<*contador;i++){
    	if(cadastrados[i].codigo==codigoAlterado){
    			printf("Digite o numero do codigo: ");
	            scanf("%d",&cadastrados[i].codigo);
	            getchar();
	            printf("Digite o titulo: ");
             	gets(cadastrados[i].titulo);
             	printf("Digite a sinopse: ");
             	gets(cadastrados[i].sinopse);
            	printf("Digite o nome do diretor: ");
            	gets(cadastrados[i].diretor);
            	printf("Digite o genero: ");
            	gets(cadastrados[i].genero);
             	printf("Digite o ano do livro(EX 2000): ");
	            scanf("%d",&cadastrados[i].ano);		
		} 	
	}
  }
	system("pause");
	system("cls");
}
void listarFilmes(Locadora ListandoCadastrados[],int *contador){
	int i;
	for(i=0;i<*contador;i++){
		printf("Codigo==%d\n",ListandoCadastrados[i].codigo);
		printf("titulo==%s\n",ListandoCadastrados[i].titulo);
		printf("Sinopse==%s\n",ListandoCadastrados[i].sinopse);
		printf("Diretor==%s\n",ListandoCadastrados[i].diretor);
		printf("Genero==%s\n",ListandoCadastrados[i].genero);
		printf("Ano de lançamento==%d\n",ListandoCadastrados[i].ano);
		printf("-----------------\n");
	}
	system("pause");
	system("cls");
}
void ListarPorAno(Locadora ListandoCadastrados[],int *contador){
	int i;
	int j;
	Locadora aux;
	for(i=1;i<*contador;i++){
		aux=ListandoCadastrados[i];
		for(j=i;(j>0)&&(aux.ano>ListandoCadastrados[j-1].ano);j--){
			ListandoCadastrados[j]=ListandoCadastrados[j-1];
			
		}ListandoCadastrados[j]=aux;
	}
	for(i=0;i<*contador;i++){
		printf("Codigo==%d\n",ListandoCadastrados[i].codigo);
		printf("titulo==%s\n",ListandoCadastrados[i].titulo);
		printf("Sinopse==%s\n",ListandoCadastrados[i].sinopse);
		printf("Diretor==%s\n",ListandoCadastrados[i].diretor);
		printf("Genero==%s\n",ListandoCadastrados[i].genero);
		printf("Ano de lançamento==%d\n",ListandoCadastrados[i].ano);
		printf("-----------------\n");
	}
	system("pause");
	system("cls");
}
void ProcurarPorNome(Locadora ListandoCadastrados[],int *contador){
	char nome[255];
	int result;
	int i;
	getchar();
	printf("Digite o nome do filme: ");
	gets(nome);
	for(i=0;i<*contador;i++){
		result=strcmp(ListandoCadastrados[i].titulo,nome);
		if(result==0){
				printf("Codigo==%d\n",ListandoCadastrados[i].codigo);
		        printf("titulo==%s\n",ListandoCadastrados[i].titulo);
		        printf("Sinopse==%s\n",ListandoCadastrados[i].sinopse);
		        printf("Diretor==%s\n",ListandoCadastrados[i].diretor);
	         	printf("Genero==%s\n",ListandoCadastrados[i].genero);
	         	printf("Ano de lançamento==%d\n",ListandoCadastrados[i].ano);
	         	printf("-----------------\n");
		}
	}
	system("pause");
	system("cls");
}
