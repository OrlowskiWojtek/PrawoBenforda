#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

int dig(int x, int dignum)
{
    if(x>pow(10,dignum))
    {
        while(x>=pow(10,dignum))
        x /= 10;
        return x%10;
    }
    else
    {
        return 0;
    }
}

class Histogram
{
    int tab[10];
        public:
        Histogram()
        {
            for(int i = 0; i<10;i++)
            {
                tab[i] = 0; 
            }
        } 
        void add_data(int data)
        {
            cout << data << endl;
            ++tab[data];
        }
        int get_val(int dig)
        {
            return tab[dig];
        }
        int sum()
        {
            int x = 0;
            for(int i = 0; i < 10; i++)
            {
                x += tab[i];
            }
            return x;
        }
};

int main()
{
    string dataName= "Iran_pres_2009.csv";
    int rowNum = 7;   
    
    
    ifstream data;
    Histogram hist;
    
    string line, word;
    
    data.open(dataName);
    
	vector <string> row;
    
    int i;

    if(data.is_open())
	{
		while(getline(data, line))
		{
			stringstream str(line);

            if(!line.empty())
            {
                i = 1;
                while(getline(str, word, ','))
                {
                    if(i == rowNum && isdigit(word[0]) && word[0] != 0) hist.add_data(dig(stoi(word),1));
                    i++;
                }
            }
            
		}
	}
	else
		cout<<"Could not open the file\n";

    data.close();
    

    ofstream outData;

    system ("touch gnuData.dat");
    outData.open("gnuData.dat");

    int allData = hist.sum();

    for(int i = 1;  i<=9; i++)
        outData << i << " " << ((double)hist.get_val(i))/allData << endl;

    outData.close();

    system("gnuplot plot.gnu");

    system("rm gnuData.dat");

    return 0;
}