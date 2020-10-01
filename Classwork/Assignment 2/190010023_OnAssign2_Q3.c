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

//========================================= sortRecords2======================
void sortRecords2(struct student *ptr)
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
//========================================   printRecords2  ===================
void printRecords2(struct student *ptr)
{
      for(int i=0;i<100;i++)
      {
            printf("%s\t %s\t\t %0.1f\n",ptr->name,  ptr->roll, ptr->mark);
            ptr++;
      }
}

//=============================================Main========================
FILE *fileptr;
      char temp[20];
      float sum=0,maxmarks;
      int i;

void main()
{

      struct student *ptr;
      ptr = malloc(100 * sizeof(struct student));
      fileptr=fopen("records.txt","r+");
      sum=0;
      if(fileptr==NULL)
            printf("Unable to open file\n");
      else
      {
             maxmarks=0;
            for(i=0;i<100;i++)
            {
                   fscanf(fileptr,"%[^,], %[^,],%f ", &ptr->name,  &ptr->roll, &ptr->mark  );
                   sum+=ptr->mark;
                   if(maxmarks<ptr->mark)
                        maxmarks=ptr->mark;
                   ptr++;

            }
            sum=sum/100;
            printf("Mean Marks: %0.1f  Maximum Marks: %0.1f\n\n",sum,maxmarks);
      }
      ptr=ptr-100;                  // The pointer now points to the first element of the array of structures
       fclose(fileptr);
       sortRecords2(ptr);
       printRecords2(ptr);
}
