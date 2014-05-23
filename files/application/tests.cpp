#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <windows.h>

#include "exec.c"

using namespace std;

/**
 * Generowanie wyników pomiaru wydajności algorytmu
 * Funkcja wysyła na standardowe wyjście programu tablicę w formacie JSON
 * zawierającą zależność czasu wykonywania od ilości danych wejściowych
 * @param a - numer algorytmu
 * @param d - numer typu danych
 * @param rho - gęstość punktów pomiarowych
 * 				( ilość w przedziale od log(n) do log(n+1) )
 * @param stop - docelowy czas wykonywania programu
*/
void test(int a, int d, double rho, double stop){
	double q;
	long long int i;
	char buff[100];
	string r;
	double data;
	
	bool first = true;
	
	rho = 1/rho;
	q = 3-rho;
	cout << "[";
	do {
		q+=rho;
		
		i = (long long int)round(pow(10.,q));
		sprintf(buff, "sort.exe %d %d %d", a, d, i);
		if(i <= 0 || i >= /*1280*/1280*1024*1000/4) break;
		r = exec(buff);
		data = ::atof(r.c_str());
		if(data){
			if(first){
				first = false;
			} else {
				cout << ",";
			}
			cout << endl << "\t[" << i << ", " << data << "]";
		}
		Sleep(1);
	} while(/*i<=1*k*k*/data<stop);
	cout << endl << "]" << endl;
}

int main(int argc, char **argv){
	int a, d, q, s;
	sscanf(argv[1], "%d", &a);
	sscanf(argv[2], "%d", &d);
	sscanf(argv[3], "%d", &q);
	sscanf(argv[4], "%d", &s);
	
	test(a, d, q, s);
	
	return 0;
}




