# Sorting

-   [Classification]()
-   [Selection Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#selection-sort-slow-sorting-algo-on2)
-   [Bubble Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#bubble-sort)
-   [Insertion sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#insertion-sort)
-   [Merge Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#merge-sort)
-   [Quick Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#quick-sort)
-   [Shell Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#shell-sort)
-   [Count Sort](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#count-sort)
-   [All time complexity](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#count-sort)
-   [All space complexity](https://github.com/bhagat-hrishi/Ds-Algo/tree/main/Sorting#count-sort)

## Classification of sorting algo

-   Time complexity
-   Space complexity or Memory Usage
    -   Some sorting algos are inplace **(They use constant amount of extra memory)**
    -
-   Stability

    -   For **Stable sorting algo** when elements are equal then relative order is maintained

    -   ![StaBility](https://media.geeksforgeeks.org/wp-content/cdn-uploads/stability-sorting.jpg)

-   Internal or External sort
    -   Internal
        -   When all records that we want to sort are present in RAM
        -   Sort algorithms that use main memory exclusively during the sort
    -   External
        -   Records are on disk or tapes as all of this record fetching is not possible
        -   Sorting algorithms that use external memory
-   Recusrive or Iterative
    -   Recursive
        -   Quick
        -   **Merge**
    -   Iterative
        -   Insertion
        -   Selection
        -   **Merge**

### Selection Sort (**Slow Sorting Algo [O(n^2)]**)

-   Find the minimum value in the list
-   Swap it with the value in the current position
-   Repeat this process for all the elements until the entire array is sorted
-   ![Selection Sort](https://i2.wp.com/algorithms.tutorialhorizon.com/files/2019/01/Selection-Sort-Gif.gif?ssl=1)
-   Code

```
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
```

### Bubble Sort

-   a[current element] > a[next element] then swap
    ![Selection Sort](https://www.programmingsimplified.com/images/c/bubble-sort.gif)

-   Code

```
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
}
```

## Insertion Sort

-   ![Insertion Sort](https://thagomizer.com/img/InsertionSortInPlace.gif)
-   Code

```
int n = a.size();
for (int index = 1; index < n; index++)
{
    int j=index-1;
    int val=a[index];
    while(j>0 && a[j]>val)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=val;
}
```

### Merge Sort

### Quick Sort

-   ![Quick Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/quick_sort_partition_animation.gif)
-   ![Quick Sort](https://fullyunderstood.com/wp-content/uploads/2019/09/quicksort.gif)
-   Algo
    -   select one of element as pivot(here we select righmost) and all elements less than pivot are to left and all elements greater than pivot are to right
    -   Then sort segment of pivot on left and sort segment on pivot to right
-   Code

```
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

//call to this QuickSort(a,0,n-1);
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
```

### Shell Sort

-   ![Shell Sort](https://www.programmersought.com/images/328/bbd7d8f1c8b40dad6ca9b812117deb98.gif)
-   Also known as - `Diminishing increment sort` - `n-gap insertion sort`
-   generalized of insertion sort

## Linear Sorting Algo

### Count Sort

-   not comparison base
-   Complexity O(n)
-   ![Counting Sort 1](https://www.codesdope.com/staticroot/images/algorithm/count1.gif)
-   ![Counting Sort 2](https://miro.medium.com/max/1432/0*B-CyBxmCVUolqSjj.gif)

```
void countSort(vector<int> &a)
{
	int n = a.size();

	int maxofa = a[0];

	// Find max element from array
	for (int i = 0; i < a.size(); i++)
	{
		maxofa = max(maxofa, a[i]);
	}
	// max define size of count array

	// make array of size max  and init all element to 0
	vector<int> count(maxofa + 1, 0);

	// store count of each element from original array
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}

	// modify count array (a)
	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	// make output array
	vector<int> output(n);

	// traverse original array from last
	for (int i = n - 1; i >= 0; i--)
	{
		output[--count[a[i]]] = a[i];
	}

	// now put output array inside original array
	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}
```

## Time Complexity of All Sorting Algos

> ![Time Complexity](https://he-s3.s3.amazonaws.com/media/uploads/c950295.png)

## Inplace and Stable

> ![Inplace and Stable](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/comparison-of-sorting-algorithms-compare3-205baca859250562.png)
