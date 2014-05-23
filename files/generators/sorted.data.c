// Dane posortowane
void data_sorted(int *t, int n){
	int i;
	t[0] = n;
	for(i = 0; i < n; i++){
		t[i+1] = i;
	}
}