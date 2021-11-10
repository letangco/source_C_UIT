#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Patient
{
  char maBN[30];
  char hoTen[30];
  char sdt[10];
  char namSinh[10];
};

typedef Patient PT;

void writeDataPatient(PT &pt)
{
  cout << "Nhap maBN: ";
  cin >> pt.maBN;
  cout << "Nhap hoTen: ";
  cin >> pt.hoTen;
  cout << "Nhap sdt: ";
  cin >> pt.sdt;
  cout << "Nhap namSinh: ";
  cin >> pt.namSinh;
}

void readDataPatient(PT patient)
{
  cout << " - maBN patient: " << patient.maBN << endl;
  cout << " - Ho ten patient: " << patient.hoTen << endl;
  cout << " - sdt patient: " << patient.sdt << endl;
  cout << " - namSinh patient: " << patient.namSinh << endl;
}

void inputListPatient(PT a[], int n)
{
  cout << "\n____________________________________\n";
  for (int i = 0; i < n; ++i)
  {
    cout << "\nNhap PT thu " << i + 1 << endl;
    writeDataPatient(a[i]);
  }
  printf("\n____________________________________\n");
}

void outputListPatient(PT a[], int n)
{
  cout << "\n____________________________________\n";
  for (int i = 0; i < n; ++i)
  {
    cout << "==>> Thong tin PT thu: " << i + 1 << endl;
    readDataPatient(a[i]);
  }
  cout << "\n____________________________________\n";
}

void countPTLess10Year(PT a[], int n)
{
  time_t ttime = time(0);
  tm *local_time = localtime(&ttime);

  int currentYear = 1900 + local_time->tm_year;

  int countYear = 0;
  for (int i = 0; i < n; ++i)
  {
    // conver char to number
    int oldYear = atoi(a[i].namSinh);
    if (currentYear - oldYear < 10)
    {
      countYear++;
    }
  }
  cout << "==>> Number patient < 10 year old: " << countYear << endl;
}

// AVG Year

void avgYearPT(PT a[], int n)
{
  float totalYear = 0;
  for (int i = 0; i < n; ++i)
  {
    // conver char to number
    float oldYear = atoi(a[i].namSinh);
    totalYear += oldYear;
  }
  cout << "==>> Number avg year: " << float(totalYear / n) << endl;
}

// findPAtient
void findPatient(PT a[], int n, string x)
{
  int countPT = 0;
  for (int i = 0; i < n; ++i)
  {
    string s = "";
    s += a[i].hoTen;
    // string tempString = a[i].hoTen
    int isConstant = s.find(x);
    if (isConstant != -1) {
      countPT ++ ;
      readDataPatient(a[i]);
    }
  }
  if (countPT == 0) {
    cout << "Khong tim thay PT." << endl;
  }
}

int main(void)
{
  int n;
  cout << "=>> Nhap so Patient: ";
  cin >> n;
  PT arrayPT[n];
  // Input
  inputListPatient(arrayPT, n);

  // Output
  outputListPatient(arrayPT, n);

  // Cout BN < 10 year
  countPTLess10Year(arrayPT, n);

  // avg year
  avgYearPT(arrayPT, n);

  // FInd name
  string x;
  cout << "Nhap keyword: ";
  cin >> x;
  findPatient(arrayPT, n, x);

  return 0;
}
