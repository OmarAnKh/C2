#include <iostream>

using namespace std;

// creat a class

class Country
{
public:
	//Country();
	Country(string , int , float );
	void Set(string, int, float);
	string getCountryName();
	int getPopulation();
	float getArea();
	//	~ Country();
	string LargestArea(Country[], int);
	string LargestPopulation(Country a[], int);
	string LargestPopulationDentisy(Country[], int);

private:
	string CountryName;
	int Population;
	float Area;
};
Country::Country(string c = "a", int p = 1, float a = 1)
{
	CountryName = c;
	Population = p;
	Area = a;
}

// set the values in a Set function

void Country::Set(string c , int p , float a )
{
	CountryName = c;
	Population = p;
	Area = a;
}

// the geter functions

string Country::getCountryName()
{
	return CountryName;
}

int Country::getPopulation()
{
	return Population;
}

float Country::getArea()
{
	return Area;
}

// creat the other functions

string Country::LargestArea(Country d[], int count)
{
	float max = 0;
	string largestArea;
	for (int i = 0; i < count; i++)
	{
		largestArea = (max < d[i].Area) ? d[i].CountryName : largestArea;
	}
	return largestArea;
}

string Country::LargestPopulation(Country a[], int count)
{
	int max = 0;
	string largestPopulation;
	for (int i = 0; i < count; i++)
	{
		largestPopulation = (max < a[i].Population) ? a[i].CountryName : 0;
	}
	return largestPopulation;
}

string Country::LargestPopulationDentisy(Country b[], int count)
{
	float max = 0;
	string largestDensity;
	for (int i = 0; i < count; i++)
	{
		largestDensity = (max < (b[i].Population / b[i].Area)) ? b[i].CountryName : 0;
	}
	return largestDensity;
}

//~Country() {
//
// }

int main()
{
	Country f[3];
	f[0].Set("Palestine", 6000000, 270027);
	f[1].Set("Egypt", 120000000, 1002000);
	f[2].Set("Turkey", 84000000, 783562);
	cout << f->LargestArea(f, 3) << "\t" << f->LargestPopulation(f, 3) << "\t" << f->LargestPopulationDentisy(f,3);
}