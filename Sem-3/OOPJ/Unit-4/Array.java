
import java.util.Arrays;
public class Arrays{
  public static void main(String[] args)
  int [] arr = {2,3,4,1,5,6,7,9,10,8}; 
  for (int i=0;i<arr.length;i++){
    System.out.println("Array Element "+ i + ":"+ arr[i]);
  }
  int search = Arrays.binarySearch (arr, 8); 
  System.out.println("Element found at" : + search);
  Arrays.sort(arr);
  for (int i=0;i<arr.length; i++){
    System.out.println("Array Element " +i+ ": "1 + arr[i]);
  }
}
