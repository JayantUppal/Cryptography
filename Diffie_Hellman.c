#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double p, g, a, b, A, B, S_A, S_B;
	
	//Choose two prime numbers p and g(primitive root of p)
  printf("Enter modulo(p): ");
  scanf("%lf", &p);
  printf("Enter primitive root of %.0lf(q): ", p);
  scanf("%lf", &g);
  
  //Sender and Receiver selects a secret number a and b
  printf("Choose 1st secret number(Sender): ");
  scanf("%lf", &a);
  printf("Choose 2nd secret number(Receiver): ");
  scanf("%lf", &b);
  
  //Sender sends A to Receiver
  A = fmod(pow(g,a), p);
  //Receiver sends B to Sender
  B = fmod(pow(g,b), p);
 
 	//Sender caclulates S_A
  S_A = fmod(pow(B,a), p);
  //Receiver calculates S_B
  S_B = fmod(pow(A,b), p); 
 
 	//If S_A == S_B, Sender and reciever can agree for future communication
  if(S_A == S_B)
  {
 	  printf("\nSender and Receiver can communicate with each other!\n");
 	  printf("They share a secret number = %.0lf\n", S_A); 
  }
  else
  {
 	  printf("\nSender and Receiver cannot communicate with each other!\n");
  }
  return 0;
} 




