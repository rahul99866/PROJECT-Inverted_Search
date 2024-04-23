#include "main.h"
/* the files will be read and validated int this function */
int read_n_validate(char *filename)
{
		if ((strstr(filename, ".")))
		{
				if (!(strcmp(strstr(filename,"."),".txt" )))  // if not .txt extention file the the error will be returned 
				{
						FILE *fptr = fopen(filename,"r");
						if(fptr  == NULL ) return -1;
						fseek(fptr,0,SEEK_END);
						if(ftell (fptr) != 0)  // checks wheather the file is empty of not
						{
								return 0;
						}
						else
						{
								printf("Error : %s Empty File detected\n",filename);
								return -1;
						}
				}
				else
				{
						printf("Error : Invalid file extention\n");
						return -1;
				}
		}
		else
		{
				printf("Error : Invalid file entered \n");
				return -1;
		}
}
