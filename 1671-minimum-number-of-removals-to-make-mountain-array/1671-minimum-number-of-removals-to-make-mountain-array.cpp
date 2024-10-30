class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        int dpl[n],dpr[n],m=0;
        
        memset(dpl,0,sizeof(dpl));
        memset(dpr,0,sizeof(dpr));
        dpl[0]=1,dpr[n-1]=1;
        
        for(int i=1;i<n;i++){
            dpl[i]=1,dpr[i]=1;
            for(int j=0;j<i;j++)
                if(arr[j]<arr[i])
                    dpl[i]=max(dpl[i],dpl[j]+1);
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--)
                if(arr[j]<arr[i])
                    dpr[i]=max(dpr[i],dpr[j]+1);
        }
        
        for(int i=0;i<n;i++)
            if(dpl[i]>1 && dpr[i]>1)
                m=max(m,(dpl[i]-1)+(dpr[i]-1)+1);
        
        return n-m;
    }
};