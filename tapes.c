#include<stdio.h>
#include<stdlib.h>

int noOfTapes;			//number of tapes
int sizeOfTapes;		//size of all tapes
int noOfProcess;		//no of process
int len_process[20] = {0};	//length of each process
int tapes[10][10];		
int flag = 0;
int cnt;
int size[20];			//ramaining size of each tape left

void merge(int len_process[20],int low,int mid,int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = len_process[low + i];
    for (j = 0; j < n2; j++)
        R[j] = len_process[mid + 1+ j];
   
  
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of merged subarray
     
  while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            len_process[k] = L[i];
            i++;
        }
        else
        {
            len_process	[k] = R[j];
            j++;
        }
        k++;
    }
 
   while(i<n1)
  { 
    len_process[k]=L[i];
    i++;
k++;
  }
  
  while(j<n2)
  { 
    len_process[k]=R[j];
    j++;
  k++;
  }
  
  
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void partition(int len_process[20],int low,int high)
{
    if (low < high)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = (low+high)/2;
 
        // Sort first and second halves
       partition(len_process,low,mid);
                partition(len_process,mid+1,high);
                merge(len_process,low,mid,high);
    }
}
 
int store(int len_process[20],int noOfProcess,int noOfTapes,int tapes[10][10])
{
        int tape_no;
        int i = 0;
        int k = -1;
        int j = 0;
        for(i = 0,j = 0;i < noOfProcess;i++,j++)
        {
        	tape_no = (i % noOfTapes);
        	if(size[tape_no] >= len_process[i])
        	{
		        if(tape_no == 0)
		        {           	
		                k++;
		                j = 0;
		        }
		        cnt++;
		        tapes[j][k] = len_process[i];
		        size[j] = size[j] - len_process[i];
		 }
		 else
		 {
		 	flag = 1;
		 }
        }
        return k;
}

int main()
{       
        int i = 0,j,count = -1;
        printf("Enter the no of tapes\n");
        scanf("%d",&noOfTapes);
        printf("Enter the size of tapes\n");
        scanf("%d",&sizeOfTapes);
        for(i = 0;i < noOfTapes;i++)
        {
        	size[i] = sizeOfTapes;
        }
        printf("Enter the no of process\n");
        scanf("%d",&noOfProcess);
        for(i = 0;i < noOfProcess;i++)
        {
                    printf("Enter the length of process %d\n",i);
                    scanf("%d",&len_process[i]);        
        }
        partition(len_process,0,noOfProcess-1);
        int k = store(len_process,noOfProcess,noOfTapes,tapes);
        i = 0;
        for(count = 0;count < noOfTapes;count++)
        {
        	printf("Tape %d\t - \t",count);
                for(j = 0;j<=k;j++)
                {
                        i++;
                        if(tapes[count][j] != 0)
                                printf("%d\t",tapes[count][j]);
                }
                printf("\n");
        }
        if(flag == 1)
        {
        	printf("Memory Full.Cannot store - \t");
        	for(i = cnt;i< noOfProcess;i++)
        	{
        		printf("%d\t",len_process[i]);        	}
        	printf("\n");
        }
}





