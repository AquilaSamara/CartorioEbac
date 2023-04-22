#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memóriao
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadrasta os usuáriios no sistema
{
	//ínicio de criação de varíaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de criação de varíaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string,o cpf que sera salvo na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // acessar e cria o arquivo
	file = fopen(arquivo, "w"); // abrir/cria o arquivo e escrever
	fprintf(file,cpf); // armazenar e salvar o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);// fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome);//%s refere-se a string,o nome que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,nome);//salvando o conteúdo da variável nome dentro do arquivo
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);//fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",sobrenome);//%s refere-se a string,o sobrenome que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,sobrenome);//salvando o conteúdo da variável sobrenome dentro do arquivo
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);//fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//%s refere-se a string,o cargo que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,cargo);//salvando o conteúdo da variável cargo dentro do arquivo
	fclose(file);//fechar arquivo	
	
    system("pause");//pausar o programa no menu 
}

int consulta()//Função responsavel por consultar os usuáriios cadrastados no sistema
{
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem 
	 
    char cpf[40];//criar arquivo cpf
	char conteudo[200];//conteúdo do arquivo
	
	printf ("Digite o CPF a ser consultado: ");//consultando o cpf do usuário
	scanf("%s",cpf);//salvando a consulta da string cpf
	
	FILE *file;//consultar arquivo cpf
	file = fopen(cpf,"r");//abrir o arquivo cpf e ler
	
    if(file == NULL)//se o arquivo não for localizado é null
    {
    printf("Não foi possivel abrir o arquivo, não localizado!.\n");	// caso o arquivo não seja localizado isso que vai aparecer na tela
	}

	
while(fgets(conteudo, 200, file) != NULL)//função laço de repetição,esta salvando 200 caracteres que estão dentro do arquivo,e quando não encontrar é nulo
{
	printf("\n Essas são as informações do usuário: ");//mostrando na tela as informações do usuário
	printf("%s", conteudo);//salvando o conteúdo dentro da string
	printf("\n\n");//pulou duas linhass
}
  	
system ("pause");//pausar o programa no menu 
	
}

int deletar()//Função responsavel por deletar os usuáriios cadrastados no sistema
{
    char cpf[40];//string cpf
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);// //salvando a string cpf a ser deletado
	
	remove(cpf);//delta o arquivo desejado no caso cpf
	
	FILE *file;	//consultar arquivo
	file = fopen(cpf,"r");//abrir o arquivo cpf e ler
	
	if(file == NULL)// se o arquivo for nulo ou não for encontrado
	{
		printf ("O usuário não se encontra no sistema! . \n");//se for nulo ira aparecer este comando na tela
		system ("pause");//pausar o programa no menu
	}
} 	

int main() //função principal
{
	int opcao=0; //Definindo variáveis
	int laco=1;// entrou no laço
	
	for(laco=1;laco=1;)//laço de repetição para voltar ao menu principal
  {
  
	 
	 system("cls");//limpa a tela
	
	 setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	 printf("### Cartório da EBAC ###\n\n"); //inicio do menu principal
	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Opção:"); //fim do menu principal
	
	 scanf("%d", &opcao);// armazenando a escolha do usário
	
	 system("cls");//limpa a tela
	 
	 
	 switch(opcao)//analisando as variáveis
	 {
	 	 case 1://variável 1
	 	 registro();//chamada do case 1
		 break;
		
		 case 2://variável 2
		 consulta();//chamada do case 2
		 break;
		
		 case 3:// variável 3
		 deletar();//chamada do case 3
		 break;
		
		 default:// caso não haja variável disponivel	
		 printf("Essa opção não está disponivel!\n");
		 system("pause");//pausar o programa no menu 
		 break;
	    }//fim da seleção
    }
}
  
