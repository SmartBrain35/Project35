#include <iostream>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

	map<std::string, float>::iterator iter;
int main()
{
	map<std::string, float>stock;
	std::string product;
	
	float cartTotal = 0;
	map<std::string, float> cart;
	

	stock["Itel 337"] = 101.250;
	stock["Pendrive"] = 742.021;
	stock["Techno"] = 457.590;
	stock["Infinx"] = 875.600;
	stock["iphone"] = 978.213;
	stock["headphone"] = 56.340;
	stock["airpods"] = 80.100;

	//stock.insert({});
	puts("\t\t\tWELCOME TO SMART PHONE SHOP!!\n");
	puts("\t*******************************************\n");
	
	puts("Prducts <----------> Prices($)");
	for(iter = stock.begin(); iter != stock.end(); ++iter)
	{
		cout<<iter->first<<"\t :\t"<<iter->second<<"\n";
	}
	
	puts("\n*******************************************\n");
	
	do
	{
		puts("Enter product from above list to buy: ");
		getline(cin, product);
		
		puts("\n");
		
		if(!cin)
		{
			cout<<"oops!!...try again!!\n";
			abort();
		}else
		{
			if (stock.find(product) == stock.end() )
			{
				cout<<"oops!!..product not in stock!!\n\n";
					
			}else
			{
				for(iter = stock.begin(); iter != stock.end(); iter++)
				{
					cart[product] = stock[product];
				}
			}
		}

	}while(product != "exit");

	
	puts("\t*******************************************");
	puts("\t\t\tProducts in your cart: ");
	puts("\t*******************************************\n");
	
	for(iter = cart.begin(); iter != cart.end(); ++iter)
	{
		cartTotal += iter->second;
		
		cout<<iter->first<< " : "<<iter->second<<"\n";
	}
	
	cout<<fixed<<setprecision(3)<<"\nTotal amount: $"<<cartTotal<<endl;
	
	puts("\n");
	system("pause");
	
    return 0;
}
//Coded By: Smart-Brain

