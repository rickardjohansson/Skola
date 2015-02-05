#ifndef term_h
#define term_h

typedef struct term_t term_t;

struct term_t {
	term_t* 	pred;
	term_t* 	succ;
	int 		deg;
	int 		coef;
};

term_t *new_list(int *deg, int *coef);
void insert(term_t** terms, int* deg, int* coef);


#endif