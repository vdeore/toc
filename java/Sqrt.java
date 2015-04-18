public class Sqrt {
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
    public static void main (String []args) {
        double  n = 5;
        pow(5, 2);
        sqrt(n);
    }
}
