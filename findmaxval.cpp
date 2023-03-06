#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& a) {
   return *max_element(a.begin(), a.end());
   // O(n)
}

int func2(vector<int>& a) {
   // O(logn)
   int l = 0, r = (int)a.size() - 1;
   while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (a[mid] >= a[mid - 1]) {
         l = mid;
      } else {
         r = mid - 1;
      }
   }
   return a[l];
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   cout << func1(a) << ' ' << func2(a) << '\n';
   return 0;
}