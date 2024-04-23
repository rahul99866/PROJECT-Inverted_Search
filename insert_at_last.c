#include "main.h"
/* the filenames will be inserted at done */
int insert_at_last(f_list **head,char *file)
{
		f_list *new = malloc(sizeof(f_list));
		if(new == NULL ) return -1;
		new->fname = file;
		new->link = NULL;
		if( *head == NULL)
		{
				*head = new;
				return 0;
		}
		f_list *prev, *temp = *head;

		while(temp!= NULL)
		{
				prev=temp;
				if((strcmp(temp-> fname ,file)) == 0)
						return -3;
				temp=temp->link;
		}
		prev->link=new;
		return 0;
}




