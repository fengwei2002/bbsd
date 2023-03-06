#include <bits/stdc++.h>
using namespace std;

// 时间复杂度 O(n)，空间复杂度 O(n)
vector<int> trans1(vector<int>& a) {
   vector<int> ans(0, 0);
   for (int i = 0; i < (int)a.size(); i++) {
      if (a[i] == 0) {
         ans.push_back(0);
         ans.push_back(0);
      } else {
         ans.push_back(a[i]);
      }
   }
   ans.erase(ans.begin() + (int)a.size(), ans.end());
   return ans;
}

// O(n), O(1)
void trans2(vector<int>& a) {
   int n = (int)a.size();
   a.push_back(-1);
   for (int i = 0, cnt = 0; i < n; i++) {
      if (a[i] == 0) {
         cnt += 2;
      } else {
         cnt += 1;
      }
      if (cnt >= n) {
         for (int j = cnt - 1; i >= 0; i--) {
            if (a[i] == 0) {
               a[j] = a[i];
               j--;
               a[j] = a[i];
               j--; // 两次
            } else {
               a[j] = a[i];
               j--;
            }
         }
         break;
      }
   }
   a.pop_back();
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   vector<int> ans = trans1(a);
   for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int)ans.size() - 1];
   }

   trans2(a);
   for (int i = 0; i < (int)a.size(); i++) {
      cout << a[i] << " \n"[i == (int)a.size() - 1];
   }

   return 0;
}