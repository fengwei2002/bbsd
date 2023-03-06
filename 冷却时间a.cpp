#include <bits/stdc++.h>
using namespace std;
// A 角色： 冷却 k1 攻击力 d1
// B 角色： 冷却 k2 攻击力 d2
// 总时长是 t 秒
// 如果一起打，则 d1*=0.12, d2*=0.12

class player {
  public:
   int time, power;
   player(int _time, int _power) {
      this->time = _time;
      this->power = _power;
      cout << "create player time: " << _time << " power: " << _power << '\n';
   }
};

// 贪心可得充分利用所有时间是最佳选择，每一个选手都不停的攻击，取总和即可
double maxPower(player& A, player& B, int totalTime, double x) {
   double ans = 0.0;
   int minTogetherTime = A.time * B.time / gcd(A.time, B.time);
   // 重合的时间点，minTogetherTime
   int aCnt = totalTime / A.time;
   int bCnt = totalTime / B.time;
   ans = aCnt * A.power + bCnt * B.power;
   if (totalTime < minTogetherTime) {
      // 没有重合的时间点，正常运行
      return ans;
   }
   // 否则计算存在多少次合体暴击
   int togeterCnt = totalTime / minTogetherTime;
   // 然后在原有的 ans 的暴击处加上这些合体暴击的攻击力
   cout << "have " << togeterCnt << " together" << '\n';
   ans += togeterCnt * (x * A.power + x * B.power);
   return ans;
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int totalTime = 0;
   cin >> totalTime;
   int k1, k2, d1, d2;
   cin >> k1 >> k2 >> d1 >> d2;
   double x = 0.0;
   cin >> x;
   // edge:
   // 10
   // 2 4 100 200
   // 0.12

   auto A = player(k1, d1);
   auto B = player(k2, d2);

   cout << maxPower(A, B, totalTime, x);

   return 0;
}