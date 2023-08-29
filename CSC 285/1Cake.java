import java.util.*;

class Cake {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    String line = sc.nextLine();

    String[] numsStr = line.split(" ");
    int[] nums = new int[3];
    for (int i = 0; i < 3; i++) nums[i] = Integer.parseInt(numsStr[i]);  

    int maxH = Math.max(Math.abs(nums[0] - nums[1]),  nums[1]);
    int maxL = Math.max(Math.abs(nums[0] - nums[2]),  nums[2]);


    System.out.println(maxH * maxL * 4);
    }
}