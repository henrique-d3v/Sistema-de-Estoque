# Sistema de Gestão de Estoque

Um sistema em C para gestão e controle de estoque, desenvolvido em equipe. Permite o registro, busca, edição e controle de quantidades de produtos armazenados. Para facilitar a usabilidade e representar uma situação real de aplicação, o sistema foi adaptado ao contexto de uma loja de roupas, permitindo o gerenciamento de produtos, categorias, tamanhos e quantidades em estoque.

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
 ├── [Opção 4] Editar Produtos
 │    └── Chama: editar_produto()
 │         ├── [Opção 1] Editar Nome
 │         ├── [Opção 2] Editar Categoria
 │         ├── [Opção 3] Editar Preço
 │         ├── [Opção 4] Editar Quantidade em Estoque
 │         ├── [Opção 5] Editar Tamanho
 │         └── [Opção 0] Sair do menu de edição
 │
 ├── [Opção 5] Alterar Estoque
 │    └── Chama: alterar_estoque()
 │         ├── [Opção 1] Registrar Entrada
 │         │    └── Chama: registrar_entrada() -> selecionar_produto_estoque()
 │         ├── [Opção 2] Registrar Venda
 │         │    └── Chama: registrar_venda()   -> selecionar_produto_estoque()
 │         └── [Opção 0] Voltar ao menu principal
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

[X] Alterar Estoque

[X] Registrar Entrada

[X] Registrar Venda

Esthefany

[x] Editar Produtos

[x] Menu de edição

Kauê

[x] Exibir por categoria

[x] Exibir Baixa Quantidade
