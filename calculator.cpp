#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void deg2();
int main();
float sum(float a,float b)
{
    return a+b;
}
float diff(float a,float b)
{
    return a-b;
}
float product(float a,float b)
{
    return a*b;
}
float quotient(float a,float b)
{
    return a/b;
}
int rem(int a,int b)
{
    return a%b;
}
void eq2() // for solving linear equations with two variables
{
    float a[9],x,y;
    int i,n=0;
    printf("\nEnter the equation in the form of ax+by=c\n");
    for(i=0;i<6;i++)
    {
        printf("\nEnter the values for equation no.%d\n",++n);
        printf("\nCoefficient of x=");
        scanf("%f",&a[i]);
        printf("\nCoefficient of y=");
        scanf("%f",&a[++i]);
        printf("\nValue of constant=");
        scanf("%f",&a[++i]);
    }
    a[6]=a[4]*a[2]-a[1]*a[5];
    a[7]=a[0]*a[5]-a[3]*a[2];
    a[8]=a[0]*a[4]-a[3]*a[1];
    x=a[6]/a[8];
    y=a[7]/a[8];
    printf("\nx=%f\ty=%f\n",x,y);
}
void eq3() // for solving linear equations with three variables
{
    float a[16],x,y,z;
    int i,n=0;
    printf("\nEnter the equations in the form of ax+by+cz=d\n");
    for(i=0;i<12;i++)
    {
        printf("\nEnter the values for equation no.%d\n",++n);
        printf("\nCoefficient of x=");
        scanf("%f",&a[i]);
        printf("\nCoefficient of y=");
        scanf("%f",&a[++i]);
        printf("\nCoefficient of z=");
        scanf("%f",&a[++i]);
        printf("\nValue of constant=");
        scanf("%f",&a[++i]);
    }
    a[12]=(a[0]*a[5]*a[10]+a[1]*a[6]*a[8]+a[2]*a[4]*a[9])-(a[8]*a[5]*a[2]+a[4]*a[1]*a[10]+a[0]*a[9]*a[6]);
    a[13]=(a[1]*a[6]*a[11]+a[2]*a[7]*a[9]+a[3]*a[5]*a[10])-(a[9]*a[6]*a[3]+a[5]*a[2]*a[11]+a[1]*a[10]*a[7]);
    a[14]=(a[8]*a[6]*a[3]+a[4]*a[2]*a[11]+a[0]*a[10]*a[7])-(a[0]*a[6]*a[11]+a[4]*a[10]*a[3]+a[8]*a[2]*a[7]);
    a[15]=(a[0]*a[5]*a[11]+a[1]*a[7]*a[8]+a[3]*a[4]*a[9])-(a[8]*a[5]*a[3]+a[4]*a[1]*a[11]+a[0]*a[9]*a[7]);
    x=a[13]/a[12];
    y=a[14]/a[12];
    z=a[15]/a[12];
    printf("\nx=%f\ty=%f\tz=%f\n",x,y,z);
    getch();
}
void simple()
{
    int n;
    float a,b;
    smpl:
    printf("\n\nChoose an operation by pressing appropriate key:\n\n");
    printf("1.Addition                     Press 1\n");
    printf("2.Subtraction                  Press 2\n");
    printf("3.Multiplication               Press 3\n");
    printf("4.Division                     Press 4\n");
    printf("5.Remainder                    Press 5\n");
    scanf("%d",&n);
    if((n<1)||(n>5))
    {
        printf("\n\nEntered a wrong key");
        goto smpl;
    }
    printf("\nEnter the first number=\n");
    scanf("%f",&a);
    printf("\nEnter the second number=\n");
    scanf("%f",&b);
    switch(n)
    {
        case 1: printf("\nSum is %f",sum(a,b));
        break;
        case 2: printf("\nDifference is %f",diff(a,b));
        break;
        case 3: printf("\nProduct is %f",product(a,b));
        break;
        case 4: printf("\nQuotient is %f",quotient(a,b));
        break;
        case 5: printf("\nRemainder is %d",rem(a,b));
        break;
    }
}
void equation()
{
    int n,t;
    printf("\n[1]  Unknowns\t\t[2]  Degrees\n");
    eq:
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        equa:
        printf("\nEnter number of unknowns: 2 or 3\n");
        scanf("%d",&t);
        switch(t)
        {
            case 2:eq2();break;
            case 3:eq3();break;
            default:
                printf("\nPlease enter a valid number\n");
                goto equa;
        }
        break;
    case 2:
        deg2();
        break;
    default:
        printf("\nPlease enter a valid number\n");
        goto eq;
    }
}
void control()
{
    int n;
    printf("\n\n[0]  Main Menu\t\t[Any key]  Exit\n");
    scanf("%d",&n);
    if(n!=0)
    {
        exit(0);
    }
    else
    {
        system("cls");
        main();
    }
}
void deg2()
{
    double a,b,c,d,D,R;
    printf("\nEnter the coefficient of x^2 =\n");
    scanf("%lf",&a);
    printf("\nEnter the coefficient of x =\n");
    scanf("%lf",&b);
    printf("\nEnter the value of constant =\n");
    scanf("%lf",&c);
    d=b*b-4*a*c;
    if(d>=0)
    {
        D=sqrt(d);
        printf("\nRoots are real\nx = %lf , %lf ",((-b+D)/(2*a)),((-b-D)/(2*a)));
    }
    else
    {
        d = -d;
        D = sqrt(d)/(2*a);
        R = -b/(2*a);
        printf("\nRoots are imaginary\nx= %lf + %lfi , %lf - %lfi",R,D,R,D);
    }
}



int main()
{
    int n;
    printf("Welcome User\n");
    printf("Have a good day\n\n");
    mode:
    printf("\nPlease select an appropriate mode\n\n");
    printf("[1]  Simple         [2]  Equation\n\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:simple();
        break;
        case 2:equation();
        break;
        default:printf("\nEnter a valid key\n");
        goto mode;
    }
    control();
    printf("\n\n\n\n");
    return 0;
}
