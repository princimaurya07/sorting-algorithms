#include<iostream>
#include<string>
using namespace std;
string partition(long long arr[],int l,int h)
{
	long long pivot=arr[l],temp;
	char s[2];
	int j=l,k;
	for(int i=l+1;i<=h;i++)
	{
		if(arr[i]<=pivot)
		{
		    j++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;	
			}	
	}
	
	k=j;
	for(int i=j;i>=l;i--)
	{
		if(arr[i]==pivot){
		   temp=arr[i];
		   arr[i]=arr[k];
		   arr[k]=temp;
		   k--;
    	}
	}
    s[0]=k+1;
	s[1]=j;
	return s;
	
}
int qsort(long long arr[],int l,int h)
{
	string r;
	if(l>=h)
	  return 0 ;
	 r=partition(arr,l,h);
	 qsort(arr,l,(int)r[0]-1);
	 qsort(arr,(int)r[1]+1,h);
   return 0;	  
}
int main()
{
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int l=0,h=n-1;
	
	qsort(arr,l,h);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
