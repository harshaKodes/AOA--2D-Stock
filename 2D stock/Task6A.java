import java.util.*;
public class Task6A {
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
    static int  calcProfit(int m, int n, int k, int[][] prices, int[][] maxDiff, int[][] table ){
        if(table[k][n] == -1)
        {
            int maximum = calcProfit(m, n-1, k,prices, maxDiff, table);
            for(int sId=0; sId<m; sId++){
                maxDiff[k][sId] = Math.max(calcProfit(m, n, k-1, prices, maxDiff, table) - prices[sId][n],maxDiff[k][sId] );
                maximum = Math.max( prices[sId][n] + maxDiff[k][sId],maximum);
        }
        table[k][n] = maximum;
        return maximum;
        }
    return table[k][n];
    }
    static int maxProfit(int m, int n , int k, int[][] prices){
        int[][] table = new int[k+1][n];
        for( int[] e : table){
            Arrays.fill(e,-1);
        } 

        for (int i=0; i <n; i++){
            table[0][i] = 0;
        }

        for (int i=0; i<k+1; i++){
            table[i][0] = 0;
        }

        int[][] maxDiff = new int[k+1][m];
        for(int[] e : maxDiff){
            Arrays.fill(e,0);
        }

        for (int j=0; j<k+1;j++){
            for(int i=0; i < m; i++){
            maxDiff[j][i] = -prices[i][0];
            }
        }

        int maximumProfit = calcProfit(m, n-1, k, prices, maxDiff, table);
        ArrayList<Integer> dates = calcBuyandSell(m,n,k,prices,table);
        for(int i = dates.size() -1; i>=0;i=i-3){
            System.out.println(dates.get(i-2) + " " + dates.get(i-1) + " " + dates.get(i));
        }
        return maximumProfit;

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
        maxProfit(prices.length,prices[0].length,k, prices);
        double endTime = System.currentTimeMillis();
        // long endTime   = System.nanoTime();
        double totalTime = endTime - startTime;
        System.out.println("Total Running time: " + totalTime);
        }
}
