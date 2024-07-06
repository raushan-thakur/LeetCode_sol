class Solution {
public:
  int passThePillow(int n, int time) {
        int mod = time / (n - 1);
        int rem = time % (n - 1);
        if (mod & 1) return n - rem;
        return rem + 1;
  }
};