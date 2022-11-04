
#include <iostream>
using namespace std;

// optimal - 最佳的
/*
    最优子结构：
    定义集合S[i][j]={a[k]∈S:f[i]≤ s[k] < f[k] ≤ s[j] }。为了完整地表示问题，加入两个虚拟活动a[0]和
    a[n + 1],其中，f[0] = 0，s[n+1]=∞，这样S=S[0] ~ S[n+1]

    【定理8.3】对于任意非空子问题S[i][j],设a[m]是S[i][j]中具有最早结束时间的活动。
    那么，(1)活动a[m]在S[i][j]的某个最大兼容活动子集中。
         (2)子问题S[i][m]为空，所以选择a[m]将使S[m][j]为唯一可能非空的子问题。
    假设对n个活动按其结束时间单调递增进行了排序，排序的时间复杂度为O(nlgn)。下面给出解决活动选择问题的贪心算法的递归形式和迭代形式。
 */

/*
  评论：这要用在操作系统的优先级调度上，肯定有进程会被饿死
 */

int OptimalSubset[100];
// s-start, f-final
int RecursiveActivitySelector(int* s, int* f, int index, int n) {
  int m = index + 1;
  static int activity_number = 0;
  while (m <= n && s[m] <= f[index]) // 寻找一个活动晚于index活动的活动，f[index]相当于【最优子结构】中描述的f[j]
    m++;
  if (m <= n) {
    OptimalSubset[activity_number++] = m;
    RecursiveActivitySelector(s, f, m, n);
  } else {
    return activity_number;
  }
}

int GreedyActivitySelector(int* s, int* f, int n) {
  int activity_number = 0;
  OptimalSubset[activity_number++] = 1; // 选择活动1
  int index = 1;
  int m;
  for (m = 2; m <= n; m++) {
    if (s[m] >= f[index]) {                 // 寻找开始时间晚于index结束的活动
      OptimalSubset[activity_number++] = m; // 选择找到的活动
      index = m;                            // 继续寻找
    }
  }
  return activity_number;
}


void main(int argc, char* argv[]) {
  int s[13] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, 10000}, f[13] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0};
  //RecursiveActivitySelector(s, f, 0, 13);
  GreedyActivitySelector(s, f, 13);
}
