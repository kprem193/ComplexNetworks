#include<stdio.h>

#define node 4039
#define edges 88234

int array[node][2];

void swap(int i, int j) 
{ 
    array[i][0]=array[j][0]+array[i][0]-(array[j][0]=array[i][0]);
    array[i][1]=array[j][1]+array[i][1]-(array[j][1]=array[i][1]);
}

int partition (int low, int high) 
{ 
    int pivot = array[high][1];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (array[j][1] <= pivot) 
        { 
            i++;   
            swap(i, j); 
        } 
    } 
    swap(i + 1, high); 
    return (i + 1); 
} 

void quickSort( int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(low, high); 
  
        quickSort( low, pi - 1); 
        quickSort( pi + 1, high); 
    } 
}


int main()
{
    FILE *fp,*fp1;
    fp=fopen("facebook_combined.txt","r");

    int i,j=0,x,num;

    for( i = 0; i < node; i++)
        array[i][0]=i;
    
    for(i=0;i<edges;i++)
    {
        fscanf(fp,"%d %d",&j,&x);
        //printf("%d  %d\n",j,x);
        ++array[j][1];
        ++array[x][1];
    }
    fclose(fp);
    quickSort(0,node-1);
    fp1=fopen("degree.txt","w+");
    for(i=0;i<node;i++)
    {
        fprintf(fp1,"%d %d\n",array[i][0],array[i][1]);
    }
    fclose(fp1);
    return 0;
}
