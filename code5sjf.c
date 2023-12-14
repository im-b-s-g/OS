#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sortat(int p[],int at[],int bt[],int n){
for (int i=1;i<n;i++){
    for (int j=1;j<n;j++){
        if(at[j]>at[j+1]){
         swap(&p[i], &p[j]);
		swap(&at[i], &at[j]);
		swap(&bt[i], &bt[j]);
        }
        else if(at[j]==at[j+1]){
             if(bt[i]>bt[j]){
                 swap(&p[i], &p[j]);
                 swap(&at[i], &at[j]);
                 swap(&bt[i], &bt[j]);
        }
    }
}
}
}


void tatwt( int ct[], int at[], int bt[], int tat[], int wt[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
	tat[i]=ct[i]-at[i];
	wt[i]=tat[i]-bt[i];
   }
}


int main()
{
    int *p,*at,*bt,*ct,*tat,*wt,pos,i,j,min=1000,n;
    float atat=0,awt=0;
    printf("Enter the number of Processes\n");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    at=(int *)malloc(n*sizeof(int));
    bt=(int *)malloc(n*sizeof(int));
    ct=(int *)malloc(n*sizeof(int));
    wt=(int *)malloc(n*sizeof(int));
    tat=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
   printf("Enter the process %d \n",i+1);
   scanf("%d",&p[i]);
   printf("Enter the arrival time of %d\n",i+1);
   scanf("%d",&at[i]);
   printf("Enter the burst time of %d\n",i+1);
   scanf("%d",&bt[i]);
    }
    sortat(p,at,bt,n);
    ct[0]=at[0]+bt[0];
    for (int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            if (at[j]<=ct[i-1]){
                if(bt[j]<min)
                {                                                           
                    min=bt[j];
                    pos=j;
                }
            }
        }
         swap(&p[i], &p[pos]);
    swap(&at[i], &at[pos]);
    swap(&bt[i], &bt[pos]);
    min=1000;
    ct[i]=ct[i-1]+bt[i];
  }
        
    printf("\np\t at\t bt\t ct\t tat\t wt"); 
    for(i=0;i<n;i++)
    {
    printf("\n%d\t %d\t %d\t %d\t %d\t %d",p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
     }
     for(i=0;i<n;i++)
     { 
     atat+=tat[i];
     awt+=wt[i];
    }
  // average turnaround time and average waiting time
  atat=atat/n;
  awt=awt/n;
  printf("\n avg tat=%.2f and avg wt=%.2f",atat, awt); 
  return 0;
}



