/** 
 * Sortowanie przez wstawianie
 * @author Tymoteusz Czech <Czech.Tymoteusz@student.pk.edu.pl>
 */

void insertion_sort(int t[], int n){
	int i, j, x;
	for(i = 1; i < n; i++){
		x = t[i];
		for(j = i; j>0 && x<t[j-1]; j--){
			t[j] = t[j-1];
		}
		t[j] = x;
    }
}

/*
LISTA KROKÓW

I, J - Zmienne iteracyjne
X - Zmienna pomocnicza (do wstawiania)

1. Ustaw I na pierwszy element tablicy.
2. Zwiększ I o 1.
3. Przypisz J wartość I.
4. Jeśli J nie większe od numeru pierwszego elementu lub
	wartość I-tego elementu nie większa od wartości elementu poprzedzającego J-ty,
	idź do kroku 7.
5. Zamień miejscami J-ty element z elementem poprzedzającym J-ty.
6. Idź do kroku 4.
7. Jeśli I mniejsze od liczby elementów tablicy, idź do kroku 2.
8. Zakończ.

*/
