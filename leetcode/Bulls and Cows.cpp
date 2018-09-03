class Solution {
public:
    string getHint(string secret, string guess) {
        map<long long, long long> mp_secret,mp_guess;
        
        for(long long i=0;i<secret.size();i++) mp_secret[secret[i]-'0']++;
        for(long long i=0;i<guess.size();i++) mp_guess[guess[i]-'0']++;
        
        long long a=0,b=0;
        for(long long i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) a++, mp_secret[secret[i]-'0']--,mp_guess[guess[i]-'0']--;
        }
        auto it=mp_secret.begin();
        for(it;it!=mp_secret.end();it++){
            long long var=it->first;
            b+= min(mp_secret[var],mp_guess[var]);
        }
        string ans="";
        ans+= to_string(a) + 'A';
        ans+= to_string(b) + 'B';
        
        return ans;
    }
};