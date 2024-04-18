import 'dart:io';

void main(List<String> args) {
  int lines = int.parse(stdin.readLineSync()!); // null safety in name string

  int fTrain = 0;
  int lTrain = 0;
  int count = 0;

  for (int i = 0; i < lines; i++) {
    int t = int.parse(stdin.readLineSync()!);
    if (fTrain == 0) {
      fTrain = t;
      lTrain = t;
      count++;
      continue;
    }

    if (t >= fTrain) {
      fTrain = t;
      count++;
    } else if (t <= lTrain) {
      lTrain = t;
      count++;
    }
  }

  print(count);
}
