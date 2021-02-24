#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

string choice;
/*Files
    |--[账户名]
    |   |--Commands
    |   |   |--[Command Name].pcf
    |   |
    |   |--[Pic.png]|[Pic.jpg]
    |   |--settings.pcf
    |   |--Commands.pcf
	|	|--Password.pcp
    |
    |--accounts.pci
*/

int main() {
	if(false){
		ExitThisApplication:
				clog<<"Run ~$(End the Host Application)$"<<endl;
				system("taskkill /f /t /im WindowsTerminal.exe");
				system("taskkill /f /im powershell.exe");
				clog<<"Exit this Application"<<endl;
				system("taskkill /f /im 1.exe");
	}
    cout<<"\033[32m\033[40 This Application is starting, Please waiting for a minute. \033[0m"<<endl;

    ifstream AccountFile;
    AccountFile.open("accounts.pci",ios::in);
    /*
        Administrator
        SSS
        [Other Users' name]
    */
   string AccountFromFile;
   AccountFile >> AccountFromFile;
   if(AccountFromFile == ""){
        ofstream CreateAccountFile;
        CreateAccountFile.open("accounts.pci",ios::out);
        CreateAccountFile << "Administrator\n";
		CreateAccountFile << "0x0000";
		CreateAccountFile.close();
        system("mkdir \"Administrator\"");
        system("mkdir \"Administrator\\Commands\"");
		ofstream CreateAccountPwFile;
		CreateAccountPwFile.open("Password",ios::out);
		CreateAccountPwFile << "123";
		CreateAccountPwFile.close();
		cout<<"\033[32m\033[40m The default Account is \"Admnistrator\", Password is \"123\"\n";
		
		//About 7-zip
		string SevenZSourceFile = "Password";
		string SevenZAimFile = "Password.zip";
		string SevenZOperationString = "7z.exe a " + SevenZAimFile + " " + SevenZSourceFile;
		const char *SevenZOperationCode = SevenZOperationString.c_str();
		system(SevenZOperationCode);
		system("cls");

		//About copy file
		string CopyFrom = "Password.zip";
		string CopyTo = "Administrator\\Password.pcp";
		string CopyOperationString = "Copy " + CopyFrom + " " + CopyTo;
		const char *CopyOperationCode = CopyOperationString.c_str();
		system(CopyOperationCode);
		system("cls");

		//About Delete File;
		string DelFile = "Password";
		string DelOperationString = "Del " + DelFile;
		const char *DelOperationCode1 = DelOperationString.c_str();
		system(DelOperationCode1);
		DelFile = "Password.zip";
		DelOperationString = "Del " + DelFile;
		const char *DelOperationCode2 = DelOperationString.c_str();
		system(DelOperationCode2);
		system("cls");


    }
PressInUserNameAgain:
	cout<<"\033[32m\033[40m The default Account is \"Admnistrator\", Password is \"123\"\n";
    cout<<"Please enter your Account name: ";
    string AccountFromUser;
    getline(cin,AccountFromUser);
    do{
        if(AccountFromUser == AccountFromFile){
            break;
		}
        AccountFile >> AccountFromFile;
    }while(AccountFromFile < "0x0000" | AccountFromFile > "0x0000");
	if(AccountFromFile == "0x0000"){
		cout<<"\033[32m\033[40m [\033[33m\033[40m WARN\033[32m\033[40m ]\033[0m\033[32m\033[40m Can't find this Account, create it? \033[0m"<<endl<<
			"Press in your choice (y - yes, n - no): ";
		cin>>choice;
		if(choice == "y"){
PressInPasswordAgainWhenCreatingAccountFromErrorAccount:
			system("cls");
			cout<<"\033[32m\033[40m AccountName: \033[33m"<<AccountFromUser<< "\033[32m"<<endl;
			cout<<"\033[32m\033[40m Password: \033[37m";
			string PwFromUserCreating;
			cin>>PwFromUserCreating;
			cout<<"\033[32m\033[40m Password again to check: \033[37m";
			string PwFromUserCreating2;
			cin>>PwFromUserCreating2;
			if(PwFromUserCreating == PwFromUserCreating2){
		   		int a;
		   		a = 10;
		   		cout <<a;
			}else{
				system("cls");
				cout<<"\033[32m\033[40m [\033[31m\033[40m ERRO \033[32m\033[40m ] The two Passwords you entered do not match. Please try again. Or you could press in \"Exit\" to exit this Application. "<<endl;
				cout<<"Press in your choice(t - try again , Exit - Exit this Application): ";
				cin>>choice;
				if(choice == "t"){
					goto PressInPasswordAgainWhenCreatingAccountFromErrorAccount;
				}else{
					goto ExitThisApplication;
				}
			}
		}else{
			goto PressInUserNameAgain;
		}
	}else{
		string PasswordFromUser;
		string charsss1 = AccountFromUser;
		string charsss2 = AccountFromUser;
		charsss1 = AccountFromUser + "\\Password.pcp";
		charsss2 = "Password.zip";
		string charsss3 = "copy " + charsss1 + " " + charsss2; 
		const char *chass = charsss3.c_str();
		system(chass);
		string charsss4 = "7z.exe e " + charsss2;
		const char *chass2 = charsss4.c_str();
		system(chass2);
		ifstream PasswordFile;
		PasswordFile.open("Password",ios::in);
		string PasswordFromFile;
		PasswordFile >> PasswordFromFile;
		PasswordFile.close();
		system("del Password");
		system("del Password.zip");
		system("cls");
		cout<<"\033[32m\033[40m The default Account is \"Admnistrator\", Password is \"123\"\n";
		cout<<"\033[32m\033[40m Please press in your Password: \033[8m";
		cin>>PasswordFromUser;
		if(PasswordFromUser == PasswordFromFile){
			cout<<"Right\t";
		}else{
			cout<<"Wrong\t";
		}
	}
	


	// 基于当前系统的当前日期/时间
	time_t now = time(0);

	// 把 now 转换为字符串形式
	char* dt = ctime(&now);

	cout << "\033[0m\033[40m\033[32m Local date and time: " << dt << "\n";
	cout << "This Application Program is made by Locked_Fog\n"<<endl;

	do {
		cout<<"User\\"<<AccountFromUser<<"\\$> ";
		string pressin;
		getline(cin,pressin);
		if(pressin == "help"|pressin == "?"|pressin == "？") {
			clog<<"Show ~$(Help-Screen)$ to User\\Administrator\n\n";
			cout<<"\t\t\t\tHelp-Scree\n\n"<<
			    "This Application Program is Developed By Locked_Fog\nVersion: 2.3.1\n"<<
			    "\tFunction List\nKey\t\t\tFunction\n\n"<<
			    "?|help\t\t\tShow this Help-Screen\n"<<
			    "explorer\t\tRun \"Explorer.exe\"\n"<<
			    "cmd\t\t\tRun \"cmd.exe\"\n"<<
			    "powershell\t\tRun \"Powershell.exe\"\n"<<
			    "clr\t\t\tClear the screen\n"<<
			    "taskkill\t\tEnd a Program\n"<<
			    "keyboard\t\tShow the KeyBoard\n"<<
			    "edge\t\t\tMicrosoft Edge\n"<<
				"shutdown\t\tShut Down the Computer\n"<<
			    "exit\t\t\tExit the Application"<<
				"\n\nThis Appliaction can also run CMD-command"<<endl;
		} else if(pressin == "explorer") {
			clog << "Run Command ~$(explorer)$"<<endl;
			system("start explorer");
		} else if(pressin == "explorer-r"){
			clog << "Run Command ~$(Restart Explorer)$~"<<endl;
			system("taskkill /f /im explorer.exe");
			system("start explorer");
		}
		else if(pressin == "shutdown"){
			cout<<"Sure to shutdown this Computer?"<<"\n\t(y - yes , n - no):  ";
			string choice1;
			cin>>choice1;
			if(choice1 == "y" | choice1 == "Y"){
				clog<<"Run Command~$(Shut Down The Computer)$"<<endl;
				system("shutdown /s /t 10");
			} 
		}
		 else if(pressin == "cmd") {
			clog<<"Run Command~$(cmd.exe)$"<<endl;
			system("wt -p \"������ʾ��\"");
		} else if(pressin == "powershell") {
			clog<<"Run Command~$(Windows PowerShell)$"<<endl;
			system("wt -p \"Windows PowerShell\"");
		} else if(pressin == "clr") {
			clog<<"Clear the screen"<<endl;
			system("cls");
			cout << "Local date and time: " << dt << "\n";
			cout << "This Application Program is made by Locked_Fog\n"<<endl;
		} else if(pressin == "taskkill") {
			cout<<"Input the Image name:  ";
			string Img;
			cin >> Img;
			Img = "taskkill /f /im " + Img;
			const char *cha = Img.c_str();
			clog<<"Run ~$(taskill /f /im "<<Img<<")$"<<endl;
			system(cha);
		} else if(pressin == "keyboard") {
			clog<<"Run Command~$(KeyBoard)$"<<endl;
			system("osk");
		} else if(pressin == "edge") {
			clog<<"Run Command~$(Microsoft Edge)$"<<endl;
			system("\"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\"");
		} else if(pressin == "exit") {
			cout<<"Sure to exit?\t(y - yes , n - no)\n";
			string choice;
			cin >> choice;
			if(choice == "Y" | choice == "y") {
				goto ExitThisApplication;
			}
		} else if(pressin == ""){
		} else if(pressin == "password" | pressin =="Password"){
			system("cls");
			//Input the old password
			ifstream PwFileChanging;
			cout << "\033[32m\033[40m Press in your old Password: \033[30m\033[40m";
			string PwFromUserChanging;
			
		}
		else{
			const char *cha = pressin.c_str();
			cout<<"Run ~$(Use the CMD Command parser to run: &&("<<pressin<<")&&)$"<<endl;
			system(cha);
		}

	} while(true);
}
