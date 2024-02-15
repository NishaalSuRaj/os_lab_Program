/* program to implement FIFO SJF Round Robin and priority Scheduling using c Program*/

#include <stdio.h>
#include <stdlib.h>
int FIFS();
int SJF();
int Priority();

void rr(int n, int quantum);
int i=0;
int i,j,temp,pid[10],burst[10],priority[10],qt[10],arrival[10],num,grat[20];
int b[10],tq;
float awt,att,wait[10],tat[10];
void display()
{
    printf("Process ID\tWaiting Time\tTurnaround Time\t Priority\n\n");
     for(i=0;i<num;i++)
         {
            printf("%d\t\t%0.2f\t\t%0.2f\t\t\t%d \n",pid[i],wait[i],tat[i],priority[i]);
            wait[i+1]=wait[i]+burst[i]-arrival[i];
            tat[i+1]=tat[i]+burst[i+1];
        }
}
void display1()
{
        printf("\nProcess ID\tWaiting Time\t Turnaround Time\t  Priority\n\n");
     for(i=0;i<num;i++)
         {
            printf("%d\t\t%0.2f\t\t%0.2f\t\t\t%d \n",pid[i],wait[i],tat[i],priority[i]);
        }
}
void reSet(){
    for(i=0;i<num;i++)
    {
        wait[i]=0;
        tat[i]=0;
        burst[i]=b[i];
        priority[i]=1;
    }
}
int main (){
         int ch,exit=0;
     for ( i=0; i<10; i++)
        {
                arrival[i]=0;
        }
        printf ("number of Process:");
        scanf ("%d",&num);
        printf ("\nburst time :");
        for (i=0;i<num;i++)
        {
                pid[i]=i+1;
                printf("\nP%d : ",i+1);
                scanf("%d",&burst[i]);
                b[i]=burst[i];
                priority[i]=1;
        }
   while(exit !=1)
   {

      printf("\n1.FCFS\n2.SJF\n3.PRIORITY\n4.ROUND ROBIN\n5.EXIT\n");
      printf("\n\nEnter a choice :");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
            {
                FIFS();

               break;
            }
        case 2:
            {
            SJF();
            break;
            }
        case 3:
            {
            Priority();
            break;
            }
                case 4:
            {
                printf("\nENTER THE TIME QUANTUM VALUE  :\n");
                scanf("%d",&tq);
                rr(num,tq);
                        break;
            }
                case 5:
            {
                        exit=1;
                        break;
            }
                default :
                {
                printf("Enter correct Choice !!!!!!");
       }
      }
    }
   return 0;
}
int FIFS()
{
        wait[0]=0.0;
        tat[0]=burst[0];
       display();
        awt=0.0;
        att=0.0;
        for(i=0;i<num;i++)
        {
            awt=awt+wait[i];
            att=att+tat[i];
        }
        printf("\nThe Average Waiting Time is %0.2f",awt/num);
        printf("\nThe Average TurnAround Time is %0.2f",att/num);
       reSet() ;
}
int SJF(void)
{
        for(i=0;i<num;i++)
        {
             for(j=i+1;j<num;j++)
             {
                 if(burst[j]<burst[i])
                 {
                        temp=burst[i];
                        burst[i]=burst[j];
                        burst[j]=temp;
                        temp=pid[i];
                        pid[i]=pid[j];
                        pid[j]=temp;
                  }
               }
         }
         wait[0]=0;
         tat[0]=burst[0];
         display();
         awt=0.0;
         att=0.0;
         for(i=0;i<num;i++)
         {
             awt=awt+wait[i];
             att=att+tat[i];
         }
         printf("\nThe Average Waiting Time is %0.2f",awt/num);
         printf("\nThe Average TurnAround Time is %0.2f",att/num);
         reSet();
}
int Priority()
{
        printf("\npriority :");
        for(i=0;i<num;i++)
        {

            printf("\nP%d : ",i+1);
            scanf("%d",&priority[i]);
        }
        for(i=0;i<num;i++)
        {
             for(j=i+1;j<num;j++)
             {
                 if(priority[j]<priority[i])
                 {
                        temp= priority[i];
                        priority[i]=priority[j];
                        priority[j]=temp;
                        temp=burst[i];
                        burst[i]=burst[j];
                        burst[j]=temp;
                        temp=pid[i];
                        pid[i]=pid[j];
                        pid[j]=temp;
                  }
               }
         }
         wait[0]=0;
         tat[0]=burst[0];
         display();
         awt=0.0;
         att=0.0;
         for(i=0;i<num;i++)
         {
             awt=awt+wait[i];
             att=att+tat[i];
         }
         printf("\nThe Average Waiting Time is %0.2f",awt/num);
         printf("\nThe Average TurnAround Time is %0.2f",att/num);
         reSet();
}
void rr(int n, int quantum)
{

        int i,total_wt=0,total_tat=0;
        int rem_bt[n],count=0,t=0;
        for ( i = 0 ; i < n ; i++)
        {
                rem_bt[i] = burst[i];
        }
        while (1)
        {
                int flag=1;
                for (i = 0;i < n;i++)
                {
                        if (rem_bt[i] > 0)
                        {
                                flag=0;
                                if (rem_bt[i] > quantum)
                                {
                                        t += quantum;
                                        rem_bt[i] -= quantum;

                                }
                                else
                                {
                                        t = t + rem_bt[i];
                                        wait[i] = t - burst[i];
                                        rem_bt[i] = 0;
                                }
                        }
                }
                if (flag==1)
                        break;
        }
                awt=0.0;
        att=0.0;
        for(i=0;i<n;i++)
        {
                tat[i]=wait[i]+burst[i];
                awt=awt+wait[i];
                att=att+tat[i];
        }
        display1();
        printf("\nThe Average Waiting Time is %0.2f",awt/num);
        printf("\nThe Average TurnAround Time is %0.2f",att/num);
        reSet();
}
