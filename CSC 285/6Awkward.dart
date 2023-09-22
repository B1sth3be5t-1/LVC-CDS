import 'dart:io';

void main(List<String> args) {
  String inp = stdin.readLineSync()!;
  int numSeats = int.parse(inp);
  Map<int, List<int>> map = {};
  List<int> lis = [];

  inp = stdin.readLineSync()!;
  List<String> strs = inp.split(' ');

  int index = 0;

  for (String s in strs) {
    int num = int.parse(s);

    if (!map.containsKey(num))
      map[num] = [index];
    else
      map[num]!.add(index);

    lis.add(num);
    index++;
  }

  int minDis = -1;
  if (map.length == numSeats) {
    print(numSeats);
    return;
  }

  for (MapEntry<int, List<int>> me in map.entries) {
    if (me.value.length == 1) continue;
    int minDisInner = -1;

    for (int i = 0; i < me.value.length - 1; i++)
      if (minDisInner == -1 || me.value[i + 1] - me.value[i] < minDisInner) {
        minDisInner = me.value[i + 1] - me.value[i];
        if (minDisInner == 1) {
          print(1);
          return;
        }
      }

    if (minDis == -1 || minDisInner < minDis) minDis = minDisInner;
  }

  print(minDis);
}
