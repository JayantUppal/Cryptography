//Vignere Cypher
#include<stdio.h>
#define MAX 100

int main()
{
  char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char str[MAX], key[MAX], mat[26][26], cor_str[MAX], e_str[MAX], d_str[MAX];

  int k;
  for(int i=0;i<26;i++)
  {
    k = i;
    for(int j=0;j<26;j++)
    {
      mat[i][j] = alpha[k++];
      if(k==26)
        k=0;
    }
  }

  printf("Vignere Cypher\n``````````````\n");

  printf("Encryption table: \n");
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      printf("%c ", mat[i][j]);
    }
    printf("\n");
  }

  printf("\nNOTE: Enter string in lowercase.\n");
  printf("\nEnter the string:\n");
  scanf("%[^\n]%*c", str);

  printf("\nEnter the key:\n");
  scanf("%[^\n]%*c", key);

  //Finding length of key
  int len_key=0;
  for(int i=0;key[i]!='\0';i++)
    len_key++;

  //Finding length of string
  int len_str=0;
  for(int i=0;str[i]!='\0';i++)
    len_str++;

  //Encryption
  int j;
  k=0;
  for(int i=0;str[i]!='\0';i++)
  {
    for(j=0;j<26;j++)
    {
      if(str[i]==alpha[j])
      {
        cor_str[i] = key[k++];
        break;
      }
    }
    if(j==26)
      cor_str[i] = str[i];

    if(k==len_key)
      k=0;
  }
  cor_str[len_str] = ' ';

  int row, col;
  for(int i=0;str[i]!='\0';i++)
  {
    for(col=0;col<26;col++)
      if(cor_str[i]==alpha[col])
        break;
    for(row=0;row<26;row++)
      if(str[i]==alpha[row])
        break;
    if(row==26 && col==26)
      e_str[i] = str[i];
    else
      e_str[i] = mat[row][col];
  }
  e_str[len_str] = ' ';
  printf("\nEncrypted string: %s\n\n", e_str);
  return 0;
}






