#include "Header.h"
void InserAtLast(struct data **book, char *name, int bytes){
	struct data *last = *book, *newpage = NULL;
	newpage = (struct data *)malloc(sizeof(struct data));
	strcpy(newpage->name, name);
	newpage->nofbytes = bytes;
	if ((*book) == NULL){
		newpage->address = BASE_ADDRESS;
		newpage->next = NULL;
		(*book) = newpage;
	}
	else{
		while (last->next)last = last->next;
		newpage->address = last->address + last->nofbytes;
		newpage->next = NULL;
		last->next = newpage;
	}
}
int checkinBook(struct data **book, char *name){
	struct data *last = *book;
	if (last == NULL)return -1;
	while (last){
		if (strcmp(name, last->name) == 0){
			return last->address;
		}
		last = last->next;
	}
	return -1;
}
void freetheBook(struct data *book){
	if (book){
		freetheBook(book->next);
		free(book);
	}
}