import java.util.*;
public class Main {
    static boolean isArmstrong(int n)  {   
        int temp, digits=0, last=0, sum=0;   
        temp=n;   
        while(temp>0) {   
            temp = temp/10;   
            digits++;   
        }   
        temp = n;   
        while(temp>0) {        
            last = temp % 10;   
            sum +=  (Math.pow(last, digits)); 
            temp = temp/10;   
        }  
        if(n==sum)    
        return true;      
        //returns false if sum and n are not equal  
        else return false;   
    }   
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(isArmstrong(n) && n%2 == 0) {
            System.out.println("True");
        }
        else {
            System.out.println("False");
        }
    }
}