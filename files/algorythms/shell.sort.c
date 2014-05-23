/** 
 * Sortowanie Shella
 * @author Tymoteusz Czech <Czech.Tymoteusz@student.pk.edu.pl>
 */

void shell_sort(int t[], int n) {
	int h[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750, 1588, 3599, 8157, 18489,
			  41908, 94991, 215312, 488040, 1106224, 2507441, 5683532, 12882672,
			  29200723, 66188305, 150026824, 340060801, 770804482, 1747156825};
    int c, // indeks u¿ywanego odstêpu
		i, j, // zmienne iteracyjne
		x, // zmienna pomocnicza
		g; // zmienna pomocnicza na odstêp
	
	c = 27;
	g = n*(15./34);
	while(g <= h[c-1]) c--;
	
	while(c--){
		g = h[c];
		for(i = g; i <= n - g; i++){
			x = t[i];
			for(j = i; j > g && x<t[j-g]; j-=g){
				t[j] = t[j-g];
			}
			t[j] = x;
		}
	}
}

/*
SPOSÓB WYBORU ODSTÊPÓW
Wed³ug publikacji Best Increments for the Average Case of Shellsort
(M. Ciura, 2001 - http://sun.aei.polsl.pl/~mciura/publikacje/shellsort.pdf)

Pocz¹tkowe 9 liczb zosta³o podane w publikacji. 
Pozosta³e obliczono ze wzoru rekurencyjnego:
h(n) = floor( (34/15) * h(n-1) )

Zakoñczono kiedy dalsze obliczenia powodowa³y przekroczenie zakrasu zmiennej.
*/
