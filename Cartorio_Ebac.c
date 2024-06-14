#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco de memoria
#include <locale.h> // biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() { // Função responsável por registrar os usuários no sistema
	//Início criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis

	printf("Digite o cpf a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a strings

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings

	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" escreve
	fprintf(file,cpf); //salva o valor
	fclose(file);//fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva a virgula
	fclose(file); //fecha o arquivo

	printf("Digite o nome que deseja cadastrar: "); //Coletando info nome
	scanf("%s",nome); //%s se referindo a strings

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //salva o valor
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva a virgula
	fclose(file); //fecha o arquivo

	printf("Digite o sobrenome que deseja cadastrar: "); //coletando info sobrenome
	scanf("%s",sobrenome); //%s se referindo a string

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o valor
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); //salva a virgula
	fclose(file); //fecha o arquivo

	printf("Digite o cargo que deseja cadastrar: "); //coletando info cargo
	scanf("%s",cargo); //%s se referindo a string

	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor
	fclose(file); //fecha o arquivo

	system("pause"); //pausa o sistema



}

int consulta() {
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40]; //inicio criacao variaveis
	char conteudo[200]; //fim criacao variaveis

	printf("Digite o CPF que deseja consultar: "); //coletando info cpf
	scanf("%s",cpf); //%s se referindo a string

	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" lê o arquivo

	if(file == NULL) {      
		printf("Arquivo não localizado, não foi possível abrir!\n"); //caso não ache o cpf, mostrar essa mensagem ao usuário

	}  

	while(fgets(conteudo, 200, file) != NULL) {             
		printf("\nEssas são as informações do usuário: ");   //mostrando as informações ao usuário
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause"); //pausa no sistema

}

int excluir() {  

	char cpf[40]; //criando variavel

	printf("Digite o cpf a ser excluído: "); //coletando informacoes cpf para excluir
	scanf("%s", cpf); //%s se referindo a string

	remove(cpf); //excluir o cpf

	FILE *file;  //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" lê o arquivo

	if(file == NULL) {
		printf("Usuário não encontrado nos sistema! \n"); //mensagem se não achar o usuário
		system("pause"); //pausa no sistema
	}

}

int main() {
	int opcao=0; //Definindo Variáveis
	int laco=1;

	for(laco=1; laco=1;) {

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção que você deseja no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Digite a opção desejada: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando escolha do usuário

		system("cls"); //limpar a tela

		switch(opcao) {  //inicio da seleção do menu
			case 1:

				registro(); //chamada de funções
				break;

			case 2:
				consulta();
				break;

			case 3:
				excluir();
				break;
			
			case 4:					
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;

			default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;

		}   //Fim da seleção

	}
}
