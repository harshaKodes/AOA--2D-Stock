
// priyalakshmitheagarajan@Programming project :~$  g++ -std=c++11 -o test BuySellSingle-bforce.cpp
// priyalakshmitheagarajan@Programming project :~$ ./test

#include <iostream>
#include <vector>
#include<map>
#include<chrono>

using namespace std;
using namespace std::chrono;

int stock = -1;
int buyDay = -1;
int sellDay = -1;

void printVector(vector<vector<int> > v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}

int findMax(vector<int> v){
    int maxProfit = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>maxProfit){
            maxProfit = v[i];
            stock = i;
        }
    }
    return maxProfit;
}

int maxProfit(vector<vector<int> > prices)
{
    //  Goal is to minimize the BUY and maximize SELL

    vector<int> profits;
    map<int,pair<int,int> > mp;
    map<int,pair<int,int> >::iterator it;

    if (prices.size() < 2)
        return 0;

    int m = prices.size();
    int n = prices[0].size();
    int max_profit = -1;

    for (int j = 0; j < m; j++)
    {

        int buy = prices[j][0];
        int profit = 0;
        int temp_profit = -1;

        for (int i = 0; i < prices[j].size(); i++)
        {
            
            for(int k = i+1;k<prices[j].size();k++){

                // cout<<i<<" and "<<k<<"\n";
                // cout<<prices[j][k]<<" and "<<prices[j][i]<<"\n";

                // cout<<(prices[i][k] - buy)<<"\n";

                if((prices[j][k] - prices[j][i])> profit){
                    profit = prices[j][k] - prices[j][i];
                }

                //  Makesure that the profit is still MAXIMUM

                if (profit > temp_profit)
                {
                    temp_profit = profit;
                    
                    if(mp.find(j) != mp.end()){
                        mp[j] = make_pair(i,k);
                    }
                    else
                        mp[j] = make_pair(i,k);
                        // mp.insert({j,make_pair(i,k)});
                    // cout<<"Temp profit is "<<temp_profit<<"\n";
                }
            
            }
            
        }
        profits.push_back(temp_profit);
        // cout << temp_profit << "\n";

        max_profit = findMax(profits);
        
    }
    pair<int, int> p;
    if(stock != -1){
        p = mp[stock];
        buyDay = p.first;
        sellDay = p.second;
    }        
    cout<<"Stock : "<<stock<<"\t";
    cout<<"Buy day : "<<buyDay<<"\t";
    cout<<"Sell day : "<<sellDay<<"\t";


    return max_profit;
}

// Driver code
int main()
{
    // vector<int> prices{100, 180, 260, 310, 40, 535, 695};

    auto start = high_resolution_clock::now();
    int m,n;

    cin>>m;
    cin>>n;

    vector<vector<int> > prices;

    for(int i =0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            int c;
            cin>>c;
            v.push_back(c);
        }
        prices.push_back(v);
    }

    // printVector(prices);
    int res = maxProfit(prices);
    cout<<"Max Profit : "<<res;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "\n Time taken by function: "
         << duration.count() << " milliseconds" << endl;

    // vector<vector<int>> price{
    //     {1, 2, 3, 10},
    //     {8, 7, 9, 10},
    //     {3, 7, 4, 2}};
    // 

    // vector<int> price {100, 180, 260, 310, 40, 535, 695};

    // int price[] = {100, 180, 260, 310, 40, 535, 695};
    // int n = sizeof(price) / sizeof(price[0]);

    return 0;
}
