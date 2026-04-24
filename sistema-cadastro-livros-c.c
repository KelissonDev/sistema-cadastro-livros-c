#include<stdio.h>
#include<stdlib.h>

#define TAM 20 //quantidade maxima de livros que podem ser cadastrados//

//estrutura que representa um livro//
struct livro
{
	int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;	
    char editora[30];
};

int main()
{
	int busca, i, j, acha, op;
	int totalLivros = 0;
	printf("\n\t=====================================\n");
	printf("\033[34m\t  SISTEMA DE CADASTRO DE LIVROS    \033[0m\n");
	printf("\t=====================================\n\n");
	struct livro ficha[TAM];//vetor contendo todos os livros cadastrados//
	struct livro troca;

	
	op = 0;
	//loop do menu principal, repete até quando osuario escolher sair//
	while (op !=6)
	//exibe o menu//
	{
		
		printf("Livros cadastrados: %d/%d\n",totalLivros, TAM);
		
		printf("\033[36m 1 - Cadastrar os livros\033[0m\n");
		printf("\033[36m 2 - Imprimir os livros cadastrados\033[0m\n");
		printf("\033[36m 3 - Pesquisar livros por codigo\033[0m\n");
		printf("\033[36m 4 - Ordenar livros por ano de publicacao\033[0m\n");
		printf("\033[36m 5 - Editar livro\033[0m\n");
		printf(" 6 - sair\n");
		printf("\n-------------------------\n");
		printf(" Digite a opcao desejada: ");
		scanf("%d", &op);
		
		
		// cadastrar os livros//
		switch(op)
		{
		
			case 1:
			system("cls");
			
			if(totalLivros < TAM)
			{
				printf("Digite o codigo do livro: ");
				scanf ("%d", &ficha[totalLivros].codigo);
			
				printf("Digite o titulo do livro: ");
				scanf(" %49[^\n]", &ficha[totalLivros].titulo);
			
				printf("Digite o nome do autor: ");
				scanf(" %29[^\n]", &ficha[totalLivros].autor);
			
				printf("Digite a area do livro: ");
				scanf(" %29[^\n]", &ficha [totalLivros].area);
			
				printf("Digite o ano: ");
				scanf(" %d", &ficha[totalLivros].ano);
			
				printf("Digite o nome da editora: ");
				scanf(" %29[^\n]", &ficha[totalLivros].editora);
			
				totalLivros++;
				printf("\033[32m\n Livro cadastrado com sucesso!\033[0m\n");
			}
			else
			{
				printf("Limite maximo de livros atingido\n");
			}
			
			break;
		
		//imprimir os livros//
	    case 2:
				system("cls");
				
				 if(totalLivros == 0){
        			printf("\nNenhum livro cadastrado ainda.\n");
    				}else{		
				for (i=0; i<totalLivros; i++)
				{
					printf("\nCODIGO: %d\n",ficha[i].codigo );
					printf("TITULO: %s\n",ficha[i]. titulo);
					printf("AUTOR: %s\n",ficha[i].autor);
					printf("AREA: %s\n", ficha[i].area);
					printf("ANO: %d\n", ficha[i].ano);
					printf("EDITORA: %s\n\n",ficha[i].editora);
				}
			}
				
				break;
			
			//pesquisar por codigo//
			case 3:
					system("cls");
					printf("Digite o codigo que deseja buscar: ");
					scanf ("%d", &busca);
					i = 0;
					acha = 0;
					while ((i < totalLivros) && (acha == 0))
					{
						if (ficha[i].codigo == busca)
							acha = 1;
						else
							i++;	
					}
					if (acha == 1)
					{
						printf("\nCODIGO: %d\n",ficha[i].codigo );
						printf("TITULO: %s\n",ficha[i].titulo);
						printf("AUTOR: %s\n",ficha[i].autor);
						printf("AREA: %s\n",ficha[i].area);
						printf("ANO: %d\n", ficha[i].ano);
						printf("EDITORA: %s\n\n",ficha[i].editora);
					}
					else
						printf("\n Registro nao encontrado");
					break;
				
				//ordenar por ano do livro//
			case 4:
						system("cls");
						for (i=0;i<totalLivros-1;i++)
						{
							for (j=i+1;j<totalLivros;j++)
							{
								if (ficha[i].ano > ficha[j].ano)
								{
									troca = ficha [i];
									ficha[i] = ficha[j];
									ficha[j] = troca;
								}
							}
						}
						printf("\nCOD    |    TITULO    |        ANO\n");
                        printf("--------------------------------------\n");
						
					for (i=0;i<totalLivros;i++)
								{
 							   printf("%-6d | %-20s | %d\n",
   								 ficha[i].codigo,
   								 ficha[i].titulo,
   								 ficha[i].ano);
								}
						break;
						
			case 5:
    				system("cls");

    			if(totalLivros == 0){
        				printf("Nenhum livro cadastrado.\n");
        				break;
   				 }

   				 printf("Digite o codigo do livro que deseja editar: ");
    			 scanf("%d", &busca);

    			acha = 0;
    			i = 0;

    		while(i < totalLivros && acha == 0){
        		if(ficha[i].codigo == busca)
            		acha = 1;
        		else
           		 i++;
   				 }

   				 if(acha == 1){
        			printf("\nEditando livro: %s\n", ficha[i].titulo);

        		printf("Novo titulo: ");
        		scanf(" %49[^\n]", ficha[i].titulo);

       			 printf("Novo autor: ");
       			 scanf(" %29[^\n]", ficha[i].autor);

        		printf("Nova area: ");
       			 scanf(" %29[^\n]", ficha[i].area);

       			 printf("Novo ano: ");
        		scanf("%d", &ficha[i].ano);

        		printf("Nova editora: ");
      			  scanf(" %29[^\n]", ficha[i].editora);

       			printf("\nLivro editado com sucesso!\n");
    			}else{
       			 printf("\nLivro nao encontrado.\n");
    		}

    		  break;

        default:
            printf("Opcao invalida!\n");
            break;

        }  
    }      

    return 0;
}           
