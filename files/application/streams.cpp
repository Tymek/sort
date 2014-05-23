#include <cmath>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

#include "../application/exec.c"

/**
 * Generowanie wyników pomiaru wydajności algorytmu
 * @param a - numer algorytmu
 * @param d - numer typu danych
 * @param rho - gęstość punktów pomiarowych
 * 				( ilość w przedziale od log(n) do log(n+1) )
 * @param stop - docelowy czas wykonywania programu
 * @return string z danymi w formacie JSON zawierający zależność czasu
 *			wykonywania sortowania od ilości danych wejściowych
*/
std::string test(int a, int d, double rho, double stop){

	std::stringstream output;
	
	double q;
	long long int i;
	double data;
	
	char buff[100];
	std::string r;
	
	bool first = true;
	
	rho = 1/rho;
	q = 3-rho;
	output << "[";
	do {
		q+=rho;
		
		i = (long long int)round(pow(10.,q));
		sprintf(buff, "sort.exe %d %d %d", a, d, i);
		if(i <= 0 && i >= 1536*1024*1000/4) break;
		r = exec(buff);
		data = ::atof(r.c_str());
		if(data){
			if(first){
				first = false;
			} else {
				output << ",";
			}
			output << std::endl << "\t[" << i << ", " << data << "]";
		}
		Sleep(1);
	} while(/*i<=1*k*k*/data<stop);
	output << std::endl << "]" << std::endl;
	
	return output.str();
}

/**
 * Wypisywanie czasu
 * @return char * czas w formacie "HH:MM:SS"
 */
char* printTime(){
	char *s;
	s = (char*)calloc(8+1, sizeof(char));
    time_t t = time(0);
    struct tm * now = localtime(&t);
	sprintf(s, "%.2d:%.2d:%.2d", now->tm_hour, now->tm_min, now->tm_sec);
	return s;
}

int main(){
	int time,
		density;
	
	std::cout << "Execution time target [s]: ";
	std::cin >> time;
	std::cout << "Density [tests per order of magnitude]: ";
	std::cin >> density;
	
	int a,
		d;
	
	char c[32];
	std::string s;
	std::ofstream f;
	
	const char* algorythms[] = {"", "coctail", "selection", "insertion", "quick", "heap", "shell" };
	const char* dataType[] = {"random/", "sorted/", "reverse/", "exceptions/"};
	
	std::cout << std::endl;
	
	for(d = 0; d < 4; d++){
		for(a = 1; a <= 6; a++){
			
			std::cout << "./tests.exe " << a<<" "<<d<<" "<<density<<" "<<time;
			std::cout << " | tee ../results/" << dataType[d] << algorythms[a];
			std::cout << ".sort.json" << std::endl;

		}
	}
	std::cout << std::endl;
	
}