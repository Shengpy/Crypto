#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string reverseStr(string temp) {
    string input = "";
    for (int i = 0; i < temp.length(); i++) {
        input = temp[i] + input;
    }
    return input;
}
void readFilelevel1(string filename,string &input) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    input = reverseStr(file_data);
}
void readFilelevel3(string filename, string& N, string& k,string &x) {
    string file_data;
    ifstream MyReadFile(filename);
    MyReadFile >> file_data;
    N = reverseStr(file_data);
    MyReadFile >> file_data;
    k = reverseStr(file_data);
    MyReadFile >> file_data;
    x = reverseStr(file_data);
}
void writeFile(string outFileName,string result) {
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
bool isPrime64bit(unsigned long long int number) {
    if (number <= 1)
        return false;
    if (number <= 3) 
        return true;

    // Check if the numberber is divisible by 2 or 3
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    // Check for prime candidates of the form 6k +/- 1
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }

    return true;
}
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
    size_t size = maxLength - minLength-1;
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
string binaryMultiply(string a,string b) {
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
string binaryMod(string a,string b) {
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
        if(compareBinaryStrings(a, temp)==1)
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
        a = binarySubtract(a,b);
    return a;
}
char binaryMod2(const string& a) {
    return a[a.length() - 1];
}
string binaryDivide(string a, string b, string* remainder=nullptr) {
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
        *remainder = a;
        return counter;
    }
    else if (n == 0) {
        *remainder = "0";
        return binaryAdd(counter, "1");
    }
    else {
        *remainder = binarySubtract(a, b);
        return binaryAdd(counter, "1");
    }
}
//return decimal number, a is binary result
int binaryDivide2(string& a){
    int index = a.length()-1;
    int i = 0;

    while (a[index] != '1') {
        i++;
        index--;
        a.pop_back();
    }
    return i;
}

//---------------------------------------------------------------------
string modPow(string a, string b, string n) {
    string result = "1";
    a = binaryMod(a,n);
    int i = 0;
    while (b != "") {
        i++;
        //cout << i << endl;
        if (binaryMod2(b) == '1') {
            //result = binaryMod(binaryMultiply(result,a),n);   // (result * a) % n
            //result=modPow(result, a, n);
            result=binaryMod(binaryMultiply(binaryMod(result, n), binaryMod(a, n)), n);
        }
        //a = binaryMod(binaryMultiply(a,a), n);                  //(a * a) % n;
        //if(a.length()>16)
        //a = modPow(a, "10", n);
        //else
            //a = binaryMod(binaryMultiply(a, a), n);
        //a = binaryMod(a, n);
        a = binaryMod(binaryMultiply(a,a), n);
        //b /= 2;
        b.pop_back();
    }
    return result;
}
bool isPrimeMillerRabin(const string& binaryStr) {
    if (binaryStr.back() == '0') return false;
    string n = binaryStr;
    //if (binaryStr.size() <= 1) return false;
    //if (binaryStr == "10") return true;

    //find s and d
    unsigned long long s = 0;
    string d = binarySubtract(n, "1");
    string n1 = d;
    s = binaryDivide2(d);

    //srand(static_cast<unsigned int>(std::time(nullptr)));
   int ls[]={2,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
   size_t len = binaryStr.length();
   int k = 13;

    //repeat k times
    for (int i = 0; i < k; i++) {
        //a ← random(2, n − 2)  # n is always a probable prime to base 1 and n − 1
        string a = intToBinaryString(ls[i]);
        
        //    x ← a^d mod n
        string x = modPow(a, d, n);//x = pow(a,d) % n 

        //    repeat s times 
        for (int r = 0; r < s; r++) {
            //y ← x^2 mod n
            string y = modPow(x, "10", n);

            //if y = 1 and x ≠ 1 and x ≠ n − 1 then # nontrivial square root of 1 modulo n
            if (y == "1" && x != "1" && x != n1)
                return false;
            //x ← y
            x = y;
        }
        if (x != "1")
            return false;;
    }
    return true;
}
string RSAsolver(string N,string k,string x) {
    N = hexToBinary(N);
    k = hexToBinary(k);
    x = hexToBinary(x);
    string temp=modPow(x, k, N);
    return binToHex(temp);
}
//----------------------------------------------level 2
class combo {
public:
    string x,y,r = "";

    combo(string a,string b,string c) {
        x = a;
        y = b;
        r = c;
    }
};
string GCD(string a, string b) {
    while (b != "0") {
        string temp = b;
        b = binaryMod(a,b);
        a = temp;
    }
    return a;
}
string Euclide(string e, string phi) {
   //phi.y + ed = 1
    combo time0 = combo("1", "0", phi);
    combo time1 = combo("0", "1", e);
    //phi = e.q1 + r2 => q1 = phi/e
    string remainder;
    phi = binaryDivide(phi, e, &remainder);
    //cout << phi << endl;

    //(x2, y2, r2) = (x0 - x1.q1, y0 - y1.q1, r0 - r1.q1)
    //subtract negative number
    combo time2 = combo(
        "1",
        phi,
        binarySubtract(time0.r,
           binaryMultiply(time1.r, phi)));
    //cout << binaryStringToUnsignedLong(time2.x) << " " << binaryStringToUnsignedLong(time2.y) << " " << binaryStringToUnsignedLong(time2.r) << endl;
    
    //--------------------------------------------
    string cp_remainder = remainder;
    phi = binaryDivide(e, remainder, &remainder);
    e = cp_remainder;
    combo time3 = combo(
        binaryMultiply(time2.x,phi), 
        binaryAdd(binaryMultiply(time2.y, phi),"1"),
        binarySubtract(time1.r,
            binaryMultiply(time2.r, phi)));      
    //cout << binaryStringToUnsignedLong(time3.x) << " " << binaryStringToUnsignedLong(time3.y) << " " << binaryStringToUnsignedLong(time3.r) << endl;
    while (time3.r != "1") {
        cp_remainder = remainder;
        phi = binaryDivide(e, remainder, &remainder);
        //cout << binaryStringToUnsignedLong(e)<< "  =  " << binaryStringToUnsignedLong(cp_remainder)<<"   *   " << binaryStringToUnsignedLong(phi) << "   |   " << binaryStringToUnsignedLong(remainder) << endl;
        //cout << e << "  =  " <<cp_remainder << "   *   " << phi << "   |   " << remainder << endl;
        e = cp_remainder;

        time2 = combo(
            binaryAdd(time2.x, binaryMultiply(time3.x,phi)),
            binaryAdd(time2.y,binaryMultiply(time3.y,phi)),
            binarySubtract(time2.r,
                binaryMultiply(time3.r, phi)));

        //cout << binaryStringToUnsignedLong(time2.x) << " " << binaryStringToUnsignedLong(time2.y) << " " << binaryStringToUnsignedLong(time2.r) << endl;
        combo tmp = time3;
        time3 = time2;
        time2 = tmp;
    }
     return time3.y;
}
string RSAfindD(string p,string q,string e) {
    p = hexToBinary(p);
    q = hexToBinary(q);
    e = hexToBinary(e);
    string phi = binaryMultiply(binarySubtract(p, "1"), binarySubtract(q, "1"));
    
    //GCD(a must be > b)
    if (GCD(phi, e) != "1") return "-1";

    string result = Euclide(e, phi);
    return binToHex(result);
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
    string hexInput = "";
    //readFilelevel1("./project_01_01/test_02.inp", hexInput);
    //readFilelevel1(argv[1], hexInput);
    //string binaryResult = hexToBinary(hexInput);

    //if (binaryResult.length() <= 64) {
    //    unsigned long long int decimalValue = binaryStringToUnsignedLong(binaryResult);
    //    //cout << isPrime64bit(decimalValue) << endl;
    //    writeFile(argv[2], isPrime64bit(decimalValue) ? "1" : "0");
    //}
    //else {
    //    //cout << isPrimeMillerRabin(binaryResult);
    //    writeFile(argv[2], isPrimeMillerRabin(binaryResult)?"1":"0");
    //}
    // -------------------------------------------------------------level 2
    string p = "";
    string q = "";
    string e = "";
    readFilelevel3("./project_01_02/test_08.inp", p, q, e);
    //readFilelevel3(argv[1], p, q, e);
    //cout << p << endl;
    //cout << q << endl;
    //cout << e << endl;
    string result=RSAfindD(p, q, e);
    if (result == "-1")
        cout << "-1"<<endl;
        //writeFile(argv[2], "-1");
    else cout << reverseStr(result)<<endl;
    //else writeFile(argv[2], reverseStr(result));
    //--------------------------------------------------------------level 3
    //string N = "";
    //string k = "";
    //string x = "";
    ////readFilelevel3("./project_01_03/test_09.inp", N,k,x);
    //readFilelevel3(argv[1], N, k, x);
    ////cout << reverseStr(RSAsolver(N,k,x))<<endl;
    //writeFile(argv[2], reverseStr(RSAsolver(N, k, x)));

    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}
