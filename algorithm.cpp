#include <stdio.h>
#include <stdlib.h>
 
struct space
{
  int key;
  char data;
  float price;
};
struct space *arr;
int MAX = 10;
int size = 0;
 
int hash_func(int a)
{
  return (a % MAX);
}
int space_hashtable()
{
  return size;
}
int check_primeNumber(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
    return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}
int get_primeNumber(int n)
{
  if (n % 2 == 0)
  {
    n++;
  }
  while (!check_primeNumber(n))
  {
    n += 2;
  }
  return n;
}
void create()
{
  MAX = get_primeNumber(MAX);
  arr = (struct space *)malloc(MAX * sizeof(struct space));
  for (int i = 0; i < MAX; i++)
  {
    arr[i].key = 0;
    arr[i].data =NULL;
    arr[i].price=0;
  }
}
 
void add(int key, char data,float price)
{
  int index = hash_func(key);
  if (arr[index].data == 0)
  {
    arr[index].key = key;
    arr[index].data = data;
    arr[index].price=price;
    size++;
    printf("\nda duoc them\n");
  }
  else if (arr[index].key == key)
  {
    arr[index].data = data;
    arr[index].price=price;
  }
  else
  {
    printf("\nCo Loi\n");
  }
}
 
void del(int key)
{
  int index = hash_func(key);
  if (arr[index].data == NULL)
  {
    printf("\nKhong ton tai\n");
  }
  else
  {
    arr[index].key = 0;
    arr[index].data = NULL;
    arr[index].price=0;
    size--;
    printf("\nda xoa\n");
  }
}
void print(){
  int i;
  int m = space_hashtable();
  for (i = 0; i <= m; i++)
  {
    if (arr[i].data != NULL)
    {
    	printf("\nKhoa: %d du lieu a[%d]: %s f\t", arr[i].key, i, arr[i].data, arr[i].price);
    }
  }
}
void timkiem(int key){
	
	int index = hash_func(key);
  if (arr[index].data == NULL)
  {
    printf("\nKhong ton tai\n");
  }
  else
  {
    printf("\nTIM THAY\n");
  }
}

 
int main()
{
  int inp, key, n;
  int c = 0;
  char data;
  float price;
  create();
  printf("\rCac thao tac voi bang bam\n");
  do
  {
    printf("1.Them phan tu"
         "\n2.Xoa phan tu"
         "\n3.Tim Kiem"
         "\n4.In gia tri?"
         "\n\nMoi Ban Nhap: ");
    scanf("%d", &inp);
    switch (inp)
    {
    case 1:
      printf("Khoa: ");
      scanf("%d", &key);
      printf("du lieu: ");
      scanf("%s", &data);
       printf("price: ");
      scanf("%f", &price);
      add(key, data,price);
      break;
 
    case 2:
      printf("Nhap khoa:");
      scanf("%d", &key);
      del(key);
      break;
 
    case 3:
      printf("Nhap khoa:");
      scanf("%d", &key);
      timkiem(key);
      break;
 
    case 4:
      print();
      break;
 
    default:
      printf("Ban da nhap qua gia tri cho phep\n");
    }
    printf("\nban co muon tiep tuc khong(1/0): ");
    scanf("%d", &c);
  } while (c == 1);
  printf("\nKet thuc");
}
