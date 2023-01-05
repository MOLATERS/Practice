#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        return n - intervalSchedule(intervals);
    }

    // ��������㷨����� intvs ������м��������ཻ������
    int intervalSchedule(int[][] intvs) {
        if (intvs.length == 0) return 0;
        // �� end ��������
        Arrays.sort(intvs, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });
        // ������һ�����䲻�ཻ
        int count = 1;
        // ����󣬵�һ��������� x
        int x_end = intvs[0][1];
        for (int[] interval : intvs) {
            int start = interval[0];
            if (start >= x_end) {
                // �ҵ���һ��ѡ���������
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
}
// ��ϸ�����μ���
// https://labuladong.github.io/article/?qno=435