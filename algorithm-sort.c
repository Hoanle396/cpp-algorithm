#include <stdio.h>
#include <time.h>

const int MAX = 10000;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
void SortBubble(int a[], int n);
void SelectionSort(int arr[], int n);
void quicksort(int arr[],int first,int last);
void insertionSort(int arr[], int n);
int Linear(int a[], int n, int v);

int main(){
    int arr[MAX];
    int n;
    printf("\nNUMBER OF COMPONENTS: ");
    do{
        scanf("%d", &n);
        if(n <= 0 || n > MAX){
            printf("\n  RE-ENTER THE NUMBER OF COMPONENTS: ");
        }
    }while(n <= 0 || n > MAX);
    NhapMang(arr, n);
    printf("\n======OUTPUT ARRAY=====\n");
    XuatMang(arr, n);
    printf("\n======SORT======\n");
    insertionSort(arr,n);
    getch();
    printf("\n======SREACH======\n");
    int v;
    printf("\nINPUT SREACH: ");
    scanf("%d", &v);
    if(Linear(arr, n, v)==-1){
    	printf("NOT PRESENT");
    }
    else{
    	printf("\n%d FOUND IN LOCATION %d", v, Linear(arr, n, v));
    }
}

void NhapMang(int a[], int n){
	int i;
    for(i = 0;i < n; ++i){
       a[i]=rand()%1001;
    }
}
void XuatMang(int a[], int n){
	int i;
    for(i = 0;i < n; ++i){
        printf("\n a[%d] = %d", i, a[i]);
    }
}
// sap xep noi boi
 void SortBubble(int a[], int n){
 	float start=clock();
    int Mid;
    int i ,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(a[j]>a[i]){
                Mid=a[i];
                a[i]=a[j];
                a[j]=Mid;
            }
        }
     }
	float end=clock();
    printf("TIME %f",(end-start));   
    //O(n^2)
}
// sap xep chon
//void SelectionSort(int arr[], int n)
//{
	
//    int i, j, min_idx;
//    float start=clock();
//    for (i = 0; i < n-1; i++)
//    {
//    min_idx = i;
//    for (j = i+1; j < n; j++)
//        if (arr[j] < arr[min_idx])
//        min_idx = j;
//        swap(arr[min_idx], arr[i]);
//    }
//     float end=clock();
//    printf("TIME %f",(end-start));
//}
// quicksort
void quicksort(int arr[],int first,int last){
   int i, j, pivot, temp;
   float start=clock();
   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quicksort(arr,first,j-1);
      quicksort(arr,j+1,last);

   }
    float end=clock();
    printf("TIME %f",(end-start));
} 
// sap xep chen
void insertionSort(int arr[], int n)
{
   int i, key, j;
   double start=clock();
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
    double end=clock();
    printf("TIME %fs",(end-start));
}
//tim kiem nhi phan
int Linear(int a[], int n, int v){
	int i;
    for(i = 0;i < n; ++i){   // O(n)
        if(a[i] == v){
            return i;
        }
    }
    return -1;
}
 
