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
      float maxmark;

void main()
{
      struct student std[100];
      fileptr=fopen("records.txt","r+");

      maxmark=0;
      if(fileptr==NULL)
            printf("Unable to open file\n");
      else
      {
            for(int i=0;i<100;i++)
            {
                   fscanf(fileptr,"%[^,], %[^,],%f ", &std[i].name,  &std[i].roll, &std[i].mark  );
                   sum+=std[i].mark;
                   if(std[i].mark>maxmark)
                        maxmark=std[i].mark;
            }
            sum=sum/100;
            printf("Mean Marks:%0.1f  Maximum Marks: %0.1f \n",sum,maxmark);
      }
      fclose(fileptr);

}
