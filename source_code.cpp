#include<iostream>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<fstream>
#include<ctime>


using namespace std;


void fontSize(int size)
{
	//FONT SIZE CHANGE 
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void swap (long int *a, long int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  

//func to randomize and rearrange the array 
void randomize (long int arr[], int n)  
{  
   
    srand (time(NULL));  
  
    
    for (int i = n - 1; i > 0; i--)  
    { 
        int j = rand() % (i + 1); 
        swap(&arr[i], &arr[j]);  
    }  
}  


long int digitToNumber(int *inputArray , int arrayCount)      //transfer the array containing the digits with the count
{
	long int sum = 0;
	int tempArray[100];
	for(int i=0 ; i<arrayCount ; i++)
	{
		tempArray[i] = *inputArray;
		*inputArray++;
	}
	
		for(int i=0 ; i<arrayCount ; i++)
	{
		int x = arrayCount - (1 + i) ;
		sum = sum + (tempArray[i]*(pow(10,x)));
	}
	return sum;
}

//func for converting input string to number 
long int stringTOnumber(string innput)
{
	int stringLength = innput.size();
	int stringNUM[1000];
	int count=0 ;
	for(int i=0; i<stringLength ;i++)
	{
		switch(innput[i])
		{
			case '0' : stringNUM[i] = 0; break;
			case '1' : stringNUM[i] = 1; break;
			case '2' : stringNUM[i] = 2; break;
			case '3' : stringNUM[i] = 3; break;
			case '4' : stringNUM[i] = 4; break;
			case '5' : stringNUM[i] = 5; break;
			case '6' : stringNUM[i] = 6; break;
			case '7' : stringNUM[i] = 7; break;
			case '8' : stringNUM[i] = 8; break;
			case '9' : stringNUM[i] = 9; break;
			default : system("cls"); cout<<"oops some error occured\n\n"; system("pause"); exit(1);		//#include<windows.h>
		}
		count++;
	}
	
	long int result = 0;
	result = digitToNumber(stringNUM , count);
	return result;
}


//main
int main()
{
	fontSize(24); 		//font size change func 
	cout<<"Enter 000 in the input to go to results\n\n";
	cout<<"Enter 2-9 for inputting number's from 2 to 9\n\n";
	cout<<"Max number of input's can be 99999\n\n";
	system("pause");
	
	long int range0=0;
	long int range1=0;
	
	string input;
	int count0=0;
	long int conInput[100000];
	
	while(1)
	{
		range0=0;
		range1=0;
		int yes = 0;
		input = "";
		system("cls");
		
		
		cout<<"Give a input "<<count0<<" - ";
		getline(cin , input);
		
		//exit condition from loop
			if(input[0]=='0')
			{
				if(input[1]=='0')
				{
					if(input[2]=='0')	
					{
						break;
					}	
				}	
			}
			
			
		int inputLength = input.size();
		yes=0;
		//checking for if we have to build a range
		for(int i=0 ; i<inputLength;i++)
		{
			if(input[i]=='-')
			{
				yes++;
			}
		}
		
		//checking is range operator is found 	
		if(yes>0)
		{
			int stringNUM[1000];
			int countYES=0;
			for(int i=0; i<inputLength ;i++)
		{
			switch(input[i])
			{
				case '0' : stringNUM[countYES] = 0; countYES++; break;
				case '1' : stringNUM[countYES] = 1; countYES++; break;
				case '2' : stringNUM[countYES] = 2; countYES++; break;
				case '3' : stringNUM[countYES] = 3; countYES++; break;
				case '4' : stringNUM[countYES] = 4; countYES++; break;
				case '5' : stringNUM[countYES] = 5; countYES++; break;
				case '6' : stringNUM[countYES] = 6; countYES++; break;
				case '7' : stringNUM[countYES] = 7; countYES++; break;
				case '8' : stringNUM[countYES] = 8; countYES++; break;
				case '9' : stringNUM[countYES] = 9; countYES++; break;
				case ' ' : break;
				case '-' : goto out; break;
				default : system("cls"); cout<<"oops some error occured\n\n"; system("pause"); exit(1);		//#include<windows.h>
			}
		}
		out : ;				//goto statement 
		
		range0 = digitToNumber(stringNUM , countYES);
		int count2=0;
		int stringNUM0[1000];
		
		for(int i=countYES; i<inputLength ;i++)
		{
			switch(input[i])
			{
				case '0' : stringNUM0[count2] = 0; count2++; break;
				case '1' : stringNUM0[count2] = 1; count2++; break;
				case '2' : stringNUM0[count2] = 2; count2++; break;
				case '3' : stringNUM0[count2] = 3; count2++; break;
				case '4' : stringNUM0[count2] = 4; count2++; break;
				case '5' : stringNUM0[count2] = 5; count2++; break;
				case '6' : stringNUM0[count2] = 6; count2++; break;
				case '7' : stringNUM0[count2] = 7; count2++; break;
				case '8' : stringNUM0[count2] = 8; count2++; break;
				case '9' : stringNUM0[count2] = 9; count2++; break;
				case ' ' : break;
				case '-' : break; break;
				default : system("cls"); cout<<"oops some error occured\n\n"; system("pause"); exit(1);		//#include<windows.h>
			}
		}
		range1 = digitToNumber(stringNUM0 , count2);
		yes==0;
		}	
		
		if(range0==0 && range1==0)
		{
			conInput[count0] = stringTOnumber(input);
		}
		else
		{
			for(long int i=range0;i<=range1;i++)
			{
				conInput[count0] = i;
				count0++;
			}
			count0--;
			yes==0;
		}
		count0++;
	}
	
	//now we the array having the elements required for the random group formation
	
	system("cls");
	cout<<"Total number of members are - "<<count0;
	cout<<"\n\n";
	system("pause");
	system("cls");
	
	int groups=0 , mem=0;
	cout<<"Enter the total number of groups - ";
	cin>>groups;
	cout<<"\n\nEnter the members in each in group - ";
	cin>>mem;
	cout<<"\n\n";
	system("pause");
	

	int extra=0;
	int buffer = count0 - (groups*mem);
	long int arr[count0+10];
	
	//checking if their will be some extra members in th groups
	if((groups*mem)!=count0)
	{
		system("cls");
		cout<<"Their is will be some extra or less members in some groups\n\n";
		system("pause");
		extra++;
		system("cls");
	}
	
	
	//randamizing the array 
	for(int i=0;i<count0;i++)
	{
		arr[i] = conInput[i];
	}
	randomize (arr, count0);  //converted to arr because arr has the reference in teh function 
	
	system("cls");
	int i=0;
	int yesTXT=0;
	cout<<"Want to have a txt file the output\n";
	cout<<"enter 1 for yes and any other for no : ";
	cin>>yesTXT;
	system("cls");
	if(yesTXT==1)
	{
			ofstream file;
			file.open("C:\\Users\\harsh\\Desktop\\RESULT detail.txt", ios::out);
			//printing the groups member vise 
		for(int k=1;k<=groups;k++)
		{
			cout<<"\n\nMembers in the group "<<k<<" = \n";
			file<<"\n\nMembers in the group "<<k<<" = \n";
			for(int j=1;j<=mem;j++)
			{
				cout<<"\t"<<j<<". "<<arr[i]<<endl;
				file<<"\t"<<j<<". "<<arr[i]<<endl;
				i++;
				if(j==mem)
				{
					if(buffer>0)
					{
						cout<<"\t"<<j+1<<". "<<arr[i]<<endl;
						i++;
						file<<"\t"<<j+1<<". "<<arr[i]<<endl;
						buffer--;
					}
				}
			}
		
		}
		file.close();
		cout<<"\n\n";
		system("pause");
		system("cls");
		cout<<"TXT file has been generated at the desktop named as RESULT.txt\n\n";
		system("pause");
	}
	else
	{
		for(int k=1;k<=groups;k++)
		{
			cout<<"\n\nMembers in the group "<<k<<" = \n";
			for(int j=1;j<=mem;j++)
			{
				cout<<"\t"<<j<<". "<<arr[i]<<endl;
				i++;
				if(j==mem)
				{
					if(buffer>0)
					{
						cout<<"\t"<<j+1<<". "<<arr[i]<<endl;
						i++;
						buffer--;
					}
				}
			}
		}
	}
		cout<<"\n\n";
		system("pause");
	return 0;
}
