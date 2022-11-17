#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	//B=256  A=13  C=43  T(0)=37
	
	int Arr1[100];               // открытый текст
	cout << "Открытый текст: ";
	string str = "";
	cin >> str;
	cout << str << endl;
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		Arr1[i] = str[i]; 
		if ((int)str[i] < 0) Arr1[i] += 256;
	}
/*
	for (int i = 0; i < length; i++)
	{
		cout << Arr1[i] << " ";             
	}
*/

	// T(i+1)=(A*T(i)+C) mod B
	int B = 256;
	int A = 13;
	int C = 43;
	int T0 = 37;
	int Arr2[100];                    // гамма последовательность
	Arr2[0] = T0;
	for (int i = 1; i < length; i++)
	{
		Arr2[i] = (A* Arr1[i-1] + C) % B;
	}
	cout << "Гамма последовательность: ";
	for (int i = 0; i < length; i++)
	{
		cout << Arr2[i] << " ";
		if (i % 15 == 0 && i != 0) cout << endl << "                          ";
	}

	int Arr3[100];                  // шифртекст
	for (int i = 0; i < length; i++)
	{
		if (Arr1[i] + Arr2[i] < 255)
		{
			Arr3[i] = Arr1[i] + Arr2[i];
		}
		else
			Arr3[i] = Arr1[i] + Arr2[i] - 256;
	}

	string str2;                   // шифртекст (буквы)
	for (int i = 0; i < length; i++)
	{
		str2 += Arr3[i];
	}
	cout << endl << "Зашифрованный текст: " << str2;

	int Arr4[100];                 // дешифрованный текст
	for (int i = 0; i < length; i++)
	{
		if (Arr3[i] - Arr2[i] > 0)
		{
			Arr4[i] = Arr3[i] - Arr2[i];
		}
		else
			Arr4[i] = Arr3[i] - Arr2[i] + 256;
	}

	string str3;                   // дешифрованный текст (буквы)
	for (int i = 0; i < length; i++)
	{
		str3 += Arr4[i];
	}
	cout << endl << "Дешифрованный текст: " << str3;


}
