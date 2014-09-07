/*
    PROGRAM: question4.CPP
    Written by Bruno Paulino
    This program calculates the movie theater revenue
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

  string movieName;

  double adultTicketPrice =  6;
  double childTicketPrice =  3;
  double movieTheaterPercentage = 0.2;

  double adultTicketsSold;
  double childTicketsSold;
  double total;
  double netBoxProffit;


  cout << "Enter the name of the movie: ";
  getline(cin, movieName);

  cout << "How many adult tickets were sold: ";
  cin >> adultTicketsSold;

  cout << "How many child tickets were sold: ";
  cin >> childTicketsSold;

  total = (adultTicketsSold * adultTicketPrice) + (childTicketsSold * childTicketPrice);
  netBoxProffit = total * movieTheaterPercentage;

  cout << "Movie Name: " << "\t\t\t" << "\"" << movieName << "\"" << endl;
  cout << "Adult Tickets Sold: " << "\t\t" << setw(6) << adultTicketsSold << endl;
  cout << "Child Tickets Sold: " << "\t\t" << setw(6) << childTicketsSold << endl;
  cout << "Gross Box Office Proffit: " << "\t" << "$ " << fixed << setprecision(2) << setw(7) << total << endl;
  cout << "Net  Box Office Proffit: " << "\t" << "$ " << fixed <<  setprecision(2) << setw(7) << netBoxProffit << endl;
  cout << "Amount Paid to Distributor: " << "\t" << "$ " << fixed << setprecision(2) << setw(7) << (total - netBoxProffit) << endl;

  return 0;
}
