class Solution {
public:
    long long mod= 1e9+7;
    long long power(long long x, long long n){
        if(n==0) return 1;
        long long half= power(x,n/2);
        if(n%2==0){//even
            return (half*half)%mod;
        }
        else return (half*half*x)%mod;
    }
    int countGoodNumbers(long long n) {
        
        long long odd_indices=n/2;
        long long even_indices=(n+1)/2;

        long long first_part=power(5,even_indices);
        long long second_part=power(4,odd_indices);
        return (int)((first_part*second_part)%mod);
    }
};