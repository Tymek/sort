/** 
 * Sortowanie przez wybór
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
LISTA KROKÓW

N - numer ostatniego elementu tablicy
I - zmienna iteracyjna
MAX - element rozdzielaj¹cy

1. Przypisz MAX wartoœæ N, przypisz I wartoœæ o 1 mniejsz¹ od N
2. Jeœli I-ty element tablicy jest mniejszy lub równy elementowi na pozycji MAX,
	idŸ do kroku 4.
3. Przypisz MAX wartoœæ I
4. Zmniejsz wartoœæ I o 1.
5. Jeœli I jest wiêksze lub równe numerowi pierwszego elementu tablicy, 
	idŸ do kroku 2.
6. Zamieñ miejscami elementy o numerach N i MAX.
7. Zmniejsz N o 1.
8. Jeœli wartoœæ N jest wiêksza lub równa numerowi pierwszego elementu tablicy,
	idŸ do kroku 1.
9. Zakoñcz.

*/
