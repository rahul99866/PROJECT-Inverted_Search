#include "main.h"
/* Displays the hashtable and the data stored in them */
void display(mainnode *hash[27])
{
		printf("--------------------------------------`---------------------------------------------------------------\n");
		printf("%s %15s %18s %14s %18s\n","Index","Word","Filecount","Filename","Wordcount");
		printf("-----------------------------------------------------------------------------------------------------\n");
		int j=0;
		while(j<27)
		{
				mainnode *t = hash[j];
				while(t != NULL )
				{
						printf("%-3d",j);
						printf("%17s",t->name);
						printf("%19d",t->filecount);
						subnode *p = t->sublink;
						while(p)
						{
								printf("%17s",p->filename);
								printf("%17d",p->wordcount);
								p=p->sublink;
						}
						t=t->mainlink;
				printf("\n");
				}
				j++;
		}
}

