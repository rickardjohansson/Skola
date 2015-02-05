#include <stdio.h>
#include <stdlib.h>

term_t *new_list(int *deg, int *coef)
{
	term_t *terms;

	terms = malloc(sizeof(term_t));
	terms->pred = terms;
	terms->succ = terms;
	terms->deg = deg;
	terms->coef = coef;
}

void free_list(term_t **list)
{
	term_t = *p;
	term_t = *q;

	p = *list;

	if(p == NULL) 
		return;

	p->pred->succ = NULL;
	do {
		q = p->succ;
		free(p);
		p = q;
	} while(p != NULL);

	*list = NULL;
}

void insert(term_t** terms, int* deg, int* coef)
{
	term_t* 	p = *terms;
	term_t*		q;

	if(p == NULL) {
		*terms = new_list(deg, coef);
		return;
	} else {
		while(p->deg != deg || (p->deg < deg && p->succ->deg > deg) {
			if(p->deg < deg) {
				p = p->succ;
			} 
			if(p->deg > deg) {
				p = p->pred;
			}

		}	

		if(p->deg < deg && p->succ->deg > deg) {
			q = malloc(sizeof(term_t));
			q->deg = deg;
			q->coef = coef;
			q->pred = p;
			q->succ = p->succ;
			p->succ->pred = q;
			p->succ = q;
		} else {
			p->deg = p->coef + coef;
		}
	}
}