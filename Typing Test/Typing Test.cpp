#include <iostream>
#include <fstream>
#include <time.h>
#include <dos.h>
#include <Windows.h>
#include <string>

using namespace std;
class menu
{
private:
	ifstream para;
	int GrossWPM, NetWPM;
	int CorrectEntry = 0, IncorrectEntry = 0, AllTypedEntry = 0, TotalEntries = 0;
	double TotalTime = 0.00000, Accuracy=0.00;
	double TimeMin;
public:

	void face()
	{
		short int opt;
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		cout << "----------TYPING TEST----------\n";
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		cout << "-------------------------------\n";
		Sleep(2000);
		system("clear");

		cout << "----------Tpying Test----------\n";
		cout << "Main Menu\n";
		cout << "1) Select Paragraph\n";
		cout << "2) Exit\n\n";
		cout << "Select Option - ";
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			ListOfParas();
			break;
		}
		case 2:
		{
			system("clear");
			cout << "Thank You for using our app\n";
			exit(0);
		}
		}


	}
	void ListOfParas()
	{
		short int opt1;
		cout << "----------Tpying Test----------\n";
		system("clear");
		cout << "List of Paragraphs - \n";
		cout << "1) A House on Fire\n";
		cout << "2) A Visit to an Exibition\n";
		cout << "3) Book\n";
		cout << "4) Importance of Education\n";
		cout << "5) Demo - Camel\n";
		cout << "6) Exit\n\n";
		cout << "Select paragraph - ";
		cin >> opt1;
		DisplayPara(opt1);
	}

	void DisplayPara(short int opt)
	{
		string word;
		switch (opt)
		{
		case 1 :
		{
			para.open("A House on Fire.txt");
			
			break;
		}
		case 2 :
		{
			para.open("A Visit to an Exibition.txt");
			break;
		}
		case 3:
		{
			para.open("Book.txt");
			
			break;
		}
		case 4:
		{
			para.open("Importance of Education.txt");
			break;
			
		}
		case 5:
		{
			para.open("Demo - Camel.txt");
			break;
		}
		case 6 :
		{
			system("clear");
			cout << "Thank You for using our app\n";
			exit(0);
		}
		default:
		{
			cout << "Invalid Input\n";
			Sleep(2000);
			system("clear");
			ListOfParas();
		}
		}
		system("clear");
		cout << "Paragraph - \n\n ";
		if (para)
		{
			para.seekg(0);
			while (!para.eof())
			{
				para >> word;
				cout << word << " ";
			}
		}
		else
		{
			cout << "File not open";
			Sleep(1000);
			system("clear");
			ListOfParas();
		}
		
	}

	void test()
	{
		cout << "\n\n1..";
		Sleep(1500);
		cout << "2..";
		Sleep(1500);
		cout << "3";
		Sleep(1500);
		cout << "\nStart Typing - \n";


		//taking input
		
		string CorrectWord, TypedWord;
		
		para.seekg(0);
		while (!para.eof())
		{
			time_t start, end;
			int len, ExtraLetter = 0;

			para >> CorrectWord;
			TotalEntries += CorrectWord.length();

			start = clock();
			cin >> TypedWord;
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
			TotalTime += time_taken;

			if (CorrectWord.length() >= TypedWord.length())
			{
				len = TypedWord.length();
				IncorrectEntry += CorrectWord.length() - TypedWord.length();
			}
			else
			{
				len = CorrectWord.length();
				ExtraLetter = TypedWord.length() - CorrectWord.length();
			}

			for (int a = 0; a < len; a++)
			{
				if (CorrectWord[a] == TypedWord[a])
				{
					CorrectEntry++;
				}
				else
				{
					IncorrectEntry++;
				}
			}
			IncorrectEntry += ExtraLetter;
			AllTypedEntry += TypedWord.length();

		}

		//counting Gross WPM and Net WPM
		
		TimeMin = (double)TotalTime / 60;
		GrossWPM = (AllTypedEntry / 5) / TimeMin;
		NetWPM = GrossWPM - (IncorrectEntry / TimeMin);
		Accuracy = (double)CorrectEntry*100.00 / AllTypedEntry;
	}

	void result()
	{
		system("clear");
		cout << "\nCongratulations!!!! You have completed your typing test successfully :))\n\nHere's your result -\n";
		cout << "-----------------------------------------\n";
		cout << "| Total Entries       | " << TotalEntries << "\n";
		cout << "| Total Typed Entries | " << AllTypedEntry << "\n";
		cout << "| Incorrect Enrtries  | " << IncorrectEntry << "\n";
		cout << "| Correct Entries     | " << CorrectEntry << "\n";
		cout << "|---------------------|-----------------\n";
		cout << "| Total Time (sec)    | " << TotalTime << " sec\n";
		cout << "| Total Time (min)    | " << TimeMin << " m-in\n";
		cout << "|---------------------|------------------\n";
		cout << "| Gross Speed (wpm)   | " << GrossWPM << " wpm\n";
		cout << "| Net Speed (wpm)     | " << NetWPM << " wpm\n";
		cout << "| Accuracy (%)        | " << Accuracy << " %\n";
		cout << "-----------------------------------------\n";

		cout << "\nPress Enter to continue.......";
		while ((getchar()) != '\n');
		if( cin.get() == '\n')
		{
			void end();
		}
	}

	void end()
	{
		short int opt3;
		para.close();
		system("clear");
		cout << "1) Take another test ??\n";
		cout << "2) Main Menu\n";
		cout << "3) Exit\n\n";
		cout << "Select option - ";
		cin >> opt3;
		switch (opt3)
		{
		case 1 :
		{
			system("clear");
			ListOfParas();
			break;
		}
		case 2:
		{
			system("clear");
			face();
			break;
		}
		case 3:
		{
			system("clear");
			cout << "Thank You for using our app\n";
			exit(0);
		}
		default:
		{
			cout << "Invalid Input:((\n";
			Sleep(1000);
			system("clear");
			end();
		}
		}

	}

};


int main()
{
	menu a, b;

	a.face();
	a.test();
	a.result();
	
	a.end();
	return 0;
}