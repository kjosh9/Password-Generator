//////////////////////////////////////////
//	Author: 	J. Knestaut
//	Date:		6/7/2016
//
//	Description:This will be a program that will generate 
// 				passwords with certain requirements and 
//				provide how unique the each password is 
//				with the likelihood that each password would
// 				be generated randomly.

#include<stdio.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

int main(int argc, char* argv[]){
	
	int length = 0;
	string password;
	string charSet = "abcdefghijklmnopqrstuvwxyz";
	string capCharSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numSet = "1234567890";
	int randNum;
	
	//prompt user for a length for the string
	cout << "Enter in the length of password:";
	cin >> length;
	cout << endl;
	
	srand(time(0));
		
	//generate a random string given a length	
	for(int i = 0; i < length; i++){
		randNum = rand()%3;
		if(randNum == 0)
			password.append(&charSet[rand()%26],1);
		if(randNum == 1)
			password.append(&capCharSet[rand()%26],1);
		if(randNum == 2)
			password.append(&numSet[rand()%10],1);
	}
	
	//display the output
	cout << "Password is: " << password << endl;	
	
	return 0;
}