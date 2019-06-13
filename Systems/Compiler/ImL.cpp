#include "Header.h"
void insertLastImL(struct ImL **head, unsigned int opcode, unsigned int param, unsigned int *par){
	struct ImL *last = *head, *newcde = NULL;
	unsigned int i = 0;
	newcde = (struct ImL *)malloc(sizeof(struct ImL));
	if ((*head) == NULL){
		newcde->no = 1;
		newcde->next = NULL;
		newcde->noofparam = param;
		newcde->opcode = opcode;
		for (i = 0; i < param; i++){
			newcde->param[i] = par[i];
		}
		(*head) = newcde;
	}
	else{
		while (last->next)last = last->next;
		newcde->no = (last->no) + 1;
		newcde->next = NULL;
		newcde->noofparam = param;
		newcde->opcode = opcode;
		for (i = 0; i < param; i++){
			newcde->param[i] = par[i];
		}
		last->next = newcde;
	}
}
void checkinImL(struct ImL **head, int line, int *ifop, int presentline, int *opc){
	struct ImL *last = *head;
	while (last){
		if (last->no == line){
			last->param[(last->noofparam)++] = presentline;
			(*ifop) = last->no + 1;
			(*opc) = last->opcode;
			return;
		}
		last = last->next;
	}
}
void freeAndprintImL(struct ImL *head, FILE *out){
	if (head){
		unsigned int i = 0;
		fprintf(out, "%d %d ", head->no, head->opcode);
		for (i = 0; i < (head->noofparam); i++){
			fprintf(out, "%d ", head->param[i]);
		}
		fprintf(out, "\n");
		freeAndprintImL(head->next, out);
		free(head);
	}
}