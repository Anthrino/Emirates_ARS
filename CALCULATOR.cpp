/*
This project simulates a Text based calculator-analyser written in C++.

=====================================================================================================================================
Project made by:
1.Jerin J John
2.Jay Vivarekar
=====================================================================================================================================
*/

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>
void password();
void roots();
void exit();
void sum();
void product();
void complex();
void numbersys();
void delay();
long double q;
gotoevery(int a);
int store = 0;
int a = 1;
void main()
{
    fflush(stdin);
    clrscr();
    char comment[255];
    float num, angle;
    int choice1;
    char choice;
    float a, b;
    if (a == 0)
        goto start;
    password();

    do{
    start: char str[] = "CALCULATION CENTER";
        fflush(stdin);
        textbackground(BLUE);
        textcolor(YELLOW);
        clrscr();
        cout << "\n{-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{--}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-}";
        cout << "\n\n\t\t\t     ";
        for (int i = 0; i <= 17; i++)
        {
            delay();
            cout << str[i];
        }
        cout << "\n\n\n{-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{--}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-}";
        cout << "\n\n Select the required branch :- ";
        cout << "\n\n  A:ARiTHMETiC";
        cout << "\n  B:LOGiCAL";
        cout << "\n  C:Program INFO";
        cout << "\n  D:EXiT";
        cout << "\n\n\n{-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{--}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-{-}-{+}-}";
        if (store>0)
        {
            cout << "\n To display the stored result press S / s......";
            cout << "\n Or select your choice : ";
        }
        char ch = getch();
        if (ch == 'A' || ch == 'a')
            goto arit;
        if (ch == 'B' || ch == 'b')
            goto logi;
        if (ch == 'C' || ch == 'c')
        {
            textbackground(BLACK);
            textcolor(LIGHTGREEN);
            clrscr();
            cout << "\n    Welcome to the Calculation Device........";
            getch();
            cout << "\n\n\n    This screen will guide you to the functions present in this device.";
            getch();
            cout << "\n\n    The program offers you two basic branches : ";
            getch();
            cout << "\n\n\n\n   1> ARITHMETIC....  \n\n   2> LOGICAL.....";
            getch();
            clrscr();
            cout << "\n\n\n   The Arithmetic branch consists of both basic and advanced\n   mathematical operations";
            getch();
            cout << "\n\n\n   Arithmetic operations includes:";
            getch();
            cout << "\n\n   1) Addition";
            getch();
            cout << "\n\n   2) Subtraction";
            getch();
            cout << "\n\n   3) Multiplication";
            getch();
            cout << "\n\n   4) Division";
            getch();
            cout << "\n\n   Other functions are : \n\n     Square root of a number \n\n     Logarithm of a number \n\n     Sine and cosine of an angle";
            getch();
            clrscr();
            cout << "\n\n\n\n The Logical branch consists of:";
            getch();
            cout << "\n\n\n 1) Operations on Complex Numbers\n    (Includes Basic operations on complex numbers)";
            getch();
            cout << "\n\n\n 2) Quadratic equation solver\n    (Finds the roots of a quadratic equation)";
            getch();
            cout << "\n\n\n 3) Number System Conversions\n    (Interconversions between Binary, Octal, Decimal and Hexadecimal)";
            getch();
            clrscr();
            cout << "\n\n\n\n Hope you enjoy the program ......... ";
            getch();
            cout << "\n\n\n For more queries contact the designers.....";
            getch();
            cout << "\n\n\n\n\n Project developed by :-   JERIN JOHN  and  JAY VIVAREKAR ";
            getch();
            cout << "\n\n\n\n Press Enter to return to the main menu ...... ";
            getch();
            goto start;
        }
        if (ch == 'D' || ch == 'd')
            exit();
        if (ch == 'S' || ch == 's')
        {
            cout << "\n\n ....  The stored value is = " << store;
            getch();
            clrscr();
            goto start;
        }
    arit: textbackground(BLUE);
        textcolor(WHITE);
        clrscr();
        cout << "\n\n--------------------------------------------------------------------------------";
        cout << "\n\n A:Addition";
        cout << "\n\n B:Subtraction";
        cout << "\n\n C:Multiplication";
        cout << "\n\n D:Division";
        cout << "\n\n E:More functions";
        cout << "\n\n F:Exit";
        cout << "\n\n--------------------------------------------------------------------------------";
        cout << "\n Please enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case'a':
        case'A': clrscr();
            sum();
            cout << "\n";
            break;
        case'b':
        case'B':float sub;
            textcolor(YELLOW);
            textbackground(BLACK);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n  Please enter the numbers : ";
            cin >> a >> b;
            cout << "\n\n--------------------------------------------------------------------------------";
            cout << "\n\n  The difference of the numbers is = " << a - b;
            sub = a - b;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            clrscr();
            cout << "\n\n\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n Do you want to store the result for further use .... ?  (Y/N)";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            char store0;
            store0 = getch();
            if (store0 == 'Y' || store0 == 'y')
            {
                store = sub;
                clrscr();
                cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Your result has been stored in a variable .....";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                getch();
            }
            textcolor(GREEN);
            textbackground(BLACK);
            clrscr();
            char ex2;
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press any key  ";
            cout << "\n\n--------------------------------------------------------------------------------";
            ex2 = getch();
            if (ex2 == 'Q' || ex2 == 'q')
                exit();
            else
                goto start;
        case'c':
        case'C':clrscr();
            product();
            cout << "\n";
            break;
        case'd':
        case'D':float quo;
            textcolor(YELLOW);
            textbackground(BLACK);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n Please enter the numbers : ";
            cin >> a >> b;
            cout << "\n\n The Quotient is = " << a / b;
            quo = a / b;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            clrscr();
            cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n Do you want to store the result for further use ... ?  (Y/N)";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            char store9;
            store9 = getch();
            if (store9 == 'Y' || store9 == 'y')
            {
                store = quo;
                clrscr();
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Your result has been stored in a variable ..... ";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                getch();
            }
            textcolor(GREEN);
            textbackground(BLACK);
            clrscr();
            char exi;
            cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press any key  ";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            exi = getch();
            if (exi == 'Q' || exi == 'q')
                exit();
            else
                goto start;
        case'e':
        case'E':textcolor(WHITE);
            textbackground(BLUE);
            clrscr();
        start2:cout << "\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n More functions:";
            cout << "\n\n\n 1:Find the square root of a number";
            cout << "\n\n 2:Find the logarithm of a number to base 10";
            cout << "\n\n 3:Find the sine of an angle";
            cout << "\n\n 4:Find the cosine of an angle";
            cout << "\n\n 5:Exit";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\nPlease enter your choice : ";
            cin >> choice1;
            switch (choice1)
            {
            case 1: start6 :
                textcolor(YELLOW);
                textbackground(BLACK);
                clrscr();
                cout << "\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Please enter the number : ";
                cin >> num;
                cout << "\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n The sqaure root of the number is = " << sqrt(num);
                cout << "\n\n\n--------------------------------------------------------------------------------";
                getch();
                textcolor(GREEN);
                textbackground(BLACK);
                clrscr();
                char exe;
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                exe = getch();
                if (exe == 'Q' || exe == 'q')
                    exit();
                else if (exe == 'M' || exe == 'm')
                {
                    clrscr();
                    goto start;
                }
                else if (exe == 'R' || exe == 'r')
                    goto start6;
                break;
            case 2: start8 :
                textcolor(YELLOW);
                textbackground(BLACK);
                clrscr();
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Please enter the number : ";
                cin >> num;
                cout << "\n\n--------------------------------------------------------------------------------";
                cout << "\n\n The logarithm of the number to the base 10 is = " << log10(num);
                cout << "\n\n\n--------------------------------------------------------------------------------";
                getch();
                textcolor(GREEN);
                textbackground(BLACK);
                clrscr();
                char exd;
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
                cout << "\n\n--------------------------------------------------------------------------------";
                exd = getch();
                if (exd == 'Q' || exd == 'q')
                    exit();
                else if (exd == 'M' || exd == 'm')
                {
                    clrscr();
                    goto start;
                }
                else if (exd == 'R' || exd == 'r')
                    goto start8;
                break;
            case 3: start5 :
                textcolor(YELLOW);
                textbackground(BLACK);
                clrscr();
                cout << "\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Please enter the angle in degrees ";
                cin >> angle;
                angle /= 57.2;
                cout << "\n\n--------------------------------------------------------------------------------";
                cout << "\n\n The sine of the angle (approx.) = " << sin(angle);
                cout << "\n\n--------------------------------------------------------------------------------";
                getch();
                textcolor(GREEN);
                textbackground(BLACK);
                clrscr();
                char exc;
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                exc = getch();
                if (exc == 'Q' || exc == 'q')
                    exit();
                else if (exc == 'M' || exc == 'm')
                {
                    clrscr();
                    goto start;
                }
                else if (exc == 'R' || exc == 'r')
                    goto start5;
                break;
            case 4: start7 :
                textcolor(YELLOW);
                textbackground(BLACK);
                clrscr();
                cout << "\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n Please enter the angle in degrees : ";
                cin >> angle;
                angle /= 57.2;
                cout << "\n\n--------------------------------------------------------------------------------";
                cout << "\n\n The cosine of the angle (approx.) = " << cos(angle);
                cout << "\n\n--------------------------------------------------------------------------------";
                getch();
                textcolor(GREEN);
                textbackground(BLACK);
                clrscr();
                char exf;
                cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                exf = getch();
                if (exf == 'Q' || exf == 'q')
                    exit();
                else if (exf == 'M' || exf == 'm')
                {
                    clrscr();
                    goto start;
                }
                else if (exf == 'R' || exf == 'r')
                    goto start7;
                break;
            case 5:  exit();
            default:textcolor(GREEN);
                textbackground(BLACK);
                clrscr();
                cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
                cout << "\n\n\n Please enter a valid choice ....... ";
                cout << "\n\n\n--------------------------------------------------------------------------------";
                getch();
                clrscr();
                goto start2;
            }
        case'f':
        case'F':    exit();
        }
    } while (choice != 'f' || choice != 'F');


    do{
    logi:star : fflush(stdin);
        textbackground(GREEN);
        textcolor(BLUE);
        clrscr();
        cout << "\n\n\n--------------------------------------------------------------------------------";
        cout << "\n                         ";
        char str2[] = "LOGICAL OPERATIONS CENTRE";
        for (int k = 0; k<25; k++)
        {
            delay();
            cout << str2[k];
        }
        cout << "\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n A: Operations related to Complex Numbers";
        cout << "\n\n B: Quadratic equation solver";
        cout << "\n\n C: Number System Conversions";
        cout << "\n\n D: Main Menu  ";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        char choice4;
        cout << "\n\n Enter your choice : ";
        cin >> choice4;
        switch (choice4)
        {
        case'a':
        case'A':complex();
            break;

        case'b':
        case'B':roots();
            break;
        case'c':
        case'C':numbersys();

        case'd':
        case'D':goto start;

        default:goto star;
        }

    }

    while (choice != 'f' || choice != 'F');

}


void password()
{
    textcolor(LIGHTGREEN);
    textbackground(1);
    clrscr();
    char useract[100] = { "interpol101" };
    char passact[10] = { "cpp" };
    char userent[100];
    char passent[10];
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\n                    ";
    char str6[] = "ENTER YOUR USERNAME AND ACCESS PASSWORD";
    for (int k1 = 0; k1 <= 38; k1++)
    {
        delay();
        cout << str6[k1];
    }
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n\t\t            ";
    char str7[] = "Username : ";
    for (k1 = 0; k1 <= 10; k1++)
    {
        delay();
        cout << str7[k1];
    }
    cin >> userent;
    if (strcmp(useract, userent) != 0)
    {
        textbackground(BLACK);
        textcolor(RED + BLINK);
        clrscr();
        cout << " \n\n\n\n\n\n\t Incorrect Username ...... ACCESS DENIED           ";
        getch();
        exit(0);
    }
    cout << " \n\t\t            ";
    char str8[] = "Password : ";
    for (k1 = 0; k1 <= 10; k1++)
    {
        delay();
        cout << str8[k1];
    }
    for (int i = 0; i<3; i++)
    {
        passent[i] = getch(); cout << "*";
    }
    if (strcmp(passact, passent) == 0)
    {
        textbackground(BLACK);
        textcolor(RED + BLINK);
        clrscr();
        cout << " \n\n\n\n\n\n                 Incorrect Password ...... ACCESS DENIED           ";
        getch();
        exit(0);
    }
    else
    {
        textbackground(BLACK);
        textcolor(YELLOW + BLINK);
        clrscr();
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n              >>>>    >>>>      ACCESS GRANTED      <<<<    <<<<    \n\n\n";
    }
    cout << "\n--------------------------------------------------------------------------------";
    a = 0;
    getch();
    clrscr();
}
void sum()
{
    textbackground(BLACK);
    textcolor(YELLOW);
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    int n;
    int i;
    int num[60];
    long int sum;
    cout << "\n\n Enter the no. of numbers to be added :  ";
    cin >> n;
    sum = 0;
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Please enter the numbers : ";
    for (i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum = sum + num[i];
    }
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n The sum is = " << sum;
    cout << "\n\n--------------------------------------------------------------------------------";
    if (store>0)
        cout << "\n\n To use stored result in additon .... press U / u";
    cout << "\n\n--------------------------------------------------------------------------------";
    char store1;
    store1 = getch();
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    if (store1 == 'U' || store1 == 'u')
    {
        sum = sum + store;
        cout << "\n\n The resultant sum is = " << sum;
        cout << "\n\n--------------------------------------------------------------------------------";
        getch();
    }
    clrscr();
    cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n  Do you want to store the result for further use ....  ?  (Y/N)  ";
    cout << "\n\n\n--------------------------------------------------------------------------------";
    char store2;
    store2 = getch();
    if (store2 == 'Y' || store2 == 'y')
    {
        store = sum;
        clrscr();
        cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n Your result has been stored in a variable .... ";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        getch();
    }
    textbackground(BLACK);
    textcolor(GREEN);
    clrscr();
    fflush(stdin);
    char ex;
    cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press any key  ";
    cout << "\n\n\n--------------------------------------------------------------------------------";
    ex = getch();
    if (ex == 'Q' || ex == 'q')
        exit();
    else
        gotoevery(2);
}



void product()
{
    fflush(stdin);
    textbackground(BLACK);
    textcolor(YELLOW);
    clrscr();
    cout << "\n\n\n--------------------------------------------------------------------------------";
    int n;
    int i;
    int num[60];
    long product;
    cout << "\n\n How many numbers do you want to multiply : ";
    cin >> n;
    cout << "\n\n--------------------------------------------------------------------------------";
    product = 1;
    cout << "\n\n Please enter the numbers : ";
    for (i = 0; i<n; i++)
    {
        cin >> num[i];
        product = product*num[i];
    }
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n The product is = " << product;
    cout << "\n\n--------------------------------------------------------------------------------";
    if (store>0)
        cout << "\n\n To use stored result for multiplication .... press U / u";
    char store2;
    store2 = getch();
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    if (store2 == 'U' || store2 == 'u')
    {
        product *= store;
        cout << "\n\n The new result is = " << product;
        cout << "\n\n--------------------------------------------------------------------------------";
        getch();
    }
    clrscr();
    cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Do you want to store the result for further use ....  ?  (Y/N) .....";
    cout << "\n\n--------------------------------------------------------------------------------";
    char store6;
    store6 = getch();
    if (store6 == 'Y' || store6 == 'y')
    {
        store = product;
        textcolor(RED);
        textbackground(BLACK);
        clrscr();
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n Your result has been stored in a variable .... ";
        cout << "\n\n--------------------------------------------------------------------------------";
        getch();
    }
    textcolor(GREEN);
    textbackground(BLACK);
    clrscr();
    fflush(stdin);
    char ex3;
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press any key  ";
    cout << "\n\n\n--------------------------------------------------------------------------------";
    ex3 = getch();
    if (ex3 == 'Q' || ex3 == 'q')
        exit();
    else
        gotoevery(2);
    clrscr();
}


void roots()
{
startf:
    fflush(stdin);
    textbackground(BLACK);
    textcolor(MAGENTA);
    clrscr();
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n                          ";
    char str4[] = "QUADRATIC EQUATION SOLVER";
    for (int k4 = 0; k4 <= 24; k4++)
    {
        delay();
        cout << str4[k4];
    }

    cout << "\n\n--------------------------------------------------------------------------------";
    float a, b, c;
    float r1, r2, temp, term;
    cout << "\n\n Please enter the coefficients for the standard equation ( ax^2 + bx + c ) : \n\n";
    cin >> a >> b >> c;
    cout << "\n\n--------------------------------------------------------------------------------";
    temp = 2 * a;
    term = (b*b) - (4 * a*c);
    if (term == 0)
    {
        cout << " The roots are real and equal";
        r1 = (-b + sqrt(term)) / temp;
        r2 = (-b - sqrt(term)) / temp;
        cout << "\n--------------------------------------------------------------------------------";
        cout << "\n The roots are =  " << r1 << "  " << r2;
        cout << "\n\n--------------------------------------------------------------------------------";

    }
    else
    {
        if (term>0)
        {
            cout << " The roots are real and distinct";
            r1 = (-b + term) / temp;
            r2 = (-b - term) / temp;
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n The roots are =  " << r1 << "  " << r2;
            cout << "\n\n--------------------------------------------------------------------------------";

            getch();
        }
        else
        {
            cout << "\n...The roots are imaginary";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            getch();
        }
        clrscr();
        fflush(stdin);
        char exg;
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        exg = getch();
        if (exg == 'Q' || exg == 'q')
            exit();
        else if (exg == 'M' || exg == 'm')
            gotoevery(2);
        else if (exg == 'R' || exg == 'r')
            goto startf;

    }
}


void complex()
{
start1:
    fflush(stdin);
    textbackground(BLUE);
    textcolor(WHITE);
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n                  ";
    char str0[] = "COMPLEX NUMBER OPERATIONS CENTRE";
    for (int k3 = 0; k3 <= 31; k3++)
    {
        delay();
        cout << str0[k3];
    }

    cout << "\n\n--------------------------------------------------------------------------------";
    float real, imag, real1, imag1, real2, imag2;
    cout << "\n Enter the complex number (a+ib format) as instructed below : ";
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Enter the real part : ";
    cin >> real;
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Enter the imaginary part : ";
    cin >> imag;
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n                <)*(>   COMPLEX NUMBER OPERATIONS CENTRE   <)*(>                 ";
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n Enter the second complex number as instructed : ";
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Enter the real part : ";
    cin >> real1;
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Enter the imaginary part : ";
    cin >> imag1;
    clrscr();
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n                 <)*(>   COMPLEX NUMBER OPERATIONS CENTRE   <)*(>        ";
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n Select the required operation : ";
    cout << "\n\n A:Addition";
    cout << "\n\n B:Subtraction";
    cout << "\n\n C:Multiplication";
    cout << "\n\n D:Division";
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Enter here : ";
    char ch3;
    cin >> ch3;
    switch (ch3)
    {
    case'a':
    case'A': textcolor(CYAN);
        textbackground(BLACK);
        clrscr();
        real2 = real + real1;
        imag2 = imag + imag1;
        cout << "\n\n\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n The sum of these complex numbers is : " << real2 << "+(i" << imag2 << ")";
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        textbackground(BLACK);
        textcolor(GREEN);
        clrscr();
        fflush(stdin);
        char ex3;
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        ex3 = getch();
        if (ex3 == 'Q' || ex3 == 'q')
            exit();
        else if (ex3 == 'M' || ex3 == 'm')
        {
            gotoevery(2);
        }
        else if (ex3 == 'R' || ex3 == 'r')
            goto start1;


    case 'b':
    case 'B':textcolor(CYAN);
        textbackground(BLACK);
        clrscr();
        real2 = real - real1;
        imag2 = imag - imag1;
        cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n The difference of these complex numbers is :  " << real2 << "+(i" << imag2 << ")";
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        textbackground(BLACK);
        textcolor(GREEN);
        clrscr();
        fflush(stdin);
        char ex4;
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        ex4 = getch();
        if (ex4 == 'Q' || ex4 == 'q')
            exit();
        else if (ex4 == 'M' || ex4 == 'm')
        {
            gotoevery(2);
        }
        else if (ex4 == 'R' || ex4 == 'r')
            goto start1;
        break;

    case 'c':
    case 'C':textcolor(CYAN);
        textbackground(BLACK);
        clrscr();
        real2 = ((real*real1) - (imag*imag1));
        imag2 = ((real*imag1) + (imag*real1));
        cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n The product of the complex numbers is :  " << real2 << "+(i" << imag2 << ")";
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        textbackground(BLACK);
        textcolor(GREEN);
        clrscr();
        fflush(stdin);
        char ex5;
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        ex5 = getch();
        if (ex5 == 'Q' || ex5 == 'q')
            exit();
        else if (ex5 == 'M' || ex5 == 'm')
        {
            gotoevery(2);
        }
        else if (ex5 == 'R' || ex5 == 'r')
        {
            clrscr();
            goto start1;
        }

    case'd':
    case'D':textcolor(CYAN);
        textbackground(BLACK);
        clrscr();
        float temp, temp1, temp2 = 0;
        temp = ((real*real) + (real1*real1));
        temp1 = ((real*real1) + (imag*imag1));
        temp2 = ((real*imag1) - (real1*imag));
        real2 = temp1 / temp;
        imag2 = temp2 / temp;
        cout << "\n\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n The division of the complex numbers is : " << real2 << "+(i" << imag2 << ")";
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        textbackground(BLACK);
        textcolor(GREEN);
        clrscr();
        fflush(stdin);
        char exh;
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
        cout << "\n\n\n--------------------------------------------------------------------------------";
        exh = getch();
        if (exh == 'Q' || exh == 'q')
            exit();
        else if (exh == 'M' || exh == 'm')
        {
            gotoevery(2);
        }
        else if (exh == 'R' || exh == 'r')
        {
            clrscr();
            goto start1;
        }
        break;
    }
}

void numbersys()
{
    fflush(stdin);
    textbackground(MAGENTA);
    textcolor(YELLOW);
    clrscr();
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n                          ";
    char str9[] = "NUMBER SYSTEM OPERATIONS";
    for (int k2 = 0; k2 <= 23; k2++)
    {
        delay();
        cout << str9[k2];
    }
    cout << "\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Select the required type of conversion :- ";
    cout << "\n\n A: Decimal <--> Binary ";
    cout << "\n B: Decimal <--> Octal ";
    cout << "\n C: Decimal <--> HexaDecimal ";
    cout << "\n D: Exit  \n\n";
    cout << "\n\n--------------------------------------------------------------------------------";
    char ch10;
    ch10 = getch();
    switch (ch10)
    {
    case'a':
    case'A': start2 : fflush(stdin);
        textbackground(GREEN);
        textcolor(BLACK);
        clrscr();
        cout << "\n\n\n--------------------------------------------------------------------------------";
        cout << "\n Select required conversion :- ";
        cout << "\n\n A: Decimal --> Binary ";
        cout << "\n B: Decimal <-- Binary ";
        char erre;
        erre = getch();
        if (erre == 'a' || erre == 'A')
        {
            fflush(stdin);
            cout << "\n\n\n--------------------------------------------------------------------------------";
            int dec;
            long int bin;
            cout << "\n\n Enter the Decimal Number : ";
            cin >> dec;
            cout << "\n\n--------------------------------------------------------------------------------";
            int b, i = 0;
            bin = 0;
            while (dec>0)
            {
                b = dec % 2;
                bin = bin + (b*pow(10, i));
                i++;
                dec = dec / 2;
            }
            cout << "\n\n Binary Equivalent : " << bin;
            getch();
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            char ex6;
            ex6 = getch();
            if (ex6 == 'Q' || ex6 == 'q')
                exit();
            else if (ex6 == 'M' || ex6 == 'm')
            {
                gotoevery(2);
            }
            else if (ex6 == 'R' || ex6 == 'r')
                goto start2;

        }
        if (erre == 'b' || erre == 'B')
        {
            fflush(stdin);
            cout << "\n\n\n--------------------------------------------------------------------------------";
            int dec1;
            long int bin1;
            cout << "\n\n Enter the Binary Number : ";
            cin >> bin1;
            cout << "\n\n--------------------------------------------------------------------------------";
            int b1, i1 = 0;
            dec1 = 0;
            while (bin1>0)
            {
                b1 = bin1 % 10;
                dec1 = dec1 + (b1*pow(2, i1));
                i1++;
                bin1 = bin1 / 10;
            }
            cout << "\n\n Decimal Equivalent : " << dec1;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            char ex7;
            ex7 = getch();
            if (ex7 == 'Q' || ex7 == 'q')
                exit();
            else if (ex7 == 'M' || ex7 == 'm')
            {
                gotoevery(2);
            }
            else if (ex7 == 'R' || ex7 == 'r')
                goto start2;
            break;

        }
    case'b':
    case'B': start3 :
        fflush(stdin);
        textbackground(GREEN);
        textcolor(BLACK);
        clrscr();
        cout << "\n\n\n--------------------------------------------------------------------------------";
        cout << "\n Select required conversion :- ";
        cout << "\n\n A: Decimal --> Octal ";
        cout << "\n B: Decimal <-- Octal ";
        char erre1;
        erre1 = getch();
        if (erre1 == 'a' || erre1 == 'A')
        {
            cout << "\n\n\n--------------------------------------------------------------------------------";
            int dec2;
            long int oct;
            cout << "\n\n Enter the Decimal Number : ";
            cin >> dec2;
            cout << "\n\n--------------------------------------------------------------------------------";
            int b2, i = 0;
            oct = 0;
            while (dec2>0)
            {
                b2 = dec2 % 8;
                oct = oct + (b2*pow(10, i));
                i++;
                dec2 = dec2 / 8;
            }
            cout << "\n Octal Equivalent : " << oct;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n--------------------------------------------------------------------------------";
            char ex8;
            ex8 = getch();
            if (ex8 == 'Q' || ex8 == 'q')
                exit();
            else if (ex8 == 'M' || ex8 == 'm')
            {
                clrscr();
                gotoevery(2);
            }
            else if (ex8 == 'R' || ex8 == 'r')
                goto start3;

        }
        if (erre1 == 'b' || erre1 == 'B')
        {
            cout << "\n\n\n-------------------------------------------------------------------------------";
            int dec3 = 0;
            long int oct1;
            cout << "\n Enter the Octal Number : ";
            cin >> oct1;
            cout << "\n\n--------------------------------------------------------------------------------";
            int b3, i2 = 0;
            dec3 = 0;
            while (oct1>0)
            {
                b3 = oct1 % 10;
                dec3 = dec3 + (b3*pow(8, i2));
                i2++;
                oct1 = oct1 / 10;
            }
            cout << "\n Decimal Equivalent : " << dec3;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            fflush(stdin);
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n--------------------------------------------------------------------------------";
            char ex9;
            ex9 = getch();
            if (ex9 == 'Q' || ex9 == 'q')
                exit();
            else if (ex9 == 'M' || ex9 == 'm')
            {
                gotoevery(2);
            }
            else if (ex9 == 'R' || ex9 == 'r')
                goto start3;



        }
    case'c':
    case'C': start4 :
        fflush(stdin);
        textbackground(GREEN);
        textcolor(BLACK);
        clrscr();
        cout << "\n\n\n--------------------------------------------------------------------------------";
        cout << "\n Select required conversion :- ";
        cout << "\n\n A: Decimal --> HexaDecimal ";
        cout << "\n B: Decimal <-- HexaDecimal ";
        char erre2;
        erre2 = getch();
        if (erre2 == 'a' || erre2 == 'A')
        {
            textcolor(BLACK);
            clrscr();
            cout << "\n\n\n-----------------------------------------------------------------------------";
            int deci2;
            cout << "\n\n Enter the Decimal Number : ";
            cin >> deci2;
            cout << "\n\n--------------------------------------------------------------------------------";
            cout << "\n\n HexaDecimal Equivalent : " << hex << deci2;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            char exa;
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            exa = getch();
            if (exa == 'Q' || exa == 'q')
                exit();
            else if (exa == 'M' || exa == 'm')
            {
                gotoevery(2);
            }
            else if (exa == 'R' || exa == 'r')
                goto start4;
            break;
        }
        if (erre2 == 'b' || erre2 == 'B')
        {
            fflush(stdin);
            textcolor(BLACK);
            clrscr();
            cout << "\n\n\n-------------------------------------------------------------------------------";
            char hex2[50];
            int deci2 = 0;
            cout << "\n Enter the HexaDecimal Number : ";
            gets(hex2);
            cout << "\n\n--------------------------------------------------------------------------------";
            int a32 = strlen(hex2);
            int k = a32 - 1;
            int o = 0;
            int r, p;
            while (o<a32)
            {
                if (hex2[k] == 'a' || hex2[k] == 'A')
                    r = 10;
                else if (hex2[k] == 'b' || hex2[k] == 'B')
                    r = 11;
                else if (hex2[k] == 'c' || hex2[k] == 'C')
                    r = 12;
                else if (hex2[k] == 'd' || hex2[k] == 'D')
                    r = 13;
                else if (hex2[k] == 'e' || hex2[k] == 'E')
                    r = 14;
                else if (hex2[k] == 'f' || hex2[k] == 'F')
                    r = 15;
                else if (hex2[k] == '0')
                    r = 0;
                else if (hex2[k] == '1')
                    r = 1;
                else if (hex2[k] == '2')
                    r = 2;
                else if (hex2[k] == '3')
                    r = 3;
                else if (hex2[k] == '4')
                    r = 4;
                else if (hex2[k] == '5')
                    r = 5;
                else if (hex2[k] == '6')
                    r = 6;
                else if (hex2[k] == '7')
                    r = 7;
                else if (hex2[k] == '8')
                    r = 8;
                else
                    r = 9;
                p = pow(16, o);
                deci2 = deci2 + (r*p);
                k--;
                o++;
            }
            cout << "\n\n Decimal Equivalent : " << deci2;
            cout << "\n\n--------------------------------------------------------------------------------";
            getch();
            deci2 = 0;
            textbackground(BLACK);
            textcolor(GREEN);
            clrscr();
            cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
            char exb;
            cout << "\n\n\n To Exit ..... Press Q / q \n\n To return to Main Menu .....Press M / m\n\n To restart this function press R / r";
            cout << "\n\n\n--------------------------------------------------------------------------------";
            exb = getch();
            if (exb == 'Q' || exb == 'q')
                exit();
            else if (exb == 'M' || exb == 'm')
            {
                gotoevery(2);
            }
            else if (exb == 'R' || exb == 'r')
                goto start4;
        }
    case 'd':
    case 'D':goto start2;
    }

}


gotoevery(int a)
{
    return a;
}

void exit()
{
    textcolor(RED);
    textbackground(BLACK);
    clrscr();
    char comment;
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Please enter your valuable comments below : ";
    cin >> comment;
    cout << "\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n Thank you for your comments.........";
    getch();
    textcolor(YELLOW);
    clrscr();
    cout << "\n\n\n\n\n\n\n--------------------------------------------------------------------------------";
    cout << "\n\n\n\n            ";
    char str1[] = "Developed by Intel Inc >>.>>.>> Sponsers of tommorow";
    for (int j = 0; j <= 51; j++)
    {
        delay();
        //cout<<str1[j];}
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        textcolor(GREEN + BLINK);
        clrscr();
        cout << "\n\n\n\n\n--------------------------------------------------------------------------------";
        cout << "\n\n\n Chief Designers :- \n\n = Jay.M.Vivarekar \n\n = Jerin John";
        cout << "\n\n\n\n--------------------------------------------------------------------------------";
        getch();
        exit(0);
    }
    void delay()
    {
        for (q = 0; q <= 300000; q++)
        {
        }
    }