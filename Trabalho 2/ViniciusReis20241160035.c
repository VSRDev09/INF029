#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "ViniciusReis20241160035.h"

struct EstruturaAuxiliar
{
    int *dados;
    int tamanho;
    int quantidade;
};

struct EstruturaAuxiliar vetorPrincipal[TAM];
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados != NULL)
    {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if (tamanho < 1)
    {
        return TAMANHO_INVALIDO;
    }

    int *tam = (int *)malloc(tamanho * sizeof(int));
    if (tam == NULL)
    {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao - 1].dados = tam;
    vetorPrincipal[posicao - 1].tamanho = tamanho;
    vetorPrincipal[posicao - 1].quantidade = 0;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao - 1].quantidade >= vetorPrincipal[posicao - 1].tamanho)
        return SEM_ESPACO;

    vetorPrincipal[posicao - 1].dados[vetorPrincipal[posicao - 1].quantidade] = valor;
    vetorPrincipal[posicao - 1].quantidade++;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao - 1].quantidade == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    vetorPrincipal[posicao - 1].quantidade--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int valor_existe = 0;
    int indiceValor = 0;
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao - 1].quantidade == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for (int i = 0; i < vetorPrincipal[posicao - 1].quantidade; i++)
    {

        if (vetorPrincipal[posicao - 1].dados[i] == valor)
        {
            valor_existe = 1;
            indiceValor = i;
            break;
        }
    }

    if (!valor_existe)
    {
        return NUMERO_INEXISTENTE;
    }
    else
    {
        for (int i = indiceValor; i < vetorPrincipal[posicao - 1].quantidade - 1; i++)
        {
            vetorPrincipal[posicao - 1].dados[i] = vetorPrincipal[posicao - 1].dados[i + 1];
        }
        vetorPrincipal[posicao - 1].quantidade--;
    }
    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }
    else
        return SUCESSO;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao - 1].quantidade == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for (int i = 0; i < vetorPrincipal[posicao - 1].quantidade; i++)
    {
        vetorAux[i] = vetorPrincipal[posicao - 1].dados[i];
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
void insertionSort(int vetor[], int tamanho)
{
    int i, j, chave;
    for (i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = chave;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (posicao < 1 || posicao > 10)

    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao - 1].quantidade == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for (int i = 0; i < vetorPrincipal[posicao - 1].quantidade; i++)
    {
        vetorAux[i] = vetorPrincipal[posicao - 1].dados[i];
    }

    insertionSort(vetorAux, vetorPrincipal[posicao - 1].quantidade);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int preenchida = 0;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i].dados != NULL && vetorPrincipal[i].quantidade > 0)
        {
            preenchida = 1;
            break;
        }
    }

    if (!preenchida)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i].dados != NULL)
        {

            for (int j = 0; j < vetorPrincipal[i].quantidade; j++)
            {
                vetorAux[k] = vetorPrincipal[i].dados[j];
                k++;
            }
        }
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int preenchida = 0;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i].dados != NULL && vetorPrincipal[i].quantidade > 0)
        {
            preenchida = 1;
            break;
        }
    }

    if (!preenchida)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i].dados != NULL)
        {

            for (int j = 0; j < vetorPrincipal[i].quantidade; j++)
            {
                vetorAux[k] = vetorPrincipal[i].dados[j];
                k++;
            }
        }
    }

    insertionSort(vetorAux, k);
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    int indice = posicao - 1;

    if (vetorPrincipal[indice].dados == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoFinal = vetorPrincipal[indice].tamanho + novoTamanho;

    if (tamanhoFinal < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoDados = realloc(vetorPrincipal[indice].dados, tamanhoFinal * sizeof(int));
    if (novoDados == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[indice].dados = novoDados;
    vetorPrincipal[indice].tamanho = tamanhoFinal;

    if (vetorPrincipal[indice].quantidade > tamanhoFinal)
        vetorPrincipal[indice].quantidade = tamanhoFinal;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    if (posicao < 1 || posicao > 10)
    {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao - 1].dados == NULL)
    {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao - 1].quantidade == 0)
    {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    return vetorPrincipal[posicao - 1].quantidade;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabecote = (No *) malloc(sizeof(No));
    if (cabecote == NULL)
        return NULL; 

    cabecote->prox = NULL; 

    No *ultimo = cabecote; 

    int encontrou = 0; 

    for (int i = 0; i < 10; i++)
    {
        if (vetorPrincipal[i].dados != NULL && vetorPrincipal[i].quantidade > 0)
        {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++)
            {
                No *novo = (No *) malloc(sizeof(No));
                if (novo == NULL)
                {
                    
                    No *atual = cabecote;
                    while (atual != NULL)
                    {
                        No *temp = atual;
                        atual = atual->prox;
                        free(temp);
                    }
                    return NULL;
                }

                novo->conteudo = vetorPrincipal[i].dados[j];
                novo->prox = NULL;
                ultimo->prox = novo;
                ultimo = novo;
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        free(cabecote);
        return NULL;
    }

    return cabecote; 
}


/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    
    No *atual = inicio->prox;

    int i = 0;
    while (atual != NULL)
    {
        vetorAux[i] = atual->conteudo; 
        i++;
        atual = atual->prox; 
    }
}


/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    while (atual != NULL)
    {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].dados = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].quantidade = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].dados != NULL)
        {
            free(vetorPrincipal[i].dados);
            vetorPrincipal[i].dados = NULL;
            vetorPrincipal[i].tamanho = 0;
            vetorPrincipal[i].quantidade = 0;
        }
    }
}
