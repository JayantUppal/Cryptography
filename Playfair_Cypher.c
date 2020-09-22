//Playfair cipher
#include<stdio.h>
#define MAX 100

int main()
{
  char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char str[MAX], key[MAX], mat[5][5], e_str[MAX], rem_alpha[26];
  int i, j, k, index;

  printf("Playfair Cypher\n``````````````\n");
  printf("\nNOTE: Enter string in lowercase.\n");
  printf("\nEnter the string:\n");
  scanf("%[^\n]%*c", str);

  printf("\nEnter the key:\n");
  scanf("%s", key);

  //Finding length of key
  int len_key=0;
  for(int i=0;key[i]!='\0';i++)
    len_key++;

  //Finding length of string
  int len_str=0;
  for(int i=0;str[i]!='\0';i++)
    len_str++;


  //Remaining alphabets (Alpha-keys)
  index = 0;
  for(i=0;i<26;i++)
  {
    for(j=0;j<len_key;j++)
    {
      if(alpha[i]==key[j])
        break;
    }
    if(j==len_key)
      rem_alpha[index++] = alpha[i];
  }

  //Making and printing encryption table
  printf("\nEncryption table: \n");
  index=0;k=0;
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      if(index == len_key)
        mat[i][j] = rem_alpha[k++];
      else
        mat[i][j] = key[index++];
    }
  }
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      printf("%c ", mat[i][j]);
    }
    printf("\n");
  }

  //Dividing string into pairs and checking!
  if(len_str%2!=0)
    str[len_str]='x';

  for(i=0;str[i]!='0';i+=2)
    if(str[i]==str[i+1])
      str[i+1]='x';

  //Encryption process
  int row1, row2, col1, col2;
  for(i=0;str[i]!='\0';i+=2)
  {
    for(j=0;j<5;j++)
    {
      for(k=0;k<5;k++)
      {
          if(str[i]==mat[j][k])
          {
            row1=j;
            col1=k;
          }
          if(str[i+1]==mat[j][k])
          {
            row2=j;
            col2=k;
          }
      }
    }
    if(row1==row2)
    {
      if(col1==4)
        e_str[i] = mat[row1][0];
      else
        e_str[i] = mat[row1][col1+1];
      //For second element in pair
      if(col2==4)
        e_str[i+1] = mat[row1][0];
      else
        e_str[i+1] = mat[row1][col2+1];
    }
    if(col1==col2)
    {
      if(row1==4)
        e_str[i] = mat[0][col1];
      else
        e_str[i] = mat[row1+1][col1];
      //For second element in pair
      if(row2==4)
        e_str[i+1] = mat[0][col2];
      else
        e_str[i+1] = mat[row2+1][col2];
    }
    if(row1!=row2 && col1!=col2)
    {
      //Forming a rectangle
      e_str[i] = mat[row1][col2];
      e_str[i+1] = mat[row2][col1];
    }
  }
  printf("\nEncrypted string: %s\n", e_str);
  return 0;
}















