#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{	//Displaying paragraph to be typed
	ifstream ifs("Para1.txt");
	string word;
	ifs.seekg(0);
	if (ifs)
	{
		while (!ifs.eof())
		{
			ifs >> word;
			cout << word << " ";
		}
	}
	else
	{
		cout << "File not open";
		return 0;
	}
	//---------------------------------

	cout << "\n\nStart Typing - \n";

	//taking input
	double TotalTime = 0.00000;
	string CorrectWord, TypedWord;
	int CorrectEntry = 0, IncorrectEntry = 0, AllTypedEntry = 0;
	ifs.seekg(0);
	while (!ifs.eof())
	{
		time_t start, end;
		int len, ExtraLetter = 0;
		ifs >> CorrectWord;

		start = clock();
		cin >> TypedWord;
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		TotalTime += time_taken;
		if (CorrectWord.length() >= TypedWord.length())
		{
			len = TypedWord.length();		
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
	cout << CorrectEntry << " " << IncorrectEntry <<" "<<AllTypedEntry<<" "<<(double)TotalTime << "\n\n";

	//counting Gross WPM and Net WPM
	int GrossWPM, NetWPM;
	double TimeMin = (double)TotalTime / 60;
	GrossWPM = (AllTypedEntry / 5) / TimeMin;
	cout << TimeMin << endl;

	NetWPM = GrossWPM - (IncorrectEntry / TimeMin);

	cout << "Gross Speed = " << GrossWPM << " wpm\n";
	cout << "Net Speed = " << NetWPM << " wpm\n";
	return 0;

}