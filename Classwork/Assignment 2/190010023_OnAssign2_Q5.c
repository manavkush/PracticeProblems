#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
char name [40];
char roll [13];
float mark ;
int numFriends;
int numFrFriends;
};

FILE *fileptr;
      char temp[20];
      float sum=0;
      char str1[25], str2[25];
      int minfrnd,maxfrnd;
      int i,id1,id2;
//=============================================Main========================
void main()
{
      struct student std[100];
      fileptr=fopen("records.txt","r+");

      if(fileptr==NULL)
            printf("Unable to open file\n");
      else
      {

            for(int i=0;i<100;i++)
            {
                   fscanf(fileptr,"%[^,], %[^,],%f ", &std[i].name,  &std[i].roll, &std[i].mark  );

            }
      }
      fclose(fileptr);

//==========================================    5    ====================================
      for(i=0;i<100;i++)
            std[i].numFriends=0;

      fileptr=fopen("friendship_pairs.txt","r");

      if(fileptr==NULL)
            printf("Unable to open file\n");


      while(fscanf(fileptr,"%[^,], %s ", str1,  str2 )!=EOF)
      {
            for(i=0;i<100;i++)
            {
                  if(strcmp(str1,std[i].name)==0||strcmp(str2,std[i].name)==0)
                        std[i].numFriends++;
            }
      }
      fclose(fileptr);

for( i =0;i < 100;i++)
        std[i].numFrFriends=0;

     fileptr = fopen("friendship_pairs.txt","r");

    if(fileptr==NULL)
        printf("Unable to open file\n");

    else
      {
           while(fscanf(fileptr,"%[^,], %s ",str1,str2)!=EOF)
           {
               for( i =0; i <  100;i++)
               {
                    if(strcmp(std[i].name,str1)==0)
                    {
                            id1 = i;
                            break;
                     }
               }
               for( i =0; i <  100;i++)
               {
                    if(strcmp(std[i].name,str2)==0)
                    {
                            id2 = i;
                            break;
                    }
               }
               std[id1].numFrFriends = std[id1].numFrFriends +  std[id2].numFriends-1;
               std[id2].numFrFriends = std[id2].numFrFriends + std[id1].numFriends-1;
          }

           }
      fclose(fileptr);


     for( i =0;i < 100;i++){
        printf("No. of friends of friends of %s : %d\n",std[i].name,std[i].numFrFriends);

    }
    }
