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
    if (argc == 1)
    {
        cout << "filename: ";
        cin >> filename;
    }
    else if (argc == 2)
    {
        filename = argv[1];
        cout << "Reading from file " << filename << endl;
    }
    else
    {
        cerr << "Invalid number of arguements entered. Termininating.";
        exit(1);
    }

    int cases;
    vector<vector<int>> proc;

    readFile(filename, cases, proc);
}

vector<string> readFile(string filename, int &cases, vector<vector<int>> &proc)
{
    ifstream file;
    string line;
    vector<string> schedAlg;
    int x;
    vector<int> temp;

    schedAlg.push_back(" ");
    file.open(filename);
    cout << "[DEBUG] File read.\n";

    if (!file) //If no such file exists, exit.
    {
        cerr << "File does not exist. Terminating program.";
        exit(1);
    }

    file >> cases;
    cout << "[DEBUG] Cases read: " << cases << endl;        cout << "[DEBUG] Loop started.\n";
    for (int n = 1; n <= cases; n++)
    {
        int procNum;
        file >> procNum;
        temp.assign(3, procNum);
        proc.push_back(temp);
        cout << "[DEBUG] Number of processes read: " << procNum << endl;

        string alg;
        getline(file, alg);
        schedAlg.push_back(alg);
        cout << "[DEBUG] Scheduling algorithm read: " << alg << endl;

        temp.clear();

        cout << "[DEBUG] Loop started.\n";
        for (int i = 1; i <= procNum; i++)
        {
            getline(file, line);
            istringstream iss(line);
            for (int j = 1; j <= 3; j++)
            {
                iss >> x;
                temp.push_back(x);
            }
            cout << "[DEBUG] Process " << i << " done:\n";
            for(auto i: temp)
            {
                cout << i << " ";
            }
            cout << endl;
            proc.push_back(temp);
            temp.clear();
        }
        cout << "[DEBUG] Loop ended.\n\n";
    }

    cout << "[DEBUG] Process array:\n";
    for (auto x : proc)
    {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    return schedAlg;
}