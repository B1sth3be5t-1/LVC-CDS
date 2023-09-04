import java.util.*;

class Dyslectionary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = " ";
        boolean bool = true;
        ArrayList<String> out = new ArrayList<>();

        while (sc.hasNextLine()) {
            if (bool)
                str = sc.nextLine();
            ArrayList<String> lis = new ArrayList<>();
            int largest = 0;

            while (!str.equals("")) {
                if (str.length() > largest) largest = str.length();
                lis.add(str);
                str = sc.nextLine();
            }
            
            lis.sort(new Comparator<String> () {
                public int compare(String a,String b)
                {
                    return ((int) a.charAt(a.length() - 1)) - ((int) b.charAt(b.length() - 1));
                }
            });
            for (String s : lis) {
                String ret = " ".repeat(largest - s.length());
                System.out.println(ret + s);
            }

            //out.add("\n");
            System.out.println();
            lis.clear();
            largest = 0;
            bool = false;
            /* for (String s : out) {
                System.out.println(s);
            } */
            str = sc.nextLine();
        }

        
    }
}
