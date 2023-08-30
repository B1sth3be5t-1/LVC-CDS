// importing dart:io file
import 'dart:io';

void main() {
  // Reading name of the Geek
  int lines = int.parse(stdin.readLineSync()!); // null safety in name string

  RegExp reg1 = RegExp(r'^Simon says .');
  // Printing the name
  for (int i = 0; i < lines; i++) {
    String? s = stdin.readLineSync();
    if (reg1.hasMatch(s!)) print(s.substring(11));
  }
}
