import java.util.*;
public class Task6B {
    static ArrayList<Integer> calcBuyandSell(int m, int n ,int k , int[][] prices, int [][]dp){
        ArrayList<Integer> list = new ArrayList<>();
        int counter=k, day = n-1;
        while(true){
            if( counter ==0 || day ==0)
            break;
            if(dp[counter][day] == dp[counter][day-1])
            day = day -1;
            else {
                boolean b = false;
                for (int i =0; i<m; i++){
                    int profit = dp[counter][day] - prices[i][day];
                    for(int j = day-1; j>=0; j--)
                    {
                        if(dp[counter-1][j] - prices[i][j] == profit)
                        {
                            list.add(i+1);
                            list.add(j+1);
                            list.add(day+1);
                            counter = counter-1;
                            day=j;
                            b = true;
                            break;
                        }
                    }
                    if(b)
                        break;
                }
            }
        }
        return list;
    }
    static int maxProfit(int[][] arr, int n, int k, int stocks) {


        int dp[][] = new int[k + 1][n + 1];

        for (int i = 0; i <= k; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= k; i++) {
            for (int v = 0; v < stocks; v++) {
                int maxDiff = Integer.MIN_VALUE;
                for (int j = 1; j < n; j++) {
                    maxDiff = Math.max(dp[i - 1][j - 1] - arr[v][j - 1],maxDiff);
                    int temp = Math.max(arr[v][j] + maxDiff, dp[i][j - 1] );
                    dp[i][j] = Math.max(temp,dp[i][j] );
                }
            }
        }

        ArrayList<Integer> dates= calcBuyandSell(stocks,n,k,arr,dp);
        for(int i = dates.size() -1; i>=0;i=i-3){
            System.out.println(dates.get(i-2) + " " + dates.get(i-1) + " " + dates.get(i));
        }
        return dp[k][n - 1];
    }
    public static void main(String args[]) {
            
        double startTime = System.currentTimeMillis();
        Scanner scn = new Scanner(System.in);
        int k;
        int m;
        int n;
        k = scn.nextInt();
        m = scn.nextInt();
        n = scn.nextInt();
        int prices[][] = new int[m][n];
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                prices[x][y] = scn.nextInt();
            }
        }
        // Calculate profit for all the stocks with all combinations
        System.out.println("--------------------------- ----------------------------     ");
        System.out.println(maxProfit(prices,prices[0].length,k,prices.length));
        double endTime = System.currentTimeMillis();
        // long endTime   = System.nanoTime();
        double totalTime = endTime - startTime;
        System.out.println("Total Running time: " + totalTime);
        }
    
}
