#include "main.h"
/* creates the hash table in and stores the data in them index wise by allocating the memory dynamically*/
int create_hashtable(mainnode *hash[27],f_list **head ,f_list **head2)
{
		f_list *temp= *head,*t2;
		int flag=0;
		while(temp != NULL )
		{
				FILE *file ;
				char *fname;
				file= fopen(temp->fname,"r");
				if(file == NULL) return -1;
				char word[50];
				int i=0;
				while((fscanf(file,"%s",word)) > 0)   //access the string from the file 
				{
						if((toupper(word[0])) >= 'A' &&  (toupper(word[0])) <= 'Z')   // index i values from 0 to 25 is assgned for alphabets 
						{

								i=toupper(word[0]) % 65;
						}
						else   // all others values will be stored in an index value 26
								i = 26;  
						if(hash[i] == NULL )  // if hash is empty then the new nodes will be created
						{
								mainnode *new = malloc(sizeof(mainnode));
								if(new == NULL) return -1;
								subnode *subnew = malloc(sizeof(subnode));
								if(subnew == NULL) return -1;
								strcpy(new->name, word);
								new->filecount=1;
								new->sublink = subnew;
								new->mainlink = NULL;
								hash[i]=new;

								subnew->wordcount = 1;
								strcpy(subnew->filename , temp->fname);
								subnew->sublink = NULL;
						}
						else if (hash[i] != NULL )  // if hash is not null then the new node is created and we traverse and update
						{
								int flag=0;
								mainnode *trav = hash[i],*prev = NULL;
								while(trav)
								{
										prev=trav;
										if((strcmp(trav->name, word)) == 0 )
										{
												flag =1;
												int f2=1;
												subnode *t2 = trav->sublink,*p2;
												while(t2)
												{
														p2=t2;
														if(strcmp(t2->filename, temp->fname) == 0)
														{
																f2=0;
																++(t2->wordcount);
														}
														t2=t2->sublink;
												}
												if(f2 == 1)
												{
														++(trav->filecount);
														subnode *subnew = malloc(sizeof(subnode));
														if(subnew == NULL) return -1;

														subnew->wordcount = 1;
														strcpy(subnew->filename ,temp->fname);
														subnew->sublink = NULL;
														p2->sublink= subnew;
												}

										}
										trav=trav->mainlink;
								}
								if(flag == 0)
								{
										mainnode *new = malloc(sizeof(mainnode));
										if(new == NULL) return -1;
										subnode *subnew = malloc(sizeof(subnode));
										if(subnew == NULL) return -1;

										strcpy(new->name, word);
										new->filecount=1;
										new->sublink = subnew;
										new->mainlink = NULL;
										prev->mainlink=new;

										subnew->wordcount = 1;
										strcpy(subnew->filename ,temp->fname);
										subnew->sublink = NULL;
								}
						}
				}
				insert_at_last(head2,(char*)(temp->fname));
				fclose(file);
				temp=temp->link;
		}
		return 0;
}
