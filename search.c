#include"main.h"
/* the seach function searches the word in a hash table if present */
int search(mainnode *hash[27],char data[20])
{
		int j=0;
		while(j<27)
		{   
				mainnode *t = hash[j];
				while(t != NULL )
				{  
						if(strcmp(t->name, data) == 0)
						{
								printf("The word '%s' is present in %d files. \n",t->name,t->filecount);
								subnode *p = t->sublink;
								while(p)
								{   
										printf("In %s for %d times.\n",p->filename,p->wordcount);
										p=p->sublink;
								}  
								printf("\n");
								return 0;
						}	
						t=t->mainlink;
				}   
				j++;
		}   
		return -1;
}


