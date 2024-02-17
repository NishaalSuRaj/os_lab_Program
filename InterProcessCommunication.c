/*
        Program to Implement Inter-process Communication using message Queue using System Call
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>

struct msg
{
        int type;
        char text[100];
}*m;

int main()
{
   int msgid;
   key_t key;
   key=ftok("progfile",65);
   msgid=msgget((key_t)1777,0700|IPC_CREAT);
   if (msgid==-1)
   {
      printf("Error in creating shared memory\n");
      return 1;
   }
   m=(struct msg*)malloc(sizeof(struct msg));
   while(1)
   {
      msgrcv(msgid,m,110,0,0);
      if(m->type ==1)
      {
                int n,i,ch,count=0;
                char word[50];
                printf("Given input string  : %s \n",m->text);
                printf("\nGive the  word to  count its occurence in the input : ");
                scanf("%s",word);
                char *token=strtok(m->text," ");
                while(token!=NULL)
                {
                   if (strcmp(token,word)==0)
                   {
                      count++;
                   }
                   token=strtok(NULL," ");
                }
                printf("'%s' is occured %d times in the Input\n",word,count);


      }
      else if(m->type ==2)
      {
          int n,i,counta =0,counte=0,counti=0,counto=0,countu=0;
          printf("Given Input string  : %s\n ",m->text);
          n=strlen(m->text);
          for(i=0;i<=n;i++)
          {

             if(m->text[i]=='a'||m->text[i]=='A')
                counta++;
             if(m->text[i]==' hg   h    e'||m->text[i]=='E')
                counte++;
             if(m->text[i]=='i'||m->text[i]=='I')
                counti++;
             if(m->text[i]=='o'||m->text[i]=='O')
                counto++;
             if(m->text[i]=='u'||m->text[i]=='U')
                countu++;

          }
          printf("\tVOWELS COUNT\n");
          printf(" 'a' - %d times\n",counta);
          printf(" 'e' - %d times\n",counte);
          printf(" 'i' - %d times\n",counti);
          printf(" 'o' - %d times\n",counto);
          printf(" 'u' - %d times\n",countu);


      }
      printf("\nDo you want to continue the process \n1.Yes\n2.No\n");
      int ch;
      scanf("%d",&ch);
      if(ch==2)
         break;

   }
   msgctl(msgid,IPC_RMID,NULL);
}
