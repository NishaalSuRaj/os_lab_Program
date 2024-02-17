 //Program to Implement Inter-process Communication using message Queue using System Call

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
struct buf
{
   int type;
   char text[100];
}*b;
int main()
{
   int msgid;
   key_t key;
   key=ftok("progfile",65);
   msgid=msgget((key_t)1777,0700|IPC_CREAT);
   if (msgid==-1)
   {
      printf("error");
      exit(0);
   }
   b=(struct buf*)malloc(sizeof(struct buf));
   printf("Give the input string\n");
   scanf("%[^\n]",b->text);
   b->type=1;
   msgsnd(msgid,b,110,0);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
struct buf
{
   int type;
   char text[100];
}*b;
int main()
{
   int msgid;
   int ch;
   key_t key;
   key=ftok("progfile",65);
   msgid=msgget((key_t)1777,0700|IPC_CREAT);
   if (msgid==-1)
   {
      printf("error");
      return 1;
   }
   b=(struct buf*)malloc(sizeof(struct buf));
   printf("Enter the input string\n");
   scanf("%[^\n]",b->text);
   b->type=2;
   msgsnd(msgid,b,110,0);
   return 0;
}
