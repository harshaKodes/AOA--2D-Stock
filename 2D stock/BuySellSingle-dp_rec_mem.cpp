#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

int stock = -1;

int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int> > &v, int stockDay, vector<int>& buyDays, vector<int>& sellDays)
{
    //if we have no stock or we have no chance of transaction(k=0)
    
    if(i>=prices.size()||k<=0) return 0;
    if(v[i][buy]!=-1) return v[i][buy];
    
    if(buy)  //if we are buying then next time we will sell else next time we will buy
    {        //-prices[i], because bought stock of prices[i], expend money
        int q1 = -prices[i]+find(prices,i+1,k,!buy,v, stockDay, buyDays, sellDays);
        int q2 = find(prices,i+1,k,buy,v, stockDay, buyDays, sellDays);

        if(q1 > q2){
            buyDays[stockDay] = i;
        }
        return v[i][buy] = max(q1,q2);
        // return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v)); 
    }
    else    //it's time to sell , now decrease k, we have done 1 transaction
    {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
        int s1 = prices[i]+find(prices,i+1,k-1,!buy,v, stockDay, buyDays, sellDays);
        int s2 = find(prices,i+1,k,buy,v, stockDay, buyDays, sellDays);

        if(s1 > s2){
            sellDays[stockDay] = i;
        }

        return v[i][buy] = max(s1, s2);
        // return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v, stockDay),find(prices,i+1,k,buy,v, stockDay)); 
    }
}
int maxProfit(vector<int>& prices, int stockDay, vector<int>& buyDays, vector<int>& sellDays ) {
    
    int n=prices.size(); 
    vector<vector<int> > v(n,vector<int> (2,-1));
    
    
    //passing here buy=1 because we will first buy then sell
    //we can do atmost k=1 transaction
    return find(prices,0,1,1,v, stockDay, buyDays, sellDays);
}

// Driver code
int main()
{
    auto start = high_resolution_clock::now();
    int m,n;

    cin>>m;
    cin>>n;

    vector<vector<int> > price;
    

    for(int i =0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            int c;
            cin>>c;
            v.push_back(c);
        }
        price.push_back(v);
    }

    vector<int> buyDays(price.size());
    vector<int> sellDays(price.size());
    // vector<int> price{ 7,1,5,3,6,4 };
    // cout << maxProfit(price);
    // vector<vector<int>> price{
    //     {1, 2, 3, 10},
    //     {8, 7, 9, 10},
    //     {3, 7, 4, 2}};
    
    int tempProfit = -1;
    int max_profit = -1;

    for(int i=0;i<price.size();i++){

        tempProfit = maxProfit(price[i], i, buyDays, sellDays);
        // cout<<tempProfit<<"\n";
        if(tempProfit > max_profit){
            max_profit = tempProfit;
            stock = i;
        }
        // max_profit = max(max_profit, tempProfit);
    }

    cout<<"Stock : "<<stock<<"\t";
    cout<<"Buy day : "<<buyDays[stock]<<"\t";
    cout<<"Sell day : "<<sellDays[stock]<<"\t";


    // vector<int> price {100, 180, 260, 310, 40, 535, 695};

    // int price[] = {100, 180, 260, 310, 40, 535, 695};
    // int n = sizeof(price) / sizeof(price[0]);

    cout<<max_profit;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "\n Time taken by function: "
         << duration.count() << " milliseconds" << endl;

    return 0;
}

