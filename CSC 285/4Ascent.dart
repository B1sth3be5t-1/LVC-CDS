import 'dart:io';

void main(List<String> args) {
  String inp = stdin.readLineSync()!; // null safety in name string

  int finx = int.parse(inp.split(' ')[0]);
  int finy = int.parse(inp.split(' ')[1]);

  int numShields = int.parse(stdin.readLineSync()!);

  List<int> heights = [];
  List<double> forces = [];

  for (int i = 0; i < numShields; i++) {
    String line = stdin.readLineSync()!;

    int start = int.parse(line.split(' ')[0]);
    int end = int.parse(line.split(' ')[1]);
    double force = double.parse(line.split(' ')[2]);

    heights.add(end - start);
    forces.add(force);
  }

  double maxGuess = 100000000;
  double minGuess = -100000000;

  if (finx >= 0)
    minGuess = 0;
  else
    maxGuess = 0;

  double lastGuess = (maxGuess + minGuess) / 2;

  while (true) {
    double positionx = 0;
    double positiony = 0;

    for (int i = 0; i < heights.length; i++) {
      positionx += heights[i] * forces[i] * lastGuess;
      positiony += heights[i];
    }
    ;

    if (positiony < finy) {
      positionx += ((finy - positiony) * lastGuess);
      positiony += (finy - positiony);
    }

    if ((positionx - finx).abs() < .0000005) {
      print(lastGuess);
      return;
    }

    if (positionx < finx) {
      minGuess = lastGuess;
      lastGuess = (lastGuess + maxGuess) / 2;
    } else {
      maxGuess = lastGuess;
      lastGuess = (lastGuess + minGuess) / 2;
    }
  }
}

class Shield {
  int start, end;
  double force;

  Shield({required this.start, required this.end, required this.force});

  double addedHeight(double speed) {
    return end - start * speed;
  }
}
