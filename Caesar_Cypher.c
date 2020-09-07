//Caesar Cypher

#include<stdio.h>
#include<stdlib.h>

char str[100];
char estr[100], dstr[100];
char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int key;

void encryption()
{
  int temp;
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
        {
          temp=j+key;
          if(temp>25)
            temp=temp-26;

          estr[i]=alpha[temp];
        }
      }
    }
  }
  printf("Encrypted string: %s\n", estr);
}

void decryption(int key)
{
  int temp;
  printf("\n");

  for(int i=0;str[i]!='\0';i++)
  {
    if(str[i]==' ' || str[i]=='.' || str[i]==',' || str[i]=='\'' || str[i]=='\"')
      dstr[i]=str[i];
    else
    {
      for(int j=0;j<26;j++)
      {
        if(str[i]==alpha[j])
        {
          temp=j-key;
          if(temp<0)
            temp=temp+26;

          dstr[i]=alpha[temp];
        }
      }
    }
  }
  printf("Key:%d, Decrypted string: %s\n", key, dstr);
}

int main()
{
  printf("Caesar Cypher\n``````````````\n");
  printf("NOTE: Enter string in lowercase.\n");
  printf("\nEnter the string:\n");
  scanf("%[^\n]%*c", str);

  char choice;
  printf("Do you want to encrypt or decrypt? (e/d)\nYour choice: ");
  scanf("%c", &choice);

  if(choice=='e')
  {
  	printf("Enter key: ");
  	scanf("%d", &key);
    encryption();
   }
  else
  {
  	for(key = 1;key<=26;key++)
  		decryption(key);
  }
  return 0;
}
