/** 
 * Sortowanie szybkie
 */
 
void quick_sort(int t[], int left, int right)
{
	int i,
		j,
		p,
		x;

	i = (left + right) / 2;
	p = t[i];
	t[i] = t[right];
	for(j = i = left; i < right; i++)
	if(t[i] < p)
	{
		x = t[i];
		t[i] = t[j];
		t[j] = x;
		j++;
	}
	t[right] = t[j];
	t[j] = p;
	if(left < j - 1) quick_sort(t, left, j - 1);
	if(j + 1 < right) quick_sort(t, j + 1, right);
}
