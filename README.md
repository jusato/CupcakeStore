# Cupcake Store <img src="./other files/imgs/ess.png" width="45px">

<p align="center">
  <img src="./other files/imgs-tela/2_sobre.png" width="45%">
</p>

**Cupcake Store** foi desenvovido como uma forma de aprender de forma prática sobre a Programação Orientada a Objetos. Trata-se de um sistema para vendas e estoque de uma loja de cupcakes. 

Há três tipos de usuários:
- Cliente: clientes podem pesquisar por produtos disponíveis na loja, adicioná-los à sua lista de compras e alterar a quantidade ou remover itens de seu carrinho.
- Funcionário: funcionários podem adicionar, editar ou remover itens do estoque da loja.
- Gerente: gerentes possuem acesso ao estoque da loja e à área de gestão de funcionários, onde podem adicionar, remover ou alterar informações de membros da loja.

<!--
**Cupcake Store** was developed for an Object-Oriented Programming assignment.

It's a sales and inventory system for a cupcake shop.

There are three types of users:
- Customer: customers can search for items available in the store, add them to their shopping list, change the quantity of an item and remove it from their cart.
- Employee: employees can add, edit or delete items from the store's inventory.
- Manager: managers can add, edit or delete items from the inventory, as well as add, remove or change information of employees.
-->

## Home
Na página inicial, o usuário pode:
- Ir para a página de login;
- Ir para a página de compras;
- Ver as informações da loja;
- Ir para a página de gestão de produtos ou gestão de membros, se possuir acesso.

<p align="center">
  <img src="./other files/imgs-tela/1_home.png" width="450px">
  <img src="./other files/imgs-tela/4_logado.png" width="450px">
</p>

   _*Após a realização do login, aparece o nome do membro da loja que está logado na parte inferior da tela._

## Login 
Existem três tipos de contas:
- Gerente, que possui acesso ao gerenciamento de produtos e de funcionários;
- Funcionário, que possui acesso ao gerenciamento de produtos;
- Cliente, que não precisa logar e possui acesso à parte de Compras.

<!--
There are 3 types of accounts:
- Manager: managers have access to the inventory and the employees control page. They can add, edit or remove items and they can change employees information li
- Employee: employees have access to the inventory. They can add, edit or remove items. 
- Customer: customers don't need to log in.
-->

<p align="center">
  <img src="./other files/imgs-tela/3_login.png" width="350px">
</p>

## Produtos
### Novo produto
- Adicionar um novo produto ao estoque da loja.

<p align="center">
  <img src="./other files/imgs-tela/5_novoProduto.png" width="70%">
</p>

### Gerenciamento de produtos
- Selecionar um produto e alterar suas informações ou excluí-lo;
- Ordenar os produtos disponíveis por código ou nome;
- Pesquisar por um produto.

<p align="center">
  <img src="./other files/imgs-tela/6_gestãoProdutos_editar.png" width="70%">
  <br>
  <img src="./other files/imgs-tela/6_gestãoProdutos_pesquisar.png" width="70%">
</p>

## Funcionários
### Novo funcionário
- Adicionar uma conta para um novo membro da loja.

<p align="center">
  <img src="./other files/imgs-tela/7_membros.png" width="60%">
</p>

### Gerenciamento de funcionários
- Alterar informações sobre um membro da loja ou excluir sua conta;
- Ver os membros atuais.

<p align="center">
  <img src="./other files/imgs-tela/9_membrosAtuais_editar.png" width="60%">
</p>

## Compra de produtos 
- Ver os produtos disponíveis na loja;
- Adicionar um produto no carrinho;
- Alterar a quantidade de um produto no carrinho;
- Excluir um produto do carrinho;
- Finalizar a compra.

<p align="center">
  <img src="./other files/imgs-tela/11_produtos_adicionar.png" width="85%">
  <br>
  <img src="./other files/imgs-tela/12_produtos_editar.png" width="85%">
</p>

## Como acessar o projeto:
**1.** Instalar **[QT](https://www.qt.io/download)**

**2.** Abrir projeto no _Qt Creator_ e clicar no botão _Run_.

- Para acessar como gerente: 

     _username: jusato / senha: 1234_

- Para acessar como funcionário:

     _username: lasato / senha: 1234_

<!--
After downloading the necessary software, to access the project you must open it in the Qt Creator IDE and click on the "Run" button.
-->
