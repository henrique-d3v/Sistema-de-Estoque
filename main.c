#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


////                    seção produtos                           ////
typedef struct
{
    char nome[MAX];
    char codigo[MAX];
    char categoria[MAX];
    int qtd_estoque;
    float preco;
    char tamanho[MAX];
} Produto;

//allocamos a variavel produtos zerada e crescemos conforme cadastramos
Produto *produtos = NULL;
//esta variavel se refere a quantidade de produtos no vetor de produtos
int quantidade = 0;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void reallocar_produtos(){ //função para realocar produtos
    quantidade++;
    produtos = realloc(produtos, quantidade * sizeof(Produto)); //realocando produtos com a função realloc
}

int verificar_codigo(char codigo_digitado[], Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade-1; i++) {
        if (strcmp(produtos[i].codigo, codigo_digitado) == 0) {
            return 1;
        }
    }
    return 0;
}
void cadastro_codigo(){
    do{
        char codigo_digitado[MAX];
        scanf(" %99[^\n]",codigo_digitado);
        if((verificar_codigo(codigo_digitado, produtos, quantidade))==0){
            strcpy(produtos[quantidade - 1].codigo, codigo_digitado);
            break;
        }else{
            printf("Codigo ja registrado, tente outro!\n"); 
        }
    }while(1);
}



int verificar_nome(char nome_digitado[], Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade-1; i++) {
        if (strcmp(produtos[i].nome, nome_digitado) == 0) {
            return 1;
        }
    }
    return 0;
}

void cadastro_nome(){
    do{
        char nome_digitado[MAX];
        scanf(" %99[^\n]",nome_digitado);
        if((verificar_nome(nome_digitado, produtos, quantidade))==0){
            strcpy(produtos[quantidade - 1].nome, nome_digitado);
            break;
        }else{
            printf("Nome ja registrado, tente outro!\n"); 
        }
    }while(1);
}


void cadastrar_produto(){ //função cadastrar produto| procura produtos e quantidade na struct Produto
    reallocar_produtos();
    int i = quantidade - 1;
    
    printf("Digite o nome do produto: ");
    cadastro_nome();
    printf("Digite o codigo do produto: ");
    cadastro_codigo();
    printf("Digite a categoria do produto: ");
    scanf(" %99[^\n]",produtos[i].categoria);
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d",&produtos[i].qtd_estoque);
    printf("Digite o preco do produto: ");
    scanf("%f",&produtos[i].preco);
    limpar_buffer();
    printf("Digite o tamanho do produto: ");
    scanf("%s",produtos[i].tamanho);

}

void exibirInfoProduto(Produto produtos[], int i){
    printf("\n--- PRODUTO %d ---\n", i + 1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Codigo: %s\n", produtos[i].codigo);
    printf("Categoria: %s\n", produtos[i].categoria);
    printf("Tamanho: %s\n", produtos[i].tamanho);
    printf("Quantidade em estoque: %d unidades\n", produtos[i].qtd_estoque);
    printf("Preco: R$ %.2f\n", produtos[i].preco);
} // funcao que sera usada para exibir as informacoes dos produtos tanto na funcao exibir_estoque quanto na buscar_produto

//pedro
//elimina a repetição do 'for' e do 'encontrado')
int executarBusca(Produto produtos[], int quantidade, char *termo, int tipoCampo) {
    int encontrados = 0;

    for (int i = 0; i < quantidade; i++) {
        char *campoComparar = NULL; // Inicializado por segurança

        // Define qual campo da struct vai ser lido
        if (tipoCampo == 1) campoComparar = produtos[i].codigo;
        else if (tipoCampo == 2) campoComparar = produtos[i].nome;
        else if (tipoCampo == 3) campoComparar = produtos[i].tamanho;

        if (campoComparar != NULL && strcmp(campoComparar, termo) == 0) {
            exibirInfoProduto(produtos, i);
            encontrados++;

            // Se for busca por CÓDIGO (único), pode parar o loop logo
            if (tipoCampo == 1) {
                break;
            }
        }
    }

    return encontrados; 
}


//funçaõ de busca novo | pedro e henrique
//pedro busca codigo
void buscar_codigo(Produto produtos[], int quantidade) {
    char codigo_busca[MAX];
    printf("Digite o codigo do produto que deseja buscar: ");
    scanf(" %[^\n]", codigo_busca);

    // Chama o núcleo passando '1' para buscar no campo .codigo
    int total = executarBusca(produtos, quantidade, codigo_busca, 1);

    if (total == 0) {
        printf("Produto com codigo '%s' nao encontrado.\n", codigo_busca);
    }
}
//pedro busca codigo

//pedro busca nome
void buscar_nome(Produto produtos[], int quantidade) {
    char nome_busca[MAX];
    printf("Digite o nome do produto que deseja buscar: ");
    scanf(" %[^\n]", nome_busca);

    // Chama o núcleo passando '2' para buscar no campo .nome
    int total = executarBusca(produtos, quantidade, nome_busca, 2);

    if (total == 0) {
        printf("Produto com nome '%s' nao encontrado.\n", nome_busca);
    }
}
//pedro busca nome

//henrique - implementacao da funcao buscar tamanho

void buscar_tamanho(Produto produtos[], int quantidade) {
    char tamanho_busca[MAX];
    printf("Digite o tamanho do produto que deseja buscar: ");
    scanf(" %[^\n]", tamanho_busca);

    // Chama o núcleo passando '3' para buscar no campo .tamanho
    int total = executarBusca(produtos, quantidade, tamanho_busca, 3);

    if (total == 0) {
        printf("Produto com tamanho '%s' nao encontrado.\n", tamanho_busca);
    }
}

// menu de busca
int menuBusca() {
    int opc_busca;
    printf("\n===== BUSCAR PRODUTOS =====\n");
    printf("1 - Buscar por codigo\n ");
    printf("2 - Buscar por nome\n ");
    printf("3 - Buscar por tamanho\n "); 
    printf("Digite uma opcao: ");
    scanf("%d", &opc_busca);

    if (opc_busca < 1 || opc_busca > 3) {
        printf("Opcao invalida!\n");
        return -1; 
    }

    return opc_busca; // retorna a opcao de busca digitada pelo usuario
}

// funcao buscar_produto que controla o fluxo da opcao digitada chamando uma funcao especifica

void buscar_Produto(int o, Produto produtos[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    switch (o) {
        case 1:
            buscar_codigo(produtos, quantidade);
            break;
        case 2:
            buscar_nome(produtos, quantidade);
            break;
        case 3:
            buscar_tamanho(produtos, quantidade);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

// funcao que exibe o estoque total ou por categoria

void exibir_estoque(Produto produtos[],int quantidade){
    if(quantidade==0){
        printf("Nenhum produto cadastrado");
        return;
    } // se não houver nenhum produto cadastrado ele printa a mensagem e retorna

    printf("\n=====EXIBIR ESTOQUE=====\n");

    int choice; // o usuario escolhe se quer exibir o estoque total ou por categoria
    printf("1 - Exibir estoque total\n "); // menu de escolha
    printf("2 - Exibir por categoria\n ");
    printf("3 - Baixa Quantidade\n ");
    printf("Digite uma opcao: ");
    scanf("%i",&choice);

    if(choice==1){
        printf("=====PRODUTOS CADASTRADOS=====\n");
    
        for(int i = 0; i<quantidade; i++){
            exibirInfoProduto(produtos, i); // chamada da funcao que exibe as informacoes do produto
        }
        
//Kauê

    }else if(choice==2){
        char categoria_busca[MAX];
        
            printf("Digite a categoria que deseja buscar: ");
                scanf(" %99[^\n]", categoria_busca);
                
        int encontrado = 0; //Usado para controlar se pelo menos um produto foi localizado
            
        //Percorre todo o vetor de produtos cadastrados
            for(int i = 0; i < quantidade; i++){
                
        // Compara a categoria informada com a categoria do produto
            if(strcmp(produtos[i].categoria, categoria_busca) == 0){
                exibirInfoProduto(produtos, i);
                encontrado = 1; // Marca que encontrou ao menos um item
            }
        }
        
        // Se a  variavel "encontrado" continuar em 0, avisa ao usuário que nada foi encontrado
        if(encontrado == 0){
            printf("Nenhum produto encontrado nessa categoria.\n");
        }
        
    }else if(choice==3){
        int limite;
        
    //Laço para não ser possivel a entrada de números negativos pelo usuario!!
        do {  
            printf("Digite a quantidade limite: ");
                scanf("%d", &limite);
            
            if (limite < 0) {
                printf("A quantidade deve ser maior ou igual a 0!\n");
            }
        } while (limite < 0);
            
            
        int encontrado = 0;
        
            for(int i = 0; i < quantidade; i++){
        // Verifica se a quantidade em estoque do produto é menor ou igual ao limite definido
                if(produtos[i].qtd_estoque <= limite){
                    exibirInfoProduto(produtos, i);
                    encontrado = 1; // Registra que encontrou item na condição
            }
        }
        
    //Menssagem aparecerá caso nenhum produto tenha o estoque igual ou menor ao limite digitado!!
        if(!encontrado){
            printf("\nNenhum produto com quantidade menor ou igual a %d em estoque.\n", limite);
        }
    
    }else{
        printf("Opcao invalida \n");
    }
}

int menu_produtos(){
    int escolha;
    printf("\n=====MENU PRODUTOS=====\n ");
        printf("1 - Cadastrar Produto\n ");
        printf("2 - Buscar Produtos\n ");
        printf("3 - Exibir Estoque\n ");
        printf("4 - Editar Produtos\n ");
        printf("5 - Alterar Estoque\n ");
        printf("0 - Sair\n ");
        printf("Digite uma opcao: ");
        scanf("%i", &escolha);
        limpar_buffer();
    return escolha;
} // funcao que exibe o menu do sistema de estoque e retorna o inteiro digitado (escolha) pelo usuario

void editar_produto(Produto produtos[], int quantidade){
    if(quantidade == 0){
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    char codigo[MAX];
    int encontrado = -1;

    printf("Digite o codigo do produto que deseja editar: ");
    scanf(" %99[^\n]", codigo);

    // Procura o produto pelo código
    for(int i = 0; i < quantidade; i++){
        if(strcmp(produtos[i].codigo, codigo) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("Produto nao encontrado!\n");
        return;
    }

    int opcao;

    do{
        printf("\n===== EDITAR PRODUTO =====\n");
        printf("1 - Nome\n");
        printf("2 - Categoria\n");
        printf("3 - Preco\n");
        printf("4 - Quantidade em estoque\n");
        printf("5 - Tamanho\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch(opcao){

            case 1:
                printf("Novo nome: ");
                scanf(" %99[^\n]", produtos[encontrado].nome);
                break;

            case 2:
                printf("Nova categoria: ");
                scanf(" %99[^\n]", produtos[encontrado].categoria);
                break;

            case 3:
                printf("Novo preco: ");
                scanf("%f", &produtos[encontrado].preco);
                break;

            case 4:
                printf("Nova quantidade: ");
                scanf("%d", &produtos[encontrado].qtd_estoque);
                break;

            case 5:
                printf("Novo tamanho: ");
                scanf(" %99[^\n]", produtos[encontrado].tamanho);
                break;

            case 0:
                printf("Edicao encerrada.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);
}



////                    seção produtos                           ////

int main(){
int opcao;
    do{
        opcao = menu_produtos();
        switch (opcao){
            case 1:
                cadastrar_produto();
                break;
            case 2: {
            //pedro|case
            int opc_busca = menuBusca();
                if (opc_busca != -1) { 
                    buscar_Produto(opc_busca, produtos, quantidade);
                }
                break;
            //pedro|case2
            }   
            case 3:
                exibir_estoque(produtos, quantidade);
                break;
            case 4:
                editar_produto(produtos, quantidade);
                break;

            case 5:
                break;
            case 0:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao!=0);
    
    return 0;
}
