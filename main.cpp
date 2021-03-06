#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int rotationAmount, vector<int> myArray) {
    /*
     * Goal: Create a function that is able to shift an array of size n some units to the left
     * For example: [1,2,3,4,5] with rotationAmount = 2
     * newArray = [3,4,5,1,2] where 1,2 "wrapped around the end of the array
     *
     * Note: seems like a potentially good use of a FIFO Queue where we push elements in the back & pop them out
     * Perhaps using a for loop to pop and push the same elements.
     */
    queue<int> myQueue;

    //load vector into queue (highly inefficient)
    for (int i = 0; i < myArray.size(); i++) {
        int element = myArray[i];
        myQueue.push(element);
    }
    //perform front pop/push rotationAmount number of times.
    for (int j = 0; j < rotationAmount; j++) {
        int shiftedElement = myQueue.front();
        myQueue.pop();
        myQueue.push(shiftedElement);
    }
    myArray.clear();

    //load contents of queue into vector
    while (!myQueue.empty()) {
       int processedElement = myQueue.front();
       myArray.push_back(processedElement);
       myQueue.pop();
    }
    //return new vector
    return myArray;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
