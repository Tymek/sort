// Dane losowe
void data_random(int *t, int n){
	srand(0);
	t[0] = n;
	while(n>0){
		t[n] = rand();
		n--;
	}
}