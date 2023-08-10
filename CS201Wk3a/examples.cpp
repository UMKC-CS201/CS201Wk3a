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
    //issues with combining different types of stream input 
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
void example3aPart1() {

    //example1();
    //example2();
    //example3();
    //example4();

}

void example5() {
    //Demonstration of File I/O
    ifstream inFile;
    ofstream outFile;
    
    inFile.open("input5.txt");
    outFile.open("output5.txt");

    if (!inFile.good()) {
        cout << "Unable to open input file/n";
        return;
    }
    //find average of the odd values
    int next, sum = 0, count = 0;
    while (inFile >> next) {
        if (next % 2 == 1) {
            sum += next;
            count += 1;
            outFile << next << " ";
        }
    }
    outFile << "The average of the odd numbers is: " << static_cast<double>(sum) / count << endl;
    outFile.close();
    inFile.close();
}

void example6() {
    //Demonstration of File I/O & CSV file input using string stream & output formatting
    ifstream inFile;
    ofstream outFile;
 
    inFile.open("input6.txt");
    outFile.open("output6.txt");

    if (!inFile.good()) {
        cout << "Unable to open input file/n";
        return;
    }
 
    //find average for each student
    stringstream inSS;
    string inLine, temp;
    vector<string> row;
    int sum;
    while (getline(inFile, inLine)) {
        stringstream inSS(inLine);                 //copy input line to stringstream
        row.clear();                          //clear vector of previous row information
        sum = 0;
        while (getline(inSS, temp, ',')) {
            row.push_back(temp);              //loop as long as there are commas - push each value onto row
        }
        outFile << row[0] << "  " << setw(15) << left << row[1] << right << '\t';  //print id and name
        sum = stoi(row[2]) + stoi(row[3]) + stoi(row[4]);  //add 3 values together
        outFile << setprecision(2) << fixed << static_cast<double>(sum) / 3 << endl;
    }
    outFile.close();
    inFile.close();
}

void example7() {
    //Demonstration of File I/O & CSV file input using string stream & vector manipulation
    ifstream inFile;
    ofstream outFile;

    inFile.open("input7.txt");
    outFile.open("output7.txt");

    if (!inFile.good()) {
        cout << "Unable to open input file/n";
        return;
    }

    //find average for each student
    stringstream inSS;
    string inLine, temp;
    vector<string> row, names;
    vector<string>::iterator it;

    int sum;
    while (getline(inFile, inLine)) {
        stringstream inSS(inLine);                 //copy input line to stringstream
        row.clear();                          //clear vector of previous row information
        sum = 0;
        while (getline(inSS, temp, ',')) {
            row.push_back(temp);              //loop as long as there are commas - push each value onto row
        }
        if (row[0] == "a") 
            names.push_back(row[1]);
        else if (row[0] == "d") {
            it = find(names.begin(), names.end(), row[1]);
            if (it != names.end())
                names.erase(it);
        }
        else if (row[0] == "r") {
            replace(names.begin(), names.end(), row[1], row[2]);  //replace is found in algorithms
            //it = find(names.begin(), names.end(), row[1]);
            //if (it != names.end()) {
                //names.erase(it);
                //names.push_back(row[2]);
            //}
        }
    }
    for (int i = 0; i < names.size(); i++)
        outFile << names.at(i) << endl;   

    outFile.close();
    inFile.close();
}

void example3aPart2() {

    //example5();
    //example6();
    example7();

}