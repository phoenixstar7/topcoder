// BEGIN CUT HERE
/*
SRM 649 Div1 Easy (250)

PROBLEM STATEMENT
You have a string s that contains at least K characters.
Cat Snuke will remove exactly K characters from the string.
Afterwards, Snuke will show you the new string and you have to guess the original indices of all removed characters.
You win the game if you guess all of them correctly.

For example, suppose that s="snuke" and K=2.
Snuke removed two characters and showed you the string "nue".
In this situation you can easily deduce that Snuke must have removed the characters s[0] and s[3].
You announce that the indices of removed characters are 0 and 3, and you win the game.

You are given the string s and the int K.
Return "Certain" (quotes for clarity) if you can always be sure to win the game, regardless of which characters Snuke removes.
Otherwise, return "Uncertain".
Note that the return value is case-sensitive.


DEFINITION
Class:Decipherability
Method:check
Parameters:string, int
Returns:string
Method signature:string check(string s, int K)


CONSTRAINTS
-K will be between 1 and 50, inclusive.
-The length of s will be between K and 50, inclusive.
-Every character in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"snuke"
2

Returns: "Certain"

This is the example from the problem statement. As all characters are unique, you can always determine the indices of the erased ones.


1)
"aba"
1

Returns: "Certain"

Snuke will show you one of the strings "ba", "aa", and "ab".
In the first case you can be sure that he erased the character at index 0.
The second and the third string correspond to indices 1 and 2, respectively.


2)
"aba"
2

Returns: "Uncertain"

If Snuke shows you the string "a", there are two possibilities: either he erased the characters at indices 0 and 1, or the characters at indices 1 and 2.


3)
"abcdabcd"
3

Returns: "Certain"


4)
"koukyoukoukokukikou"
2

Returns: "Uncertain"


5)
"wolfsothe"
8

Returns: "Uncertain"


6)
"aa"
2

Returns: "Certain"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class Decipherability {

public:
	string check(string s, int K) {
		return chk(s, K) ? "Certain" : "Uncertain";
	}

	string check2(string s, int K) {
		return chk2(s, K) ? "Certain" : "Uncertain";
	}

private:
	bool chk(string s, int K) {
		int len = (int)s.length();
		if (len == K) {
			return true;
		}
		for (int i = 0; i < len; ++i) {
			char c = s[i];
			for (int j = 1; j <= K && i + j < len; ++j) {
				if (c == s[i + j]) {
					return false;
				}
			}
		}
		return true;
	}

	bool chk2(string s, int K) {
		int len = (int)s.length();
		int B = 1 << len;
		set<string> m;
		for (int i = 0; i < B; ++i) {
			if (popcount(i) == K) {
				string a;
				for (int j = 0; j < len; ++j) {
					if (((1 << j) & i) == 0) {
						a += s[j];
					}
				}
				if (m.find(a) != m.end()) {
					return false;
				}
				m.insert(a);
			}
		}
		return true;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "snuke";
			int Arg1 = 2;
			string Arg2 = "Certain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 1;
			string Arg2 = "Certain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 2;
			string Arg2 = "Uncertain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcdabcd";
			int Arg1 = 3;
			string Arg2 = "Certain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "koukyoukoukokukikou";
			int Arg1 = 2;
			string Arg2 = "Uncertain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wolfsothe";
			int Arg1 = 8;
			string Arg2 = "Uncertain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aa";
			int Arg1 = 2;
			string Arg2 = "Certain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcabc";
			int Arg1 = 3;
			string Arg2 = "Uncertain";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Decipherability ___test;
	___test.run_test(-1);

#ifdef _DEBUG
	const int T = 10000;
#else
	const int T = 10000000;
#endif
	for (int i = 0; i < T; ++i) {
		int K = (rand() * 3) / (RAND_MAX+1) + 1;
		int N = K + (rand() * 6) / (RAND_MAX + 1);
		char w[64] = {};
		for (int i = 0; i < N; ++i) {
			w[i] = 'a' + (rand() * 12) / (RAND_MAX + 1);
		}
		string a = ___test.check(w, K);
		string b = ___test.check2(w, K);
		if (a != b) {
			printf("err: %s, %d\n", w, K);
			break;
		}
	}

}
// END CUT HERE
