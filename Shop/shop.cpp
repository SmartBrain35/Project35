#include <iostream>
#include <iterator>//iterator (iter)
#include <map> // map, begin(), end()
#include <iomanip>//precision & fixed
#include <algorithm>//tolower();
#include <ctime> //time & date for checkin/out
using namespace std;

//global iterator i.e iter
map<string, float>::iterator iter;

int main()
{
	map<string, float>stock; //store products
	string product;//item to be bought
	
	//total price of product(s) bought
	double  cartTotal = 0.000;
	double discount = 0.000; 
	map<string, float> cart;// user's cart
	
	//time & date for user check in / out
	time_t mytime;
	time(&mytime);
	
	//current products with prices in stock
	stock["Itel 337"] = 101.250;
	stock["Pendrive"] = 742.021;
	stock["Techno"] = 457.590;
	stock["Infinix"] = 875.600;
	stock["Iphone"] = 978.213;
	stock["Headphone"] = 56.340;
	stock["Airpod"] = 80.100;
	
	//sort(iter.begin(), iter.end());
	
	//stock.insert({}); //wanna add to stock?
	puts("\t\t\tWELCOME TO SMART PHONE SHOP!!\n");
	puts("\t*******************************************\n");
	
	//displaying products and thier prices
	puts("Prducts <----------> Prices($)");
	for(iter = stock.begin(); iter != stock.end(); ++iter)
	{
		cout<<iter->first<<"\t :\t"<<iter->second<<"\n";
	}
	
	puts("\n*******************************************\n");
	
	do
	{	//ask user to buy prefered product
		puts("Enter product from above list to buy: ");
		getline(cin, product);
		
		//convert inputs typed to lowercase
		transform(begin(product), end(product), begin(product), [](char const &c)
		{
                    return tolower(c);
         });
 
    	product[0] = std::toupper(product[0]);
		
		puts("\n");
		
		if(!cin) //if nothing is typed
		{
			cout<<"oops!!...try again!!\n";
			abort();
			
			//if item is type but not in stock
		}else if (stock.find(product) == stock.end())
		{
			cout<<"oops!!..product not in stock!!\n\n";				
		}else
		{
			//if item typed is in stock, add it to user's cart
			cart[product] = stock[product];
		}
	
	//ask user to continue making purchase until "exit" is typed to end the shoppin
	}while(product != "Exit");

	
	puts("\t*******************************************");
	puts("\t\t\tProducts in your cart: ");
	puts("\t*******************************************\n");
	
	//calculating items price added to user's cart and displaying product(s) bought in user's cart with thier prices
	for(iter = cart.begin(); iter != cart.end(); ++iter)
	{
		cartTotal += iter->second;
		
		cout<<iter->first<< " : "<<iter->second<<"\n";
	}
	
	puts("\n*******************************************");
	//time and date for user's "check in"
	cout<<"Check in: "<<ctime(&mytime)<<"\n";
	
	//calculating 10% discount on amount > $1500
	if(cartTotal >= 1500.000)
	{
		cout<<fixed<<setprecision(3)<<"Total amount: $"<<cartTotal<<"\n";
		
		//discount = 10%
		discount = ((10/100) * cartTotal);
		cartTotal = cartTotal - discount;
		
		cout<<"\nDiscount: 10%";
		cout<<fixed<<setprecision(3)<<"\nOverall amount: $"<<cartTotal<<endl;
	}else
	{
		//5% discount here if cartTotal < 1000
		discount = ((5/100) * cartTotal);
		cartTotal = cartTotal - discount;
		
		cout<<"\nDiscount: 5%";
		cout<<fixed<<setprecision(3)<<"\nOverall amount: $"<<cartTotal<<endl;	
	}
	
	puts("\n");
	system("pause");
	
    return 0;
}
//Coded By: Smart-Brain

