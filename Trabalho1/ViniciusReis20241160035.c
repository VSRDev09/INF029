// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Vinicius Santos dos Reis
//  email: 20241160035@ifba.edu.br
//  Matrícula: 20241160035
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "ViniciusReis20241160035.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ // função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int isBissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    else
        return 0;
}

int q1(char data[])
{
    DataQuebrada dq = quebraData(data);

    if (dq.valido == 0)
        return 0; // formato inválido

    int dia = dq.iDia;
    int mes = dq.iMes;
    int ano = dq.iAno;

    // Ano de 2 dígitos: assume 2000+
    if (ano < 100)
    {
        ano += 2000;
    }

    // Verificar mês válido
    if (mes < 1 || mes > 12)
        return 0;

    // Verificar dias válidos para o mês
    int diasNoMes;

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        diasNoMes = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        diasNoMes = 30;
        break;
    case 2:
        diasNoMes = isBissexto(ano) ? 29 : 28;
        break;
    default:
        return 0;
    }

    if (dia < 1 || dia > diasNoMes)
        return 0;

    return 1;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;

    if (q1(datainicial) == 0)
    {
        dma.retorno = 2;
        return dma;
    }

    if (q1(datafinal) == 0)
    {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada d1 = quebraData(datainicial);
    DataQuebrada d2 = quebraData(datafinal);

    // Verifica se datainicial > datafinal
    if (d1.iAno > d2.iAno ||
        (d1.iAno == d2.iAno && d1.iMes > d2.iMes) ||
        (d1.iAno == d2.iAno && d1.iMes == d2.iMes && d1.iDia > d2.iDia))
    {
        dma.retorno = 4;
        return dma;
    }

    int dia1 = d1.iDia;
    int mes1 = d1.iMes;
    int ano1 = d1.iAno;

    int dia2 = d2.iDia;
    int mes2 = d2.iMes;
    int ano2 = d2.iAno;

    // Empréstimo de dias e meses, se necessário
    if (dia2 < dia1)
    {
        mes2 -= 1;

        // dias no mês anterior a datafinal
        int diasNoMesAnterior;
        if (mes2 == 0)
        {
            mes2 = 12;
            ano2 -= 1;
        }

        // calcula quantos dias teve o mês anterior
        if (mes2 == 2)
        {
            diasNoMesAnterior = (ano2 % 4 == 0 && (ano2 % 100 != 0 || ano2 % 400 == 0)) ? 29 : 28;
        }
        else if (mes2 == 4 || mes2 == 6 || mes2 == 9 || mes2 == 11)
        {
            diasNoMesAnterior = 30;
        }
        else
        {
            diasNoMesAnterior = 31;
        }

        dia2 += diasNoMesAnterior;
    }

    if (mes2 < mes1)
    {
        ano2 -= 1;
        mes2 += 12;
    }

    dma.qtdDias = dia2 - dia1;
    dma.qtdMeses = mes2 - mes1;
    dma.qtdAnos = ano2 - ano1;

    dma.retorno = 1;
    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

void paraMaiusculas(char *texto)
{
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = texto[i] - 32;
        }
    }
}
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    if (isCaseSensitive)
    {
        for (int i = 0; texto[i]; i++)
        {
            if (c == texto[i])
            {
                qtdOcorrencias++;
            }
        }
    }
    else
    {
        if (c >= 'a' && c <= 'z')
        {
            c = c - 32;
        }

        char textoCopia[1000];
        int x = 0;
        while (texto[x] != '\0')
        {
            textoCopia[x] = texto[x];
            x++;
        }
        textoCopia[x] = '\0'; 

        paraMaiusculas(textoCopia);

        for (int y = 0; textoCopia[y]; y++)
        {
            if (textoCopia[y] == c)
            {
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int idxTexto = 0;
    int idxBusca = 0;
    int tamTexto = 0;
    int tamBusca = 0;

    // Calcula tamanho do texto
    while (strTexto[tamTexto] != '\0')
        tamTexto++;

    // Calcula tamanho da palavra de busca
    while (strBusca[tamBusca] != '\0')
        tamBusca++;

    // Percorre o texto base
    while (idxTexto < tamTexto)
    {
        int encontrou = 1;

        for (idxBusca = 0; idxBusca < tamBusca; idxBusca++)
        {
            if (strTexto[idxTexto + idxBusca] != strBusca[idxBusca])
            {
                encontrou = 0;
                break;
            }
        }

        if (encontrou)
        {
            // Armazena a posição da ocorrência (começando do índice 1)
            posicoes[qtdOcorrencias * 2] = idxTexto + 1;                // Início
            posicoes[qtdOcorrencias * 2 + 1] = idxTexto + tamBusca;     // Fim
            qtdOcorrencias++;

            idxTexto += tamBusca; // Avança após a ocorrência
        }
        else
        {
            idxTexto++;
        }
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
     int invertido = 0;

    while (num > 0)
    {
        invertido = invertido * 10 + (num % 10);
        num /= 10;
    }

    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */


int contarDigitos(int num) {
    if (num == 0) return 1;
    int cont = 0;
    while (num > 0) {
        cont++;
        num /= 10;
    }
    return cont;
}

void numeroParaVetor(int num, int vet[], int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        vet[i] = num % 10;
        num /= 10;
    }
}

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;

    int tamBase = contarDigitos(numerobase);
    int tamBusca = contarDigitos(numerobusca);

    int digitosBase[20];
    int digitosBusca[20];

    numeroParaVetor(numerobase, digitosBase, tamBase);
    numeroParaVetor(numerobusca, digitosBusca, tamBusca);

    int pos = 0;
    while (pos <= tamBase - tamBusca) {
        int bateu = 1;
        for (int z = 0; z < tamBusca; z++) {
            if (digitosBase[pos + z] != digitosBusca[z]) {
                bateu = 0;
                break;
            }
        }
        if (bateu) {
            qtdOcorrencias++;
            pos += tamBusca; // pula o tamanho da busca pra evitar sobreposição
        } else {
            pos++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int calcularTamanho(char palavra[]) {
    int tamanho = 0;
    while (palavra[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

int buscarEmDirecao(char matriz[8][10], int linha, int coluna, char palavra[], int dx, int dy) {
    int tamanho = calcularTamanho(palavra);

    for (int i = 0; i < tamanho; i++) {
        int novaLinha = linha + i * dx;
        int novaColuna = coluna + i * dy;

        // Verifica limites da matriz
        if (novaLinha < 0 || novaLinha >= 8 || novaColuna < 0 || novaColuna >= 10)
            return 0;

        // Verifica caractere da matriz com a letra da palavra
        if (matriz[novaLinha][novaColuna] != palavra[i])
            return 0;
    }

    return 1; // Palavra encontrada nessa direção
}

int q7(char matriz[8][10], char palavra[]) {
    // Todas as 8 direções possíveis (linha, coluna)
    int direcoes[8][2] = {
        {0, 1},   
        {0, -1},  
        {1, 0},   
        {-1, 0},  
        {1, 1},   
        {1, -1},  
        {-1, -1}, 
        {-1, 1}   
    };

    for (int i = 0; i < 8; i++) {         // linhas
        for (int j = 0; j < 10; j++) {    // colunas
            for (int d = 0; d < 8; d++) { // direções
                if (buscarEmDirecao(matriz, i, j, palavra, direcoes[d][0], direcoes[d][1])) {
                    return 1; 
                }
            }
        }
    }

    return 0; 
}

DataQuebrada quebraData(char data[])
{
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;

    for (i = 0; data[i] != '/'; i++)
    {
        sDia[i] = data[i];
    }
    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sDia[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    int j = i + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++)
    {
        sMes[i] = data[j];
        i++;
    }

    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sMes[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    j = j + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '\0'; j++)
    {
        sAno[i] = data[j];
        i++;
    }

    if (i == 2 || i == 4)
    {                   // testa se tem 2 ou 4 digitos
        sAno[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    dq.valido = 1;

    return dq;
}
