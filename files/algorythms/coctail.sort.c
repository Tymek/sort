/** 
 * Sortowanie bąbelkowe dwukierunkowe (koktajlowe)
 * @author Tymoteusz Czech <Czech.Tymoteusz@student.pk.edu.pl>
 */

void coctail_sort(int t[], int n){
    int i,
		min,
		max,
		pos;
	
	min = 0;
	max = n-2;
	pos = -1;
	do {
		for(i = min; i <= max; i++){ // w prawo
			if(t[i] > t[i+1]){
				pos = t[i+1];
				t[i+1] = t[i];
				t[i] = pos;
				pos = i;
			}
		}
		
		if(pos < 0) break; // nie została wykonana zmiana
		
		max = pos - 1;
		pos = -1;
		for(i = max; i >= min; i--){ // w lewo
			if(t[i] > t[i+1]){
				pos = t[i+1];
				t[i+1] = t[i];
				t[i] = pos;
				pos = i;
			}
		}
		min = pos + 1;
	} while(pos >= 0);
}

/* 
LISTA KROKÓW

I - zmienna iteracyjna
MIN - granica zbioru posortowanego po lewej stronie
MAX - granica zbioru posortowanego po prawej stronie
POS - numer pozycji, na której wykonano ostatnią zmianę

1.	Przypisz numer pierwszego elementu tablicy do MIN oraz I,
	numer ostatniego elementu tablicy do MAX.
2.	Wyzeruj POS, przypisz I wartość MIN
3.	Jeśli I-ty element tablicy jest mniejszy lub równy elementowi I+1 
	idź do kroku 6.
4.	Zamień miejscami elementu numer I oraz I+1
5.	Przypisz POS wartość I
6.	Zwiększ wartość I o 1
7.	Jeśli I jest mniejsze lub równe MAX, idź do kroku 3.
8.	Jeśli POS wyzerowana, idź do kroku 18.
9.	Zmniejsz wartość MAX o 1, wyzeruj POS.
10.	Przypisz I wartość MAX.
11.	Jeśli I-ty element tablicy jest mniejszy lub równy elementowi I+1 
	idź do kroku 14.
12.	Zamień miejscami elementu numer I oraz I+1
13.	Przypisz POS wartość I
14.	Zmniejsz wartość I o 1
15. Jeśli I jest większe lub równe MIN, idź do kroku 11.
16. Zwiększ wartość MIN o 1.
17. Jeśli POS nie wyzerowana, idź do kroku 2.
18. Zakończ

*/
