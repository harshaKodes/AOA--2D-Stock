#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
using namespace std::chrono;

int stock = -1;
    
void printVector(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\t";
    }
    cout<<"\n";
}
    
 int maxProfit(vector<int>& prices, vector<int>& buyDays, vector<int>& sellDays, int stockDay){
     int size=prices.size();
 	// deciding size of dp array
     vector<int> dp(size+1, 0);
       // if array.size()==0 then we can't buy or sell so profit=0.
     int min=INT_MAX; 
     for(int i=1;i<=size;i++){ // this is to perform bottom up dp operation.
         if(prices[i-1]<min) {
            min=prices[i-1]; 
            buyDays[stockDay] = i-1; 
            // sellDays[stockDay]
            }
               // we want to find minimum in the array behind the iterator.
         // dp[i] is the profit we finded for the array --> 1st to ith element inside the array.
 		// if the profit we get from (i-1)th-min prices is greater then the profit we finded and stored in dp[i-1] then we get our dp[ith] profit.
 		int q1 = prices[i-1]-min;
        int q2 = dp[i-1];

        if( q1 > q2){
            sellDays[stockDay] = i-1;
        }
        dp[i]=max(prices[i-1]-min,dp[i-1]); 
         
        // printVector(dp);
     }
     return dp[size]; // dp[size of price vector] is answer because it is the profit for the complete vector form 1st to last element.
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

        tempProfit = maxProfit(price[i],buyDays,sellDays, i);
        // cout<<tempProfit<<"\n";
        if(tempProfit > max_profit){
            max_profit = tempProfit;
            stock = i;
        }
        // max_profit = max(max_profit, tempProfit);
    }

    // vector<int> price {100, 180, 260, 310, 40, 535, 695};

    // int price[] = {100, 180, 260, 310, 40, 535, 695};
    // int n = sizeof(price) / sizeof(price[0]);

    cout<<"Stock : "<<stock<<"\t";
    cout<<"Buy day : "<<buyDays[stock]<<"\t";
    cout<<"Sell day : "<<sellDays[stock]<<"\t";

    cout<<max_profit;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
 
    cout << "\n Time taken by function: "
         << duration.count() << " milliseconds" << endl;
    return 0;
}

