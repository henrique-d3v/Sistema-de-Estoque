# Sistema de Gestão de Estoque

Um sistema em C para gestão e controle de estoque, desenvolvido em equipe. Permite o registro, busca, edição e controle de quantidades de produtos armazenados.

##  Estrutura de Execução do Sistema

```text
main() [Laço Principal]
 │
 ├── Chama: menu_produtos() (Exibe o menu e retorna a opção escolhida)
 │
 ├── [Opção 1] Cadastrar Produto
 │    └── Chama: cadastrar_produto()
 │         ├── Chama: reallocar_produtos()
 │         ├── Chama: cadastro_nome() -> verificar_nome()
 │         └── Chama: cadastro_codigo() -> verificar_codigo()
 │
 ├── [Opção 2] Buscar Produtos
 │    ├── Chama: menuBusca()
 │    └── Chama: buscar_Produto()
 │         ├── [Caso 1] buscar_codigo()  -> executarBusca()
 │         ├── [Caso 2] buscar_nome()    -> executarBusca()
 │         └── [Caso 3] buscar_tamanho() -> executarBusca()
 │
 ├── [Opção 3] Exibir Estoque
 │    └── Chama: exibir_estoque()
 │         ├── [Opção 1] Exibir Estoque Total
 │         ├── [Opção 2] Exibir por Categoria
 │         └── [Opção 3] Baixa Quantidade
 │
 ├── [Opção 4] Editar Produtos (Em desenvolvimento)
 │
 ├── [Opção 5] Alterar Estoque (Em desenvolvimento)
 │
 └── [Opção 0] Sair (Encerra o laço do main)



Equipe e Divisão de Tarefas
Kaio

[x] Cadastrar Produtos

[x] Verificar código

[x] Verificar nome

Pedro

[x] Buscar Produtos

[x] Busca por código

[x] Busca por nome

Henrique

[x] Busca por tamanho

[x] Exibir todo o estoque

Raphael

[ ] Alterar Estoque

[ ] Registrar Entrada

[ ] Registrar Venda

Esthefany

[ ] Editar Produtos

[ ] Menu de edição

Kauê

[x] Exibir por categoria

[x] Exibir Baixa Quantidade
