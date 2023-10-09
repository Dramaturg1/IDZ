#include <iostream>
#include <vector>

using namespace std;

double S(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	int t;
	vector<double> result;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int ax, ay, bx, by, px, py;
		cin >> px >> py >> ax >> ay >> bx >> by;
		if (S(0, 0, ax, ay) < S(0, 0, bx, by) && S(px, py, ax, ay) < S(px, py, bx, by)) {
			if (S(ax, ay, 0, 0) > S(ax, ay, px, py)) result.push_back(S(ax, ay, 0, 0));
			else result.push_back(S(ax, ay, px, py));
		};
		if (S(0, 0, bx, by) < S(0, 0, ax, ay) && S(px, py, bx, by) < S(px, py, ax, ay)) {
			if (S(bx, by, 0, 0) > S(bx, by, px, py)) result.push_back(S(bx, by, 0, 0));
			else result.push_back(S(bx, by, px, py));
		}
		if ((S(ax, ay, 0, 0) <= S(0, 0, bx, by) && S(px, py, bx, by) <= S(px, py, ax, ay)) || (S(bx, by, 0, 0) <= S(ax, ay, 0, 0) && S(px, py, ax, ay) <= S(px, py, bx, by))) {
			result.push_back(S(ax, ay, bx, by) / 2);
		}
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	};
}

#if 0

2 
3 3
1 0
-1 6
3 3
-1 -1
4 3

1
3 4
2 2
-1 -1

2 
1 2
3 4
-5 -6
5 6
-7 -8

3 
0 0
2 0
0 3
1 1
-1 -1
0 1
0 -2

#endif
