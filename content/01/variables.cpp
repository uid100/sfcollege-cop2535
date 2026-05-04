// Exploring primitive 'built-in' data types

#include <iostream>
#include <sstream>
#include <typeinfo>
#include <bitset>

using namespace std;

template <typename T> string binary(T value) {
    stringstream ss;
    int szBits = sizeof(value) * 8;

    // tried this... works for some cases and variable types.
    /*while (szBits-- > 0) {
        ss << ((value >> szBits) & 1);
        if (szBits % 8 == 0) ss << ' ';
    }*/
    // evolved to this.
    char* bits = reinterpret_cast<char*>(&value);
    for (size_t i = 0; i < sizeof(value); ++i) {
        ss << bitset<8>(bits[i]) << ' ';
    }

    return ss.str();
}

template <typename T> string about(T *value) {
    stringstream ss;
    int sz = sizeof(*value);
    ss << '\t' << "type:    " << typeid(*value).name() << endl;
    ss << '\t' << "value:   " << *value << endl;
    ss << '\t' << "size:    " << sz << " bytes (" << sz * 8 << " bits)" << endl;
    ss << '\t' << "bits:    " << binary(*value) << endl;
    ss << '\t' << "address: " << hex << value << endl;
    return ss.str();
}

void EnterToContinue() {
    cout << "Press [Enter] to continue...";
    cin.get();
    system("cls");
}

void Boolean() {
    cout << "Boolean:" << endl;
    cout << "\tA boolean value can only be true or false.\n";
    cout << "\tHere's what they look like." << endl << endl;

    bool yesNo = true;
    cout << about(&yesNo) << endl << endl;

    yesNo = false;
    cout << about(&yesNo) << endl << endl;

    bool nope = false;
    cout << about(&nope) << endl << endl;

    cout << "the address for the first two examples are the same because "
        << "they are the same variable - only the value was changed." 
        << endl << endl;

    EnterToContinue();
}

void Character() {
    cout << "Character:" << endl;

    char alpha = 'A';
    cout << about(&alpha) << endl << endl;

    char numeral = '9';
    cout << about(&numeral) << endl << endl;

    char punct = ';';
    cout << about(&punct) << endl << endl;

    unsigned char number = 123;
    cout << about(&number) << endl << endl;

    cout << "C++ uses an overload for the << operator which interprets a char * "
        << "as the start of a null-terminated string and instead of showing the address, the "
        << "system will read to the next null value." << endl << endl
        << "The signed and unsigned type modifiers can be used as integer types"
        << "that are the same size as the char type." << endl << endl;

    EnterToContinue();
}

void Integer() {
    cout << "Integer types:" << endl;

    int a = 123456789;
    cout << about(&a) << endl << endl;

    short int b = 123456789;
    cout << about(&b) << endl << endl;

    long int c = 123456789;
    cout << about(&c) << endl << endl;

    unsigned short int x = -55;
    cout << about(&x) << endl << endl;

    signed short int y = -55;
    cout << about(&y) << endl << endl;

    x = 55;
    cout << about(&x) << endl << endl;

    y = 55;
    cout << about(&y) << endl << endl;

    cout << "Scroll to see more." << endl << endl;

    cout << "The long and short type modifiers change the size of the variable"
        << "to optimize memory usage for larger or smaller values." 
        << endl << endl;

    cout << "Type \'int\' may default to long or short depending on the system."
        << endl << endl;

    cout << "Values which exceed the size available are truncated! "
        << "This is a situation to be aware of." << endl << endl;

    cout << "Compare the binary equivalent of the signed and unsigned "
        << "variables assigned the same value." << endl << endl;


    EnterToContinue();
}

void FloatingPoint() {
    cout << "Floating Point types are float, double, and long double:" << endl;

    float p = 3.14159f;
    cout << about(&p) << endl << endl;
    p = -p;
    cout << about(&p) << endl << endl;
    p = 31.4159f;
    cout << about(&p) << endl << endl;
    p = -p;
    cout << about(&p) << endl << endl;
    p = .314159f;
    cout << about(&p) << endl << endl;
    p = -p;
    cout << about(&p) << endl << endl;

    double L = 6.02e23;
    cout << about(&L) << endl << endl;

    long double big = 1.234e300L;
    cout << about(&big) << endl << endl;

    cout << "- Floating point numbers are stored in memory according to "
        << "an IEEE(754) standard." << endl
        << "- The first bit is the sign, where 0 indicates a positive "
        << "value and 1 indicates a negative value." << endl
        << "- The next 8 bits are used for the exponent." << endl
        << "- The remaining 23 bits are for the significant part" << endl
        << "- For double precision, 64 bits are used to store a floating - "
        << "point number." << endl << endl;

    EnterToContinue();
}

void Valueless() {}

void WideCharacter() {}

int menuItems()
{
    int selection;

    cout << "(main menu)" << endl;
    cout << "==================================================" << endl;
    cout << "The c++ standard includes 7 built-in data types:\n";
    cout << "\t 1. bool" << endl;
    cout << "\t 2. char" << endl;
    cout << "\t 3. int" << endl;
    cout << "\t 4. float" << endl;
    cout << "\t 5. double" << endl;
    cout << "\t 6. void" << endl;
    cout << "\t 7. wchar_t" << endl << endl;

    cout << "also 4 data type modifiers" << endl;
    cout << '\t' << "signed" << endl;
    cout << '\t' << "unsigned" << endl;
    cout << '\t' << "short" << endl;
    cout << '\t' << "long" << endl;
    cout << "==================================================" << endl << endl;

    cout << "select a menu item from above to learn more: ";
    cin >> selection;
    cin.get();
    system("cls");  // clear the screen
    return selection;
}

void mainMenu()
{
    while(true) {
        switch (menuItems()) {
            case 1:
                Boolean();
                break;
            case 2:
                Character();
                break;
            case 3:
                Integer();
                break;
            case 4:
            case 5:
                FloatingPoint();
                break;
            case 6:
                Valueless();
                break;
            case 7:
                WideCharacter();
                break;
            default:
                cout << "done." << endl;
                return;
        }
    }
}

int main()
{
    mainMenu();
}