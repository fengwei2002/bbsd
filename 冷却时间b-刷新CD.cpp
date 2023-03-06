// B 可以刷新 A 的 CD 
#include <bits/stdc++.h>
using namespace std;

class player {
  public:
   int time, power;
   player(int _time, int _power) {
      this->time = _time;
      this->power = _power;
      cout << "create player time: " << _time << " power: " << _power << '\n';
   }
};

double maxPower(player& A, player& B, int totalTime) {
   int aCnt = totalTime / A.time;
   int bCnt = totalTime / B.time;
   int ans = aCnt * A.power + bCnt * B.power;
   return ans;
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   // 如果 a 的 CD 大于 B 的 CD，那么 B 正常释放技能，A 跟着 B 释放即可
   // 如果 a 的 CD 小于 B 的 CD，那么 B 的刷新没有价值，所以两个玩家都正常释放

   return 0;
}