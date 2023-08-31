//#include <cctype>
//#include <cstring>

#include<windows.h>
#include<conio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class player
{
	float score;
	char name[400];
	void getData();
	void leaderboard();
	public:
		player()
		{
			score = 0;
		}
		void addData();
		void showData();
		void getscore();
}P_game;


class answers
{
	public:
		char a1[100];
		char a2[100];
		char a3[100];
		char a4[100];
		char a5[100];
		char a6[100];
		char a7[100];
		char a8[100];
		char a9[100];
		char a10[100];
		char m_a[100];
		answers();
}ans;


answers::answers()
{
	strcpy(m_a, "NULL");
	strcpy(a1, "Mark Zuckerberg");
	strcpy(a2, "Tim Cook");
	strcpy(a3, "Ajay Bhatt");
	strcpy(a4, "Simon");
	strcpy(a5,"Longhorn");
	strcpy(a6, "Octocat");
	strcpy(a7, "Jeff Bezos");
	strcpy(a8, "Transmission control protocol");
	strcpy(a9, "Ubisoft");
	strcpy(a10, "Blockchain");
}


void player::getData()
{
	cout<<"\n\n\n\t\tYour score: "<<score<<'\n';
	cout<<"\n\t\tEnter your name: ";
	cin.getline(name, 400);
}


void player::leaderboard()
{
	cout<<'\n'<<name<<setw(15)<<score;
}


void player::addData()
{
	ofstream F_add;
	F_add.open("QLeaderboard.dat", ios::binary | ios::app);
	P_game.getData();
	F_add.write((char*)&P_game, sizeof(P_game));
	F_add.close();
}


void player::showData()
{
	ifstream F_show;
	F_show.open("QLeaderboard.dat", ios::binary);
	cout<<"\nName:"<<"\t\tScore:";
	while(F_show)
	{
		F_show.read((char*)&P_game, sizeof(P_game));
		if(F_show.eof())
		{
			break;
		}
		P_game.leaderboard();
		
	}
	F_show.close();
}


void player::getscore()
{
	score += 10;
}

void mainGame();
void startGame();
void questions();
void menu();

int login();
void instruct();
void menu(){
	int x;
	char a;
	cout<<("\n\n\n\t\t\t\t**************************************************");
         	cout<<("\n\t\t\t\t#                   WELCOME TO                   #");
         	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t#                     THE                        #");
        	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t#                  QUIZ GAME                     #");
        	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t#               DESIGNED BY AVIRAL               #");
        	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t**************************************************\n\n"); 
	cout<<"\t\t\t\t1. New Game\n";
	cout<<"\t\t\t\t2. Instructions\n";
	cout<<"\t\t\t\t3. Leaderboard [Score Table ]\n";
	cout<<"\t\t\t\t4. Exit\n\n\n";
	cout<<"\t\t\t\tEnter Choice: ";
	ERROR;
	cin>>x;
	cin.ignore();
	switch(x)
	{
		case 1:
			startGame();
			break;
		case 2:
			  instruct();
		case 3:
		    system("cls");
			cout<<("\n\n\n**************************************************");
         	cout<<("\n#                                                #");
         	cout<<("\n#                                                #");
        	cout<<("\n#                    LEADERBOARDS                #");
        	cout<<("\n#                                                #");
        	cout<<("\n#                                                #");
        	cout<<("\n**************************************************\n\n"); 
			P_game.showData();
			cout<<"\n\n\tEnter any Character to go Back to Main Menu....";
		    a=getch();
		    system("cls");
		    menu();
			break;
			
		case 4:
		    system("cls");
			cout<<("\n\n\n\t\t\t\t**************************************************");
         	cout<<("\n\t\t\t\t#                    THANK YOU                   #");
         	cout<<("\n\t\t\t\t#                                                #");
         	cout<<("\n\t\t\t\t#                    FOR PLAYING                 #");
         	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t#                   THE QUIZ GAME                #");
        	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t#                                                #");
        	cout<<("\n\t\t\t\t**************************************************\n\n");
			exit(0);
			  
		default:cout<<"Wrong input, please enter correct choice: ";
			break; 
	}
}
int main()
{
	system("cls");
    login();
	menu();
	return 0;
}
void startGame()
{
	char cont;
	system("cls");
	
	cout<<"\n\n\t\tBEST OF LUCK!";
	cout<<"\n\n\t\tDo you wish to begin?(y/n): ";
	cin>>cont;
	cin.ignore();
	if (toupper(cont)=='Y')
	{
		mainGame();
	}
	else
	{
		exit(0);
	}
}
void mainGame()
{
	char lead,a;
	system("cls");
	questions();
	cout<<"\n\n\tGAME OVER!";
	P_game.addData();
	cout<<"\n\tDo you wish to view the leaderboard(y/n): ";
	cin>>lead;
	cin.ignore();
	if (toupper(lead)=='Y')
	{
		system("cls");
		P_game.showData();
	
	}
	else
	{
		exit(0);
	}
}
void questions()
{
	cout<<"\n\n\t\tQ1: Who is the founder of Facebook?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if (!(strcmpi(ans.m_a,ans.a1)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a1<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ2: Who is the CEO of Apple?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a2)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a2<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ3: Who invented USB?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a3)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a3<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ4: What was the first smartphone called?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a4)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a4<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ5: What was the codename for Windows Vista ?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a5)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a5<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ6: What is the GitHub mascot called?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a6)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a6<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ7:Who founded Blue Origin?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a7)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a7<<"\n\n";
		system("pause");
	}	
	system("cls");
	cout<<"\n\n\t\tQ8: What does TCP stand for?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a8)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a8<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ9: Which studio developed Asassin's Creed?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a9)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a9<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"\n\n\t\tQ10: what technology is used to record cryptocurrency transactions?\n";
	cout<<"\n\t\tAnswer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a10)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{  
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a10<<"\n\n";
		system("pause");
	}
}
int login()
{
	string pass;
	char ch, fname[20];
	int i;
	pass = "";
	cout<<("\n\n\n\n\n\n\t\t\t\t\t**************************************************"); 
	cout<<("\n\t\t\t\t\t#                   LOGIN FORM                   #");
    cout<<("\n\t\t\t\t\t#                                                #");
    cout<<("\n\t\t\t\t\t#                     THE                        #");
    cout<<("\n\t\t\t\t\t#                                                #");
    cout<<("\n\t\t\t\t\t#                  QUIZ GAME                     #");
    cout<<("\n\t\t\t\t\t#                                                #");
    cout<<("\n\t\t\t\t\t#              ENTER PASSWORD :                  #");
    cout<<("\n\t\t\t\t\t#                                                #");
    cout<<("\n\t\t\t\t\t**************************************************\n\n\n\n\t\t\t\t\t"); 
	ch = getch();
	while(ch != 13)
	{
    	pass.push_back(ch);
    	cout << '*';
    	ch = getch();
	}
	if(pass == "1234")
	{
		system("cls");
    	cout<<("\n\n\n\n\n\n\t\t\t\t\t**************************************************");
        cout<<("\n\t\t\t\t\t#                 WELCOME USER                   #");
        cout<<("\n\t\t\t\t\t#                                                #");
        cout<<("\n\t\t\t\t\t#         SYSTEM WILL AUTOMATICALLY LOAD         #");
        cout<<("\n\t\t\t\t\t#                                                #");
        cout<<("\n\t\t\t\t\t**************************************************\n\n"); 
    	Sleep(1500);
   		system ("CLS");
   		cout << "\n\n\n\n\n\n\n\n\n\t\t\tLoading > > > >                                                  | 12% ....";
		Sleep(500);
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\tLoading > > > > > > > > > > > > > > > > > > >                    | 61% ....";
	    Sleep(500);
	   system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\tLoading > > > > > > > > > > > > > > > > > > > > > > > > >        | 95% ....";
		Sleep(500);
	    system("cls");
	    cout << "\n\n\n\n\n\n\n\n\n\t\t\tLoading > > > > > > > > > > > > > > > > > > > > > > > > > > > > > 100% ....";
		Sleep(2000);
		system("cls");
   	}
	else
	{
		system("cls");
    	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t I M P O S T E R ! !\n\n" << endl;
		cout << "\t\t\t\t\t\t  Please Try Again\n" << endl << endl;
		cout << "\t\t\t\t\tPress any key to choose another option...";
		getch();
 		system("CLS");
    	login();
	}
}
void instruct(){
    char a;
	system("cls");
	cout<<"\n\n\t**********Here are the instructions for Playing this Quiz********\n\n\n";
	cout<<"\n\t [1] You will be given 10 Questions to Solve. ";
	cout<<"\n\t [2]. +10 on correct answer, +0 otherwise.";
	cout<<"\n\t [3] At the End of the Quiz you will be asked to enter your Name . ";
	cout<<"\n\t [4] You can view the Leaderboard Scores Right after the completion of the Quiz. ";
	cout<<"\n\t [5] To see the previous LeaderBoards the facilitiy is also provided. ";
	cout<<"\n\t [6] There's currently no Option to skip the questions(But it will be added in the future implementations.)\n\n\n ";
	Sleep(3500);
    cout<<"\n\n\n\t\t\t\t Apart from this.......... ";
	cout<<"\n\t\t\t\t Happy Quizzing !!!!!!!!!!!!. ";
	Sleep(700);
	
	cout<<"\n\n\n\n\nEnter any Char to go back to Main Menu..... ";
	a=getch();
	
	system("cls");
    menu();
	getch();
	}
