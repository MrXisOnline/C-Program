#include<stdio.h>
#include<conio.h>
#include<math.h>
 
void dec_bin(long int num)   
{
long int rem[50],i=0,length=0;
while(num>0)
 {
 rem[i]=num%2;
 num=num/2;
 i++;
 length++;
 }
printf("Binary number : ");
     for(i=length-1;i>=0;i--)
             printf("%ld",rem[i]);
}

void dec_oct(long int num)   
{
long int rem[50],i=0,length=0;
while(num>0)
 {
 rem[i]=num%8;
 num=num/8;
 i++;
 length++;
 }
printf("Octal number : ");
     for(i=length-1;i>=0;i--)
             printf("%ld",rem[i]);
}

void dec_hex(long int num)   
{
long int rem[50],i=0,length=0;
 
while(num>0)
   {
      rem[i]=num%16;
      num=num/16;
      i++;
      length++;
   }
 
printf("Hexadecimal number : ");
for(i=length-1;i>=0;i--)
  {
    switch(rem[i])
    {
      case 10:
          printf("A");
          break;
      case 11:
          printf("B");
          break;
      case 12:
          printf("C");
          break;
      case 13:
          printf("D");
          break;
      case 14:
          printf("E");
          break;
      case 15:
          printf("F");
          break;
      default :
         printf("%ld",rem[i]);
    }
  }
}

void bin_dec(long int num)   
{
long int rem,sum=0,power=0;
while(num>0)
 {
 rem = num%10;
 num = num/10;
 sum = sum + rem * pow(2,power);
 power++;
 }
 
printf("Decimal number : %d",sum);
}

void main()
{
long int num;
int choice;
 
 printf("Enter the number in decimal : ");
 scanf("%ld",&num);

 printf("What conversion you want to do, Enter no.\n");
 printf("1. Binary\n");
 printf("2. Octal\n");
 printf("3. Hexadecimal\n");
 scanf("%d", &choice);
 if (choice == 1){
     dec_bin(num);
 }else if (choice == 2)
 {
     dec_oct(num);
 }else if (choice == 3)
 {
     dec_hex(num);
 }

}