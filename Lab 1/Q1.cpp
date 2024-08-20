/*Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
a) Default Constructor Usage:
Create a default-initialized BankAccount object named account1. Print out the balance of
account1.
b) Parameterized Constructor Usage:
Create a BankAccount object named account2 with an initial balance of $1000. Print out the
balance of account2.
c) Copy Constructor Usage:
Using the account2 you created earlier, create a new BankAccount object named account3 using
the copy constructor. Deduct $200 from account3 and print out its balance. Also, print out the
balance of account2 to ensure it hasn't been affected by the transaction*/
/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
	
	private:
		double Balance;

	public:
		BankAccount()
		{
			this->Balance=0;
		}

			BankAccount(double Bal)
		{
			this->Balance=Bal;
		}

			BankAccount(BankAccount &B1)
		{
			this->Balance=B1.Balance;
		}

		void subtract ()
		{
			this-> Balance=Balance-200;
			cout<<"Balance after deduction is: "<<Balance<<endl;
	  }

		void display()
		{
			cout<<"Account Balance is $"<<Balance<<endl;
		}

};


main()
{
 BankAccount B1(675);
 B1.display();
 BankAccount B2(1000);
 B2.display();
 BankAccount B3(B2);
 B3.display();
 B3.subtract();
 B2.display();
}
