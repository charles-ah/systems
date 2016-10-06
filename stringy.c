#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen( char * );
char * mystrncpy( char *dest, char *source, int n);
char * mystrncat( char *dest, char *source, int n);
int mystrcmp( char *s1, char *s2 );
char * mystrchr( char *s, char c );

int main()
{
  char s1[256] = "hello";
  printf("my strlen: %d\n",mystrlen(s1));
  printf("library strlen: %d\n",strlen(s1));
  char s2[256];
  char s3[256];
  mystrncpy(s2,s1,2);
  *(s2+2)=0;
  strncpy(s3,s1,2);
  printf("my strncpy: %s\n",s2);
  printf("library strncpy: %s\n",s3);
  char s4[] = "world";
  char s5[256] = "hello";
  mystrncat(s1,s4,5);
  printf("my strncat: %s\n",s1);
  strncat(s5,s4,5);
 printf("library strncat: %s\n",s5);
  //  printf("%s\n",mystrncat(s1,s3,5));
  char s6[] = "aa";
  char s7[] = "ac";
  printf("my strcmp: %d\n",mystrcmp(s6,s7));
  printf("library strcmp: %d\n",strcmp(s6,s7));
  char s8[] = "my cat";
  char s9[] = "my cat";
  printf("my strchr: %s\n",mystrchr(s8,'c'));
  printf("library strchr: %s\n",strchr(s8,'c'));
  return 0;
}

char * mystrchr( char *s, char c )
{
  char *ret;
  int i=0;
  while(*(s+i)!=0)
    {
      if(*(s+i)==c)
	{
	  return s+i;
	}
      i++;
    }
  return 0;
}

int mystrlen(char* s)
{
  //  int length = 0;
  int i=0;
  while (*(s+i)!=0)
    {
      //  length++;
      i++;
    }
  return i;
}

char * mystrncpy( char *dest, char *source, int n)
{
  int i=0;
  //char temp[n+1];
  //dest = temp;
  for(;i<n;i++)
    {
      *(dest+i) = *(source+i);
    }
  //    *(dest+n)=0;
  return dest;
}

char * mystrncat( char *dest, char *source, int n)
{
  int i;
  //char temp[mystrlen(dest)+n+1];
  // printf("%s\n",dest);
  //printf("%s\n",strcpy(temp,dest));
  //strcpy(temp+mystrlen(dest)+1,source);
  int destlen = mystrlen(dest);
  for(i=0;i<n;i++)
    {
      //printf("%c\n",*(dest+mystrlen(dest)));
      *(dest+destlen+i) = *(source+i);
      //printf("%c %c\n",*(source+i),*(dest+mystrlen(dest)+i));
    }
  //*(temp+mystrlen(dest)+n)=0;
  //dest = temp;
  *(dest+destlen+n)=0;
  return dest;
}

int mystrcmp( char *s1, char *s2 )
{
  int n = 0;
  int i;
  if(mystrlen(s1)>=mystrlen(s2))
    {
      for(i=0;i<mystrlen(s2);i++)
	{
	  n = *(s1+i) - *(s2+i);
	  if(n!=0)
	    {
	      return n;
	    }
	}
    }
  if(mystrlen(s2)>=mystrlen(s1))
    {
      for(i=0;i<mystrlen(s1);i++)
	{
	  n = *(s1+i) - *(s2+i);
	  if(n!=0)
	    {
	      return n;
	    }
	}
    }
  
  return n;
  
}
