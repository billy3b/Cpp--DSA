class ProductOfNumbers {
public:
    vector<int>pre_pro;
    ProductOfNumbers() {
        pre_pro.clear();
        pre_pro.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            pre_pro.clear();
            pre_pro.push_back(1);
        }
        else{
            pre_pro.push_back(pre_pro.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=pre_pro.size();
        if(n-k-1<0) return 0;
        int ans=pre_pro.back()/pre_pro[n-1-k];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */