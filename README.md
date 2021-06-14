# Data Structure and Algorihtms
## Time complexity
- Time taken by algo as function of length of i/p 
## Sorting 
- Inplace sorting algo take const amount of extra memory
- Classification of sorting algo 
    - Time complexity 
    - Space complexity  or Memory Usage 
        - Some sorting algos are inplace **(They use constant amount of extra memory)**
        - 
    - Stability 
        - For **Stable sorting algo** when elements are equal then relative order is maintained 
    
        - ![StaBility](https://media.geeksforgeeks.org/wp-content/cdn-uploads/stability-sorting.jpg)
    
    - Internal or External sort 
        - Internal 
            - When all records that we want to sort are present in RAM
            - Sort algorithms that use main memory exclusively during the sort 
        - External 
            - Records are on disk or tapes as all of this record fetching is not possible 
            - Sorting algorithms that use external memory
    - Recusrive or Iterative 
        - Recursive 
            - Quick 
            - **Merge** 
        - Iterative 
            - Insertion 
            - Selection  
            - **Merge**
- Selection Sort (**Slow Sorting Algo [O(n^2)]**)
    - Selecting min at each pass and put element at 
    appropriate position. 
    ![Selection Sort](https://i2.wp.com/algorithms.tutorialhorizon.com/files/2019/01/Selection-Sort-Gif.gif?ssl=1)
    - Code 
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
    

- Bubble Sort
    - a[current element]  > a[next element] then swap
     ![Selection Sort](https://www.programmingsimplified.com/images/c/bubble-sort.gif)

    - Code 

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

- Insertion Sort 
    - ![Insertion Sort](https://thagomizer.com/img/InsertionSortInPlace.gif)
    - Code 
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
- Merge Sort 

- Quick Sort 
- ![Quick Sort](https://www.tutorialspoint.com/data_structures_algorithms/images/quick_sort_partition_animation.gif)
- ![Quick Sort](https://fullyunderstood.com/wp-content/uploads/2019/09/quicksort.gif)
- Algo 
    - select one of element as pivot(here we select righmost) and all elements less than pivot are to left and all elements greater than pivot are to right
    - Then sort segment of pivot on left and sort segment on pivot to right
- Code 
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



   
- Time Complexity of All Sorting Algos 
    ![Time Complexity](https://he-s3.s3.amazonaws.com/media/uploads/c950295.png)
- Inplace and Stable 
    ![Inplace and Stable](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/comparison-of-sorting-algorithms-compare3-205baca859250562.png)
    

## Heap
- To identify heap question 
    - K is given 
    - to find smallest or largest
        - if smallest make min heap
        - if largest make max heap
- STL 
    - max heap 
    > `priority_queue <int> max_heap`

    - min heap 
    > `priority_queue< int,vector<int>,greater<int> >min_heap`

- Note 
    - for every heap questions first discuss sorting approach



## Sliding window
- To identify sliding window question
    - given array or string and question ask about some subarry or substring and also about some largetst or min and k(window size) is given 
- Types of sliding window
    - Fixed size window
        - window size is fixed and asked some info on windows(like max sum or min sum etc.)
        - Easy problem
    - Variable size window
        - window size **not** given , window size may be  asked or  some sum or max , min is given 
        - Comparatively hard some times need to use map and list 
- note 
    - sliding window is always continous


## Binary Search 
- Time complexity - O(log(n))
- Whenever there is **sorted** keyword thing once to apply Binary Search


## Stack 
- Identification 
    - if array is presnet may be stack or heap (may be u want to sort for heap)
    - 

