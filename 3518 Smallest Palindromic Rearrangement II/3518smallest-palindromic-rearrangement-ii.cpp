class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    long long comb(int n, int r, long long lim) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;
            long long g = gcdll(a, b);
            a /= g;
            b /= g;
            g = gcdll(res, b);
            res /= g;
            b /= g;
            __int128 cur = (__int128)res * a;
            if (cur > lim) return lim + 1;
            res = (long long)cur;
            res /= b;
            if (res > lim) return lim + 1;
        }
        return res;
    }
    long long ways(vector<int> &cnt, long long lim) {
        int tot = 0;
        for (int x : cnt) tot += x;
        long long res = 1;
        int rem = tot;
        for (int x : cnt) {
            if (x == 0) continue;
            long long c = comb(rem, x, lim);
            __int128 cur = (__int128)res * c;
            if (cur > lim) return lim + 1;
            res = (long long)cur;
            rem -= x;
            if (res > lim) return lim + 1;
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1)
                mid.push_back(char('a' + i));
            cnt[i] /= 2;
        }
        if (ways(cnt, k) < k)
            return "";
        string left = "";
        int len = 0;
        for (int x : cnt)
            len += x;
        for (int pos = 0; pos < len; pos++) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                cnt[i]--;
                long long w = ways(cnt, k);
                if (w >= k) {
                    left.push_back(char('a' + i));
                    break;
                }
                k -= w;
                cnt[i]++;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};