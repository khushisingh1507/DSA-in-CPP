class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        int moves=0;
        int i=10;
       int num=n;
            while(num>=i){
                num-=i;
                moves++;
                i--;
            }
        
        if(moves%2==1)return true;
        return false;
    }
};