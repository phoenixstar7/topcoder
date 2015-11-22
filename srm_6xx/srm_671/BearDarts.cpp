// BEGIN CUT HERE
/*
SRM 671 Div1 Medium (500)

問題
問題
-何回かダーツを投げたスコアが記録されている
-そのうちの4つだけ残し、順にa,b,c,dとする
-a*c=b*dとなる場合の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef map<LL, LL> LLMap;
typedef map<LL, LLMap> LLMapMap;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

class BearDarts {
public:
	long long count(vector <int> w) {
		LL ans = 0;
		LLMapMap m;
		for (LL c = w.size() - 2; c >= 2; --c) {
			for (LL d = c + 1; d < w.size(); ++d) {
				LL g = gcd(w[c], w[d]);
				m[w[c] / g][w[d] / g] += 1;
			}
			LL b = c - 1;
			for (LL a = 0; a < b; ++a) {
				LL g = gcd(w[a], w[b]);
				ans += m[w[b] / g][w[a] / g];
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,8,4,3,6};
			long long Arg1 = 2LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,4,12,1};
			long long Arg1 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42,1000000,1000000,42,1000000,1000000};
			long long Arg1 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1};
			long long Arg1 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,5,4,3,2,1};
			long long Arg1 = 22LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33554432, 33554432, 67108864, 134217728};
			long long Arg1 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 169, 85, 290, 11, 458, 131, 53, 176, 333, 177, 72, 409, 148, 493, 319, 470, 81, 430, 447, 366, 24, 256, 171, 465, 43, 448, 92, 190, 357, 161, 495, 169, 81, 70, 60, 408, 417, 65, 277, 493, 355, 490, 344, 112, 252, 289, 213, 186, 229, 487, 350, 28, 94, 454, 169, 130, 46, 430, 475, 11, 286, 163, 230, 117, 188, 481, 76, 118, 28, 78, 195, 102, 300, 118, 328, 406, 144, 117, 101, 444, 274, 198, 179, 49, 233, 80, 334, 217, 435, 13, 231, 303, 201, 206, 40, 195, 174, 299, 70, 249, 347, 11, 2, 92, 256, 264, 483, 224, 484, 236, 210, 445, 258, 130, 46, 247, 446, 103, 138, 11, 183, 327, 445, 44, 264, 318, 321, 226, 30, 312, 385, 209, 394, 471, 48, 400, 161, 466, 167, 353, 376, 199, 151, 297, 368, 126, 190, 263, 176, 147, 498, 337, 180, 46, 374, 238, 299, 157, 399, 260, 398, 459, 94, 22, 450, 126, 40, 151, 218, 272, 262, 176, 260, 272, 407, 374, 375, 209, 286, 63, 288, 39, 444, 429, 91, 390, 72, 264, 35, 459, 498, 410, 272, 374, 110, 237, 79, 452, 106, 198, 453, 422, 182, 221, 280, 297, 6, 52, 106, 278, 111, 495, 428, 50, 293, 437, 173, 354, 326, 269, 380, 407, 20, 95, 196, 426, 36, 315, 11, 251, 368, 13, 31, 345, 75, 172, 449, 92, 134, 42, 112, 387, 31, 51, 64, 484, 227, 64, 193, 47, 120, 161, 175, 67, 32, 99, 142, 119, 291, 342, 160, 159, 399, 184, 358, 193, 211, 326, 483, 6, 323, 493, 82, 52, 264, 230, 95, 429, 344, 402, 211, 357, 296, 18, 393, 353, 224, 496, 104, 384, 16, 12, 196, 475, 248, 300, 134, 326, 137, 199, 107, 336, 304, 208, 124, 196, 204, 3, 313, 490, 455, 28, 269, 208, 490, 352, 119, 137, 445, 107, 498, 11, 382, 106, 469, 478, 486, 12, 48, 250, 282, 306, 22, 432, 188, 242, 125, 360, 481, 438, 57, 423, 228, 360, 409, 129, 336, 484, 269, 286, 293, 28, 316, 494, 10, 396, 258, 390, 380, 117, 67, 54, 211, 425, 387, 307, 337, 95, 50, 79, 388, 315, 157, 292, 211, 491, 24, 285, 385, 200, 496, 86, 14, 473, 446, 104, 110, 438, 269, 426, 172, 249, 47, 485, 268, 369, 122, 191, 45, 151, 196, 386, 337, 30, 477, 295, 259, 480, 281, 476, 427, 284, 48, 311, 25, 411, 380, 112, 168, 241, 414, 419, 469, 123, 249, 51, 242, 314, 52, 64, 333, 371, 235, 187, 336, 191, 387, 391, 224, 456, 151, 398, 241, 139, 266, 104, 399, 434, 465, 147, 257, 140, 430, 466, 31, 350, 125, 69, 369, 94, 137, 425, 280, 139, 368, 71, 391, 50, 283, 421, 427, 459, 379, 328, 194, 22, 364, 472, 258, 376, 75, 381, 204, 12, 60, 65, 207, 126, 358, 249, 334, 313, 406, 82, 216, 60, 160, 95, 410, 60, 216, 480, 439, 166, 143, 376, 279, 119, 49, 325, 394, 182, 378, 166, 200, 336, 390, 55, 243, 497, 77, 490, 189, 18, 49, 152, 437, 348, 48, 484, 2, 95, 56, 499, 391, 340, 348, 288, 482, 314, 438, 2, 484, 40, 430, 454, 314, 271, 234, 397, 492, 124, 396, 339, 234, 6, 128, 434, 32, 99, 258, 400, 359, 445, 124, 101, 289, 122, 265, 119, 161, 15, 93, 104, 166, 125, 302, 40, 348, 127, 107, 41, 325, 265, 278, 317, 331, 401, 434, 352, 25, 232, 445, 352, 404, 185, 113, 254, 496, 385, 382, 444, 404, 411, 334, 46, 361, 167, 41, 302, 67, 279, 200, 280, 413, 51, 277, 175, 99, 300, 390, 58, 393, 200, 361, 271, 52, 202, 312, 411, 206, 373, 225, 297, 365, 349, 474, 347, 187, 436, 327, 224, 290, 202, 312, 398, 267, 401, 207, 277, 257, 448, 161, 420, 422, 354, 276, 340, 197, 51, 348, 265, 268, 372, 170, 350, 6, 16, 448, 206, 176, 129, 86, 238, 302, 397, 332, 192, 245, 120, 141, 474, 285, 78, 244, 462, 278, 196, 66, 225, 315, 316, 348, 438, 474, 186, 414, 197, 479, 316, 89, 85, 456, 445, 90, 265, 237, 445, 331, 211, 292, 464, 337, 249, 160, 459, 454, 473, 364, 118, 253, 302, 427, 151, 277, 292, 252, 142, 198, 206, 319, 116, 179, 101, 350, 382, 374, 429, 222, 239, 373, 33, 452, 213, 99, 20, 449, 326, 57, 318, 5, 232, 183, 252, 490, 456, 423, 240, 200, 129, 281, 464, 413, 174, 383, 308, 295, 289, 496, 95, 369, 477, 146, 474, 273, 427, 202, 249, 44, 339, 214, 115, 88, 248, 366, 85, 482, 380, 492, 201, 51, 248, 136, 33, 183, 359, 302, 467, 280, 319, 361, 168, 198, 351, 231, 359, 112, 247, 442, 414, 424, 220, 171, 69, 56, 317, 209, 486, 187, 363, 98, 139, 482, 474, 29, 237, 234, 491, 253, 313, 233, 42, 2, 386, 417, 323, 226, 2, 72, 68, 329, 194, 310, 96, 246, 230, 24, 367, 139, 307, 145, 306, 465, 287, 206, 138, 114, 87, 323, 52, 95, 469, 253, 397, 170, 61, 4, 119, 153, 289, 144, 24, 5, 426, 259, 180, 99, 175, 289, 151, 158, 348, 231, 135, 351, 277, 333, 432, 86, 4, 179, 142, 200, 17, 480, 197, 10, 277, 67, 360, 148, 97, 353, 193, 347, 323, 375, 261, 80, 273, 395, 122, 272, 238, 44, 356, 88, 148, 20, 366, 162, 219, 319, 283, 288, 429, 389, 331, 16, 24, 297, 248, 140, 367, 171, 262, 289, 138, 134, 393, 142, 134, 31, 459, 159, 405, 41, 79, 311, 381, 190, 382, 37, 418, 212, 485, 277, 119, 328, 297, 81, 316, 74, 57, 461, 262, 30, 57, 427, 206, 192, 236, 31, 138, 317, 269, 277, 263, 346, 388, 168, 317, 478, 154, 161, 112, 455, 295, 385, 443, 105, 238, 362, 140, 483, 431, 364, 445, 62, 144 };
			long long Arg1 = 1277442LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256, 258, 260, 262, 264, 266, 268, 270, 272, 274, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298, 300, 302, 304, 306, 308, 310, 312, 314, 316, 318, 320, 322, 324, 326, 328, 330, 332, 334, 336, 338, 340, 342, 344, 346, 348, 350, 352, 354, 356, 358, 360, 362, 364, 366, 368, 370, 372, 374, 376, 378, 380, 382, 384, 386, 388, 390, 392, 394, 396, 398, 400, 402, 404, 406, 408, 410, 412, 414, 416, 418, 420, 422, 424, 426, 428, 430, 432, 434, 436, 438, 440, 442, 444, 446, 448, 450, 452, 454, 456, 458, 460, 462, 464, 466, 468, 470, 472, 474, 476, 478, 480, 482, 484, 486, 488, 490, 492, 494, 496, 498, 500, 502, 504, 506, 508, 510, 512, 514, 516, 518, 520, 522, 524, 526, 528, 530, 532, 534, 536, 538, 540, 542, 544, 546, 548, 550, 552, 554, 556, 558, 560, 562, 564, 566, 568, 570, 572, 574, 576, 578, 580, 582, 584, 586, 588, 590, 592, 594, 596, 598, 600, 602, 604, 606, 608, 610, 612, 614, 616, 618, 620, 622, 624, 626, 628, 630, 632, 634, 636, 638, 640, 642, 644, 646, 648, 650, 652, 654, 656, 658, 660, 662, 664, 666, 668, 670, 672, 674, 676, 678, 680, 682, 684, 686, 688, 690, 692, 694, 696, 698, 700, 702, 704, 706, 708, 710, 712, 714, 716, 718, 720, 722, 724, 726, 728, 730, 732, 734, 736, 738, 740, 742, 744, 746, 748, 750, 752, 754, 756, 758, 760, 762, 764, 766, 768, 770, 772, 774, 776, 778, 780, 782, 784, 786, 788, 790, 792, 794, 796, 798, 800, 802, 804, 806, 808, 810, 812, 814, 816, 818, 820, 822, 824, 826, 828, 830, 832, 834, 836, 838, 840, 842, 844, 846, 848, 850, 852, 854, 856, 858, 860, 862, 864, 866, 868, 870, 872, 874, 876, 878, 880, 882, 884, 886, 888, 890, 892, 894, 896, 898, 900, 902, 904, 906, 908, 910, 912, 914, 916, 918, 920, 922, 924, 926, 928, 930, 932, 934, 936, 938, 940, 942, 944, 946, 948, 950, 952, 954, 956, 958, 960, 962, 964, 966, 968, 970, 972, 974, 976, 978, 980, 982, 984, 986, 988, 990, 992, 994, 996, 998, 1000, 1002, 1004, 1006, 1008, 1010, 1012, 1014, 1016, 1018, 1020, 1022, 1024, 1026, 1028, 1030, 1032, 1034, 1036, 1038, 1040, 1042, 1044, 1046, 1048, 1050, 1052, 1054, 1056, 1058, 1060, 1062, 1064, 1066, 1068, 1070, 1072, 1074, 1076, 1078, 1080, 1082, 1084, 1086, 1088, 1090, 1092, 1094, 1096, 1098, 1100, 1102, 1104, 1106, 1108, 1110, 1112, 1114, 1116, 1118, 1120, 1122, 1124, 1126, 1128, 1130, 1132, 1134, 1136, 1138, 1140, 1142, 1144, 1146, 1148, 1150, 1152, 1154, 1156, 1158, 1160, 1162, 1164, 1166, 1168, 1170, 1172, 1174, 1176, 1178, 1180, 1182, 1184, 1186, 1188, 1190, 1192, 1194, 1196, 1198, 1200, 1202, 1204, 1206, 1208, 1210, 1212, 1214, 1216, 1218, 1220, 1222, 1224, 1226, 1228, 1230, 1232, 1234, 1236, 1238, 1240, 1242, 1244, 1246, 1248, 1250, 1252, 1254, 1256, 1258, 1260, 1262, 1264, 1266, 1268, 1270, 1272, 1274, 1276, 1278, 1280, 1282, 1284, 1286, 1288, 1290, 1292, 1294, 1296, 1298, 1300, 1302, 1304, 1306, 1308, 1310, 1312, 1314, 1316, 1318, 1320, 1322, 1324, 1326, 1328, 1330, 1332, 1334, 1336, 1338, 1340, 1342, 1344, 1346, 1348, 1350, 1352, 1354, 1356, 1358, 1360, 1362, 1364, 1366, 1368, 1370, 1372, 1374, 1376, 1378, 1380, 1382, 1384, 1386, 1388, 1390, 1392, 1394, 1396, 1398, 1400, 1402, 1404, 1406, 1408, 1410, 1412, 1414, 1416, 1418, 1420, 1422, 1424, 1426, 1428, 1430, 1432, 1434, 1436, 1438, 1440, 1442, 1444, 1446, 1448, 1450, 1452, 1454, 1456, 1458, 1460, 1462, 1464, 1466, 1468, 1470, 1472, 1474, 1476, 1478, 1480, 1482, 1484, 1486, 1488, 1490, 1492, 1494, 1496, 1498, 1500, 1502, 1504, 1506, 1508, 1510, 1512, 1514, 1516, 1518, 1520, 1522, 1524, 1526, 1528, 1530, 1532, 1534, 1536, 1538, 1540, 1542, 1544, 1546, 1548, 1550, 1552, 1554, 1556, 1558, 1560, 1562, 1564, 1566, 1568, 1570, 1572, 1574, 1576, 1578, 1580, 1582, 1584, 1586, 1588, 1590, 1592, 1594, 1596, 1598, 1600, 1602, 1604, 1606, 1608, 1610, 1612, 1614, 1616, 1618, 1620, 1622, 1624, 1626, 1628, 1630, 1632, 1634, 1636, 1638, 1640, 1642, 1644, 1646, 1648, 1650, 1652, 1654, 1656, 1658, 1660, 1662, 1664, 1666, 1668, 1670, 1672, 1674, 1676, 1678, 1680, 1682, 1684, 1686, 1688, 1690, 1692, 1694, 1696, 1698, 1700, 1702, 1704, 1706, 1708, 1710, 1712, 1714, 1716, 1718, 1720, 1722, 1724, 1726, 1728, 1730, 1732, 1734, 1736, 1738, 1740, 1742, 1744, 1746, 1748, 1750, 1752, 1754, 1756, 1758, 1760, 1762, 1764, 1766, 1768, 1770, 1772, 1774, 1776, 1778, 1780, 1782, 1784, 1786, 1788, 1790, 1792, 1794, 1796, 1798, 1800, 1802, 1804, 1806, 1808, 1810, 1812, 1814, 1816, 1818, 1820, 1822, 1824, 1826, 1828, 1830, 1832, 1834, 1836, 1838, 1840, 1842, 1844, 1846, 1848, 1850, 1852, 1854, 1856, 1858, 1860, 1862, 1864, 1866, 1868, 1870, 1872, 1874, 1876, 1878, 1880, 1882, 1884, 1886, 1888, 1890, 1892, 1894, 1896, 1898, 1900, 1902, 1904, 1906, 1908, 1910, 1912, 1914, 1916, 1918, 1920, 1922, 1924, 1926, 1928, 1930, 1932, 1934, 1936, 1938, 1940, 1942, 1944, 1946, 1948, 1950, 1952, 1954, 1956, 1958, 1960, 1962, 1964, 1966, 1968, 1970, 1972, 1974, 1976, 1978, 1980, 1982, 1984, 1986, 1988, 1990, 1992, 1994, 1996, 1998, 2000, 2002, 2004 };
			long long Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	BearDarts ___test;
	___test.run_test(-1);
}
// END CUT HERE