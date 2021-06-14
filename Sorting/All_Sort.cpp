#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a)
{
	for (auto data : a)
		cout << data << " ";
}
/*
    Bubble sort
    Best case - O(n) [when array is allready sorted so swap will not happen]
    Average case - O(n^2)
    Worst case - O(n^2)
*/
void bubbleSort(vector<int> &a)
{
	int n = a.size();
	for (int index = 0; index < n - 1; index++)
	{
		for (int j = 0; j < n - index - 1; j++)
		{
			// if curr > next then swap
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
		}
		cout << endl;
		printArray(a);
	}
}
void modifiedBubbleSort(vector<int> &a)
{
	int n = a.size();
	bool swapped = false;
	for (int index = 0; index < n - 1; index++)
	{
		for (int j = 0; j < n - index - 1; j++)
		{
			// if curr > next then swap
			if (a[j] > a[j + 1])
			{
				swapped = true;
				std::swap(a[j], a[j + 1]);
			}
		}
		// if swapped is false means array is allready sorted so break;
		if (swapped == false)
		{
			break;
		}
		cout << endl;
		printArray(a);
	}
}

void insertionSort(vector<int> &a)
{
	int n = a.size();
	for (int index = 1; index < n; index++)
	{
		int val = a[index];

		int j = index - 1;
		while (j >= 0 && a[j] > val)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = val;

		cout << endl;
		printArray(a);
	}
}
/*
	Selection Sort
	Best case - O(n^2)
    Average case - O(n^2)
    Worst case - O(n^2)
*/
void selectionSort(vector<int> &a)
{
	int n = a.size();

	// In each iteration place appropriate element at ith position
	for (int index = 0; index < n - 1; index++)
	{
		int indexOfMinElement = index;
		for (int j = index + 1; j < n; j++)
		{
			if (a[j] < a[indexOfMinElement])
				indexOfMinElement = j; //update index of min element
		}
		if (index != indexOfMinElement)
			std::swap(a[index], a[indexOfMinElement]);
	}
}
/*
Analysis for merge sort

1) It is Divide and conquer - we divide problems into sub problems and find solution for sub problems and from that
							 we find soltion to atual problem
2) Recursive 
3) Stable sorting algo - preserve relative order of records with same key 
4) NOT an inplace sorting algo - we divide array in 2 sub list and we create entirely new arrays
5) Space complexity - O(n) 

6) Time complexity - O(n*log(n))

*/
void merge(vector<int> &a, int left, int mid, int right)
{
	int i = 0, j = 0, k = 0;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// creating tmp arrays
	int leftarr[n1], rightarr[n2];

	for (i = 0; i < n1; i++)
		leftarr[i] = a[i + left];

	for (j = 0; j < n2; j++)
		rightarr[j] = a[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (leftarr[i] < rightarr[j])
		{
			a[k] = leftarr[i];
			i++;
		}
		else
		{
			a[k] = rightarr[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = leftarr[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = rightarr[j];
		j++;
		k++;
	}
}

void mergerSort(vector<int> &a, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergerSort(a, left, mid);
		mergerSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int partition(vector<int>&a,int start,int end)
{
	int pivot=a[end];//rightmost selected as pivot 
	
	int pIndex=start;//set partition index at start

	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[pIndex],a[i]);//swap if element is less than pivot 
			pIndex++;
		}
	}
	swap(a[end],a[pIndex]);//swap pivot with element at parition Index 

	return pIndex;
}
void QuickSort(vector<int>&a,int start,int end)
{
	if(start>=end)//if only one element left then return 
		return ;
	
	int pIndex=partition(a,start,end);//this give index of pivot after rearragement 
	/*
	after partition call all elements left of pivot are small 
	and all elements greater than pivot are large 
	*/

	QuickSort(a,start,pIndex-1);
	QuickSort(a,pIndex+1,end); 
}
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	cout << "Before sorting" << endl;
	printArray(a);

	QuickSort(a,0,n-1);

	cout << endl
		 << "After sorting" << endl;
	printArray(a);
}