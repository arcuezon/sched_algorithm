#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<string> readFile(string filename, int &cases, vector<vector<int>> &proc);

int main(int argc, char *argv[])
{
    string filename;
    //Checking filename
    if (argc == 1) //User input filename
    {
        cout << "filename: ";
        cin >> filename;
    }
    else if (argc == 2) //Filename as argument
    {
        filename = argv[1];
    }
    else //Invalid nu,ber of arguments
    {
        cerr << "Invalid number of arguements entered. Termininating.";
        exit(1);
    }
    cout << "Reading from file: " << filename << endl;

    /*
    proc(process) vector contains all processes and their details in a (numofproc x 3) dimension vector with
    index starting at 1 since 0 is allocated to the number of processes per case
    */

    int cases;                                                 //Number of test cases (First line in txt file)
    vector<vector<int>> proc;                                  //Vector for processes
    vector<string> schedAlg = readFile(filename, cases, proc); //Read from file

    cout << "[DEBUG] Algorithm vector:\n";
    for (auto x : schedAlg) //Debug
    {
        cout << x << endl;
    }

    cout << "[DEBUG] Process vector:\n";
    for (auto x : proc) //Debug
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    cout << endl;
    for (int n = 0; n < cases; n++) //Main for loop
    {
        cout << "Case " << n << ": " << schedAlg[n] << endl;
        cout << proc[0][0] << " processes\n";




        proc.erase(proc.begin(), proc.begin() + proc[0][0] + 1); //Erase test cases that are done
    }

    return 0;
}

vector<string> readFile(string filename, int &cases, vector<vector<int>> &proc)
{
    ifstream file;
    string line;
    vector<string> schedAlg;
    int x;
    vector<int> temp;

    file.open(filename);
    cout << "[DEBUG] File read.\n";

    if (!file) //If no such file exists, exit.
    {
        cerr << "File does not exist. Terminating program.";
        exit(1);
    }

    file >> cases;
    cout << "[DEBUG] Cases read: " << cases << endl;
    cout << "[DEBUG] Case Loop started.\n\n";
    for (int n = 1; n <= cases; n++)
    {
        int procNum; //num of processes for test case
        file >> procNum;
        temp.assign(3, procNum); //assign to a vector
        proc.push_back(temp);    //push to proc
        cout << "[DEBUG] Number of processes read: " << procNum << endl;

        string alg; //algorithm for test case
        getline(file, alg);
        istringstream iss(alg);
        iss >> ws; //trim whitespace
        getline(iss, alg);
        schedAlg.push_back(alg); //push to schedAlg
        cout << "[DEBUG] Scheduling algorithm read: " << alg << endl;

        temp.clear();

        cout << "[DEBUG] Process Loop started.\n";
        for (int i = 1; i <= procNum; i++)
        {
            getline(file, line);
            istringstream iss(line);
            for (int j = 1; j <= 3; j++)
            {
                iss >> x;
                temp.push_back(x);
            }
            cout << "[DEBUG] Process " << i << " done: ";
            for (auto i : temp)
            {
                cout << i << " ";
            }
            cout << endl;
            proc.push_back(temp);
            temp.clear();
        }
        cout << "[DEBUG] Process Loop ended.\n\n";
    }

    return schedAlg;
}