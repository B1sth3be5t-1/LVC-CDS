import 'dart:io';

void main(List<String> args) {
  String inp = stdin.readLineSync()!;
  int numSeats = int.parse(inp);
  Map<int, int> map = {};

  inp = stdin.readLineSync()!;
  List<String> strs = inp.split(' ');

  int minDis = -1;
  int index = 0;

  for (String s in strs) {
    int num = int.parse(s);

    if (map.containsKey(num) && (minDis == -1 || index - map[num]! < minDis)) {
      minDis = index - map[num]!;
    }

    if (minDis == 1) {
      print(1);
      return;
    }

    map[num] = index;

    index++;
  }

  if (map.length == numSeats) {
    print(numSeats);
    return;
  }

  print(minDis);
}
