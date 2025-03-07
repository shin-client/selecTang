#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void interchangeSort(vector<int>& a, bool greater = false) {
  int n = a.size();
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j)
      if (!greater) {
        if (a[i] > a[j]) swap(a[i], a[j]);
      }
      else {
        if (a[i] < a[j]) swap(a[i], a[j]);
      }
}

void selectionSort(vector<int>& a, bool greater = false) {
  int n = a.size();
  for (int i = 0; i < n - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (!greater) {
        if (a[min] > a[j]) min = j;
      }
      else {
        if (a[min] < a[j]) min = j;
      }
    }
    swap(a[min], a[i]);
  }
}

void bubbleSort(vector<int> &a, bool greater = false) {
  int n = a.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      bool condition = greater ? (a[j] < a[j + 1]) : (a[j] > a[j + 1]);
      if (condition) {
        swap(a[j], a[j + 1]);
      }
    }
  }
}

void quickSort(vector<int> &a, int l, int r, bool greater = false){
  if (l >= r) return;
  int p = a[l + (r - l) / 2];
  int i = l, j = r;
  while (i <= j){
    if (!greater) {
      while (a[i] < p) i++;
      while (a[j] > p) j--;
    } else {
      while (a[i] > p) i++;
      while (a[j] < p) j--;
    }
    if (i <= j){
      swap(a[i], a[j]);
      i++; j--;
    }
  }
  if (l < j) quickSort(a, l, j);
  if (i < r) quickSort(a, i, r);
}

int main() {
  faster();
  freopen("test.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // Code
  int x;
  vector<int> a;
  auto start = high_resolution_clock::now();
  while (cin >> x) a.push_back(x);
  selectionSort(a);
  auto stop = high_resolution_clock::now();
  // End code

  // Measure execution time
  duration<double> total_duration = stop - start;
  cout << fixed << setprecision(10) << "Thoi gian ham thuc thi la: "
       << total_duration.count() << " giay";
  return 0;
}
