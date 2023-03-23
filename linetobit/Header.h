#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<bitset>
#include<fstream>
#include <sstream>
#include<math.h>
#include <vector>
class Sec {
private:
	std::string secret = "XYI";
public:
	friend void shif(Sec);
	friend void ras(std::string);
};
void shif(Sec s) {
	int n = s.secret.length();
	std::cout << "Kol-vo simbols = ";
	std::cout << n << std::endl;
	for (std::size_t i = 0; i < n; i++) {
		std::cout << std::bitset<8>(s.secret[i]);

	}
	std::ofstream inf; 
	inf.open("pentagon secret.txt");
	for (std::size_t i = 0; i < n; i++) {
		inf << std::bitset<8>(s.secret[i]);

	}
	inf.close();

}
void ras(std::string str) {
	std::string line;
	std::ifstream j;
	j.open(str);
	if (j.is_open()) {
		getline(j, line);
	}
	//std::cout << line << std::endl;
	const char* buf = line.c_str();
	//std::cout << buf<<std::endl;
	int k = 0;
	for (int i = 0;buf[i] != 0;++i) {
		k++;
	}
	//std::cout << "INFO"<<std::endl;
	//std::cout << k<<std::endl;
	int *num=new int[k];
	for (int i = 0;buf[i] != 0;++i) {
		num[i] = buf[i] - '0';
	}
	for (int i = 0;i<k;i++) {
		std::cout << num[i] ;
		
	}
	std::cout << "\n";
	char dec;
	int l = 0;
	while (1)
	{
		dec = 0;
		for (int j = 7; j >= 0;j--)//перебираем очередные 8 "бит"
		{
			dec += pow(2, (j)) * num[l];
			l++;
		}
		std::cout << dec;
		if (l >= k)//не забываем, что в a у нас остался размер двоичного массива
			break;
	}
	std::cout << "\n";
	delete[] num;
	j.close();
}
