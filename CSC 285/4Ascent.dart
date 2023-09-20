import 'dart:io';

void main(List<String> args) {
  String inp = stdin.readLineSync()!; // null safety in name string

  int finx = int.parse(inp.split(' ')[0]);
  int finy = int.parse(inp.split(' ')[1]);

  int numShields = int.parse(stdin.readLineSync()!);

  List<Shield> shields = [];

  for (int i = 0; i < numShields; i++) {
    String line = stdin.readLineSync()!;

    int start = int.parse(line.split(' ')[0]);
    int end = int.parse(line.split(' ')[1]);
    double force = double.parse(line.split(' ')[2]);

    shields.add(Shield(start: start, end: end, force: force));
  }

  shields.sort((Shield a, Shield b) => a.start - b.start);

  double lastGuess = finx * 1.0 / finy;

  while (true) {
    double positionx = 0;
    double positiony = 0;

    for (Shield s in shields) {
      if (positiony < s.start) {
        double dis = s.start - positiony;
        positionx += (dis * lastGuess);
        positiony += dis;
      }
      positionx += (s.end - s.start) * s.force * lastGuess;
      positiony += (s.end - s.start);
    }

    if (positiony < finy) {
      positionx += ((finy - positiony) * lastGuess);
      positiony += (finy - positiony);
    }

    if ((positionx - finx).abs() < .0000005) {
      print(lastGuess);
      return;
    }

    if (positionx < finx)
      lastGuess = (lastGuess + (finx - positionx) / 100 * lastGuess);
    else
      lastGuess = (lastGuess - (finx - positionx) / 100 * lastGuess);
  } //todo fix
}

class Shield {
  int start, end;
  double force;

  Shield({required this.start, required this.end, required this.force});

  double addedHeight(double speed) {
    return end - start * speed;
  }
}
