#include <stdio.h>
#include <stdlib.h>

struct listaSimples {
	int matricula;
	float media;
	char situacao;
	struct listaSimples* prox;
};

typedef struct listaSimples Lista;

Lista* create() {
	return NULL;
}

int vazia(Lista* l) {
	if(l == NULL) {
		printf("\n---A lista esta vazia---\n");
		return 1;
	} else {
		printf("\n---A lista nao esta vazia---\n");
		return 0;
	}
}

/*Lista* adicionar(Lista* l, int mat, float med) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->matricula = mat;
	novo->media = med;
	novo->prox = l;
	if(med >= 7) {
		novo->situacao = 'A';
	}
	else {
		novo->situacao = 'R';
	}
	return novo;
}*/

void imprimir(Lista* l) {
	
	if(l == NULL) {
		printf("\n---A lista esta vazia---\n");
	} else {
		Lista* p;
		printf("\nExibindo matriculas de forma ordenada:\n");
		for(p = l; p != NULL; p = p->prox) {
			printf("\nMatricula do aluno: %d\n", p->matricula);
			printf("Media do aluno: %.2f\n", p->media);
			printf("Situacao do aluno: %c\n", p->situacao);
		}	
	}
}

Lista* buscar(Lista* l, int mat) {
	Lista* p;
	
	for(p = l; p != NULL; p = p->prox) {
		if(p->matricula == mat) {
			printf("\n---A matricula %d foi encontrada---\n", mat);
			return p;
		}
	}
	printf("\n---A matricula %d nao foi encontrada---\n", mat);
	
	return NULL;
}

Lista* remover(Lista *l, int mat) {
	Lista* ant;
	Lista* p;
	ant = NULL;
	p = l;
	
	while(p != NULL && p->matricula != mat) {
		ant = p;
		p = p->prox;
	}
	if(p == NULL) {
			printf("\n---Matricula %d nao encontrada---\n", mat);
			return l;
		}
	if (ant == NULL) {
		l = p->prox;
	} else {
		ant->prox = p->prox;
	}
	free(p);
	
	printf("\n---Matricula %d removida com sucesso---\n", mat);
	
	return l;
}

Lista* liberar(Lista* l) {
	Lista *p = l;
	Lista* aux;

	while(p != NULL) {
		aux = p->prox;
		free(p);
		p = aux;
	}
	
	printf("\nTodos os elementos da lista foram removidos com sucesso\n");
	return p;
}

void quantElementos(Lista* l) {
	
	Lista* p = l;
	int quant;
	
	while(p != NULL) {
		quant = quant + 1;
		p = p->prox;
	}
	printf("\nA quantidade de elementos da lista eh: %d\n", quant);
}

Lista* adicionarOrdenar(Lista *l, int mat, float med){
    
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->matricula < mat){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*)malloc(sizeof(Lista));
    novo->matricula = mat;
    novo->media = med;
    
    if(med >= 7) {
		novo->situacao = 'A';
	}
	else {
		novo->situacao = 'R';
	}

    if(ant == NULL) {
        novo->prox = l;
        l = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    
    printf("\nMatricula %d adicionada com sucesso a lista\n", mat);
    return l;
}

int main(int argc, char *argv[]) {
	
	Lista* teste;
	teste = create();
	
	printf("========================================================");
	
	vazia(teste);
	
	printf("========================================================");
	
	quantElementos(teste);
	
	printf("========================================================");
	
	teste = adicionarOrdenar(teste, 8, 8.5);
	teste = adicionarOrdenar(teste, 1, 4.6);
	teste = adicionarOrdenar(teste, 3, 7.6);
	teste = adicionarOrdenar(teste, 2, 7.6);
	
	vazia(teste);
	
	printf("========================================================");
	
	quantElementos(teste);
	
	printf("========================================================");
	
	imprimir(teste);
	
	printf("========================================================");
	
	buscar(teste, 1);
	
	printf("========================================================");
	
	buscar(teste, 2);
	
	printf("========================================================");
	
	buscar(teste, 8);
	
	printf("========================================================");
	
	buscar(teste, 20);
	
	printf("========================================================");
	
	teste = remover(teste, 2);
	
	printf("========================================================");
	
	quantElementos(teste);
	
	printf("========================================================");
	
	imprimir(teste);
	
	printf("========================================================");
	
	teste = remover(teste, 7);
	
	printf("========================================================");
	
	teste = liberar(teste);
	
	printf("========================================================");
	
	quantElementos(teste);
	
	printf("========================================================");
	
	imprimir(teste);
	
	printf("========================================================");
	
	return 0;
}
