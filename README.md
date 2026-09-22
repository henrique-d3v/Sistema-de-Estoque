main() [Laço Principal]
 │
 ├── Chama: menu_produtos() (Exibe o menu e retorna a opção escolhida)
 │
 ├── [Opção 1] Cadastrar Produto
 │    └── Chama: cadastrar_produto()
 │         ├── Chama: reallocar_produtos()
 │         ├── Chama: cadastro_nome()
 │         │    └── Chama: verificar_nome()
 │         ├── Chama: cadastro_codigo()
 │         │    └── Chama: verificar_codigo()
 │         └── Chama: limpar_buffer()
 │
 ├── [Opção 2] Buscar Produtos
 │    ├── Submenu de Busca (Leitura de opc_busca no próprio main)
 │    │    ├── [Sub-Opção 1] Buscar por Código
 │    │    │    └── Chama: buscar_codigo()
 │    │    │         └── Chama: exibirInfoProduto()
 │    │    │
 │    │    └── [Sub-Opção 2] Buscar por Nome
 │    │         └── Chama: buscar_nome()
 │    │              └── Chama: exibirInfoProduto()
 │
 ├── [Opção 3] Exibir Estoque
 │    └── Chama: exibir_estoque()
 │         ├── Submenu de Exibição (choice)
 │         │    ├── [Choice 1] Exibir Estoque Total
 │         │    │    └── Chama: exibirInfoProduto() (em laço para todos)
 │         │    │
 │         │    ├── [Choice 2] Exibir por Categoria
 │         │    │    └── Chama: exibirInfoProduto() (filtrado)
 │         │    │
 │         │    └── [Choice 3] Baixa Quantidade
 │         │         └── Chama: exibirInfoProduto() (filtrado por limite)
 │
 ├── [Opção 4] Editar Produtos (Sem implementação/break)
 │
 ├── [Opção 5] Alterar Estoque (Sem implementação/break)
 │
 └── [Opção 0] Sair (Encerra o laço do main)
 
 
 
 
 
 
 
 
 
 # Sistema-de-Estoque
Kaio
* Cadastrar Produtos
  * Verificar código
  * Verificar nome


Pedro
* Buscar Produtos
  * Busca por codigo
  * Busca por nome
  
Henrique
* Buscar Produtos
  * Busca por tamanho
* Exibir Estoque
  * Todo estoque

  
Raphael
* Alterar Estoque
  * Registrar Entrada
  * Registrar Venda

  
Esthefany
* Editar Produtos
* Menu de edição

  
Kauê
* Exibir Estoque
  * Por categoria
  * Baixa Quantidade
