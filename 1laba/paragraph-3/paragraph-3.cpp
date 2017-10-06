/*
 10. Имеется текстовый файл с некоторым описанием. Переносов
слов нет.  Требуется каждые 3 предложения выделить в отдельный
абзац.  Каждое   предложение   может   заканчиваться   точкой,
вопросительным либо восклицательным знаком (6).
*/

#include "stdafx.h"

using namespace std;

string getStringFromInput(ifstream &input)
{
	string str;
	string result;
	while (getline(input, str))
	{
		for (size_t i = 0; i < str.length(); ++i)
		{
			result += str[i];
		}
	}
	return result;
}

void divisionOnParagraphs(string &oneString, ofstream &output)
{
	int counter = 0;
	bool flag = false;
	string finalString;
	for (size_t i = 0; i < oneString.length(); i++)
	{
		if ((flag) && (isspace(static_cast<unsigned char>(oneString[i]))))
		{
			continue;
		}
		else if (oneString[i] != ' ')
		{
			flag = false;
		}
		finalString += oneString[i];
		if ((oneString[i] == '.') || (oneString[i] == '?') || (oneString[i] == '!'))
		{
			++counter;
		}
		cout << counter;
		output << finalString;
		if (counter == 3)
		{
			output << "\n";
			finalString.clear();
			counter = 0;
			flag = true;
		}
		finalString.clear();
	}
	
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc != 3)
	{
		std::cerr << "Invalid amount of arguments\n"
			<< "Usage: paragraph-3.exe <input>" << endl;
		return 1;
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);
	if (!input.is_open())
	{
		cerr << "Failed to open " << argv[1] << " for reading!" << endl;
		return 1;
	}
	string oneString = getStringFromInput(input);
	divisionOnParagraphs(oneString, output);
	input.close();
}
