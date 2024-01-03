#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string reverseStr(string temp) {
    string input = "";
    for (int i = 0; i < temp.length(); i++) {
        input = temp[i] + input;
    }
    return input;
}
vector<string> split(string str, char del) {
    vector<string> result;
    string temp = "";

    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != del) {
            temp += str[i];
            if(i==str.size()-1)
                result.push_back(reverseStr(temp));
        }
        else {
            result.push_back(reverseStr(temp));
            temp = "";
        }
    }
    return result;
}
void readFilelevel1(string filename, string& p, string& n, vector<string> &list, string &g) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    p = reverseStr(file_data);
    MyReadFile >> file_data;
    n = reverseStr(file_data);
    MyReadFile.ignore();
    string data;
    getline(MyReadFile,data);
    list = split(data, ' ');
    MyReadFile >> file_data;
    g = reverseStr(file_data);

    //cout << p << endl;
    //cout << n << endl;
    //for (int i = 0; i < list.size(); i++) {
    //    cout << list[i] << " ";
    //}
    //cout << endl;
    //cout << g << endl;
}
void readFilelevel2(string filename, string& p, string& g, string& a, string& b) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    p = reverseStr(file_data);
    MyReadFile >> file_data;
    g = reverseStr(file_data);
    MyReadFile >> file_data;
    a = reverseStr(file_data);
    MyReadFile >> file_data;
    b = reverseStr(file_data);
}
void readFilelevel3(string filename, string &p, string& g, string& x, string& c1, string& c2) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    p = reverseStr(file_data);
    MyReadFile >> file_data;
    g = reverseStr(file_data);
    MyReadFile >> file_data;
    x = reverseStr(file_data);
    MyReadFile >> file_data;
    c1 = reverseStr(file_data);
    MyReadFile >> file_data;
    c2 = reverseStr(file_data);
}
void readFilelevel4(string filename, string& p, string& g, string& y, string& m, string& r,string &h) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    p = reverseStr(file_data);
    MyReadFile >> file_data;
    g = reverseStr(file_data);
    MyReadFile >> file_data;
    y = reverseStr(file_data);
    MyReadFile >> file_data;
    m = reverseStr(file_data);
    MyReadFile >> file_data;
    r = reverseStr(file_data);
    MyReadFile >> file_data;
    h = reverseStr(file_data);
}
void writeFile(string outFileName, string result) {
    ofstream myfile;
    myfile.open(outFileName);
    myfile << result;
    myfile.close();
}
//--------------------------------------------------------------convert
string hexDigitToBinaryString(char hexChar) {
    switch (hexChar) {
    case '0': return "0000";
    case '1': return "0001";
    case '2': return "0010";
    case '3': return "0011";
    case '4': return "0100";
    case '5': return "0101";
    case '6': return "0110";
    case '7': return "0111";
    case '8': return "1000";
    case '9': return "1001";
    case 'A': case 'a': return "1010";
    case 'B': case 'b': return "1011";
    case 'C': case 'c': return "1100";
    case 'D': case 'd': return "1101";
    case 'E': case 'e': return "1110";
    case 'F': case 'f': return "1111";
    default: return " "; // Invalid hex character (four spaces)
    }
}
string hexToBinary(const string& hexInput) {
    string binaryResult = "";

    for (char hexChar : hexInput) {
        string a = hexDigitToBinaryString(hexChar);
        if (a != " ") {
            binaryResult += a;
        }
        else {
            // Invalid hex character
            cerr << "Invalid hex character: " << hexChar << endl;
            return "";
        }
    }
    size_t start = binaryResult.find_first_not_of('0');
    if (start != std::string::npos) {
        binaryResult = binaryResult.substr(start);
    }
    else {
        binaryResult = "0";
    }
    return binaryResult;
}
unsigned long long int binaryStringToUnsignedLong(string binaryStr) {
    unsigned long long int result = 0;
    int length = 0;

    // Calculate the length of the binary string
    while (binaryStr[length] == '0' || binaryStr[length] == '1') {
        length++;
    }

    // Convert binary to decimal
    for (int i = 0; i < length; i++) {
        result = (result << 1) | (binaryStr[i] - '0');
    }

    return result;
}
string intToBinaryString(int number) {
    if (number == 0) {
        return "0";
    }

    string binary;
    while (number > 0) {
        int bit = number % 2;
        binary = char('0' + bit) + binary; // Append the bit to the left
        number /= 2;
    }

    return binary;
}
char binaryToHexChar(const std::string& binaryStr) {
    int decimalValue = 0;
    int base = 1;

    for (int i = binaryStr.size() - 1; i >= 0; i--) {
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2;
    }

    if (decimalValue >= 0 && decimalValue <= 9) {
        return static_cast<char>('0' + decimalValue);
    }
    else if (decimalValue >= 10 && decimalValue <= 15) {
        return static_cast<char>('A' + decimalValue - 10);
    }

    return '0';  // Return '0' for invalid input.
}
string binToHex(string binaryStr) {
    int remainder = binaryStr.length() % 4;
    if (remainder == 1) {
        binaryStr = "000" + binaryStr;
    }
    else if (remainder == 2) {
        binaryStr = "00" + binaryStr;
    }
    else if (remainder == 3) {
        binaryStr = "0" + binaryStr;
    }

    std::string hexStr;

    int padding = 4 - (binaryStr.length() % 4);
    if (padding != 4) {
        for (int i = 0; i < padding; i++) {
            hexStr += '0';
        }
    }

    for (size_t i = 0; i < binaryStr.length(); i += 4) {
        std::string fourBits = binaryStr.substr(i, 4);
        hexStr += binaryToHexChar(fourBits);
    }

    return hexStr;
}
//---------------------------------------------------------------------
int compareBinaryStrings(const std::string& a, const std::string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    // Ensure that both strings have the same length by padding with leading zeros if needed
    size_t maxLength = std::max(a.length(), b.length());
    std::string paddedA(maxLength - a.length(), '0');
    std::string paddedB(maxLength - b.length(), '0');
    paddedA += a;
    paddedB += b;

    // Compare the two binary strings lexicographically
    for (int i = 0; i < maxLength; i++) {
        int bitA = paddedA[i] - '0';
        int bitB = paddedB[i] - '0';

        if (bitA < bitB) {
            return -1; // String a is smaller than string b
        }
        else if (bitA > bitB) {
            return 1;  // String a is greater than string b
        }
    }

    return 0; // The two strings are equal
}
string binarySubtract(const string& a, const string& b) {
    std::string result;
    int borrow = 0;

    // Ensure that a and b have the same length by padding with leading zeros if needed
    size_t maxLength = std::max(a.length(), b.length());
    size_t minLength = std::min(a.length(), b.length());
    size_t size = maxLength - minLength - 1;
    std::string paddedA(maxLength - a.length(), '0');
    std::string paddedB(maxLength - b.length(), '0');
    paddedA += a;
    paddedB += b;

    // Perform binary subtraction from right to left
    for (int i = maxLength - 1; i >= 0; i--) {
        int bitA = paddedA[i] - '0';
        int bitB = paddedB[i] - '0';

        int resultBit = (bitA - bitB - borrow + 2) % 2;
        borrow = (bitA - bitB - borrow < 0) ? 1 : 0;

        result = static_cast<char>(resultBit + '0') + result;
    }

    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    if (start != std::string::npos) {
        result = result.substr(start);
    }
    else {
        result = "0";
    }

    return result;
}
string binaryAdd(string a, string b) {
    std::string result;
    int carry = 0;
    size_t max_length = max(a.length(), b.length());
    size_t min_length = min(a.length(), b.length());

    for (int i = 0; i < max_length; i++) {
        int bitA = (i < a.length()) ? a[a.length() - 1 - i] - '0' : 0;
        int bitB = (i < b.length()) ? b[b.length() - 1 - i] - '0' : 0;

        int sum = bitA + bitB + carry;
        string c = sum % 2 > 0 ? "1" : "0";
        result = c + result;
        carry = sum / 2;
    }

    if (carry != 0) {
        result = '1' + result;
    }

    return result;
}
string binaryMultiply(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";  // Multiplying by 0 results in 0.
    }

    std::string result = "0";

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '1') {
            result = binaryAdd(result, b);
        }
        b += "0";  // Shift 'b' left by one position.
    }

    return result;
}
string binaryMod(string a, string b) {
    if (b == "0") {
        //handle division by zero as needed
        return "NaN";
    }
    if (a.length() < b.length())
        return a;

    while (a.length() > b.length()) {
        size_t length = a.length() - b.length();
        string temp = b;
        for (int i = 0; i < length; i++) {
            temp += "0";
        }
        if (compareBinaryStrings(a, temp) == 1)
            a = binarySubtract(a, temp);
        else {
            temp.pop_back();
            a = binarySubtract(a, temp);
        }
    }

    // 0 is == , 1 is remainder > divisor
    int n = compareBinaryStrings(a, b);
    if (n == 0)
        return "0";
    if (n == 1)
        a = binarySubtract(a, b);
    return a;
}
char binaryMod2(const string& a) {
    return a[a.length() - 1];
}
string binaryDivide(string a, string b, string* remainder =NULL) {
    if (b == "0") {
        return "error";
    }
    if (a.length() < b.length()) {
        return "0";
    }

    string counter = "0";

    while (a.length() > b.length()) {
        size_t length = a.length() - b.length();
        string temp = b;
        string plus = "1";
        for (int i = 0; i < length; i++) {
            temp += "0";
            plus += "0";
        }
        if (compareBinaryStrings(a, temp) == 1) {
            a = binarySubtract(a, temp);
            counter = binaryAdd(counter, plus);
        }
        else {
            temp.pop_back();
            plus.pop_back();
            a = binarySubtract(a, temp);
            counter = binaryAdd(counter, plus);
        }
    }

    int n = compareBinaryStrings(a, b);
    if (n == -1) {
        if(remainder!=NULL)
        *remainder = a;
        return counter;
    }
    else if (n == 0) {
        if (remainder != NULL)
        *remainder = "0";
        return binaryAdd(counter, "1");
    }
    else {
        if (remainder != NULL)
        *remainder = binarySubtract(a, b);
        return binaryAdd(counter, "1");
    }
}
//return decimal number, a is binary result
int binaryDivide2(string& a) {
    int index = a.length() - 1;
    int i = 0;

    while (a[index] != '1') {
        i++;
        index--;
        a.pop_back();
    }
    return i;
}
string modPow(string a, string b, string n) {
    string result = "1";
    a = binaryMod(a, n);
    int i = 0;
    while (b != "") {
        i++;
        //cout << i << endl;
        if (binaryMod2(b) == '1') {
            //result = binaryMod(binaryMultiply(result,a),n);   // (result * a) % n
            //result=modPow(result, a, n);
            result = binaryMod(binaryMultiply(binaryMod(result, n), binaryMod(a, n)), n);
        }
        //a = binaryMod(binaryMultiply(a,a), n);                  //(a * a) % n;
        //if(a.length()>16)
        //a = modPow(a, "10", n);
        //else
            //a = binaryMod(binaryMultiply(a, a), n);
        //a = binaryMod(a, n);
        a = binaryMod(binaryMultiply(a, a), n);
        //b /= 2;
        b.pop_back();
    }
    return result;
}
string GCD(string a, string b) {
    while (b != "0") {
        string temp = b;
        b = binaryMod(a, b);
        a = temp;
    }
    return a;
}
//----------------------------------------------level 1
bool cannguyenthuyModuloP(string p, string n, vector<string> list, string g) {
    p = hexToBinary(p);
    n = hexToBinary(n);
    for (int i = 0; i < list.size(); i++) {
        list[i] = hexToBinary(list[i]);
    }
    g = hexToBinary(g);

    for (int i = 0; i < list.size(); i++) {
        //g^(p-1)/k (mod p)
        if (modPow(g, binaryDivide(binarySubtract(p, "1"), list[i]), p) == "1")
            return 0;
    }
    return 1;
}
//----------------------------------------------level 2
void DiffieHellman(string p, string g, string a, string b,string &A,string &B, string &K) {
    p = hexToBinary(p);
    g = hexToBinary(g);
    a = hexToBinary(a);
    b = hexToBinary(b);

    A= reverseStr(binToHex(modPow(g, a, p)));
    B= reverseStr(binToHex( modPow(g, b, p)));
    K= reverseStr(binToHex( modPow(g, binaryMultiply(a,b), p)));
}
//----------------------------------------------level 3
class combo {
public:
    string x, y, r = "";

    combo(string a, string b, string c) {
        x = a;
        y = b;
        r = c;
    }
};
string modInverse(string e, string phi) {
    //phi > e
    //phi.y + ed = 1
    string Oriphi = phi;
    string Orie = e;
    combo time0 = combo("1", "0", phi);
    combo time1 = combo("0", "1", e);
    //phi = e.q1 + r2 => q1 = phi/e
    string remainder;
    //cout << binaryStringToUnsignedLong(phi)<<endl;
    phi = binaryDivide(phi, e, &remainder);
    //cout << binaryStringToUnsignedLong(e) << "  =  " << binaryStringToUnsignedLong(e) << "   *   " << binaryStringToUnsignedLong(phi) << "   |   " << binaryStringToUnsignedLong(remainder) << endl;

    //(x2, y2, r2) = (x0 - x1.q1, y0 - y1.q1, r0 - r1.q1)
    //subtract negative number
    combo time2 = combo(
        "1",
        phi,
        binarySubtract(time0.r,
            binaryMultiply(time1.r, phi)));
    if (time2.r == "1")
        //ed mod phi =1
        if (binaryMod(binaryMultiply(Orie, time2.y), Oriphi) == "1")
            return time2.y;
        else return binarySubtract(Oriphi, time2.y);
    //cout << binaryStringToUnsignedLong(time2.x) << " " << binaryStringToUnsignedLong(time2.y) << " " << binaryStringToUnsignedLong(time2.r) << endl;
    //--------------------------------------------
    string cp_remainder = remainder;
    phi = binaryDivide(e, remainder, &remainder);
    //cout << binaryStringToUnsignedLong(e) << "  =  " << binaryStringToUnsignedLong(cp_remainder) << "   *   " << binaryStringToUnsignedLong(phi) << "   |   " << binaryStringToUnsignedLong(remainder) << endl;
    e = cp_remainder;
    combo time3 = combo(
        binaryMultiply(time2.x, phi),
        binaryAdd(binaryMultiply(time2.y, phi), "1"),
        binarySubtract(time1.r,
            binaryMultiply(time2.r, phi)));
    if (time3.r == "1")
        //ed mod phi =1
        if (binaryMod(binaryMultiply(Orie, time3.y), Oriphi) == "1")
            return time3.y;
        else return binarySubtract(Oriphi, time3.y);
    //cout << binaryStringToUnsignedLong(time3.x) << " " << binaryStringToUnsignedLong(time3.y) << " " << binaryStringToUnsignedLong(time3.r) << endl;
    //cout << e << "  =  " << cp_remainder << "   *   " << phi << "   |   " << remainder << endl;
    while (time3.r != "1") {
        cp_remainder = remainder;
        phi = binaryDivide(e, remainder, &remainder);
        //cout << binaryStringToUnsignedLong(e)<< "  =  " << binaryStringToUnsignedLong(cp_remainder)<<"   *   " << binaryStringToUnsignedLong(phi) << "   |   " << binaryStringToUnsignedLong(remainder) << endl;
        //cout << e << "  =  " <<cp_remainder << "   *   " << phi << "   |   " << remainder << endl;
        e = cp_remainder;

        time2 = combo(
            binaryAdd(time2.x, binaryMultiply(time3.x, phi)),
            binaryAdd(time2.y, binaryMultiply(time3.y, phi)),
            binarySubtract(time2.r,
                binaryMultiply(time3.r, phi)));

        //cout << binaryStringToUnsignedLong(time2.x) << " " << binaryStringToUnsignedLong(time2.y) << " " << binaryStringToUnsignedLong(time2.r) << endl;
        combo tmp = time3;
        time3 = time2;
        time2 = tmp;
    }
    //return d

        //ed mod phi =1
        if (binaryMod(binaryMultiply(Orie, time3.y), Oriphi) == "1")
            return time3.y;
        else return binarySubtract(Oriphi, time3.y);
}
void Elgamal(string p, string g, string x, string c1, string c2,string &h,string &m) {
    p = hexToBinary(p);
    g = hexToBinary(g);
    x = hexToBinary(x);
    c1 = hexToBinary(c1);
    c2 = hexToBinary(c2);

    h = modPow(g, x, p);
    string s = modPow(c1, x, p);
    string s1 = modInverse(s, p);
    m = binaryMod(binaryMultiply(c2, s1), p);

    h = reverseStr(binToHex(h));
    m = reverseStr(binToHex(m));
}
bool ElgamalSignature(string p, string g, string y, string m, string r, string h) {
    p = hexToBinary(p);
    g = hexToBinary(g);
    y = hexToBinary(y);
    m = hexToBinary(m);
    r = hexToBinary(r);
    h = hexToBinary(h);

    string gm = modPow(g, m, p);
    //cout << binaryStringToUnsignedLong(gm)<<endl;
    string yr = modPow(y, r, p);
    //cout << binaryStringToUnsignedLong(yr) << endl;
    string rh = modPow(r, h, p);
    //cout << binaryStringToUnsignedLong(rh) << endl;
    string yrrh = binaryMod(binaryMultiply(yr,rh), p);
    //cout << binaryStringToUnsignedLong(yrrh) << endl;
    if (compareBinaryStrings(gm, yrrh) == 0)return 1;
    return 0;
}
#include <time.h>
int main(int argc, char* argv[]) {
    clock_t tStart = clock();
    //if (argc != 3) {
    //    std::cerr << "Usage: " << argv[0] << " input_file output_file" << std::endl;
    //    return 1;
    //}
    //1 hex character = 4 bit
    //unsigned long long int 8 bytes = 64 bit   => 16 character

    //string inputFileName = argv[1];
    //string outputFileName = argv[2];
    //if (binaryResult.empty()) {
    //    cout << "Error input";
    //    return 0;
    //}

    //cout << "Bit length: " << binaryResult.length() << endl;
    //----------------------------------------------------------------------level 1
    string p = "";
    string n = "";
    vector<string> list;
    string g;
    //readFilelevel1("./project_02_01/test_09.inp", p,n,list,g);
    readFilelevel1(argv[1], p, n, list, g);
    //readFilelevel1(argv[1], hexInput);
    //cout << cannguyenthuyModuloP(p, n, list, g)<<endl;
    writeFile(argv[2], cannguyenthuyModuloP(p, n, list, g)?"1":"0");
    // -------------------------------------------------------------level 2
    //string p = "";
    //string g = "";
    //string a = "";
    //string b = "";
    //string A = "";
    //string B = "";
    //string K = "";
    ////readFilelevel2("./project_02_02/test_00.inp", p, g, a,b);
    //readFilelevel2(argv[1], p, g, a, b);
    //DiffieHellman(p, g, a, b,A,B,K);
    //string result = A + "\n" + B + "\n" + K;
    ////readFilelevel3(argv[1], p, q, e);
    ////cout << p << endl;
    ////cout << q << endl;
    ////cout << e << endl;
    //if (result == "-1")
    //    //cout << "-1" << endl;
    //writeFile(argv[2], "-1");
    //writeFile(argv[2], result);
    //--------------------------------------------------------------level 3
    //string p = "";
    //string g = "";
    //string x = "";
    //string c1 = "";
    //string c2 = "";
    //string h = "";
    //string m = "";
    ////readFilelevel3("./project_02_03/test_07.inp", p,g,x,c1,c2);
    //readFilelevel3(argv[1], p, g, x, c1, c2);
    //Elgamal(p, g, x, c1, c2,h,m);
    //string result = h + "\n" + m;
    //writeFile(argv[2], result);
    //--------------------------------------------------------------level 4
    //string p = "";
    //string g = "";
    //string y = "";
    //string m = "";
    //string r = "";
    //string h = "";
    //readFilelevel4("./project_02_04/test_07.inp", p, g, y,m,r,h);
    //readFilelevel4(argv[1], p, g, y,m,r,h);
    //cout<<ElgamalSignature(p, g, y,m,r,h)<<endl;
    //writeFile(argv[2], ElgamalSignature(p, g, y, m, r, h)?"1":"0");

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
