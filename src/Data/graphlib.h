/*
	Biblioteca de manipulacao de Grafos. Contém estruturas auxiliares para
	representacao e funcoes de leitura de manipulacao
	Autor: Marco Antonio Benatto
	Historico:
		* 22/09/2010 - Criacao das estruturas;
*/
#include "gstructs.h"

/*
	Matriz de adjacencia e dados auxiliares para manipulacao
*/
typedef struct AdjMatrix{
	UINT **m;
	UINT last_i;
	UINT last_j;
}AdjMatrix;

/*
	Estrutura representando um grafo
*/
typedef struct Graph{
	AdjMatrix *am; /*Matriz de adjacencia*/
	Edge *e; /*Conjunto de arestas*/
	struct AdjList *al; /*Listas de adjacencia*/
	Vertice *v; /*Conjunto de vertices*/
	UINT sizev; /*Tamanho do conjunto de vertices*/
	UINT sizee; /*Tamanho do conjunto de arestas*/
	UINT last_epos; /*Ultima posicao ocupada do vetor de arestas*/
}Graph;

/*
	Nó de uma lista de adjacencia
*/
typedef struct AdjNode{
	UINT id;
	struct AdjNode *next;
	struct AdjNode *prev;
}AdjNode;

/*
	Lista de adjacência
*/
typedef struct AdjList{
	AdjNode *begin;
	AdjNode *end;
	UINT size;
}AdjList;

/*
	Forma de leitura do arquivo
*/
typedef enum ReadFlag{
	MTR_READ = 'M', /*Forma de leitura padrão - Matriz de adjacencia*/
	EDG_READ = 'L' /*Forma de leitura por arestas - a - b => e={a;b}*/
}ReadFlag;

/*
	Descricao: Le dados de um arquivo
	Parametros: Caminho do arquivo,
				Modo de leitura
	Retorno: Estrutura de grafo
*/
Graph *ReadFile(char *path, ReadFlag rtype, int n);

/*
	Descricao: Retorna a primeira aresta do grafo
	Parametros: Grafo
	Retorno: Aresta caso exista/null caso não haja nenhuma
*/
Edge *FirstEdge(Graph*);

/*
	Descricao: Retorna a proxima aresta do grafo
	Parametros: Grafo
	Retorno: Aresta caso exista/null caso não haja nenhuma
*/
Edge *NextEdge(Graph*);

/*
	Descricao: Insere aresta na lista de arestas
	Parametros: Grafo, aresta
*/
void InsertEdge(Graph *g, Edge *e);

/*
	Descricao: Lista todas as arestas de G
	Parametros: Grafo
*/
void FindAllEdges(Graph *g);
