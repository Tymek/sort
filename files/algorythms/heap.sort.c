/** 
 * Sortowanie stogowe
 * @author Tymoteusz Czech <Czech.Tymoteusz@student.pk.edu.pl>
 */

void heap_sort(int t[], int n){
	int i,
		j,
		k,
		m,
		x;
	for(i = 2; i <= n; i++)
	{
		j = i; k = j / 2;
		x = t[i];
		while((k > 0) && (t[k] < x))
		{
			t[j] = t[k];
			j = k;
			k = j / 2;
		}
		t[j] = x;
	}

	for(i = n; i > 1; i--)
	{
		x = t[1];
		t[1] = t[i];
		t[i] = x;
		j = 1; 
		k = 2;
		while(k < i){
			if((k + 1 < i) && (t[k + 1] > t[k])){
				m = k + 1;
			} else {
				m = k;
			}
			if(t[m] <= t[j]) break;
			x = t[j];
			t[j] = t[m];
			t[m] = x;
			j = m; 
			k = j + j;
		}
	}
}
