#include <iostream>
#include <vector>
#include<map>
#include<string>

using namespace std;

int stock = -1;
int buyDay = -1;
int sellDay = -1;
map<pair<string,bool>,int > mp;

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

void printMap(map<pair<string,bool>,int > mp){

    cout<<"Map size "<<mp.size()<<"\n";
    map<pair<string,bool>,int >::iterator it;

    it = mp.begin();

    while(it != mp.end()){
        pair<string,bool> p = it->first;
        if(p.second == true){
            cout<<"\nKey "<<p.first<<" : "<<p.second<<", Value "<<it->second;
        }
        
        it++;
    }

}

int dfs(int curStock, int curDay, bool buying, vector<vector<int> >& prices , int c){

    // printMap(mp);

    int m = prices.size();
    int n = prices[0].size();
    // int c = 2;
    string s = to_string(curStock)+"-"+to_string(curDay);
    map<pair<string,bool>, int >::iterator it;
    if(curStock >= prices.size() || curDay >= prices[0].size())
        return 0;
    
    string key = s;
    
    if(mp.find(make_pair(key, buying)) != mp.end())
        return mp[make_pair(key, buying)];
    
    if(buying){
        // cout<<"Doing a buy";
        // DO CODE
        // Buy m stocks 

        // for(int i=curStock;i<m;i++){
            // for(int j = curDay;j<n;j++){
                int buy = dfs(curStock, curDay+1, !buying, prices, c) - prices[curStock][curDay];
                int cooldown = dfs(curStock, curDay+1, buying, prices, c);
                
                mp[make_pair(s, buying)] = max(buy, cooldown);
                // cout<<mp[make_pair(s,buying)];

            // }
        // }
    }
    else{
        //DO CODE
        for(int i=0;i<m;i++){
            // for(int j = curDay;j<n;j++){

                string temps = to_string(i)+"-"+to_string(curDay);

                int sell = dfs(i, curDay+c+1, !buying, prices, c) + prices[curStock][curDay];
                int cooldown = dfs(i, curDay+1, buying, prices, c);
                mp[make_pair(temps, buying)] = max(sell, cooldown);
                // cout<<"\t"<<mp[make_pair(temps,buying)];

            // }
        }
    }

    return mp[make_pair(s, buying)];

}

int maxProfit(vector<vector<int> > prices , int c)
{
    //  Goal is to minimize the BUY and maximize SELL

    
    int temp_profit = 0;

    if (prices.size() < 2)
        return 0;

    int m = prices.size();
    int n = prices[0].size();
    int max_profit = -1;

    for(int i=0;i<m;i++){
        temp_profit = dfs(i, 0, true, prices, c);
        // cout<<"Temp profit for "<<i<<" is"<<temp_profit<<"\n";
        max_profit = max(max_profit, temp_profit);
    }

    printMap(mp);

    // cout<<"Max profit : "<<max_profit<<"\t";
    // cout<<"Stock : "<<stock<<"\t";
    // cout<<"Buy day : "<<buyDay<<"\t";
    // cout<<"Sell day : "<<sellDay<<"\t";


    return max_profit;
}

// Driver code
int main()
{
    // vector<int> prices{100, 180, 260, 310, 40, 535, 695};

    int m,n,c;

    cin>>m;
    cin>>n;
    cin>>c;

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
    int res = maxProfit(prices, c);
    cout<<"Max Profit : "<<res;

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
