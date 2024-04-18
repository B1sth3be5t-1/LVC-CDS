// importing dart:io file
import 'dart:io';

void main()
{
	// Reading name of the Geek
	int lines = int.parse(stdin.readLineSync()!); // null safety in name string

	// Printing the name
    for (int i = 0; i < lines; i++) {
        String? s = stdin.readLineSync();
        if (s!.substring(0, 10) == "Simon says") print(s.substring(11));
    }
}
