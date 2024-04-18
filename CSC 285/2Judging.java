import java.util.*;

class Judge {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int lines = Integer.parseInt(scanner.nextLine());

        ArrayList<String> lis1 = new ArrayList<String>();
        ArrayList<String> lis2 = new ArrayList<String>();

        for (int i = 0; i < lines; i++) 
            lis1.add(scanner.nextLine());        
        for (int i = 0; i < lines; i++) 
            lis2.add(scanner.nextLine());


        Collections.sort(lis1);
        Collections.sort(lis2);
        
        int i1 = 0;
        int i2 = 0;

        int count = 0;
        while (i1 < lis1.size() && i2 < lis2.size()) {
            if (lis1.get(i1).equals(lis2.get(i2))) {
                count++;
                i1++;
                i2++;
            }
            else if (lis1.get(i1).compareTo(lis2.get(i2)) < 0) {
                i1++;
            }
            else i2++;
        }
        System.out.println(count);
    }
}