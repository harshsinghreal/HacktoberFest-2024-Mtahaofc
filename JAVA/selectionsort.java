import java.util.*;


public class selectionsort {
    static int[] selectionsorting(int [] A){
        
        for(int i=0;i<=A.length-2;i++){
               int min=i;
            for(int j=i+1;j<A.length;j++){
                if(A[j]<A[min]){
                    min=j;
                }
            }
            int temp=A[min];
                A[min]=A[i];
                A[i]=temp;
        }
        return A;
    }
    public static void main(String[]args){
        Scanner sc= new Scanner(System.in);
        int size=sc.nextInt();
        int arr1[]=new int[size];
        for(int i=0;i<size;i++){
            arr1[i]=sc.nextInt();
        }
        arr1=selectionsorting(arr1);
        for(int i=0;i<size;i++){
               System.out.println(arr1[i]+" ");
        }
        sc.close();

    }
}
