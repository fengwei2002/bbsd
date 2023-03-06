#include <bits/stdc++.h>
using namespace std;

bool can(vector<int>& a, int k) {
   int sum = accumulate(a.begin(), a.end(), 0);
   if (sum % k) return false;
   int edgeLen = sum / k;
   int n = (int)a.size();
   sort(a.begin(), a.end(), [](int x, int y) { return x > y; });
   vector<bool> st(n, false);
   function<bool(int, int, int)> dfs = [&](int startIdx, int nowLen,
                                           int nowCnt) -> bool {
      if (nowCnt == k - 1) return true;
      if (nowLen == edgeLen) {
         return dfs(0, 0, nowCnt + 1);
      }
      for (int i = startIdx; i < n; i++) {
         if (st[i] == true) continue;
         if (nowLen + a[i] <= edgeLen) {
            st[i] = true;
            if (dfs(i + 1, nowLen + a[i], nowCnt)) {
               return true;
            }
            st[i] = false;
         }
         if (nowLen == 0 || nowLen == edgeLen) return false;
         while (i + 1 < n and a[i] == a[i + 1]) i++;
      }
      return false;
   };

   return dfs(0, 0, 0);
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int k = 0;
   cin >> k;
   bool ok = can(a, k);
   if (ok) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
   return 0;
}