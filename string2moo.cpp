#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>

int main() {
    using namespace std;

    FILE* fp;
    fp = fopen("string.cow", "w");

    cout << "enter a string to get converted into cow script: ";
    std::string str;
    getline(cin, str);

    // create file and add the static parts
    int strLegnth = str.length();
    cout << "strlen is " << strLegnth << "  ";
    for (int i = 0; i < strLegnth; i++) {
        if (i > 0) {
            fputs("//move address", fp);
        }

        for (int k = 0; k < i; k++) {
            if (!(k % 20)) {
                fputs("\n", fp);
            }
            fputs("moO ", fp);
        }
        fputs("\n//char data\n", fp);
        for (int j = 0; j < int(str.at(i)); j++) {
            // if 20 MoO then new line becuase it looks nicer
            if (!(j % 20) && !j == 0) {
                fputs("\n", fp);
            }
            // add 1 to current mem block
            fputs("MoO ", fp);
        }
        // move one mem blockm
        fputs("\n//print val\nMoo\n\n", fp);
    }
    // exit

    fclose(fp);
    return 0;
}