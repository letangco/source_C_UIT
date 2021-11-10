#include <iostream>
#include <queue>

using namespace std;

// input array function
void input_array(int array[], int length)
{
  for (short i = 0; i < length; i++)
  {
    cout << "Nhap phan tu thu " << i + 1 << " : ";
    cin >> array[i];
  }
}

// out array function
void show_array(int array[], int length)
{
  for (short i = 0; i < length; i++)
    cout << array[i] << ' ';
}

// Check perfect num
bool isValidPerfectNum(int n)
{
  int tempNum = 0;
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
      tempNum = tempNum + i;
  }

  if (tempNum != 0 && tempNum == n)
    return true;
  else
    return false;
}

// get output perfect num
void output_Perfect_Num(int arr[], int n)
{
  int coutPerfect = 0;
  for (int i = 0; i < n; i++)
  {
    if (isValidPerfectNum(arr[i]))
    {
      cout << arr[i] << " ";
      coutPerfect++;
    }
  }
  cout << "==> Co " << coutPerfect << " so hoan hao trong mang." << endl;
}

// Last PerfectNumber
int last_perfect_num(int arr[], int n)
{
  int payload;
  queue<int> lastPerfectNum;

  for (int i = 0; i < n; i++)
  {
    if (isValidPerfectNum(arr[i]))
    {
      lastPerfectNum.push(arr[i]);
    }
  }
  int numberSize = lastPerfectNum.size();
  if (numberSize > 0)
  {
    payload = lastPerfectNum.back();
  }
  else
    payload = 0;
  return payload;
}

// Find max number in array
int findMaxNumber(int array[], int n)
{
  int i;
  int maxElement = array[0];
  for (i = 1; i < n; i++)
  {
    if (maxElement < array[i])
    {
      maxElement = array[i];
    }
  }
  return maxElement;
}

// Find min number in array
int findMinNumber(int array[], int n)
{
  int i;
  int minElement = array[0];
  for (i = 1; i < n; i++)
  {
    if (minElement > array[i])
    {
      minElement = array[i];
    }
  }
  return minElement;
}

// append x to behind max number
void insert_behind_max_number(int A[], int *n, int x)
{
  int i, j;
  int maxElement = findMaxNumber(A, *n);
  for (i = *n - 1; i >= 0; i--)
  {
    if (A[i] == maxElement)
    {
      (*n)++;
      for (j = *n - 1; j > i; j--)
      {
        A[j] = A[j - 1];
      }
      A[j + 1] = x;
    }
  }
}

// Replace Max NUmber to min number
void replaceMaxtoMinNumber(int arr[], int n)
{
  int max = findMaxNumber(arr, n);
  int min = findMinNumber(arr, n);

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == max)
    {
      arr[i] = min;
    }
  }
}


// Delete duplicate number
void deleteDupNumber(int a[], int *N)
{
  int i, j, k;
  for (i = 0; i < (*N) - 1; i++)
  {
    j = i + 1;
    while (j < *N)
      if (a[i] == a[j])
      {
        for (k = j; k < (*N) - 1; k++)
          a[k] = a[k + 1];
        *N = (*N) - 1;
      }
      else
        j = j + 1;
  }
}

int main()
{
  int n;
  cout << "=>> Nhap so phan tu: ";
  cin >> n;

  while (n > 100 || n < 1)
  {
    cout << "==> Nhap nam trong khoang (0, 100], vui long nhap lai!" << endl;
    cout << "Nhap so phan tu: ";
    cin >> n;
  }

  int array[n - 1];
  input_array(array, n);

  // Out put perfect Num
  cout << "=>> So hoan hao: ";
  output_Perfect_Num(array, n);

  // Last perfect number
  int lastPerfectNum = last_perfect_num(array, n);
  if (lastPerfectNum == 0)
  {
    cout << "==> Khong co so hoan hao nao." << endl;
  }
  else
  {
    cout << "==> So hoan hao cuoi cung: " << lastPerfectNum << endl;
  }

  // append x to behind max number
  int X;
  cout << "Nhap x: ";
  cin >> X;

  insert_behind_max_number(array, &n, X);
  cout << "=>> Mang sau khi chen X: [";
  show_array(array, n);
  cout << ']' << endl;

  // Replace max Number to min Number
  replaceMaxtoMinNumber(array, n);
  cout << "=>> Mang sau khi replace max number to min number: [";
  show_array(array, n);
  cout << ']' << endl;

  // Delete dup number
  deleteDupNumber(array, &n);
  cout << "=>> Mang sau khi xoa trung: [";
  show_array(array, n);
  cout << ']' << endl;

  return 0;
}