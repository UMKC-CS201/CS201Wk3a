#include "examples.h"

void example1() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin  >> s1;
    cout << "\nEnter string 2: ";
    cin  >> s2;
    cout << "Your strings are: " << s1 << " & " << s2 << endl << endl;

    cout << "Trying again: \nEnter string 1: ";
    getline(cin, s1);
    cout << "\nEnter string 2: ";
    getline(cin, s2);
    cout << "Your strings are: " << s1 << " & " << s2 << endl << endl;
}

void example2() {
    int n;
    string s1;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter a string: ";
    cin >> s1;
    cout << "You entered: " << n << " & " << s1 << endl << endl;

    cin.ignore(80, '\n');
    cout << "Trying again: \nEnter a number: ";
    cin >> n;
    cin.ignore(80, '\n');
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << "You entered: " << n << " & " << s1 << endl << endl;

    cout << s1.length()<< " = " << s1.size() << endl;
}

void example3() {
    //Using cin.get to get a character at a time
   
    //Read a string & get rid of any uppercase letters
    char c;
    cout << "Enter a string: ";
    cin.get(c);
    while (c != '\n') {
        if (!isupper(c))
            cout << c;
        cin.get(c);
    }
}

void example4() {
    //Read a string & create a new string with only alphabetic characters
    string s1, outString = "";
    cout << "Enter a string: ";
    getline(cin,s1);
    for (unsigned int i = 0; i < s1.length(); i++) {
        if (isalpha(s1[i]))
            outString += s1[i];
    }
    cout << outString;
}
void example3a() {

    //example1();
    //example2();
    //example3();
    example4();

    /*
    char char1[] = "This too shall pass (or not)";
    char* ptr = char1;
    while ((ptr = strchr(ptr, 'o')) != nullptr) {
        *ptr++ = toupper(*ptr);
    }
    cout << char1 << endl;

    for (int i = 0; i < strlen(char1); i++) {
        if (char1[i] == 'o')
            char1[i] = toupper(char1[i]);
    }

    char char3;
    string str1 = "";
    cin.get(char3);
    while (char3 != '\n') {
        str1 += char3;

        cin.get(char3);
    }

    str1 = "This is my line";
    int pos = str1.find("i");
    while (pos >= 0) {
        str1.replace(pos, 1, "X");
        pos = str1.find("i");
    }
    cout << str1 << endl;
    */
}