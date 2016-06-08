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
	string specChar = "!@#$%^&*()_-+=/'^?:,{}[]~`"; 	//this character set does not include the backslash
	int randNum;
	int setting =  2;
	char response;
	
	
	// prompt user for a length for the string
	cout << "Enter in the length of password:";
	cin >> length;
	cout << endl;
	
	cout << "Should the password contain at least one number? (Y/N)";
	cin >> response;
	
	
	// with this set up, if the password must contain at least one
	// special character, then it must contain at least one number
	if(response == 'y' || response == 'Y'){
		cout << "Should the password contain at least one special character? (Y/N)" << endl;
		cin >> response;
		if(response == 'y' || response == 'Y'){
			setting = 4;
		}
		else if(response == 'n' || response == 'N'){
			setting = 3;
		}
		else {
			//we want to throw an error here if the 
			//response is not accepted
			cout << "Incorrect entry" << endl;
		}
	}
	else if(response == 'n' || response == 'N'){
		setting = 2;
	}
	else{
		// we want to throw an error here if the 
		// response is not accepted
		cout << "Incorrect entry" << endl;
	}
	
	srand(time(0));
		
	// generate a random string given a length
	// this does not guarentee that any of these 
	// characters must be included in the string
	for(int i = 0; i < length; i++){
		randNum = rand()%setting;
		if(randNum == 0)
			password.append(&charSet[rand()%26],1);
		if(randNum == 1)
			password.append(&capCharSet[rand()%26],1);
		if(randNum == 2)
			password.append(&numSet[rand()%10],1);
		if(randNum == 3)
			password.append(&specChar[rand()%specChar.length()],1);
	}
	
	// display the output
	cout << "Password is: " << password << endl;

	// future work will include the uniqueness of each password
	
	return 0;
}