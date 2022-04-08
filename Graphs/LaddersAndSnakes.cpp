#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Useful links:
https://stackoverflow.com/questions/15470948/c-unordered-map-complexity

*/

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) 
{
    
    int visitCount = 0; 
    unordered_map<int,int> passages;
    unordered_map<int,int> visitedDistance; // "visited node -> distance to node" map
    queue<int> nextToVisit; // queue of nodes to visit
    
    // Add ladders and snakes to passage map
    // O(l+s)
     for(auto ladder: ladders)
    {
        passages.insert(make_pair(ladder[0],ladder[1]));
    }
    for(auto snake:snakes)
    {
        passages.insert(make_pair(snake[0],snake[1]));      
    }
    
    // Add first node to visit and its distance from start
    nextToVisit.push(1); 
    visitedDistance.insert(make_pair(1,0));
    
    // O(6*n) , where n is the number of squares (100 in this particular case)
    // => Constant drops so, 0(n)
    while(!nextToVisit.empty())
    {
        // Get first node in queue to be visited
        int node = nextToVisit.front();
        nextToVisit.pop();
        
        if(node == 100)
        {
            //cout<< "total node visits: " << visitCount<< endl;
            return visitedDistance.find(100)->second;
        }
        
        for (int iF= 1; iF <= 6 ; ++iF)
        {
            visitCount++;
            int neighbor = node + iF;
            // Find perf : average O(1), worst case O(linear) ~ depends on bucket size       
            if(passages.find(neighbor)!= passages.end())
            {
                // Since my neighbor is a passage, the other
                // end of the passage is my neigbor as well
                neighbor = passages[neighbor];
            }
            
            int nodeDist = visitedDistance[node];
             // Find perf : average O(1), worst case O(linear) ~ depends on bucket size
            if(visitedDistance.find(neighbor)==visitedDistance.end())
            {
                // Add new neighbor as visited and distance to it
                visitedDistance.insert(make_pair(neighbor, nodeDist +1));
                // Add unvisited neighbor
                nextToVisit.push(neighbor);
            }
            else if (nodeDist +1 < visitedDistance[neighbor])
            {
                // Update distance to neighbor
                visitedDistance[neighbor]= nodeDist+1;
            }
        }
    }
    // No path to end square
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

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
