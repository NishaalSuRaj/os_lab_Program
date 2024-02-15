
/*
 * Program to Build a Hierarchy using fork system call
 */

#include<stdio.h>
#include<unistd.h>
int main()
{
        int p1 = fork();
        int p2 = fork();
        if( p1 < 0 && p2 < 0)
        {
           printf("child not created\n");
        }
        if( p1 > 0 && p2 > 0)
        {
           printf("parent Id = %d \t Process Id 1 = %d \n",getppid(),getpid());
           wait(NULL);
        }
        if(p1 > 0 && p2 == 0)
         {
           printf("parent Id = %d \t Process Id 2 = %d \n",getppid(),getpid());
           wait(NULL);
           int p4 = fork();
           if( p4 == 0)
           {
                printf("parent Id = %d \t Process Id 5 = %d \n",getppid(),getpid());
                wait(NULL);
                int p5 = fork();
                int p6 = fork();
                if( p5 == 0 && p6 != 0)
                {
                   printf("parent Id = %d \t Process Id 7 = %d \n",getppid(),getpid());

                }
                if( p5 != 0 && p6 ==0)
                {
                   printf("parent Id = %d \t Process Id 8 = %d \n",getppid(),getpid());
                }
           }
         }
        if( p1 == 0 && p2 > 0)
        {
           printf("parent Id = %d \t Process Id 3 = %d \n",getppid(),getpid());
           wait(NULL);
        }
        if( p1 == 0 && p2 == 0)
        {
           printf("parent Id = %d \t Process Id 4 = %d \n",getppid(),getpid());
           wait(NULL);
        }
        int p3 = fork();
        if( p1 == 0 && p2 == 0 && p3 == 0)
        {
           printf("parent Id = %d \t Process Id 6 = %d \n",getppid(),getpid());
        }
      wait(NULL);
}
