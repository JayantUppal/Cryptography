//Substitution cypher
// For simplicity and to understand it's working, we have considered 6 choices instead of 26 - b, h, j, x, w, t
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

char str[100];
char estr[100], dstr[100];
char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char table[26];
char given[6] = {'b', 'h', 'j', 'x', 'w', 't'};

void encryption()
{
  for(int i=0;i<26;i++)
    table[i] = given[rand()%6];
  //Printing table
  printf("\nTable:-\n");
  for(int i=0;i<26;i++)
    printf("%c ", alpha[i]);
  printf("\n");
  for(int i=0;i<26;i++)
    printf("%c ", table[i]);
  printf("\n");
  for(int i=0;str[i]!='\0';i++)
  {
    if(str[i]==' ' || str[i]=='.' || str[i]==',' || str[i]=='\'' || str[i]=='\"')
      estr[i]=str[i];
    else
    {
      for(int j=0;j<26;j++)
      {
        if(str[i]==alpha[j])
          estr[i] = table[j];
      }
    }
  }
  printf("Encrypted string: %s\n", estr);
}

void decryption()
{
	//For length == 2 only!!! As with increase in length, the nesting would increase.
  printf("All possible decrypted strings:-\n");
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      printf("%c%c\n", alpha[i], alpha[j]);
    }
  }
}


int main()
{
  srand(time(0));  // Use current time as seed for random generator
  printf("Substitution Cypher\n````````````````````\n");
  printf("NOTE:-\n1. Enter string in lowercase.\n2. For decryption, enter only 2 letter string.\n");
  printf("\nEnter the string:\n");
  scanf("%[^\n]%*c", str);

  char choice;
  printf("Do you want to encrypt or decrypt? (e/d)\nYour choice: ");
  scanf("%c", &choice);

  if(choice=='e')
  {
  	printf("Creating table:-\n");
    encryption();
  }
  else
  {
  	decryption();
  }
  return 0;
}










