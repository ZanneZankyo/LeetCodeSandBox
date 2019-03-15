/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (23.93%)
 * Total Accepted:    93.8K
 * Total Submissions: 392.2K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * Example 3:
 * 
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 */
#include <string>
#include <stringstream>
using namespace std;
class Solution {
    string const sections[4] = {"", "Thousand","Million","Billion"};
public:
    string digitToStr(int n){
        switch(n){
            case 0: return "";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            default: return "???";
        }
    }
    string teenToStr(int teen){
        switch(teen){
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            default: return "???";
        }
    }
    string tensToStr(int tens){
        switch(tens){
            case 0: return "";
            case 1: return "???";
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
            default: return "???";
        }
    }
    string hundredsToString(int handreds){
        string s;
        if(handreds == 0) return "";
        int h = handreds / 100;
        if(h != 0){
            s += digitToStr(h) + " Hundred";
        }
        int t = handreds % 100;
        if(t == 0)
            return s;
        if(h != 0 && t != 0)
            s += " ";

        if(10 <= t && t <= 19){
            s += teenToStr(t);
        }
        else{
            t /= 10;
            if(t != 0)
                s += tensToStr(t);
            int d = handreds % 10;
            if(t != 0 && d != 0)
                s += " ";
            s += digitToStr(d);
        }
        return s;
    }
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        /*stringstream ss;
        ss << hundredsToString(num % 1000 % 1000 % 1000) << sections[2]
        << hundredsToString(num % 1000 % 1000) << sections[1]
        << hundredsToString(num % 1000);
        return ss.str();*/
        string s;
        int n0 = num % 1000;
        int n1 = num / 1000 % 1000;
        int n2 = num / 1000000 % 1000;
        int n3 = num / 1000000000 % 1000;
        //cout << n3 << "|" << n2 << "|" << n1 << "|" << n0 <<endl;
        if(n3 != 0)
            s += hundredsToString(n3) + " " + sections[3];
        if(n3 != 0 && n2 != 0)
            s += " ";
        if(n2 != 0)
            s += hundredsToString(n2) + " " + sections[2];
        if((n3 != 0 || n2 != 0) && n1 != 0)
            s += " ";
        if(n1 != 0)
            s += hundredsToString(n1) + " " + sections[1];
        if((n3 != 0 || n2 != 0 || n1 != 0) && n0 != 0)
            s += " ";
        s += hundredsToString(n0);
        return s;
    }
};

