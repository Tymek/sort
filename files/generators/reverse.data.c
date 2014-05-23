// Dane posortowane odwrotnie
void data_reverse(int *t, int n){
	int i;
	t[0] = n;
	for(i = 0; i < n; i++){
		t[i+1] = n-i-1;
	}
}