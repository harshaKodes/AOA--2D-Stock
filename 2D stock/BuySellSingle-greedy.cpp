#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
using namespace std::chrono;


int maxProfit(vector<vector<int> > prices)
{
    int stock = -1;
    //  Goal is to minimize the BUY and maximize SELL

    vector<int> buyDays(prices.size());
    vector<int> sellDays(prices.size());
    if (prices.size() < 2)
        return 0;
    
    int m = prices.size();
    int n = prices[0].size();
    int max_profit = -1;

    for(int j = 0; j< m;j++){

    int buy = prices[j][0];
    int profit = 0;
    int temp_profit = -1;

        for (int i = 1; i < prices[j].size(); i++)
        {
            //  Greedily finding out the maximum profit
            if ( prices[j][i] > buy)
            {
                if(prices[j][i] - buy > profit){
                    profit = prices[j][i]-buy;
                    sellDays[j] = i ;
                    // sellDay = i;
                    // cout<<"sellDay"<<sellDay<<"\n";
                }
                // profit = max( profit, prices[j][i]-buy);
            }
            
            // Greedily finding out the minimum profit
            if(prices[j][i]< buy ){
                buy = prices[j][i];
                buyDays[j] = i;
                // buyDay = i;
            }
            
        }
        // cout<<profit<<"\n";

        if(profit > max_profit){
            max_profit = profit;
            stock = j;
            
        }
        // max_profit = max(max_profit, profit);
    }

    cout<<"Stock : "<<stock<<"\t";
    cout<<"Buy day : "<<buyDays[stock]<<"\t";
    cout<<"Sell day : "<<sellDays[stock]<<"\t";


    if(max_profit < 0)
        return 0;

    return max_profit;
}

// Driver code
int main()
{
    int m,n;

    auto start = high_resolution_clock::now();

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

    // vector<int> prices{ 100, 180, 260, 310, 40, 535, 695 };
    
    // vector<vector<int>> price{
    //     {1, 2, 3, 10},
    //     {8, 7, 9, 10},
    //     {3, 7, 4, 2}};

    cout << maxProfit(prices);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "\n Time taken by function: "
         << duration.count() << " milliseconds" << endl;    


    return 0;
}
