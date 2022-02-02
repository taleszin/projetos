/* faça um Controle de Estoque que realiza as seguintes atividades: 
Adição de Produto, Remoção de Produto, Busca de Produto (por Nome ou Tipo) e 
Listar os Produto (em Ordem Alfabética ou Por Preço, bem como agrupar por Tipo ou Local). 
Cada Produto será composto de Nome (até 100 caracteres), Tipo (até 50 caracteres), Preço 
(até 10 dígitos), Local de Estoque (até 50 caracteres) e identificador (até 10 dígitos). */

//trabalho feito em conjunto pelos alunos do curso de Ciência da Computação da UECE Tales Santiago e Riquelme Jatay.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
char nome[101];
char tipo[51];
char local[51];
double preco;
int id;
};

int q = 0, ql = 0, qt = 0;
struct produto produtos[1000];
char tipos[1000][51];
char locais[1000][51];

int main(void) {
  menu();
  return 0;
}

void menu() {
  int op = 0;

  printf("\e[H\e[2J");
  printf("--- CONTROLE DE ESTOQUE 1.0 ---\nO que deseja fazer?\n(Em caso de opcao invalida, o sistema pode reiniciar ou crashar)\n");
  printf("• Cadastrar produto (1);\n");
  printf("• Remover produto (2);\n");
  printf("• Buscar produto (3);\n");
  printf("• Listar produtos (4);\n");
  printf("• Sair do sistema (5).\n-> ");

  scanf("%d", &op);

  switch(op) {
    case 1:
    adicionar();
    break;
  case 2:
    remover();
    break;
  case 3:
    buscar();
    break;
  case 4:
    listar();
    break;
  case 5:
    printf("Ate logo!");
    return 0;
    break;
  default:
    menu();
    break;
  }
}

void adicionar() {

  int decisao, i, u;

   printf("\e[H\e[2J");
   printf("-- ADICIONAR --\n");
   printf("Insira os seguintes dados:\n");

   if (q < 1) {
     printf("- Identificador: " );
     scanf("%d", &produtos[q].id);
     __fpurge(stdin);

     printf("- Nome: " );
     fgets(produtos[q].nome, 101, stdin);
     __fpurge(stdin);

     printf("- Tipo: " );
     fgets(produtos[q].tipo, 51, stdin);
     __fpurge(stdin);
     strcpy(tipos[qt], produtos[q].tipo);
     qt++;

     printf("- Local de estoque: " );
     fgets(produtos[q].local, 51, stdin);
     __fpurge(stdin);
     strcpy(locais[ql], produtos[q].local);
     ql++;

     printf("- Preco: " );
     scanf("%lf", &produtos[q].preco);
     __fpurge(stdin);
   q++;

   } else if (q >= 1) {
     printf("- Identificador (caso algum produto contenha o mesmo identificador ou nome, o cadastro sera reiniciado.): " );
     scanf("%d", &produtos[q].id);
     __fpurge(stdin);

     for (i = 0; i < q; i++) {
           while (produtos[q].id == produtos[i].id) {
             adicionar();
           }
     }

     printf("- Nome: " );
     fgets(produtos[q].nome, 101, stdin);
     for (u = 0; u < q; u++) {
           while (strcmp(produtos[q].nome, produtos[u].nome) == 0) {
             adicionar();
           }
     }

     __fpurge(stdin);

      printf("- Tipo: " );
      fgets(produtos[q].tipo, 51, stdin);
      __fpurge(stdin);
      int igualt = 0;

      for (i = 0; i < qt; i++) {
        if (strcmp(tipos[i],produtos[q].tipo) == 0) {
          igualt++;
        }
      }
      if (igualt == 0) {
              strcpy(tipos[qt], produtos[q].tipo);
              qt++;
       }

      printf("- Local de estoque: " );
      fgets(produtos[q].local, 51, stdin);
      __fpurge(stdin);

      int iguall = 0;
      for (i = 0; i < ql; i++) {
        if (strcmp(locais[i],produtos[q].local) == 0) {
          iguall++;
        }
      }
      if (iguall == 0) {
              strcpy(locais[ql], produtos[q].local);
              ql++;
       }

     printf("- Preco: " );
     scanf("%lf", &produtos[q].preco);
     __fpurge(stdin);

     q++;
  }
   printf("Produto adicionado! Deseja adicionar outro produto?\n• SIM (1);\n• NAO (2).\n-> ");
   scanf("%d", &decisao); __fpurge(stdin);

   while ((decisao!= 1) && (decisao != 2)) {
     printf("Insira uma opcao valida!\n-> ");
     scanf("%d", &decisao); __fpurge(stdin);
   }

   if (decisao == 1) {
     adicionar();
   } else if (decisao == 2) {
     menu();
   }

 return 0;
}

void remover() {
  int produtor, u, confirma = 0, decisao = 0, esse, i, existe = 0;
  printf("\e[H\e[2J");
  printf("-- REMOVER --\n");
  if (q < 1) {
    printf("Nao ha produtos cadastrados no sistema!\n");
  } else {
    printf("Qual o id do produto que deseja remover?\n");
    scanf("%d", &produtor);
    for (u=0; u<q; u++) {
              if (produtor == produtos[u].id) {
                  existe = 1;
                  esse = u;
                }
              }

                if (existe == 1) {
                  printf("O id corresponde ao seguinte produto: %s\nDeseja remove-lo?\n• SIM (1);\n• NAO (2).\n-> ", produtos[esse].nome);
                  scanf("%d", &confirma);
                  while ((confirma != 1) && (confirma != 2)) {
                    printf("Insira uma opcao valida!\n-> ");
                    scanf("%d", &confirma); __fpurge(stdin);
                  }
              if (confirma == 1) {
                  int igualt = 0, iguall = 0, mt, ml;

                  for (i = 0; i < q; i++) {
                      if (strcmp(produtos[esse].tipo, produtos[i].tipo) == 0) {
                          igualt++;
                          mt = i;
                      }
                  }
                  if (igualt == 1) {
                      for (i = mt; i < qt; i++) {
                          strcpy(tipos[i], tipos[i+1]);
                      }
                      qt--;
                  }

                  for (i = 0; i < q; i++) {
                      if (strcmp(produtos[esse].local, produtos[i].local) == 0) {
                          iguall++;
                          ml = i;
                      }
                  }
                  if (iguall == 1) {
                      for (i = ml; i < ql; i++) {
                          strcpy(locais[i], locais[i+1]);
                      }
                      ql--;
                  }
                  for (i = esse; i < q; i++) {
                      strcpy(produtos[i].nome, produtos[i+1].nome);
                      strcpy(produtos[i].tipo, produtos[i+1].tipo);
                      strcpy(produtos[i].local, produtos[i+1].local);
                      produtos[i].preco = produtos[i+1].preco;
                      produtos[i].id = produtos[i+1].id;
                  }
                  produtos[q-1].id = 0;
                  q--;

                  printf("\nRemocao concluida!\n");
              } else if (confirma == 2) {
              printf("\nRemocao cancelada!\n");
              }
      } else if (existe == 0) {
          printf("Produto nao encontrado.\n");
      }
    }
  printf("Deseja remover outro(s) produto(s)?\n• SIM (1);\n• NAO (2).\n-> ");
  scanf("%d", &decisao); __fpurge(stdin);

  while ((decisao!= 1) && (decisao != 2)) {
  printf("Insira uma opcao valida!\n-> ");
  scanf("%d", &decisao); __fpurge(stdin);
  }

  if (decisao == 1) {
  remover();
  } else if (decisao == 2) {
  menu();
  }

  return 0;
}

void buscar() {
  int op = 0, i, decisao = 0;
  char busca[101];
  int achar = 0;

  printf("\e[H\e[2J");
  printf("-- BUSCAR --\n");
  if (q < 1) {
    printf("Nao ha produtos cadastrados no sistema!\n");
  } else {
    printf("\nComo deseja buscar?\n• NOME (1);\n• TIPO (2).\n-> ");
    scanf("%d", &op); __fpurge(stdin);

    while ((op != 1) && (op != 2)) {
      printf("Insira uma opcao de busca valida!\n-> ");
      scanf("%d", &op); __fpurge(stdin);
    }

    if (op == 1) {
      printf("\n- Insira o nome do produto: ");
      fgets(busca, 101, stdin);
      __fpurge(stdin);
      for (i = 0; i < q; i++) {
        if (strcmp(busca,produtos[i].nome) == 0) {
          achar++;
          printf("\nIdentificador: %d\nNome: %sTipo: %sPreco: %.2f\nLocal de estoque: %s\n\n", produtos[i].id, produtos[i].nome,  produtos[i].tipo, produtos[i].preco,  produtos[i].local);
        }
      }

      if (achar == 0) {
        printf("Nao foram encontrados produtos correspondentes.\n\n");
      }
    } else if (op == 2) {
      printf("\n\n- Insira o tipo do produto: ");
      fgets(busca, 101, stdin);
      __fpurge(stdin);
      for (i = 0; i < q; i++) {
        if (strcmp(busca,produtos[i].tipo) == 0) {
          achar++;
          printf("\nIdentificador: %d\nNome: %sTipo: %sPreco: %.2f\nLocal de estoque: %s\n\n", produtos[i].id, produtos[i].nome,  produtos[i].tipo, produtos[i].preco,  produtos[i].local);
        }
      }

      if (achar == 0) {
        printf("Nao foram encontrados produtos correspondentes.\n\n");
      }
    }
  }

  printf("Busca finalizada! Deseja buscar outro(s) produto(s)?\n• SIM (1);\n• NAO (2).\n-> ");
  scanf("%d", &decisao); __fpurge(stdin);

  while ((decisao!= 1) && (decisao != 2)) {
    printf("Insira uma opcao valida!\n-> ");
    scanf("%d", &decisao); __fpurge(stdin);
  }

  if (decisao == 1) {
    buscar();
  } else if (decisao == 2) {
    menu();
  }

  return 0;
  }

void listar() {
  int lista, grupo, i, j, decisao;
  printf("\e[H\e[2J");
  printf("-- LISTAR --\n");
  if (q < 1) {
    printf("Nao ha produtos cadastrados no sistema");
  } else {
    printf("Ha %d produtos, %d tipos e %d locais cadastrados no sistema!\n\n", q, qt, ql);
    printf("Agrupar por:\n• Tipo (1);\n• Local de Estoque (2).\n-> ");
    scanf("%d", &grupo); __fpurge(stdin);
    while ((grupo!= 1) && (grupo != 2)) {
      printf("Insira uma opcao valida!\n-> ");
      scanf("%d", &grupo); __fpurge(stdin);
    }

    printf("\nListar por:\n• Ordem Alfabetica (1);\n• Preco (2).\n-> ");
    scanf("%d", &lista); __fpurge(stdin);
    while ((lista!= 1) && (lista != 2)) {
      printf("Insira uma opcao valida!\n-> ");
      scanf("%d", &lista); __fpurge(stdin);
    }

    if (lista == 1) {
      ordenaralfa();
    } else if (lista == 2) {
      ordenarpreco();
    }

    if (grupo == 1) {
      for (i = 0; i < qt; i++) {
      printf("\nProdutos classificados como: %s\n", tipos[i]);
        for (j = 0; j < q; j++) {
          if (strcmp(tipos[i],produtos[j].tipo) == 0) {
            printf("Identificador: %d\nNome: %sPreco: %.2f\nLocal de estoque: %s\n", produtos[j].id, produtos[j].nome, produtos[j].preco,  produtos[j].local);
          }
        }
      }
    } else if (grupo == 2) {
      for (i = 0; i < ql; i++) {
        printf("\nProdutos armazenados em: %s\n", locais[i]);
        for (j = 0; j < q; j++) {
          if (strcmp(locais[i],produtos[j].local) == 0) {
            printf("Identificador: %d\nNome: %sPreco: %.2f\nTipo: %s\n", produtos[j].id, produtos[j].nome, produtos[j].preco,  produtos[j].tipo);
          }
        }
      }
    }
}
  printf("\nListagem finalizada! Deseja listar novamente?\n• SIM (1);\n• NAO (2).\n-> ");
  scanf("%d", &decisao); __fpurge(stdin);

  while ((decisao!= 1) && (decisao != 2)) {
    printf("Insira uma opcao valida!\n-> ");
    scanf("%d", &decisao); __fpurge(stdin);
  }

  if (decisao == 1) {
    listar();
  } else if (decisao == 2) {
    menu();
  }

  return 0;
}

void ordenaralfa() {
  int i, j, auxp, auxi, o;
  char auxn[101], auxt[51], auxl[51];

  for (i = 0; i < q; i++) {
    for (j = i + 1; j < q; j++) {
        o = strcmp(produtos[i].nome, produtos[j].nome);
        if (o > 0) {
          auxp = produtos[i].preco;
          produtos[i].preco = produtos[j].preco;
          produtos[j].preco = auxp;

          auxi = produtos[i].id;
          produtos[i].id = produtos[j].id;
          produtos[j].id = auxi;

          strcpy(auxn, produtos[i].nome);
          strcpy(produtos[i].nome, produtos[j].nome);
          strcpy(produtos[j].nome, auxn);

          strcpy(auxt, produtos[i].tipo);
          strcpy(produtos[i].tipo, produtos[j].tipo);
          strcpy(produtos[j].tipo, auxt);

          strcpy(auxl, produtos[i].local);
          strcpy(produtos[i].local, produtos[j].local);
          strcpy(produtos[j].local, auxl);
        }
      }
    }
  }

void ordenarpreco() {
  int i, j, auxp, auxi;
  char auxn[101], auxt[51], auxl[51];

  for (i = 0; i < q; i++) {
    for (j = i; j < q; j++) {
      if (produtos[i].preco > produtos[j].preco) {
        auxp = produtos[i].preco;
        produtos[i].preco = produtos[j].preco;
        produtos[j].preco = auxp;

        auxi = produtos[i].id;
        produtos[i].id = produtos[j].id;
        produtos[j].id = auxi;

        strcpy(auxn, produtos[i].nome);
        strcpy(produtos[i].nome, produtos[j].nome);
        strcpy(produtos[j].nome, auxn);

        strcpy(auxt, produtos[i].tipo);
        strcpy(produtos[i].tipo, produtos[j].tipo);
        strcpy(produtos[j].tipo, auxt);

        strcpy(auxl, produtos[i].local);
        strcpy(produtos[i].local, produtos[j].local);
        strcpy(produtos[j].local, auxl);
      }
    }
  }

  return 0;
}
