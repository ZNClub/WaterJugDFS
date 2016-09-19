
#include <iostream>

using namespace std;

class Jug{
  int capacity;
	int value;
public:
	Jug(int n)
	{
		capacity = n;
		value = 0;
	}

	void Fill()
	{
		value = capacity;
	}

	void Empty()
	{
		value = 0;
	}

	bool isFull()
	{
		return value >= capacity;
	}

	bool isEmpty()
	{
		return value == 0;
	}

	//A[B] -> Transfer contents of B to A until A is full
	void operator[](Jug &B)
	{
		int old_value = value;

		value = value + B.value;
		value = value > capacity?capacity:value;

		B.value = B.value - (value - old_value);
	}

	int getValue()
	{
		return value;
	}
};


int gcd(int n,int m)
{
	if(m<=n && n%m == 0)
		return m;
	if(n < m)
		return gcd(m,n);
	else
		return gcd(m,n%m);
}

bool check(int a,int b,int c){
    //boundary cases
	if(c>a){
		cout<<"A can't hold more water than it's capacity!\n";
        return false;
    }
    //if c is multiple of HCF of a and b, then possible
    if(c % gcd(a,b) == 0){
        return true;
    }
    //if c is not multiple of HCF of a and b, then not possible
	cout<<"Can't reach this state with the given jugs\n";
    return false;
}

void solve(Jug A, Jug B, int result)
{
	while(A.getValue() != result)
	{
		if(!A.isFull() && B.isEmpty()){
			cout<<"Fill B\n";
			B.Fill();
			cout << "(A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
		}
		if(A.isFull()){
			cout<<"Empty A\n";
			A.Empty();
			cout << "(A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
		}
		cout<<"Pour from B into A\n";
		A[B];
		cout << "(A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
	}
}

int main()
{
	int a, b, result;

	cout<<"Enter capacity of A\n";
	cin >> a;
	cout<<"Enter capacity of B\n";
	cin >> b;

	do{
	cout<<"Enter required water in A:\n";
	cin >> result;
	}
	while(!check(a,b,result));

	Jug A(a), B(b);

	cout << "\n(A, B) = (" << A.getValue() << ", " << B.getValue() << ")\n";
	solve(A, B, result);
	cout<<"Done!"<<endl;

	//#ifdef _WIN32
	//system("pause");
	//#endif

	return 0;
}

/*
Output :
Enter capacity of A
4
Enter capacity of B
3
Enter required water in A:
2
(A, B) = (0, 0)
Fill B
(A, B) = (0, 3)
Pour from B into A
(A, B) = (3, 0)
Fill B
(A, B) = (3, 3)
Pour from B into A
(A, B) = (4, 2)
Empty A
(A, B) = (0, 2)
Pour from B into A
(A, B) = (2, 0)
Done!
Process returned 0 (0x0)
execution time : 4.460 s
Press any key to continue.
*/
