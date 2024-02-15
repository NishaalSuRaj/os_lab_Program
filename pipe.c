/*
 * Program to write a set of numbers into a pipe by parent process
                and child data fron pipe and write numbers into another pipe
 */

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int checkprime(int n);
main()
{
        int p2,p3;
        int i,n,j;
        printf("Enter the array size : ");
        scanf("%d",&n);
        int a[n];
        int fd1[2],fd2[2];
        printf("Enter the array Element \n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        pipe(fd1);
        p2=fork();
        if(p2<0)
        {
                printf("Unsuccessfull");
        }
        else
        {
                if(p2==0)
                {
                        read(fd1[0],&a,sizeof(int));
                        close(fd1[1]);
                        int j,k=0;
                        int arr[10];
                        for(i=0;i<n;i++)
                        {
                            j = checkprime(a[i]);
                            if (j == 0)
                            {
                                arr[k]=a[i];
                                k++;
                            }
                        }

                        int p3=fork();
                        if(p3==0)
                        {
                                 read(fd2[0],&arr,sizeof(int));
                                close(fd2[1]);
                                int l;
                                for(l=0;l<k;l++)
                                {
                                    printf("%d\t",arr[l]);
                                }
                        }
                        else
                        {
                                pipe(fd2);
                                write(fd2[1],&arr,sizeof(int));
                                close(fd2[0]);
                                wait(NULL);
                        }

                }
                else{
                    close(fd1[0]);
                    write(fd1[1],&a,sizeof(int));
                    close(fd1[1]);
                }


        }
}
int checkprime(int n)
{
        int d;
        if(n==2)
                return 0;
        else{
                for(d=2;d<=n/2;d++)
                {
                    if(n%d==0)
                         return 1;
                }
                return 0 ;
        }
}
