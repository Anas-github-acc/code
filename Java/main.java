import java.util.Scanner;
class mian {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            String a = sc.nextLine();
            String b = sc.nextLine();
            Solution sol = new Solution();
            System.out.println(a+" "+b);
        }
    }
}
class Solution {
    public String addBinary(String a, String b) {
        int binary = 0;
        int binary1 = 0;
        int i = 1;
       for(int j = a.length()-1; j >= 0; j--) {
           binary = binary + (a[j]-'0') * i;
           i = i * 2;
       }
       i = 1;
       for(int j = b.length()-1; j >= 0; j--) {
           binary1 = binary1 + (b[j]-'0') * i;
           i = i * 2;
       }
       int sum = binary + binary1;
       String result = "";
       while(sum > 0) {
           result = sum % 2 + result;
           sum = sum / 2;
       }
       return result.isEmpty() ? "0" : result;
    }
};
