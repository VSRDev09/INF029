# 🚀 TRABALHO 1 - Manipulação de Strings e Números em C

Este repositório contém um conjunto de funções em **linguagem C** desenvolvidas para resolver problemas comuns de manipulação de strings, análise de textos e operações matemáticas sobre números inteiros.  
O foco principal é lógica de programação, controle de fluxo e manipulação manual de dados — tudo **sem uso de bibliotecas externas**, para aprofundar o conhecimento nos fundamentos da programação.

---

## 🛠️ Funcionalidades Desenvolvidas

### 1️⃣ Conversão de texto  
`void paraMaiusculas(char *texto)`  
Converte todos os caracteres alfabéticos de uma string para **maiúsculas**, manipulando diretamente valores ASCII.

---

### 2️⃣ Contagem de ocorrências de caracteres  
`int q3(char *texto, char c, int isCaseSensitive)`  
Conta quantas vezes um caractere aparece na string, com opção de ser **case sensitive** ou não.

---

### 3️⃣ Pesquisa de palavras em textos  
`int q4(char *strTexto, char *strBusca, int posicoes[30])`  
Encontra todas as ocorrências de uma palavra dentro de um texto, retornando a quantidade e armazenando os índices de início e fim de cada ocorrência em um vetor.

---

### 4️⃣ Inversão de números  
Função genérica que inverte qualquer número inteiro (sem considerar sinal), demonstrando manipulação matemática e lógica.

---

### 5️⃣ Contagem de ocorrência de um número dentro de outro  
`int q6(int numerobase, int numerobusca)`  
Verifica quantas vezes um número ocorre dentro de outro, **sem utilizar funções de string**, garantindo entendimento de operações aritméticas básicas.

---

## ✨ Diferenciais do Trabalho

- **Manipulação direta de dados:**  
  Todo o processamento é feito via operações básicas, sem uso de bibliotecas padrão como `<string.h>` ou `<ctype.h>`, mostrando habilidade no nível mais baixo da linguagem C.

- **Código modular e claro:**  
  Funções independentes e bem documentadas facilitam manutenção, testes e reutilização.

- **Testes automatizados:**  
  Funções de teste garantem confiabilidade e validação do funcionamento esperado.

---
