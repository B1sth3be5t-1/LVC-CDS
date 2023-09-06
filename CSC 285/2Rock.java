import java.util.*;

class Rock {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String line = scanner.nextLine();

        String[] nums = line.split(" ");
        int M = Integer.parseInt(nums[0]);
        int S = Integer.parseInt(nums[1]);

        ArrayList<ArrayList<Integer>> map = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < M; i++) {
            ArrayList<Integer> lis = new ArrayList<Integer>();
            for (int j = 0; j < S; j++) 
                lis.add(scanner.nextInt());
            map.add(lis);
        }


        Map<Integer, Integer> numSongs = new HashMap<>();
        int numberOfSongs = 0;

        for (int i = 0; i < S; i++) {
            for (ArrayList<Integer> lis : map) {
                for (int r = i; r <= i; r++) {
                    int songNum = lis.get(r);

                    if (numSongs.containsKey(songNum))
                        numSongs.replace(songNum, numSongs.get(songNum) + 1);

                    else{ numSongs.put(songNum, 1); numberOfSongs++;}
                }
            }

            if (numberOfSongs == i + 1) {


                System.out.println(numSongs.size());
                ArrayList<Integer> songs = new ArrayList<>();
                for (Map.Entry<Integer, Integer> entry : numSongs.entrySet()) {
                    songs.add(entry.getKey());
                }

                Collections.sort(songs);
                String out = "";
                for (int num = 0; num < songs.size(); num++) out += songs.get(num) + " ";

                System.out.println(out.substring(0, out.length() - 1));
                return;
            }
        }
    }
}