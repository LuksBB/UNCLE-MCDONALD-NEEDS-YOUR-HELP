/*
Title: Uncle McDonald Needs Your Help
Author: £ukasz Boguszko
*/

#include <iostream>
#include <sstream>

using namespace std;

struct FENCE {
    int a;
    int b;
};

FENCE get_lengths(int fence_length){
    /*
    L = 2a + b => b = L - 2a
    P = a*b

    P = a*(L - 2a) = La - 2a**2

    P' = L - 4a
    P' = 0 => 4a = L

    a = L / 4
    b = L - 2(L / 4) = L - L / 2 = L / 2
    */
    FENCE lengths;
    if (fence_length % 4 == 3) {
        lengths.a = fence_length / 4 + 1;
        lengths.b = fence_length / 2;
    }
    else if (fence_length % 4 == 0) {
        lengths.a = fence_length / 4;
        lengths.b = fence_length / 2;
    }
    else {
        lengths.a = fence_length / 4;
        lengths.b = fence_length / 2 + 1;
    }
    return lengths;
}

bool is_number(string number) {
    for (int i = 0; i < number.length(); i++) {
        if (isdigit(number[i]) == false) {
            return false;
        }
    }
    return true;
}

int main()
{
    string option = "";
    while(option != "RUN"){
        cout << "Please enter \"RUN\" to run the algorithm: ";
        cin >> option;
    }
    string str_fence_length;
    int fence_length;
    while (1) {
        cout << "Please enter total fence length: ";
        cin >> str_fence_length;
        if (is_number(str_fence_length)) {
            stringstream ss;
            ss << str_fence_length;
            ss >> fence_length;
            if (fence_length >= 3) {
                break;
            }
        }
    }
    FENCE result = get_lengths(fence_length);
    cout << "a: " << result.a << endl;
    cout << "b: " << result.b << endl;
    cout << "Area: " << result.a * result.b << endl;

    return 0;
}