// Dane posortowane z wyj¹tkami
void data_exceptions(int *t, int n){
	int i;
	srand(0);
	t[0] = n;
	for(i = 0; i < n; i++){
		if(i % 100 == 0){ // losowy co 100
			t[i+1] = rand() % n;
		} else {
			t[i+1] = i;
		}
	}
}