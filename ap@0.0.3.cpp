#include <iostream>

using namespace std;

float sum(float a, char c, float b)

{
    float k;
    switch (c)

    {
        case '+':
        {
            return k = a+b;
            break;
        }

        case '-':
        {
            return k = a-b;
            break;

        }
        case '*':
        {
            return k = a*b;
            break;
        }

        case '/':
        {
            if (b==0)
            {
                cout << "Can not divide by 0!";
                exit (0);
            }

            else
            {
                return k = a/b;
                break;
            }
        }

        default:
        {
            cout << "Incorrect input!";
            exit (0);
        }
    }
};

int main()
{

    short i;
    float a[3], k;
    char op[2], op1='r';

    cin >> a[0];
    cin.get(op1);

    if (op1 == '\n')
    {
        cout << a[0];
        exit (0);
    }

    cin.get(op[0]);

    sum (0, op[0], 1);

    cin.get(op1);
    cin >> a[1];
    cin.get(op1);

    if (op1 == '\n')
    {
        a[0] = sum (a[0], op[0], a[1]);
        cout << a[0];
        exit (0);
    }

    while (op1 != '\n')
    {
        i=0;
        cin.get(op[1]);

        sum (0, op[1], 1);

        cin.get(op1);
        cin >> a[2];

        if ( ( ( (op[0] == '+') || (op[0] == '-') ) && ( (op[1] == '+') || (op[1] == '-') ) ) || ( ( (op[0] == '*') || (op[0] == '/') ) && ( (op[1] == '*') || (op[1] == '/') ) ) )
        {
            a[0] = sum (a[0], op[0], a[1]);
            k = a[0];
            a[1]=a[2];
            op[0]=op[1];
            cin.get(op1);
            continue;
        }

        if ( ( (op[0] == '+') || (op[0] == '-') ) && ( (op[1] == '*') || (op[1] == '/') ) )
        {
            a[1] = sum (a[1], op[1], a[2]);
            k = a[1];
            i=1;
            cin.get(op1);
            continue;
        }

        if ( ( (op[0] == '*') || (op[0] == '/') ) && ( (op[1] == '+') || (op[1] == '-') ) )
        {
            a[0] = sum (a[0], op[0], a[1]);
            k = a[0];
            a[1] = a[2];
            op[0] = op [1];
            cin.get(op1);
            continue;
        }
    }

    if (i == 1) k = sum (a[0], op[0], k); else k = sum (k, op[1], a[1]);

    cout << k;

    return 0;
}
