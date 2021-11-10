#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// count word
int wordCount(char str[], int length)
{
  int word = (str[0] != ' ');
  for (int i = 0; i < length - 1; i++)
  {
    if (str[i] == ' ' && str[i + 1] != ' ')
    {
      word++;
    }
  }
  return word;
}

// count character
void charCount(char str[], int length)
{
  int contIndex = 0;
  string strData = "";
  for (int i = 0; i < length + 1; i++)
  {
    if (str[i] != ' ') {
      contIndex++;
      strData = strData + str[i];
    }
    if (str[i] == ' ' || !str[i+1]) {
      cout << strData + " : " << contIndex << endl;
      strData = "";
      contIndex = 0;
    }
  }
}

// Find one left of string s
void findWordLeft(char str[], int length) {
  string strData = "";
  for (int i = 0; i < length + 1; i++)
  {
    if (str[i] != ' ' || !str[i+1]) {
      strData = strData + str[i];
    }
    if (str[i] == ' ') {
      break;
    }
  }
  cout << "==> Tu ben trai: "<< strData << endl;
}

int main()
{
  string strCharater = "truong dai hoc cong nghe thong tin truong dai hoc quoc gia tp hcm";
  int length = strCharater.length();
  char char_array[length];
  cout << length<< endl;
  strcpy(char_array, strCharater.c_str());

  // word count
  cout << "==> So tu cua chuoi: " << wordCount(char_array, length) << endl;

  // count character of word
  charCount(char_array, length);

  // Left word
  findWordLeft(char_array, length);

  return 0;
}