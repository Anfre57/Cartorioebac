#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string


int registro()//Função responsável por cadastrar os usuários no sistema
{
	char arquivo[40];//inicio da criação das variáveis/string
	char cpf[40];
	char nome[10];
	char sobrenome[40];
	char cargo[40];//final da criaçáo de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");// coleta de informações do usuário
	scanf("%s",cpf);// "%s" refere-se a string

	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //criação do arquivo
	file = fopen(arquivo, "w");// abre o arquivo. o "w" refere-se a whrite, do inglês, escrever.
	fprintf(file, cpf);// salva o valor do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" refere-se a adicionar, do inglês, append
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// travamento da tela
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo a língua
	
	char cpf[40];
	char conteudo[200];// string dos nomes, sobrenomes e cargos do usuário
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// "r" está referindo a ler, do inglês, read
	
	if(file == NULL)//condicional para verificar dados do usuário existentes
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s\n",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não é possível deletar um usuário inexistente!\n\n");
		system("pause");
	}
	while(fgets(cpf, 40, file)!= NULL)
	{
		printf("\t\nUsuario deletado com sucesso!\n\n");
		system("pause");	
	}	
}


int main()
{
	int opcao=0;//definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");// limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a língua
	
		printf("<|<|Cartório da EBAC|>|>\n\n");//inicio do menu de seleção
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - REGISTRAR NOMES \n");
		printf("\t2 - CONSULTAR NOMES \n");
		printf("\t3 - DELETAR NOMES \n");
		printf("\t4 - SAIR DO SISTEMA \n\n");//fim do menu
		printf("Opção: ");
	
		scanf("%d", &opcao);// armanzem de usuarios
	
		system("cls");
		
		switch(opcao)//inico da seleção
		{
			case 1:
			registro();//chamada de funções (int)
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("\t Obrigado por utilizar o sistema! :)\n\n");
			return 0;
			break;
			
			default:
			printf("\tOpção indisponivel.\n\n");
			system("pause");
			break;	//fim da seleção
		}
	}
}
