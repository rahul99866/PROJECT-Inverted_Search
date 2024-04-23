#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

#define SUCCESS 0
#define FAILURE -1
#define EMPTY -2
#define DUPLICATE -3

typedef struct node
{
		const char * fname;
		struct node *link;
}f_list;
typedef struct mainnode
{
		char name[100];
		int filecount;
		struct subnode *sublink;
		struct mainnode *mainlink;
}mainnode;

typedef struct subnode
{
		int wordcount;
		char filename[30];
		struct subnode *sublink;
}subnode;

int read_n_validate(char *filename);
int insert_at_last(f_list **head, char  *file);
int create_hashtable(mainnode *hash[27],f_list **head,f_list **head2);
void display(mainnode *hash[27]);
int search(mainnode *hash[27], char data[20]);
int save(mainnode *hash[27], char backup[20]);
int update(mainnode *hash[27],f_list **head2);
#endif

