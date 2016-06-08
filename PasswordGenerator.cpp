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
#include<iomanip>

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
	bool PassWorks = false;
	bool ContainsLower = false;
	bool ContainsUpper = false;
	bool ContainsNum = false;
	bool ContainsSpec = false;
	int chance = 1;
	
	
	//prompt user for a length for the string
	cout << "Enter in the length of password:";
	cin >> length;
	cout << endl;
	
	cout << "Should the password contain at least one number? (Y/N)";
	cin >> response;
	
	
	//with this set up, if the password must contain at least one
	//special character, then it must contain at least one number
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
		//we want to throw an error here if the 
		//response is not accepted
		cout << "Incorrect entry" << endl;
	}
	
	srand(time(0));
		
	//need to find a better way to handle this error
	if(length < setting){
		cout << "The specified length of password is too small";
		return 0;
	}
		
	//generate a random string given a length
	//this structure will gaurentee that the password meets
	//the specifications provided by the user. 
	while (PassWorks == false && length >= setting){
		
		//start with a cleared password
		password = "";
		
		for(int i = 0; i < length; i++){
			randNum = rand()%setting;
			if(randNum == 0){
				password.append(&charSet[rand()%26],1);
				ContainsLower = true;
			}
			if(randNum == 1){
				password.append(&capCharSet[rand()%26],1);
				ContainsUpper = true;
			}
			if(randNum == 2){
				password.append(&numSet[rand()%10],1);
				ContainsNum = true;
			}
			if(randNum == 3){
				password.append(&specChar[rand()%specChar.length()],1);
				ContainsSpec = true;
			}
		}
		
		//checks to make sure that the password includes all of the 
		//requirements specified by the user
		switch(setting){
			case 2: if(ContainsLower == true && ContainsUpper == true)
						PassWorks = true;
					break;
					
			case 3: if(ContainsLower == true && ContainsUpper == true && ContainsNum == true)
						PassWorks = true;
					break;
			
			case 4: if(ContainsLower == true && ContainsUpper == true && ContainsNum == true && ContainsSpec == true)
						PassWorks = true;
					break;
			default: 
					PassWorks = false;
					break;
		}
		
	
	}
	
	//this section while produce the uniqueness of the password
	switch(setting){
		case 2: 
				//two must be of a known subset of available characters
				chance = chance * (26) * (26);
				
				//the rest must be of the entire set of characters available
				for(int j=0; j < (length - setting); j++){
					chance = chance * 52;					
				}
				
				break;
				
		case 3: 
				//three must be of a known subset of available characters
				chance = chance * (26) * (26) * (10);
				
				//the rest must be of the entire set of characters available
				for(int j=0; j < (length - setting); j++){
					chance = chance * 62;					
				}
		
				break;
		
		case 4: 
				//four must be of a known subset of available characters
				chance = chance * (26) * (26) * (10) * (specChar.length());
				
				//the rest must be of the entire set of characters available
				for(int j=0; j < (length - setting); j++){
					chance = chance * (62 + specChar.length());					
				}
			
				break;
		default: 
				chance = 1;
				break;
	}
	
	//display the output
	cout << "Password is: " << password << endl;
				
	//display the uniqueness
	cout << endl << "Among passwords of the same length and requirements " << endl << "this password is 1 in "; 
	cout << chance << endl;
	
	return 0;
}