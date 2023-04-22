#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�riao
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadrasta os usu�riios no sistema
{
	//�nicio de cria��o de var�aveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de cria��o de var�aveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string,o cpf que sera salvo na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // acessar e cria o arquivo
	file = fopen(arquivo, "w"); // abrir/cria o arquivo e escrever
	fprintf(file,cpf); // armazenar e salvar o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);// fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome);//%s refere-se a string,o nome que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,nome);//salvando o conte�do da vari�vel nome dentro do arquivo
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);//fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",sobrenome);//%s refere-se a string,o sobrenome que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,sobrenome);//salvando o conte�do da vari�vel sobrenome dentro do arquivo
	fclose(file);//fechar arquivo
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,",");//salvar aquivo e separar
	fclose(file);//fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//%s refere-se a string,o cargo que sera salvo na string
	
	file = fopen(arquivo, "a");// abrindo arquivo salvo e atualizar
	fprintf(file,cargo);//salvando o conte�do da vari�vel cargo dentro do arquivo
	fclose(file);//fechar arquivo	
	
    system("pause");//pausar o programa no menu 
}

int consulta()//Fun��o responsavel por consultar os usu�riios cadrastados no sistema
{
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem 
	 
    char cpf[40];//criar arquivo cpf
	char conteudo[200];//conte�do do arquivo
	
	printf ("Digite o CPF a ser consultado: ");//consultando o cpf do usu�rio
	scanf("%s",cpf);//salvando a consulta da string cpf
	
	FILE *file;//consultar arquivo cpf
	file = fopen(cpf,"r");//abrir o arquivo cpf e ler
	
    if(file == NULL)//se o arquivo n�o for localizado � null
    {
    printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	// caso o arquivo n�o seja localizado isso que vai aparecer na tela
	}

	
while(fgets(conteudo, 200, file) != NULL)//fun��o la�o de repeti��o,esta salvando 200 caracteres que est�o dentro do arquivo,e quando n�o encontrar � nulo
{
	printf("\n Essas s�o as informa��es do usu�rio: ");//mostrando na tela as informa��es do usu�rio
	printf("%s", conteudo);//salvando o conte�do dentro da string
	printf("\n\n");//pulou duas linhass
}
  	
system ("pause");//pausar o programa no menu 
	
}

int deletar()//Fun��o responsavel por deletar os usu�riios cadrastados no sistema
{
    char cpf[40];//string cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);// //salvando a string cpf a ser deletado
	
	remove(cpf);//delta o arquivo desejado no caso cpf
	
	FILE *file;	//consultar arquivo
	file = fopen(cpf,"r");//abrir o arquivo cpf e ler
	
	if(file == NULL)// se o arquivo for nulo ou n�o for encontrado
	{
		printf ("O usu�rio n�o se encontra no sistema! . \n");//se for nulo ira aparecer este comando na tela
		system ("pause");//pausar o programa no menu
	}
} 	

int main() //fun��o principal
{
	int opcao=0; //Definindo vari�veis
	int laco=1;// entrou no la�o
	
	for(laco=1;laco=1;)//la�o de repeti��o para voltar ao menu principal
  {
  
	 
	 system("cls");//limpa a tela
	
	 setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	 printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu principal
	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("Op��o:"); //fim do menu principal
	
	 scanf("%d", &opcao);// armazenando a escolha do us�rio
	
	 system("cls");//limpa a tela
	 
	 
	 switch(opcao)//analisando as vari�veis
	 {
	 	 case 1://vari�vel 1
	 	 registro();//chamada do case 1
		 break;
		
		 case 2://vari�vel 2
		 consulta();//chamada do case 2
		 break;
		
		 case 3:// vari�vel 3
		 deletar();//chamada do case 3
		 break;
		
		 default:// caso n�o haja vari�vel disponivel	
		 printf("Essa op��o n�o est� disponivel!\n");
		 system("pause");//pausar o programa no menu 
		 break;
	    }//fim da sele��o
    }
}
  
