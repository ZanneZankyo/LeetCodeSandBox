/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.41%)
 * Total Accepted:    219K
 * Total Submissions: 770.8K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */
class Solution {
private:
    vector<bool> primes;
    int largestPrime = 2;
    
public:
    Solution(){
        primes.resize(3, true);
        primes[0] = false;
        primes[1] = false;
    }
    int nextPrime(vector<bool>& primes, int currentPrime){
        ++currentPrime;
        while(!primes[currentPrime] && currentPrime < primes.size()) currentPrime++;
        return currentPrime;
    }
    int countPrimes(int n) {
        if(n > primes.size()){
            primes.resize(n, true);
            int currentPrime = largestPrime;
            while(currentPrime <= n/2){
                int i = 2;
                int multiplyOfPrime = i * currentPrime;

                while(multiplyOfPrime < n){
                    //cout << multiplyOfPrime << "|";
                    primes[multiplyOfPrime] = false;
                    ++i;
                    multiplyOfPrime = i * currentPrime;
                }
                currentPrime = nextPrime(primes, currentPrime);
                largestPrime = currentPrime >= primes.size() ? largestPrime : currentPrime;
            }
        }
        
        int total = 0;
        for(int i = 0; i < n; ++i){
            if(primes[i]){
                ++total;
            }
        }
        return total;
    }
};

