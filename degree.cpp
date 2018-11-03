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
    fp1=fopen("degree.txt","w+");
    fp=fopen("facebook_combined.txt","r");

    int i,j=0,x,temp=0,num,matrix[node+1][node+1];

    // for(i=0;i<node;i++)
    //     array[i][0]=i;
    
    for(i=0;i<edges;i++)
    {
        fscanf(fp,"%d %d",&j,&x);
        matrix[j][x]=1;
        matrix[x][j]=1;

        // if(j==temp)
        // {
        //     num++;
        // }
        // else
        // {
        //    // fprintf(fp1,"%d  %d\n",temp,num);
        //     array[temp][1]=num;
        //     num=1;
        //     temp=j;
        // }
    }
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
        {
            if(matrix[i][j]==1)
                ++num;
        }
        array[i][0]=i;
        array[i][1]=num;
        num=0;
    }
    quickSort(0,node-1);
    for(i=0;i<node;i++)
    {
        fprintf(fp1,"%d  %d\n",array[i][0],array[i][1]);
    }
    return 0;
}
