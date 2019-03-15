/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.61%)
 * Total Accepted:    295.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
class Solution {
public:
	struct PowVal {
		unsigned int pow;
		double val;
		PowVal(unsigned int p, double v) : pow(p), val(v) {}
	};
	double myPow(double x, int n) {
		if (n == 0)
			return 1;

		bool positive = n > 0;
		unsigned int pow = positive ? n : -n;
		x = positive ? x : 1 / x;
		double result = x;
		unsigned int i = 1;
		double progress = x;
		unsigned int powOfPro = 1;
		vector<PowVal> powVals;
		powVals.emplace_back(powOfPro, progress);
		while (i < pow) {
			if (i <= pow / 2 && powVals.size() < 31) {
				result *= result;
				i *= 2;
				progress = result;
				powOfPro = i;
				powVals.emplace_back(powOfPro, progress);
			}
			else {

				for (int j = powVals.size() - 1; j >= 0; j--) {
					if (powVals[j].pow <= pow - i) {
						progress = powVals[j].val;
						powOfPro = powVals[j].pow;
						break;
					}
				}

				result *= progress;
				i += powOfPro;
			}

		}

		return result;
	}
};

