import java.util.*;
import java.io.*;


public class Task5{

    public static ArrayList<int[]> transactions = new ArrayList<int[]>();
    public static Map<Integer, Map<Integer, Map<Integer, List<int[]>>>> dpMap = null;

    static ArrayList<int[]> calc_profits(int [][] input_stocks, int k){

        int buy_date, sell_date, stock, profit;

        for(int j=0;j<input_stocks[0].length-1;j++)
        {
            buy_date = j;
            for(int i=0;i<input_stocks.length;i++)
            {
                stock = i;
                for(int x=j+1;x<input_stocks[0].length;x++)
                {
                    sell_date = x;
                    profit = input_stocks[i][x] - input_stocks[i][j];
                    if(profit>0)
                    {
                        transactions.add(new int[]{buy_date,sell_date, stock, profit});

                    }
                }
            }
        }
        return transactions;
    }

    public static Map<Integer, List<int[]>> findTransactions(int i, int k) {
        if(dpMap.get(i) != null && dpMap.get(i).get(k) != null) {
            return dpMap.get(i).get(k);
        }
        Map<Integer, List<int[]>> ansmap = new HashMap<>();
        List<int[]> mylist = new ArrayList<>();
        if (k <= 0 || i < 0) {
            ansmap.put(0, mylist);
            if(dpMap.get(i) == null) {
                dpMap.put(i, new HashMap<>());
            }
            dpMap.get(i).put(k, ansmap);
            return ansmap;
        }
        if (i == transactions.size() - 1) {
            mylist.add(transactions.get(i));
            ansmap.put(transactions.get(1)[3], mylist);
            return ansmap;
        }
        int next_i = -1;
        for ( int j = i; j< transactions.size(); j++) {
            if (transactions.get(j)[1] >= i) {
                next_i = j;
                break;
            }
        }
        Map<Integer, List<int[]>> ansmap2 = findTransactions(next_i,  k-1);
        Map<Integer, List<int[]>> ansmap3 = findTransactions(i+1, k);
        int ans2 = ansmap2.keySet().iterator().next();
        int ans3 = ansmap3.keySet().iterator().next();
        if(ans2+transactions.get(i)[3] > ans3) {
            mylist.add(transactions.get(i));
            mylist.addAll(ansmap2.get(ans2));
            ansmap.put(ans2+transactions.get(i)[3], mylist);
        } else {
            mylist.addAll(ansmap3.get(ans3));
            ansmap.put(ans3, mylist);
        }
        if(dpMap.get(i) == null) {
            dpMap.put(i, new HashMap<>());
        }
        dpMap.get(i).put(k, ansmap);
        return ansmap;
    }


    public static void main(String[] args) {
        // Num of stocks : m
        // Num of days : n
        // Max allowed input_stocks : k
        double startTime = System.currentTimeMillis();
        Scanner scn = new Scanner(System.in);
        int k;
        int m;
        int n;
        k = scn.nextInt();
        m = scn.nextInt();
        n = scn.nextInt();
        int A[][] = new int[m][n];
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                A[x][y] = scn.nextInt();
            }
        }
        // Calculate profit for all the stocks with all combinations
        System.out.println("--------------------------- ----------------------------     ");
        ArrayList<int[]> profits = calc_profits(A, k);
        dpMap = new HashMap<>();
        Map<Integer, List<int[]>> ansmap2 = findTransactions(0,k) ;
        int max = ansmap2.keySet().iterator().next();
        List<int[]> finaltransactions = ansmap2.get(max);
        for(int i=0; i<finaltransactions.size(); i++) {
            System.out.println(finaltransactions.get(i)[0] + " " + finaltransactions.get(i)[1] + " " + finaltransactions.get(i)[2] + " " + finaltransactions.get(i)[3] );
        }
        double endTime = System.currentTimeMillis();
        // long endTime   = System.nanoTime();
        double totalTime = endTime - startTime;
        System.out.println("Total Running time: " + totalTime);

    }

}