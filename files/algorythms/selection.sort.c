/** 
 * Sortowanie przez wyb�r
 * @author Tymoteusz Czech <Czech.Tymoteusz@student.pk.edu.pl>
 */

void selection_sort(int t[], int n){
	int i,
		x,
		max;
	while(n-->= 0){
		int max = n;
		for(i = n-1; i >= 0; i--){
			if(t[i] > t[max] ){
				max = i;
			}
		}
		x = t[max];
		t[max] = t[n];
		t[n] = x;
	}
}

/*
LISTA KROK�W

N - numer ostatniego elementu tablicy
I - zmienna iteracyjna
MAX - element rozdzielaj�cy

1. Przypisz MAX warto�� N, przypisz I warto�� o 1 mniejsz� od N
2. Je�li I-ty element tablicy jest mniejszy lub r�wny elementowi na pozycji MAX,
	id� do kroku 4.
3. Przypisz MAX warto�� I
4. Zmniejsz warto�� I o 1.
5. Je�li I jest wi�ksze lub r�wne numerowi pierwszego elementu tablicy, 
	id� do kroku 2.
6. Zamie� miejscami elementy o numerach N i MAX.
7. Zmniejsz N o 1.
8. Je�li warto�� N jest wi�ksza lub r�wna numerowi pierwszego elementu tablicy,
	id� do kroku 1.
9. Zako�cz.

*/
