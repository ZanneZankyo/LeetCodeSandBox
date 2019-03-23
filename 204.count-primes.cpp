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
    int nextPrime(int currentPrime, int n){
        ++currentPrime;
        while(!primes[currentPrime] && currentPrime < n) currentPrime+=2;
        return currentPrime;
    }
    int countPrimes(int n) {

        if(n <= 2){
            return 0;
        }

        primes.resize(n, true);
        int limit = sqrt(n);
        //cout<<"limit:"<<limit<<"!";
        int total = 1;
        for(int currentNum = 3; currentNum < n; currentNum+=2){
            if(primes[currentNum]){
                
                ++total;
                if(currentNum > largestPrime && currentNum <= limit){
                    //cout << currentNum << "|";
                    largestPrime = currentNum;
                    for(int currentPrime = largestPrime * largestPrime; 
                        currentPrime < n; 
                        currentPrime += largestPrime){
                        primes[currentPrime] = false;
                    }
                }
            }
        }
        
        return total;
    }
};

