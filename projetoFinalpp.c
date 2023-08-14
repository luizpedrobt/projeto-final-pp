// Trabalho final de Proramação Procedimental

// Luiz Pedro Bittencourt Souza - 12111EAU002

// Controle de estoque

// Q1 - Quais produtos irão vencer no dia xx/xx/xxxx?

// Q2 - Quais produtos possuem mais de X unidades?

// Q3 - Quais produtos custam X reais?


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void sair();
void pesquisa();
void cadastro();
void exibe();
void exclusao();
void menu();
void verificaValidade();
void verificaQuantia();
void verificaPreco();

typedef struct data{

    int dia;
    int mes;
    int ano;

}data;

typedef struct identidade{

    char id[10];
    char tipo[40];

}identidade;

typedef struct produto{

    data dataDeFabricacao;
    data dataDeVencimento;
    identidade identificacao;
    int quantidade;
    float preco;

}produto;

void menu(){

    int opcao = 0;

    while(opcao != 1){
        
        system("cls");
        puts("\nOlá! Seja bem-vindo(a) ao controle administrativo de estoque!");
        puts("\n\t1 - Para sair");
        puts("\n\t2 - Para cadastrar um produto");
        puts("\n\t3 - Para pesquisar um produto por Id");
        puts("\n\t4 - Para exibir todo o estoque");
        puts("\n\t5 - Para verificar a validade por data dos produtos");
        puts("\n\t6 - Para verificar o número e unidades de cada produto");
        puts("\n\t7 - Para consulta por preço");

        puts("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:

            sair();

            break;

        case 2:

            cadastro();

            break;

        case 3:

            pesquisa();

            break;

        case 4:

            exibe();

            break;

        case 5:

            verificaValidade();

            break;

        case 6:

            verificaQuantia();

            break;

        case 7:

            verificaPreco();

            break;

        case 8:

            break;

        default:

            system("cls");
            puts("A opção digitada não é válida. Insira outra.");
            system("pause");

            break;
        }
    }
}

void sair(){

    puts("Agradecemos a sua preferência pelo nosso programa! ;)");
    exit(1);

}

void pesquisa(){

    FILE *ponteiro;
    produto Produtos;
    
    ponteiro = fopen("dadosvenda.bin", "rb");
   
    char idPesquisa[10];

    system("cls");
    puts("Insira o ID do produto desejado: ");
    fflush(stdin);
    gets(idPesquisa);
    system("cls");

    if(ponteiro == NULL){

        perror("O arquivo não pôde aberto!");
        exit(1);
    }

    else{

        printf("\nOs produtos de Id %s são:\n\n", idPesquisa);

        while(fread(&Produtos, sizeof(struct produto), 1, ponteiro) == 1){

            if(strstr(Produtos.identificacao.id, idPesquisa)){
            
                printf("\nId: %s\t Produto: %s\n", idPesquisa, Produtos.identificacao.tipo);
                printf("\n");
                printf("\nData de fabricação: %.2d/%.2d/%.4d", Produtos.dataDeFabricacao.dia, Produtos.dataDeFabricacao.mes, Produtos.dataDeFabricacao.ano);
                printf("\nData de validade: %.2d/%.2d/%.4d", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes, Produtos.dataDeVencimento.ano);
                printf("\nPreço por unidade: R$%0.2f", Produtos.preco);
                printf("\nQuantidade: %d", Produtos.quantidade);
                printf("\n\n");
                }   
            }
        }
    system("pause");
    fclose(ponteiro);
}

void cadastro(){

    FILE *ponteiro;
    produto Produtos;
    setlocale(LC_ALL, "Portuguese");

    ponteiro = fopen("dadosvenda.bin", "ab");
    system("cls");

    if(ponteiro == NULL){

        perror("O arquivo não pôde ser criado!");
        exit(1);
    }

    else{

        puts("Produto a cadastrar: ");
        fflush(stdin);
        gets(Produtos.identificacao.tipo);
        system("cls");

        puts("Id: ");
        fflush(stdin);
        scanf("%s", &Produtos.identificacao.id);
        system("cls");

        puts("Data de fabricação: ");

        puts("Dia: ");
        scanf("%d", &Produtos.dataDeFabricacao.dia);
        fflush(stdin);
        system("cls");

        puts("Mês: ");
        scanf("%d", &Produtos.dataDeFabricacao.mes);
        fflush(stdin);
        system("cls");

        puts("Ano: ");
        scanf("%d", &Produtos.dataDeFabricacao.ano);
        system("cls");

        /////////////////////////////////////////////

        puts("Data de validade: ");
        puts("Dia: ");
        scanf("%d", &Produtos.dataDeVencimento.dia);
        fflush(stdin);
        system("cls");

        puts("Mês: ");
        scanf("%d", &Produtos.dataDeVencimento.mes);
        fflush(stdin);
        system("cls");

        puts("Ano: ");
        scanf("%d", &Produtos.dataDeVencimento.ano);
        system("cls");

        /////////////////////////////////////////////

        puts("Preço em real por unidade: ");
        fflush(stdin);
        scanf("%f", &Produtos.preco);
        system("cls");

        puts("Quantidade: ");
        fflush(stdin);
        scanf("%d", &Produtos.quantidade);
        system("cls");

        if (fwrite(&Produtos, sizeof(struct produto), 1, ponteiro) != 1){

            puts("Erro na escrita.");
        }

        else{

            puts("Arquivo gravado com sucesso!");
        }
        fclose(ponteiro);
    }
}

void exibe(){
    
    FILE *ponteiro;
    produto Produtos;

    ponteiro = fopen("dadosvenda.bin", "rb");

    system("cls");

    if ((ponteiro  == NULL)){

        perror("Não foi possível abrir o arquivo.");
        exit(1);
    }
    else{

        while(fread(&Produtos, sizeof(struct produto), 1, ponteiro)){
            
            printf("\n=====================================");
            printf("\nProduto: %s", Produtos.identificacao.tipo);
            printf("\nId: %s", Produtos.identificacao.id);
            printf("\nData de fabricação: %.2d/%.2d/%.4d", Produtos.dataDeFabricacao.dia, Produtos.dataDeFabricacao.mes, Produtos.dataDeFabricacao.ano);
            printf("\nData de validade: %.2d/%.2d/%.4d", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes, Produtos.dataDeVencimento.ano);
            printf("\nPreço por unidade: R$%0.2f", Produtos.preco);
            printf("\nQuantidade: %d", Produtos.quantidade);
            printf("\n\n");
        }
        system("pause");
    }
    fclose(ponteiro);
}

void verificaValidade(){

    FILE *ponteiro;
    produto Produtos;
    int dia, mes, ano;
    system("cls");

    fflush(stdin);

    puts("\n\n\tCaso nenhum produto vença na data digitada o programa voltará ao início.\n\n");
    system("pause");
    system("cls");

    ponteiro = fopen("dadosvenda.bin", "rb");

    printf("\n\tdd/mm/aaaa\n");
    puts("\nDia: ");
    scanf("%d", &dia);
    fflush(stdin);
    system("cls");
    
    printf("\n\t%.2d/mm/aaaa\n", dia);
    puts("\nMês: ");
    scanf("%d", &mes);
    fflush(stdin);
    system("cls");
    
    
    printf("\n\t%.2d/%.2d/aaaa\n", dia, mes);
    puts("\nAno: ");
    scanf("%d", &ano);
    fflush(stdin);
    system("cls");

    if(ponteiro == NULL){

        perror("Não foi possível abrir o arquivo.");
        exit(1);
    }

    else{

        while(fread(&Produtos, sizeof(struct produto), 1, ponteiro) == 1){

            if(dia == Produtos.dataDeVencimento.dia && mes == Produtos.dataDeVencimento.mes && ano == Produtos.dataDeVencimento.ano){

                printf("\n");
                printf("\nProduto: %s", Produtos.identificacao.tipo);
                printf("\nId: %s", Produtos.identificacao.id);
                printf("\nData de fabricação: %.2d/%.2d/%.4d", Produtos.dataDeFabricacao.dia, Produtos.dataDeFabricacao.mes, Produtos.dataDeFabricacao.ano);
                printf("\nData de validade: %.2d/%.2d/%.4d", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes, Produtos.dataDeVencimento.ano);
                printf("\nPreço po unidade: R$%0.2f", Produtos.preco);
                printf("\nQuantidade: %d", Produtos.quantidade);
                printf("\n\n");
                system("pause");
            }
        }
    }
    fclose(ponteiro);
}

void verificaQuantia(){

    FILE *ponteiro;
    produto Produtos;
    int quantidade;

    system("cls");

    ponteiro = fopen("dadosvenda.bin", "rb");

    puts("Insira a quantidade de estoque desejado: ");
    scanf("%d", &quantidade);

    if(ponteiro == NULL){

        perror("O arquivo não pôde ser aberto.");
        exit(1);
    }

    else{

        printf("\nOs seguintes produtos possuem mais de %d unidades no estoque:\n\n", quantidade);

        while(fread(&Produtos, sizeof(struct produto), 1, ponteiro) == 1){

            if(quantidade < Produtos.quantidade){

                printf("\n");
                printf("\nProduto: %s", Produtos.identificacao.tipo);
                printf("\nId: %s", Produtos.identificacao.id);
                printf("\nData de fabricação: %.2d/%.2d/%.4d", Produtos.dataDeFabricacao.dia, Produtos.dataDeFabricacao.mes, Produtos.dataDeFabricacao.ano);
                printf("\nData de validade: %.2d/%.2d/%.4d", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes, Produtos.dataDeVencimento.ano);
                printf("\nPreço por unidade: R$%0.2f", Produtos.preco);
                printf("\nQuantidade: %d", Produtos.quantidade);
                printf("\n\n");
            }
        }
    }
    system("pause");
    fclose(ponteiro); 
}

void verificaPreco(){

    FILE *ponteiro;
    produto Produtos;

    float pesquisa;

    ponteiro = fopen("dadosvenda.bin", "rb");

    system("cls");
    puts("Insira o valor desejado: ");
    scanf("%f", &pesquisa);

    if(ponteiro == NULL){

        perror("Não foi possível abrir o arquivo.");
        exit(1);
    }

    else{

        printf("\nOs seguintes produtos custam R$%0.2f: \n", pesquisa);
        
        while(fread(&Produtos, sizeof(struct produto), 1, ponteiro) == 1){

            if(pesquisa == Produtos.preco){

                printf("\n");
                printf("\nProduto: %s", Produtos.identificacao.tipo);
                printf("\nId: %s", Produtos.identificacao.id);
                printf("\nData de fabricação: %.2d/%.2d/%.4d", Produtos.dataDeFabricacao.dia, Produtos.dataDeFabricacao.mes, Produtos.dataDeFabricacao.ano);
                printf("\nData de validade: %.2d/%.2d/%.4d", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes, Produtos.dataDeVencimento.ano);
                printf("\nPreço por unidade: R$%0.2f", Produtos.preco);
                printf("\nQuantidade: %d", Produtos.quantidade);
                printf("\n\n");
            }
        }
    }
    system("pause");
    fclose(ponteiro);
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    menu();

    return 0;
}
