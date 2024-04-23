/*
Name			: Rahul S Dodawad
Date 			: 13/12/2023
Description 	: Inverted Search
 */

#include "main.h"
int main(int argc,char **argv)
{
		mainnode *hash[27]={NULL};   // hash table creation 
		f_list *head = NULL;
		f_list *head2= NULL;
		if(argc > 1)    // the argc should be more than 1 arguments
		{
				int flag1=1;
				/* read and validations takes place in this loop */
				for(int i=1;i< argc;i++)  
				{
						int result = 0;
						if((result=(read_n_validate(argv[i]))) == -1)
						{
							
								continue;
						}
						else
						{
								int res =0;
								if(result == 0)
								{
										char *fname = argv[i];
										/* if read and validation is success then the file names will be stored in linked list */
										if(res=(insert_at_last (&head, fname)) == -3)
										{
												printf("Duplicate file : %s\n",fname);
												continue;
										}
										else if(res == -1)
										{
												printf("Error : In inserting  at last\n");
										}
								}	
						}
				}
				if(flag1 == 1) // if read_n_validate is success then the condition becomes true
				{
						int flag =1;
						while(flag)
						{
								printf("-------------------------------------------------------------------------------------------------------\n");
								printf("Menu :\n1. Create data\n2. Display\n3. Search\n4. Save\n5. Update\n6. Exit \n");
								int opt;
								printf("Enter the option : ");
								scanf("%d",&opt);
								switch (opt)
								{
										case 1 :
												int f1=1;
												if(head2 != NULL)  // if hash table is not empty then the files will be compared before storing in hashtable
												{
														f_list *t1 = head, *t2 = head2;
														while(t1 != NULL)
														{
																while(t2)
																{

																		if(strcmp(t1->fname,t2->fname) == 0 )  // compares is the file already been updated before creating the hashtable
																				f1=0;
																		t2=t2->link;
																}
																t1=t1->link;
														}
												}
												if(f1)
												{
														if(create_hashtable(hash,&head,&head2)== -1)
														{
																printf("Info : Error in creating hashtable\n");
														}
												}
												break;

										case 2 :if(head != NULL || head2 != NULL)
												{	
														display(hash);
												}
												else
												{
														printf("Hashtable is empty \n");
												}	
												break;

										case 3 : char word[20];
												 printf("Enter the word to be searched : ");
												 scanf("%s",word);
												 if(search(hash,word) == -1)  // search the words in an hashtable
												 {
														 printf("INFO : Data not Found\n");
												 }
												 break;
										case 4 : char backup[20];
												 printf("Enter the back up filename :");
												 scanf("%s",backup);
												 if(save(hash,backup) == -1)
												 {
														 printf("Error : Invalid filename\nEnter : <filename>.txt \n");
												 }
												 break;
										case 5 : if(update(hash,&head2) == -1)
												 {
														 printf("Error : In Updating the backup file \n");
												 }
												 break;

										case 6 : return 0;

										default : printf("Invalid Entry : Choose the correct option from the above menue\n");
												  break;
								}
								char ch;
								printf("\nDo you want to continue (Y/N) : "); 
								scanf(" %c",&ch);
								if(ch == 'Y' || ch == 'y')
								{
										flag=1;
								}
								else 
								{
										flag=0;
								}

						}
				}
		}
		else
		{
				printf("INFO : Enter CLA in this format:\n./a.out file1.txt file2.txt (...)\n");
		}
}

