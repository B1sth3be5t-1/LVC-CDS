// importing dart:io file
import 'dart:ffi';
import 'dart:io';

void main() {
  // Reading name of the

  int lines = int.parse(stdin.readLineSync()!); // null safety in name string

  for (int i = 0; i < lines; i++) {
    String? s = stdin.readLineSync();

    List<String> lis = [];
    bool poss = true;
    for (String c in s!.split('')) {
      if (c == '.') continue;
      if (c == '\$') lis.add(c);
      if (c == '|') lis.add(c);
      if (c == '*') lis.add(c);
      try {
        lis.last;
      } catch (e) {
        poss = false;
        break;
      }
      if (c == 't') if (lis.last == '|')
        lis.removeLast();
      else {
        poss = false;
        break;
      }
      if (c == 'j') if (lis.last == '*')
        lis.removeLast();
      else {
        poss = false;
        break;
      }
      if (c == 'b') if (lis.last == '\$')
        lis.removeLast();
      else {
        poss = false;
        break;
      }
    }

    if (poss && lis.length == 0)
      print("YES");
    else
      print("NO");
  }
}
