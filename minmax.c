#include<stdio.h>
void minmax(int  ,int );
int s,min,max;
int a[50];

int main()
{int i,j;
    printf("enter the size of array\n");
    scanf("%d",&s);
    for(i=0;i<s;i++)
    {
        printf("enter the %d element\n",i+1);
        scanf("%d",&a[i]);
    }
    //max=a[0];
     // min=a[0];
    minmax(0,s-1);
    printf("max is %d\n",max);
    printf("min is %d\n",min);
    return 0;
}

    void minmax(int i,int j)
    {  int mid=(i+j)/2;
      int max1,min1;

        if(i==j)  // there is only one element
        {
            min=a[i];
            max=a[i];
        }
        else if(i==j-1) //there are 2 elements
        {
            if(a[i]>a[j])
            {
                min=a[j];
                max=a[i];
            }
            else

            {
                min=a[i];
                max=a[j];
            }

        }

        else          // there are more than 2 elements
        {

           minmax(i,mid);
           max1=max;
           min1=min;

           minmax(mid+1,s-1);
           if(max1>max)
           {
               max=max1;
           }
           if(min1<min)
           {
               min=min1;
           }

        }
    }



