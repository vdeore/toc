
import java.util.*;

public class MathProblems {
    static double precision = 0.000000002;
    static double pow(double n, int e) {
        double result = 1;
        System.out.println("Calulating : " + n + "^"+ e);
        while (e != 0) {
            if ((e & 1) != 0) {
                result *= n;
            }
            e = e >> 1;
            n *= n;
        }
        System.out.println("ans: " + result);
        return result;
    }

    static double sqrt(double n) {
        double ans = 0, l = 0, r = n, nn = 0; 

        System.out.println("Calulating sqrt of: " + n + " with precision :" + precision);
        while (!((nn == n) || (Math.abs(nn - n) < precision)))  {
            ans = (l + r)/2; 
            nn = ans * ans;
            if (nn > n) {
                r = ans;
            } else {
                l = ans;
            }
        }
        System.out.println("Calulating sqrt of: " + n + "-> "+ ans);
        return ans;
    }

    /* find 3 integers that sum to x */
    static boolean sum3(int a[], int sum) {
        for (int i = 0; i < 10; ++i) {
            int sum2 = sum - a[i];
            HashMap m = new HashMap();
            for (int j = 0; j < 10; ++j) {
                if (i==j) { continue; }
                if (m.containsKey(sum2-a[j])) {
                    System.out.println(" "+a[i]+", "+a[j]+" "+(sum2-a[j]));
                } else {
                    m.put(a[j], true);
                }
            }
        }
        return false;
    }

    public static void main (String []args) {
        double  n = 5;
        int a[] = {0,1,2,3,4,5,6,7,8,9};
        pow(5, 2);
        sqrt(n);
        sum3(a, 0);
    }
}
