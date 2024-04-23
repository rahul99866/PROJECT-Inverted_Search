#include"main.h"

/* Update the backup file to the hash table */
int update(mainnode *hash[27],f_list **head2)
{
		int flag=0;
		for(int i=0;i<27;i++) // checks is hash table is empty
		{
				if(hash[i] != NULL)
				{
						printf("Error : Hashtable is not completely empty\n");
						return -1;
				}
		}
		printf("Enter the backup filename : ");
		char backupfname[100];
		scanf(" %[^\n]",backupfname);
		if(read_n_validate(backupfname) == -1)  // read and validate the backup file
		{
				printf("Error in read and validating the files\n");
		}
		else   // checks is the file is actually a backup file or not
		{

				FILE *fptr = fopen (backupfname,"r");
				if(fptr == NULL) return -1;
				char ch;
				if((ch = fgetc(fptr)) == '#' )
				{
						while((ch=fgetc(fptr)) !=  '\n')
						{
								if(ch == '#')
								{
										flag = 1;
								}
						}
				}
		}
		if(flag == 0)
		{
				printf("Not the back up file\n");
				return -1;
		}
		else 
		{
				FILE *fptr = fopen (backupfname,"r");
				if(fptr == NULL) return -1;
				char arr[100];
				while((fscanf(fptr,"%s",arr)) > 0) // gets the strings from the file
				{
						int ind = atoi(strtok(arr,"#;"));   //index
						mainnode *temp = hash[ind];
						mainnode *new = malloc(sizeof(mainnode));
						if(new == NULL) return -1;

						strcpy(new->name ,strtok(NULL,"#;"));  // word
						int count = atoi(strtok(NULL,"#;"));   // filecount
						new->filecount = count;
						new->mainlink = NULL;
						new->sublink = NULL;
						for(int i=0;i<count;i++)
						{
								subnode *subnew = malloc(sizeof(subnode));
								if(subnew == NULL )return -1;
								strcpy(subnew->filename,strtok(NULL,"#;"));   //filename
								insert_at_last(head2,subnew->filename);
								subnew->wordcount = atoi(strtok(NULL,"#;"));   // wordcount
								subnew->sublink = NULL;
								if(i == 0)
								{
										new->sublink = subnew;
								}
								else
								{
										subnode *t = new->sublink;
										while(t->sublink != NULL)
										{
												printf("ent4\n");
												t=t->sublink;
										}
										t->sublink = subnew;
								}
						}
						if(hash[ind] == NULL)
						{
								hash[ind] = new;
						}
						else
						{
								mainnode *temp = hash[ind];
								while(temp->mainlink != NULL)
								{
										temp=temp->mainlink;
								}
								temp->mainlink = new;
						}
						fseek(fptr,1,SEEK_CUR);
				}
		}
		return 0;
}
