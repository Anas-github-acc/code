import java.util.ArrayList;
import java.util.List;


public class threading {
    public static void main(String[] args) {
        List<Integer> fib = new ArrayList<>();
        Thread t1 = new Thread(new AddFib(fib));
        t1.start();
    }
}

class AddFib implements Runnable {
    List<Integer> fib;
    AddFib(List<Integer> fib) {
        this.fib = fib;
    }

    public void run() {
        int n = 10;
        int a = 0, b = 1;

        synchronized (fib) {
            fib.add(a);
            System.out.println("Fibonacci sequence so far: " + fib);
            executeThreadsForFib(a);

            fib.add(b);
            System.out.println("Fibonacci sequence so far: " + fib);
            executeThreadsForFib(b);

            for (int i = 2; i < n; i++) {
                int c = a + b;
                fib.add(c);
                a = b;
                b = c;
                System.out.println("Fibonacci sequence so far: " + fib);
                executeThreadsForFib(c);
            }
        }
        System.out.println("All Fibonacci numbers and threads processed.");
    }
        

    private void executeThreadsForFib(int fibNumber) {
        Thread sumThread = new Thread(new SumFib(fib));
        Thread primeThread = new Thread(new PrimeFib(fibNumber));
        
        sumThread.start();
        primeThread.start();

        try {
            sumThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class SumFib implements Runnable {
    List<Integer> fib;
    SumFib(List<Integer> fib) {
        this.fib = fib;
    }
    public void run() {
        int sum = 0;
        for (int i = 0; i < fib.size(); i++) {
            sum += fib.get(i);
        }
        System.out.println("Sum: " + sum);
    }
}

class PrimeFib implements Runnable {
    int n;
    PrimeFib(int n) {
        this.n = n;
    }
    public void run() {
        boolean isPrime = true;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            System.out.println(n + " is a prime number.");
        } else {
            System.out.println(n + " is not a prime number.");
        }
    }
}