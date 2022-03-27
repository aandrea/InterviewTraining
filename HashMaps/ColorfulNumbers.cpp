
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


/*
    Insert all the digits into hast table
    Create a powerset of digits except empty set (Power Set)
    Multiply all the digits in the individual powerset and insert into Hash Table.
    If any point, number already present in the Hash table, return false
*/


vector<int> getDigits(int a)
{
    vector<int> solution;
    
    int mod = 0;
    int remaining = a;

    while (remaining > 0) 
    {
      int mod = remaining % 10;
      solution.push_back(mod);
      remaining = (remaining) /10;
      cout << "remaining: " << remaining <<" mod: " << mod <<endl;
      
    }

    std::reverse(solution.begin(), solution.end() );
    cout<< solution.size()<<endl;
    return solution;
}

bool isColorful(int a) {
	
    vector<int> digits = getDigits(a);

    set<int> products;
 
    // Iterate at superset level
    size_t level = 1;
    while (level <= digits.size()) 
    {
        cout << "level: " << level <<endl;
        // For each product of this level
        // (I'm moving until digits[digits.size()-level])
        for (size_t iD =0; iD < digits.size() - level+1 ; iD++) 
        {   
            cout << "subset "<< iD <<endl;
            int product = digits[iD];
            
            // For each element in the current set
            // The size of each subset in this level is equal to level
            for (size_t j = iD ; j < iD + level ; j++) 
            {
                product *= digits[j];
                cout << digits[j] << " ";
            }
            cout << endl;

           
            if (products.find(product)!= products.end()) 
            {
                return false;
            } 
            else 
            {
                products.insert(product);
            }
        }
        level++;
    }
    return true;
}

int main() {
    
    int num;

    //cin>>num;
	num = 1236;
    
    if(isColorful(num))
    {
        cout<< num << " is colorful!" << endl;
    }
    else 
    {
        cout<< num << " is not colorful."<< endl;
    }
    return 0;
}

