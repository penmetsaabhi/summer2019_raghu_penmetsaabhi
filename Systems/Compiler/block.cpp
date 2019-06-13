#include "Header.h"
void insertLastBlockLab(struct label **block, char *name, int address){
	struct label *last =(*block),*newnode;
	newnode = (struct label *)malloc(sizeof(struct label));
	strcpy(newnode->blockName, name);
	newnode->address = address;
	newnode->next = NULL;
	if ((*block) == NULL){
		(*block) = newnode;
	}
	else{
		while (last->next)last = last->next;
		last->next = newnode;
	}
}
int checkinBlockLab(struct label **block, char *name){
	struct label *last = (*block);
	if (last == NULL)return -1;
	while (last){
		if (strcmp(name, last->blockName) == 0){
			return last->address;
		}
		last = last->next;
	}
	return -1;
}
void freeAndprintBlock(struct label *block){
	if (block){
		//printf("k=%s %d\n", block->blockName, block->address);
		freeAndprintBlock(block->next);
		free(block);
	}
}