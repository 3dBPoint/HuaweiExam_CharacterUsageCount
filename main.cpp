/*输入全量字符集和已用字符集，之间用@隔开，输出未使用的字符集，如果用光了那么不显示*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct character
{
	char c;
	int times;
};

int main()
{
	string inputStr = "a:3,b:5,c:2@a:1,b:4";
	vector<character> fullChar, usedChar;
	int len = inputStr.length();
	int splitterPos = inputStr.find('@');

	//解析全量字符集
	string fullStr = inputStr.substr(0, splitterPos);//全部字符集
	int commaPos = 0;
	while ((commaPos = fullStr.find(',')) != -1)
	{
		string charStr = fullStr.substr(0, commaPos);
		int colonPos = 0;
		colonPos = charStr.find(':');
		character c; c.c = charStr.substr(0, colonPos)[0]; c.times = stoi(charStr.substr(colonPos + 1));
		fullChar.push_back(c);
		fullStr = fullStr.substr(commaPos + 1);
	}
	int colonPos = 0;
	colonPos = fullStr.find(':');
	character c; c.c = fullStr.substr(0, colonPos)[0]; c.times = stoi(fullStr.substr(colonPos + 1));
	fullChar.push_back(c);

	//解析已用字符集
	string usedStr = inputStr.substr(splitterPos + 1);
	while ((commaPos = usedStr.find(',')) != -1)
	{
		string charStr = usedStr.substr(0, commaPos);
		int colonPos = 0;
		colonPos = charStr.find(':');
		character c; c.c = charStr.substr(0, colonPos)[0]; c.times = stoi(charStr.substr(colonPos + 1));
		usedChar.push_back(c);
		usedStr = usedStr.substr(commaPos + 1);
	}
	colonPos = usedStr.find(':');
	c.c = usedStr.substr(0, colonPos)[0]; c.times = stoi(usedStr.substr(colonPos + 1));
	usedChar.push_back(c);

	//在全量列表里找已用的
	for (int i = 0; i < usedChar.size(); i++)
	{
		for (int j = 0; j < fullChar.size(); j++)
		{
			if (fullChar[j].c == usedChar[i].c)
			{
				fullChar[j].times -= usedChar[i].times;
				break;
			}
		}
	}

	//输出
	for (int i = 0; i < fullChar.size(); i++)
	{
		if (fullChar[i].times)
			cout << fullChar[i].c << ':' << fullChar[i].times << endl;
	}

	return 0;
}