#include <iostream>
using namespace std;

void TOH (int n, char src, char aux, char des)
{
    if (n==1)
        cout<<"Move disk 1 from "<<src<<" to "<<des<<endl;
    else
    {
        TOH (n-1,src,des,aux);
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
        TOH (n-1,aux,src,des);
    }
}

int main()
{
    int n; // Number of disks
    cout<<"Enter the number of disks: ";
    cin>>n;
    TOH (n, 'S', 'A', 'D'); // A, B and C are names of stack
    return 0;
}

