import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class sana {
    public static int comb(int n, int k) {
        int result=1;
        int p=1;
        for (int i = n; i > k; i--) {
            p *=i;
                            
        }
        int c=1;
        for (int i = n-k; i >0 ; i--) {
            c *=i;
                            
        }
        result=(p/c);
        return result;
    
    }

    public static void main(String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
           int n=sc.nextInt();
           int k=sc.nextInt();
            if((n>=0)&&(n<=100)&&(k>=0)&&(k<=60))
            {
                int a=k;
                int sum=0;
                int sum3=0;
                if(k==1)
                {
                    sum=1;
                }
                else{
                for(int i=1;i<n;i++)
                {
                    int sum1=comb(n,i);
                    a--;
                    while(a>1)
                    {
                        sum3=sum1;
                        n=n-1;
                    for(int j=1;j<n;j++)
                    {
                        int sum2=comb(n,i);
                        int c=n-1;
                        int  m=1;
                        while(a>1){
                        int sum2=comb(c,m);
                        sum1=sum3 * sum2;
                        a--;
                        c--;
                        m++;
                        }

                    }
                   }
                   sum+=sum1;
                 }
                }
            System.out.println(sum);
        }
           
    }
}
}