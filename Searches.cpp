int linear_search(int* array, size_t size, int number)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == number)return i;
	}
	return -1;
}

int binary_search(int* array, size_t size, int number)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		if (array[(left + right) / 2] > number) right = (right + left) / 2 - 1;
		else if (array[(left + right) / 2] < number) left = (right + left) / 2 + 1;
		else return (left + right) / 2;
	}
	return -1;
}

int interpolating_search(int* array, size_t size, int number)
{
	int left = 0, right = size - 1, now;
	while ((array[left] < number) && (array[right] > number))
	{
		now = left + ((number - array[left]) * (right - left)) / (array[right] - array[left]);
		if (array[now] < number)
			left = now + 1;
		else if (array[now] > number)
			right = now - 1;
		else
			return left;
	}
	return -1;
}