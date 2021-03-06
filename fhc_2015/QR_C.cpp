//
// Facebook Hacker Cup 2015 Qualification Round
// C. Laser Maze
//

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class Solver {
	int H;
	int W;
	int sx;
	int sy;
	int gx;
	int gy;
	vector<string> maze;
	int z[100][100];
	int vis[4][100][100];

	void fill_lazer(int x, int y, int dir) {
		const int dx[4] = { -1, 0, 1, 0 };
		const int dy[4] = { 0, -1, 0, 1 };
		for (int i = 0; i < 4; ++i) {
			for (int j = 1; ; ++j) {
				int xx = x + dx[(dir + i) % 4] * j;
				int yy = y + dy[(dir + i) % 4] * j;
				if (xx >= 0 && yy >= 0 && xx < W && yy < H && maze[yy][xx] == '.') {
					z[yy][xx] |= (1 << i);
				} else {
					break;
				}
			}
		}
	}

	void init(void) {
		memset(z, 0, sizeof(z));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				switch (maze[i][j]) {
				case 'S':
					sx = j, sy = i;
					maze[i][j] = '.';
					break;
				case 'G':
					gx = j, gy = i;
					maze[i][j] = '.';
					break;
				}
			}
		}
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				switch (maze[i][j]) {
				case '<':
					fill_lazer(j, i, 0);
					break;
				case '^':
					fill_lazer(j, i, 1);
					break;
				case '>':
					fill_lazer(j, i, 2);
					break;
				case 'v':
					fill_lazer(j, i, 3);
					break;
				}
			}
		}
	}

public:
	Solver(int h, int w, const vector<string> &m) : H(h), W(w), maze(m) {
		init();
	}

	int solve(void) {
		IIVec q;
		q.push_back(II(sx, sy));
		for (int t = 1; q.size() > 0; ++t) {
			IIVec next;
			for (int i = 0; i < (int)q.size(); ++i) {
				const int dx[4] = { -1, 0, 1, 0 };
				const int dy[4] = { 0, -1, 0, 1 };
				for (int d = 0; d < 4; ++d) {
					int x = q[i].first + dx[d], y = q[i].second + dy[d];
					if (x >= 0 && y >= 0 && x < W && y < H && ((1 << (t % 4)) & z[y][x]) == 0) {
						if (x == gx && y == gy) {
							return t;
						}
						if (!vis[t % 4][y][x] && maze[y][x] == '.') {
							vis[t % 4][y][x] = 1;
							next.push_back(II(x, y));
						}
					}
				}
			}
			q = next;
		}
		return -1;
	}
};

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int H, W;
		ss >> H >> W;
		vector<string> maze(H);
		for (int i = 0; i < H; ++i) {
			getline(cin, maze[i]);
		}
		Solver solver(H, W, maze);
		int ans = solver.solve();
		cout << "Case #" << (t + 1) << ": ";
		if (ans >= 0) {
			cout << ans << endl;
		} else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}
