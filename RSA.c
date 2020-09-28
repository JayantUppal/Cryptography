//RSA
//Note - Represents the plaintext message as a positive integer m such that 1<m<n
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100

int gcd(int a, int b)
{
    int temp;
    while(1)
    {
      temp = a%b;
      if(temp == 0)
        return b;
      a = b;
      b = temp;
    }
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

int main()
{
  char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char str[MAX];

  srand(time(0));  // Use current time as seed for random generator

  int P = 7, Q = 5; //Two random prime numbers

  int n = P*Q;

  int fi = (P-1)*(Q-1);

  int upper = fi - 1, lower = 2;
  int e = rand()%(upper-lower+1) + lower;
  while(e<fi)
  {
    if(gcd(e, fi)==1)
      break;
    else
      e++;
  }
  //We have our Public key (n, e)

  int d = modInverse(e, fi);
  //We have our Private key (d)

  //Encryption
  printf("RSA\n````\nEnter the string: ");
  scanf("%[^\n]%*c", str);

  //Finding length of string
  int len_str=0;
  for(int i=0;str[i]!='\0';i++)
    len_str++;

  int plain[MAX];
  for(int i=0;i<len_str;i++)
    for(int j=0;j<26;j++)
      if(str[i]==alpha[j])
        plain[i] = j+1;

  //Creating integer
  int a = 1;
  int plaintext = 0;
  for(int i=len_str-1;i>=0;i--)
  {
    plaintext += plain[i]*a;
    a *= 10;
  }

  printf("Message data: %d\n", plaintext);

  long double encrypted_data = pow(plaintext, e);
  encrypted_data = fmod(encrypted_data, n);
  printf("Encrypted data: %.0Lf\n", encrypted_data);

  long double decrypted_data = pow(encrypted_data, d);
  decrypted_data = fmod(decrypted_data, n);
  printf("Decrypted data: %.0Lf\n", decrypted_data);
}


