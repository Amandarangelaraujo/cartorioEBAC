#include <stdio.h>  /*notar para que serve cada variável*/
#include <stdlib.h>
#include <locale.h>   //para conseguir colocar caracteres especiais
#include <string.h> //para fazer funções junto com as strings

  int registro(){
	
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char arquivo [40];
	char cargo[40];
	
	setlocale (LC_ALL, "portuguese");
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);  //onde arquivo recebe o que tem dentro de cpf
	
	FILE *file;
	
	file = fopen(arquivo, "w");   // abre o arquivo //esse W significa que � um arquivo novo
	fprintf(file,cpf); //um printf dentro do arquivo, salvou no file a vari�vel cpf
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo, "a");   //dentro de file abra o arquivo e fa�a uma atualiza��o
	fprintf(file, ", ");   //dentro de file coloque uma v�rgula
	fclose(file);  
	
	printf ("Digite o seu nome: ");
	scanf ("%s", nome);                   //%s j� que � uma vari�vel do tipo string
	
	file = fopen(arquivo, "a");       // n�o consigo entender o motivo de abrur o a e depois ter que
	fprintf(file, nome);             // copiar a string nome para dentro de file n�o para dentro de arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");   //dentro de file abra o arquivo e fa�a uma atualiza��o
	fprintf(file, ", ");   //dentro de file coloque uma v�rgula
	fclose(file);
	
	printf ("Digite o seu sobrenome: \n ");
	scanf ("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");   //dentro de file abra o arquivo e fa�a uma atualiza��o
	fprintf(file, ", ");   //dentro de file coloque uma v�rgula
	fclose(file);
	
	printf(" Qual o seu cargo? \n ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file); 
	
	system ("pause");
}

int consulta(){

    setlocale (LC_ALL, "portuguese");
    
	char cpf[40];    //poderia ter chamado ela de arquivo?
	char conteudo[100];
	
	
	printf("Voc� escolheu consultar dados. \n");
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado \n");
	}

	while (fgets(conteudo, 100, file) != NULL)
	{   
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
	}
	system ("pause");
 }

int deletar(){
	char cpf[40];

	printf("digite o CPF a ser deletado: ");
	scanf("%s", cpf);

	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file==NULL)
	{
		printf("o usuário foi deletado com sucesso! \n\n");
	}
	system("pause");
;}

int main(){
		
	int opcao=0;
	int x=1;
	char senhaDigitada[10]="a";
	int retorno;
	
	printf("login do administrador! \n\nDigite a sua senha: ");
	scanf("%s", &senhaDigitada);
	
	retorno =  strcmp (senhaDigitada, "admin");

	if (retorno == 0)
	{

		for(x=1; x=1;) {      // para ficar em um looping infinito
	
		setlocale (LC_ALL, "portuguese");
	
		system ("cls");
		printf("Olá usuário da EBAC \n\n");  //apresenta��o
		printf ("Escolha a opção desejada \n"); //mostrar um menu de op��es
		printf("\t1- Registrar nomes.\n");     //op��es que ser�o apresnetadas no menu
		printf("\t2- Consultar nomes.\n");
		printf("\t3- Apagar nomes. \n");
		printf("\t4 - Sair do menu de opções. \n");
		printf("escolha uma opção: "); //fim do menu
		scanf("%d", &opcao);
	
		system("cls"); //para limpar a p�gina
	
		switch (opcao){
			case 1:       //nao esquecer de colocar dois pontos ao inves de ponto e v�rgula
			registro();
			break;  //aqui entra o ponto e v�rgula
		
			case 2:
			consulta();
			break;

			case 3:
			deletar();
			break;

			case 4:
			printf("Obrigada por utilizar o sistema! \n");
			system("pause");
			return 0;   /*esse return 0; pode ser utilizado como quebrador de lacos de repeticao, saindo dos sitema*/
			break;
		
			default: //esse � como se fosse o else
			printf("você escolheu uma opção inválida! Pressione enter para voltar ao menu.\n"); 
			break;
		
			printf("\n\n\n### Esse software pertence � Amanda Rangel ###");    //autoria do programa
		 }
	 	}	
  	}
	else
	printf("senha incorreta");
}

