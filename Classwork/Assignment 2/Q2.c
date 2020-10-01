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
//============================================== Sorting =======================
void sortRecords(struct student *ptr)
{
      int i,j;
      struct student t;
      for (i = 0; i < 100; i++)
      {

        for (j = i + 1; j < 100; j++) {

            if ((ptr + j)->mark < (ptr + i)->mark) {

                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}
//============================================= Printing =======================
void printRecords(struct student   std[])
{
      for(int i=0;i<100;i++)
      {
            printf("%s %s %f\n",std[i].name,std[i].roll,std[i].mark);
      }
}

//============================================= Main ========================
void main()
{
      FILE *fileptr;
      char temp[20];
      float sum=0;
      int i;

      struct student std[100];
      fileptr=fopen("records.txt","r+");

      if(fileptr==NULL)
            printf("Unable to open file\n");
      else
      {
            for(int i=0;i<100;i++)
                   fscanf(fileptr,"%[^,], %[^,],%f ", &std[i].name,  &std[i].roll, &std[i].mark  );
      }
      fclose(fileptr);
//==========================================    2    ====================================

      struct student *stdptr=std;
      sortRecords(stdptr);
      printRecords(std);

}
