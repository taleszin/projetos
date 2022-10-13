/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
   double a, b, c;
    printf("Digite a primeira nota\n");
scanf ("%lf", &a);
if(a>10){
    printf("valor da nota limitado a 10 ! tente novamente\n");
    main();
}
printf("Digite a segunda nota\n");
scanf ("%lf", &b);
if(b>10){
    printf("valor da nota limitado a 10 ! tente novamente\n");
    main();
}
 printf("Digite a terceira nota\n");
scanf ("%lf", &c);
if(c>10){
    printf("valor da nota limitado a 10 ! tente novamente\n");
    main();
}
 double nota1 = a*2;
 double nota2 = b*3;
 double nota3 = c*5;
 double mediatotal = nota1 + nota2 +nota3;
double media = mediatotal/10;
printf(" a sua media é : %.1f\n" , media);
if(media >=7){
    printf("VOCE ESTA APROVADO !");
}
else
printf("VOCE ESTA REPROVADO");
    return 0;
}
