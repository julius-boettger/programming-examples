/*

SETUP
- get dart: https://dart.dev/get-dart
    - on non-debian-based linux:
        - download zip archive
        - in your shell configuration: export PATH="$PATH:/path/to/dart-sdk/bin"
- create new project: dart create project-name
- run project: dart run

*/

// import code from other files
import "basics.dart";

// entry point of the program. the file containing this needs to be specified in pubspec.yaml
void main() {
    // run examples from other files
    basicExamples();
}
