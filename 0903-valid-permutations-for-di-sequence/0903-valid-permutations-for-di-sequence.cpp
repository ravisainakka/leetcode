class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> dp;
    int mod = (int)1e9+7;
    int n;
    int solve(string s,int idx,int prev){
        if(idx >= n){
            return 1;
        } if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        int cnt = 0;
        for(int i=0;i<=n;i++){
            if(!vis[i]){
                vis[i] = true;
                if(prev == -1){
                    cnt = (cnt + solve(s,idx,i)) % mod;
                } else if((s[idx] == 'D' && i < prev) 
                    || s[idx] == 'I' && i > prev){
                        
                    cnt = (cnt + solve(s,idx+1,i)) % mod;
                }
                vis[i] = false;
            }
        }

        return dp[idx][prev+1] = cnt;
    }
    int numPermsDISequence(string s) {
        n = s.size();
        vis = vector<bool> (n + 2 , false);
        dp = vector<vector<int>> (n + 1 , vector<int>(n + 3, -1));
        return solve(s,0,-1);
    }
};