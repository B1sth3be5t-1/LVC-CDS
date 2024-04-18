import java.util.*;

class Sync {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int fNum = 0;
        boolean first = true;

        while (sc.hasNextLine()) {

            if (!first) System.out.println();

            String line = sc.nextLine();

            if (line.equals("")) return;

            fNum = Integer.parseInt(line);


            Map<Integer, Integer> origOrder = new HashMap<>();
            Map<Integer, Integer> map2 = new HashMap<>();

            for (int i = 0; i < fNum; i++) {
                origOrder.put(Integer.parseInt(sc.nextLine()), i);
            }
            for (int i = 0; i < fNum; i++) {
                map2.put(Integer.parseInt(sc.nextLine()), i);
            }

            TreeMap<Integer, Integer> sortedOrig = new TreeMap<>(origOrder);
            TreeMap<Integer, Integer> sortedInp = new TreeMap<>(map2);
            Map<Integer, Integer> orderings = new HashMap<>(){};

            for (int i = 0; i < fNum; i++)
                orderings.put(i, Integer.parseInt(sortedOrig.entrySet().toArray()[i].toString().split("=")[1]));

            int[] out = new int[fNum];
            for (int i = 0; i < fNum; i++) {
                String val = sortedInp.entrySet().toArray()[i].toString().split("=")[0];
                out[orderings.get(i)] = Integer.parseInt(val);
            }


        /*
        10, 1
        67, 2
        68, 3
        28, 4
        after sort origOrder
        10, 1
        28, 4
        67, 2
        68, 3
        orderings has:
        1, 1 - The smallest goes first
        2, 4 - The second smallest goes last
        3, 2
        4, 3

         */
        for (int i : out) {
            System.out.println(i);
        }
        first = false;
        }
    }
}