#include"main.h"
/* save the database in the file entered by an user */
int save(mainnode *hash[27],char backup[20])
{
		if ((strstr(backup, ".")))  // read and validate the file
		{
				if ((strcmp(strstr(backup,"."),".txt" ))== 0)
				{
						FILE *fptr = fopen(backup,"w");
						if(fptr == NULL) return -1;
						int j=0;
						while(j<27)
						{
								mainnode *t = hash[j];
								while(t != NULL )
								{

										fprintf(fptr,"#%-d",j);
										fprintf(fptr,";%s",t->name);
										fprintf(fptr,";%d",t->filecount);
										subnode *p = t->sublink;
										while(p)
										{
												fprintf(fptr,";%s",p->filename);
												fprintf(fptr,";%d",p->wordcount);
												p=p->sublink;
										}
										t=t->mainlink;
										fprintf(fptr,"#\n");
								}
								j++;
						}
				}
				else
						return -1;
		}
		else
				return -1;
}
