/* Range Maximum Query Segment Tree */

int maxTree[MAX];

int updateMax(int L,int R,int l,int p,int val) {
    if(L==R) return maxTree[p]=val;
    int mid=(L+R)/2;
    if(l<=mid) maxTree[p]=max(maxTree[p*2+2],updateMax(L,mid,l,p*2+1,val));
    else maxTree[p]=max(maxTree[p*2+1],updateMax(mid+1,R,l,p*2+2,val));
    return maxTree[p];
}

int RMQMax(int L,int R,int l,int r,int i) {
    if(l<=L && r>=R) return maxTree[i];
    if(R<l || L>r) return -oo;
    int mid=(L+R)/2;
    return max(RMQMax(L,mid,l,r,2*i+1),RMQMax(mid+1,R,l,r,2*i+2));
}

int buildMax(int values[],int L,int R,int i) {
    if(L==R) return maxTree[i]=values[L];
    int mid=(L+R)/2;
    maxTree[i]=max(buildMax(values,L,mid,2*i+1),buildMax(values,mid+1,R,2*i+2));
    return maxTree[i];
}

/* Range Minimum Query Segment Tree */

int minTree[MAX];

int updateMin(int L,int R,int l,int p,int val) {
    if(L==R) return minTree[p]=val;
    int mid=(L+R)/2;
    if(l<=mid) minTree[p]=min(minTree[p*2+2],updateMin(L,mid,l,p*2+1,val));
    else minTree[p]=min(minTree[p*2+1],updateMin(mid+1,R,l,p*2+2,val));
    return minTree[p];
}

int RMQMin(int L,int R,int l,int r,int i) {
    if(l<=L && r>=R) return minTree[i];
    if(R<l || L>r) return +oo;
    int mid=(L+R)/2;
    return min(RMQMin(L,mid,l,r,2*i+1),RMQMin(mid+1,R,l,r,2*i+2));
}

int buildMin(int values[],int L,int R,int i) {
    if(L==R) return minTree[i]=values[L];
    int mid=(L+R)/2;
    minTree[i]=min(buildMin(values,L,mid,2*i+1),buildMin(values,mid+1,R,2*i+2));
    return minTree[i];
}
