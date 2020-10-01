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
      int i;
int minfrnd,maxfrnd;
char str1[25], str2[25];
//=============================================Main=============================
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

//==========================================    4    ====================================
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
      sum=minfrnd=maxfrnd=std[0].numFriends;

      for(i=1;i<100;i++)
      {
            if(minfrnd>std[i].numFriends)
                  minfrnd=std[i].numFriends;
            if(maxfrnd<std[i].numFriends)
                  maxfrnd=std[i].numFriends;
            sum+=std[i].numFriends;
      }
      sum=sum/100;
      printf("MinFriends:%d MaxFriends:%d MeanFriends:%0.1f\n\n",minfrnd,maxfrnd,sum);

//============================================================================

}
