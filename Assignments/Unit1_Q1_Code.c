/*
A company stores employee IDs in ascending order. Write a C program that
accepts n employee IDs, searches for a required ID using Binary Search,
displays its position when found, reports when it is absent, and counts the
number of comparisons. Test the program for both successful and unsuccessful
searches.
*/

#include <stdio.h>
int main()
{
	int a[100],n,id;
	int low,high,mid;
	int comp=0;
	int found=0;
	printf("Enter number of employee IDs: ");
	scanf("%d",&n);
	printf("Enter employee IDs in ascending order:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter employee ID to search: ");
	scanf("%d",&id);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		comp++;
		if(a[mid]==id)
		{
			printf("Employee ID found at position %d\n",mid+1);
			found=1;
			break;
		}
		else if(id<a[mid])
		{
			high=mid-1;
		}
		else if(id>a[mid])
		{
			low=mid+1;
		}
	}
	if(!found)
		printf("Employee ID not found\n");

	printf("Number of comparisons = %d\n",comp);
	return 0;
}
